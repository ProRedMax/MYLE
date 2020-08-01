#ifndef MYLE_H
#define MYLE_H

#include "MYLE_global.h"
#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <vector>

class MYLE
{
public:
    MYLE();

    ///
    /// \brief randomString Returns a std::string with randomly placed characters based on your charset with the given length
    /// \param length Length of the random string
    /// \param charSet string with a characters you want to fill up your random string
    /// \return std::string randomString
    ///
    std::string randomString(int length, const std::string & charSet);

    ///
    /// \brief randomString Returns a std::string with randomly placed characters with the given length
    /// \param length Length of the random string
    /// \return std::string randomString with the english alphabet
    ///
    std::string randomString(int length);

    ///
    /// \brief randomIntegerInRange Generates a random integer in the given bounds
    /// \param from Startindex
    /// \param to Endindex
    /// \return randomInteger
    ///
    int randomIntegerInRange(int from, int to);

    ///
    /// \brief writeLineToFile Write a single string to a file fast
    /// \param path Path
    /// \param content std::String
    ///
    void writeLineToFile(std::string &path, const std::string &content);

    ///
    /// \brief writeToFile Write a std::vector<std::string> to a file fast
    /// \param path Path
    /// \param content std::vector<std::string>
    ///
    void writeToFile(std::string& path, std::vector<std::string> &content);

    ///
    /// \brief readFile read a std::vector<std::string> out of a file
    /// \param path Path
    /// \return std::vector<std::string>
    ///
    std::vector<std::string> readFile(std::string &path);

    std::string IntegerToBinaryString(int& number);

    void replaceAll(const int& from, const int& to, const char& toFind, const char& replaceWith, std::string &__string);

    int luhn_checksum(std::string number);

    bool luhn(std::string number);

private:
    int getLuhnSum(std::string number);
};

#endif // MYLE_H
