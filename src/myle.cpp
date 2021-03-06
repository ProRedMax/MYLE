#include <myle.h>

#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <random>
#include <iostream>

namespace MYLE {

    void Init()
    {
        srand(std::random_device()());
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
                if (temp > 9) {
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

    bool MYLE::luhn(std::string number)
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

    void clamp(float& number, float min, float max)
    {
        if (number > max)
        {
            number = max;
        } else if (number < min)
        {
            number = min;
        }
    }


    
};
