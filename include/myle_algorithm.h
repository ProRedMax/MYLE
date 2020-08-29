#pragma once

#include <string>

namespace MYLE {

    /// <summary>
    /// Generates an 1 digit checksum for the given number.
    /// </summary>
    /// <param name="number">Number to use</param>
    /// <returns>int checksum</returns>
    int luhn_checksum(std::string number);

    /// <summary>
    /// Whether or not the number passes the luhn algorithm
    /// </summary>
    /// <param name="number">Number in a string form</param>
    /// <returns>Passes luhn</returns>
    bool luhn(std::string number);

    std::string generate_luhn(int size);

}
