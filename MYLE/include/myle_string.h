#pragma once

#include <string>

namespace MYLE {

    ///
   /// \brief randomString Returns a std::string with randomly placed characters based on your charset with the given length
   /// \param length Length of the random string
   /// \param charSet string with a characters you want to fill up your random string
   /// \return std::string randomString
   ///
    std::string rand_string(int length, const std::string& charSet);

    ///
    /// \brief randomString Returns a std::string with randomly placed characters with the given length
    /// \param length Length of the random string
    /// \return std::string randomString with the english alphabet
    ///
    std::string rand_string(int length);

    /// <summary>
    /// Replace certain characters with the given one in a certain range
    /// </summary>
    /// <param name="from">Start of the range</param>
    /// <param name="to">End of the range</param>
    /// <param name="toFind">Character to find</param>
    /// <param name="replaceWith">Character to replace with</param>
    /// <param name="__string">Your string</param>
    void replace_all(const int& from, const int& to, const char& toFind, const char& replaceWith, std::string& __string);


    /**
     * \brief Multiply the given string 
     * \param __string String to multiply
     * \param n How often the string should be multiplied
     */
    void mult_string(std::string& __string, const int& n);

    /**
     * \brief Multiply a given string with blank spaces in between. 
     * \param __string String to multiply
     * \param n How often the string should be multiplied
     */
    void mult_string_s(std::string& __string, const int& n);

    
}
