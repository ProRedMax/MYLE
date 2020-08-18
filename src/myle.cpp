#include <myle.h>

#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <vector>

namespace MYLE {

    std::string randomString(int length, const std::string& charSet)
    {
        std::string randomString(length, '0');
        int random;

        for (int i = 0; i < length; ++i)
        {
            random = randomIntegerInRange(0, charSet.size());
            randomString[i] = charSet[random];
        }

        return randomString;
    }

    std::string randomString(int length)
    {
        std::string charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghhijklmnopqrstuvwxyz";
        return randomString(length, charSet);
    }

    int randomIntegerInRange(int from, int to)
    {
        srand(time(0));
        return rand() % (to - from + 1) + from;
    }

    void writeLineToFile(std::string& path, const std::string& content)
    {
        std::ofstream file;
        file.open(path);
        file << content;
        file.close();
    }

    void writeToFile(std::string& path, std::vector<std::string>& content)
    {
        std::ofstream file;
        file.open(path);
        for (auto& line : content)
        {
            file << line;
        }
        file.close();
    }

    std::vector<std::string> readFile(std::string& path)
    {
        std::string line;
        std::vector<std::string> output;
        std::ifstream file(path);
        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                output.push_back(line);
            }
        }
        return output;
    }

    std::string integerToBinaryString(int& number)
    {
        int num;
        std::string binary(32, ' ');
        for (int var = 31; var >= 0; --var)
        {
            if (number == 0)
            {
                break;
            }
            num = (number & 1);
            if (num == 0)
            {
                binary[var] = '0';
            }
            else
            {
                binary[var] = '1';
            }

            number = number >> 1;
        }
        return binary;
    }

    void replaceAll(const int& from, const int& to, const char& toFind, const char& replaceWith, std::string& __string)
    {
        for (int var = from; var < to; ++var)
        {
            if (__string[var] == toFind)
            {
                __string[var] = replaceWith;
            }
        }
    }

    void __swap(int& a, int& b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    int getMSD(int& i)
    {
        double K = std::log10(i);
        K -= std::floor(K);
        return std::pow(10, K);
    }

    int getDigits(int& i)
    {
        return std::floor(std::log10(i)) + 1;
    }

}