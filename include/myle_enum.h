#pragma once
#include "myle_enum_entry.h"
#include <map>
#include <string>
#include <vector>

namespace MYLE
{
    class myle_enum
    {
    private:
        std::vector<enum_entry> enum_values;
        enum_entry null_entry = enum_entry("NULL");

    public:

        myle_enum(std::vector<std::string> values)
        {
            for (std::string element : values)
            {
                enum_values.emplace_back(element);
            }
        }

        enum_entry get(const std::string& entry)
        {
            std::vector<std::string> entries = getAllEntries();

            auto it = std::find(entries.begin(), entries.end(), entry);

            if (it != entries.end())
            {
                return *it;
            }
            return null_entry;
        }

        std::vector<std::string> getAllEntries()
        {
            std::vector<std::string> returnVector;
            for (enum_entry entry : enum_values)
            {
                returnVector.push_back(entry.getName());
            }
            return returnVector;
        }
    };
}
