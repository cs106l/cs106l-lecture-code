#include "soundex.h"

#include <algorithm>
#include <iterator>
#include <map>

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
  return encoding.at(std::toupper(c));
}

static bool notZero(char c)
{
  return c != '0';
}
  
std::string soundex(const std::string& s)
{
  char firstLetter = toupper(*std::find_if(s.begin(), s.end(), isalpha));

  std::string nonLetters;
  std::copy_if(s.begin(), s.end(), std::back_inserter(nonLetters), isalpha);

  std::string encoded;
  std::transform(nonLetters.begin(), nonLetters.end(), std::back_inserter(encoded), soundexEncode);

  std::string noDups;
  std::unique_copy(encoded.begin(), encoded.end(), std::back_inserter(noDups));

  noDups[0] = firstLetter;

  std::string noZeros;
  std::copy_if(noDups.begin(), noDups.end(), std::back_inserter(noZeros), notZero);

  noZeros += "0000";
  return noZeros.substr(0, 4);
}