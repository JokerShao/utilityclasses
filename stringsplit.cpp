#include <regex>
#include <vector>
#include <string>
#include <iostream>


std::vector<std::string> str_split(const std::string& input, const std::string& regex) {
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

int main()
{
    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    auto split_result = str_split(s, delimiter);
    for (auto sub_str : split_result) {
        std::cout << sub_str << "\n";
    }

    return 0;
}

