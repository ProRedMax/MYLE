#pragma once

#include <string>
#include <vector>


namespace MYLE {

    ///
    /// \brief writeLineToFile Write a single string to a file fast
    /// \param path Path
    /// \param content std::String
    ///
    void writeLineToFile(std::string& path, const std::string& content);

    ///
    /// \brief writeToFile Write a std::vector<std::string> to a file fast
    /// \param path Path
    /// \param content std::vector<std::string>
    ///
    void writeToFile(std::string& path, std::vector<std::string>& content);

    ///
    /// \brief readFile read a std::vector<std::string> out of a file
    /// \param path Path
    /// \return std::vector<std::string>
    ///
    std::vector<std::string> readFile(std::string& path);

}
