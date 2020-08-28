#pragma once

#include <string>

namespace MYLE {

    ///
    /// \brief randomIntegerInRange Generates a random integer in the given bounds
    /// \param from Startindex
    /// \param to Endindex
    /// \return randomInteger
    ///
    int rand_int(int from, int to, bool seed = false);

    ///
    /// \brief IntegerToBinaryString converts a number into a binary string in the format %32s
    /// \param number number to convert
    /// \return std::string binary string
    ///
    std::string itobs(int& number);

    void __swap(int& a, int& b);

    int msd(int& i);

    int digits(int& i);

}
