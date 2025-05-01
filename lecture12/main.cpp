#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <map>
#include <vector>
#include <random>

#include "soundex.h"

static const std::map<std::string, std::function<std::string(const std::string &)>> algorithms = {
    {"soundex", soundex},
    {"soundexRanges", soundexRanges}};

std::vector<std::string> getAlgorithms(int argc, char *argv[])
{

  auto printOptions = [&]()
  {
    std::cerr << "Options are: " << std::endl;
    for (const auto &[name, _] : algorithms)
    {
      std::cerr << "  - " << name << std::endl;
    }
  };

  std::vector<std::string> arguments(argv + 1, argv + argc);
  if (arguments.empty())
  {
    std::cerr << "No arguments provided. ";
    printOptions();
    exit(1);
  }

  for (const auto &algo : arguments)
  {
    if (algorithms.find(algo) == algorithms.end())
    {
      std::cerr << "Unknown algorithm: '" << algo << "'. ";
      printOptions();
      exit(1);
    }
  }

  return arguments;
}

auto readLines(const std::string &path)
{
  std::ifstream file(path); // Open the file
  std::vector<std::string> lines;

  for (std::string line; std::getline(file, line);)
  {
    lines.push_back(line);
  }

  return lines;
}

auto sampleN(const std::vector<std::string> &names, size_t n)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::vector<std::string> result(n);
  std::ranges::sample(names, result.begin(), result.size(), gen);
  return result;
}

template <typename Soundex>
void showSoundexCodes(const std::vector<std::string> &names, const std::string &algo, Soundex soundex)
{
  std::cout << "Soundex output for '" << algo << "'" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  for (const auto &name : names)
  {
    std::cout << name << " -> " << soundex(name) << std::endl;
  }
  std::cout << std::endl;
}

template <typename Soundex>
void timeSoundex(
    const std::vector<std::string> &names,
    const std::string &algo,
    Soundex soundex,
    size_t rounds = 8)
{
  using namespace std::chrono;

  auto start = high_resolution_clock::now();

  for (size_t i = 0; i < rounds; ++i)
  {
    for (const auto &name : names)
    {
      soundex(name);
    }
  }

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start).count();
  auto num_rounds = names.size() * rounds;
  auto average_time = duration / num_rounds;

  std::cout << "Ran algorithm '" << algo << "' " << num_rounds << " times" << std::endl;
  std::cout << "Average time per call: " << average_time << " nanoseconds\n"
            << std::endl;
}

int main(int argc, char *argv[])
{
  // Get algorithms from command line
  auto choices = getAlgorithms(argc, argv);

  // Read names from file
  auto names = readLines("names.txt");

  // Randomly sample 10 names and print soundex output
  auto sample = sampleN(names, 5);
  sample.push_back("Roberts-");

  for (const auto &algo : choices)
  {
    showSoundexCodes(sample, algo, algorithms.at(algo));
    timeSoundex(names, algo, algorithms.at(algo));
  }

  return 0;
}