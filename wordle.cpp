#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void wordleHelper(std::string partial,
    const std::string& floating,
    const std::set<std::string>& dict,
    std::set<std::string>& result,
    unsigned int curr);


bool contains(std::string partial, const std::string& floating, unsigned int index);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    std::set<std::string> result;
    std::string partial = in;
    wordleHelper(partial, floating, dict, result, 0);
    return result;
}





// Define any helper functions here
void wordleHelper(std::string partial,
    const std::string& floating,
    const std::set<std::string>& dict,
    std::set<std::string>& result,
    unsigned int curr)
{
    if (curr == partial.size())
    {
        if (dict.find(partial) != dict.end())
        {
          if (contains(partial, floating, 0))
          {
            result.insert(partial);
          }
        }
        return;
    }

    if (partial[curr] != '-')
    {
      wordleHelper(partial, floating, dict, result, curr + 1);
    }

    else
    {
      for (int i = 97; i <= 122; i++) //for all letters
      {
        partial[curr] = char(i);
        wordleHelper(partial, floating, dict, result, curr + 1);
      }
    }
}


bool contains(std::string partial, const std::string& dependents, unsigned int index)
{
  if (index == dependents.size())
  {
    return true;
  }
  if (partial.find(dependents[index]) == std::string::npos)
  {
    return false;
  }
  return contains(partial, dependents, index + 1); 
}


