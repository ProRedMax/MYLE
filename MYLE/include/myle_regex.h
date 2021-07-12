#pragma once
#include <regex>
#include <string>

namespace MYLE
{
    inline bool contains(std::string& myString, std::string otherString, bool iCase = false)
    {
        std::regex rgx(otherString, std::regex_constants::ECMAScript | iCase ? std::regex::icase : std::regex::basic);
        return std::regex_search(myString, rgx); 
    }

    inline std::vector<std::string> getAllMatches(std::string& myString, std::regex regex)
    {
        std::vector<std::string> returnVector;
       
        auto words_begin = 
        std::sregex_iterator(myString.begin(), myString.end(), regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();
            returnVector.push_back(match_str);
        }
        return returnVector;
    }

    inline int count_matches(std::string& myString, std::string& regex)
    {
        std::regex rgx(regex);
        auto words_begin = 
        std::sregex_iterator(myString.begin(), myString.end(), rgx);
        auto words_end = std::sregex_iterator();
        return std::distance(words_begin, words_end);
    }
    
}
