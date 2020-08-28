#include <myle.h>

#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <random>

namespace MYLE {

    void Init()
    {
        std::srand(std::random_device()());
    }

    std::string rand_string(int length, const std::string& charSet)
    {
        std::string randomString(length, '0');
        int random;

        for (int i = 0; i < length; ++i)
        {
            randomString[i] = charSet[rand_int(0, charSet.size())];
        }

        return randomString;
    }

    std::string rand_string(int length)
    {
        std::string charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghhijklmnopqrstuvwxyz";
        return rand_string(length, charSet);
    }

    int rand_int(int from, int to, bool seed)
    {
        if(seed) std::srand(std::random_device()());

        return std::rand() % (to - from + 1) + from;
    }

    void fwrite_line(std::string& filepath, const std::string& content)
    {
        std::ofstream file;
        file.open(filepath);
        file << content;
        file.close();
    }

    void fwrite(std::string& filepath, std::vector<std::string>& content)
    {
        std::ofstream file;
        file.open(filepath);
        for (auto& line : content)
        {
            file << line;
        }
        file.close();
    }

    std::vector<std::string> fread(std::string& filepath)
    {
        std::string line;
        std::vector<std::string> output;
        std::ifstream file(filepath);
        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                output.push_back(line);
            }
        }
        return output;
    }

    std::string itobs(int& number)
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

    void replace_all(const int& from, const int& to, const char& toFind, const char& replaceWith, std::string& __string)
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

    int msd(int& i)
    {
        double K = std::log10(i);
        K -= std::floor(K);
        return std::pow(10, K);
    }

    int digits(int& i)
    {
        return std::floor(std::log10(i)) + 1;
    }

}
