#pragma once

#include <string>

namespace MYLE {

    ///
    /// \brief randomIntegerInRange Generates a random integer in the given bounds
    /// \param from Startindex
    /// \param to Endindex
    /// \return randomInteger
    ///
    int randomIntegerInRange(int from, int to);

    ///
    /// \brief IntegerToBinaryString converts a number into a binary string in the format %32s
    /// \param number number to convert
    /// \return std::string binary string
    ///
    std::string integerToBinaryString(int& number);

    void __swap(int& a, int& b);

    int getMSD(int& i);

    int getDigits(int& i);

}
