#include "soundex.h"

#include <algorithm>
#include <iterator>
#include <map>
#include <ranges>

static char soundexEncode(char c)
{
  static const std::map<char, char> encoding = {
    {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'}, {'H', '0'}, {'W', '0'}, {'Y', '0'},
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
  };
  // std::cout << c << " -> " << encoding.at(std::toupper(c)) << std::endl;
  return encoding.at(std::toupper(c));
}

static bool notZero(char c)
{
  return c != '0';
}

std::string soundexRanges(const std::string& s)
{
  namespace rv = std::ranges::views;

  auto first = *std::ranges::find_if(s, ::isalpha);       // Get first letter 
  auto v = s | rv::filter(::isalpha) | rv::transform(soundexEncode);

  std::string encoded;
  std::ranges::unique_copy(v, std::back_inserter(encoded));
  encoded[0] = std::toupper(first);

  return encoded 
         | rv::filter(notZero)             // Get rid of zeros
      // | rv::concat("0000")              // Ensure length >= 4 (C++26)
         | rv::take(4)                     // Take first four
         | std::ranges::to<std::string>(); // Convert to string
}