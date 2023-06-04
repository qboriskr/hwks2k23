//
// Created by boris on 03.06.2023.
//

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using ParsedIP = std::tuple<int, int, int, int>;

// Преобразует тип вектора с ip-адресом в тюпл; при ошибке бросит runtime_error
ParsedIP vector_to_tuple(std::vector<std::string> &ip_vec) noexcept(false);

// делит строчку по символу d на несколько частей и возвращает вектор с результатами
std::vector<std::string> split(const std::string &str, char d);


// печатает в cout IP адрес
template<std::size_t i>
struct Printer {
    static void print_ip_iter(const ParsedIP &ip) {
        std::cout << std::get<i>(ip);
        std::cout << ".";
        Printer<i + 1>::print_ip_iter(ip);
    }
};

template<>
struct Printer<3> {
    static void print_ip_iter(const ParsedIP &ip) {
        std::cout << std::get<3>(ip);
    }
};

template<std::size_t i>
int compare_byte(const ParsedIP &lhs, const ParsedIP &rhs) {
    auto l = std::get<i>(lhs);
    auto r = std::get<i>(rhs);
    if (l < r)
        return 1;
    if (l > r)
        return -1;
    return 0;
}

// компаратор, для обратной сортировки ip адресов
template<class T>
bool compare_lexic_reversed(const T &lhs, const T &rhs) {
    // оператор должен вернуть true, если l<cmp, false иначе
    int cmp;
    cmp = compare_byte<0>(lhs, rhs);
    if (cmp < 0) return true;
    if (cmp > 0) return false;
    cmp = compare_byte<1>(lhs, rhs);
    if (cmp < 0) return true;
    if (cmp > 0) return false;
    cmp = compare_byte<2>(lhs, rhs);
    if (cmp < 0) return true;
    if (cmp > 0) return false;
    cmp = compare_byte<3>(lhs, rhs);
    if (cmp < 0) return true;
    return false;
}

void print_ip_list(const std::vector<ParsedIP> &ip_list);
