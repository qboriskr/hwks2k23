#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "ip_filter.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

ParsedIP vector_to_tuple(std::vector<std::string> &ip_vec) noexcept(false) {
    if (ip_vec.size() != 4) {
        throw std::runtime_error("Unexpected IP format");
    }
    return {std::stoi(ip_vec.at(0)), std::stoi(ip_vec.at(1)),
            std::stoi(ip_vec.at(2)), std::stoi(ip_vec.at(3))};
}


void print_ip_list(const std::vector<ParsedIP> &ip_list) {
    for (auto iter = ip_list.cbegin(); iter != ip_list.cend(); ++iter) {
        ParsedIP ip = *iter;
        Printer<0>::print_ip_iter(ip);
        std::cout << std::endl;
    }
}
