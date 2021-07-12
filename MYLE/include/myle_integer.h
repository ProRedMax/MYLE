#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

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

    /// <summary>
    /// Swap 2 numbers
    /// </summary>
    /// <param name="a">Number 1</param>
    /// <param name="b">Number 2</param>
    void __swap(int& a, int& b);

    /// <summary>
    /// Get the Most Significant Digit
    /// </summary>
    /// <param name="i">Number</param>
    /// <returns>MSD</returns>
    int msd(int& i);

    /// <summary>
    /// Returns the amount of digits in a number
    /// </summary>
    /// <param name="i">Number</param>
    /// <returns>Amount</returns>
    int digits(int& i);

};
