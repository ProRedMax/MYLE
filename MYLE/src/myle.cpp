#include <myle.h>

#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <random>
#include <iostream>

#include <map>
#include <stack>
#include <queue>

namespace MYLE
{
    void init()
    {
        srand(std::random_device()());
    }

    std::string rand_string(int length, const std::string& charSet)
    {
        std::string randomString(length, '0');

        for (int i = 0; i < length; ++i)
        {
            randomString[i] = charSet[rand_int(0, (int)charSet.size())];
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
        if (seed) std::srand(std::random_device()());

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

    void replace_all(const int& from, const int& to, const char& toFind, const char& replaceWith, std::string& string)
    {
        for (int var = from; var < to; ++var)
        {
            if (string[var] == toFind)
            {
                string[var] = replaceWith;
            }
        }
    }

    void mult_string(std::string& string, const int& n)
    {
        for (int i = 0; i < n; ++i)
        {
            string.append(string);
        }
    }

    void mult_string_s(std::string& string, const int& n)
    {
        for (int i = 0; i < n; ++i)
        {
            string.append(string);
            if (i != n - 1)
            {
                string.append(" ");
            }
        }
    }

    void swap(int& a, int& b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    int msd(int& i)
    {
        double K = std::log10(i);
        K -= std::floor(K);
        return (int)std::pow(10, K);
    }

    int digits(int& i)
    {
        return (int)std::floor(std::log10(i)) + 1;
    }


    int getLuhnSum(std::string number)
    {
        int offset = (number.size() % 2 == 0) ? 0 : 1;

        int temp, sum = 0;
        for (unsigned int i = 0; i < number.size(); i++)
        {
            temp = numeric_value(number[i]);
            if ((i + offset) % 2 == 1)
            {
                temp *= 2;
                if (temp > 9)
                {
                    temp -= 9;
                }
            }
            sum += temp;
        }
        return sum;
    }


    int luhn_checksum(std::string number)
    {
        int sum = getLuhnSum(number);
        if (sum % 10 == 0)
        {
            return 0;
        }

        return 10 - (sum % 10);
    }

    bool luhn(std::string number)
    {
        return (getLuhnSum(number.substr(0, number.size() - 1))
            + std::stoi(number.substr(number.size() - 1))) % 10 == 0;
    }

    std::string generate_luhn(int length)
    {
        int dindex = (length % 2 == 0) ? 0 : 1;

        std::string luhn(length, '0');

        int sum = 0;

        for (int i = 0; i < length; i++)
        {
            if (i == length - 1)
            {
                int rest = sum % 10;

                if (rest != 0) rest = 10 - rest;

                sum += rest;

                luhn[i] = rest + '0';

                break;
            }

            int temp = rand_int(0, 9);

            luhn[i] = temp + '0';

            if (i == dindex)
            {
                temp *= 2;

                if (temp > 9) temp -= 9;

                sum += temp;

                dindex += 2;

                continue;
            }

            sum += temp;
        }

        return luhn;
    }


    int numeric_value(char c)
    {
        return c - '0';
    }

    ECHARACTER_TYPE char_type_ascii(char c)
    {
        int char_value = static_cast<int>(c);

        if (char_value == 0)
        {
            return ECHARACTER_TYPE::NULL_CHARACTER;
        }
        if (char_value > 0 && char_value <= 31)
        {
            return ECHARACTER_TYPE::SYSTEM_DEFAULTS;
        }
        if (char_value == 32)
        {
            return ECHARACTER_TYPE::SPACE;
        }
        if (char_value > 32 && char_value <= 47)
        {
            return ECHARACTER_TYPE::SPECIAL_CHARACTERS;
        }
        if (char_value > 47 && char_value <= 57)
        {
            return ECHARACTER_TYPE::NUMBER;
        }
        if (char_value > 57 && char_value <= 64)
        {
            return ECHARACTER_TYPE::SPECIAL_CHARACTERS;
        }
        if (char_value > 64 && char_value <= 90)
        {
            return ECHARACTER_TYPE::UPPERCASE_LETTER;
        }
        if (char_value > 90 && char_value <= 96)
        {
            return ECHARACTER_TYPE::SPECIAL_CHARACTERS;
        }
        if (char_value > 96 && char_value <= 122)
        {
            return ECHARACTER_TYPE::LOWERCASE_LETTER;
        }
        if (char_value > 122 && char_value <= 126)
        {
            return ECHARACTER_TYPE::SPECIAL_CHARACTERS;
        }

        return ECHARACTER_TYPE::SYSTEM_DEFAULTS; //The 127th character is [DEL] so it is a SYSTEM_DEFAULT
    }

    void clamp(float& number, float min, float max)
    {
        if (number > max)
        {
            number = max;
        }
        else if (number < min)
        {
            number = min;
        }
    }

    
};
