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

    void replace_all(const int& from, const int& to, const char& toFind, const char& replaceWith, std::string& __string);
}
