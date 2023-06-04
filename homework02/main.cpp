#include "ip_filter.h"


int main(int argc, char const *argv[]) {
    try {
        std::vector<ParsedIP> ip_pool;
        // цикл зачитывания входного файла (stdin)
        for (std::string line; std::getline(std::cin, line);) {
            // Столбцы выделяем по табуляции и пропускаем все значения кроме первого, то есть at(0).
            auto v = split(line, '\t');
            auto ip_vec = split(v.at(0), '.');
            auto ip = vector_to_tuple(ip_vec);
            ip_pool.push_back(ip);
            // Printer<0>::print_ip_iter(ip);
            // std::cout<<std::endl;
        }

        // reverse lexicographically sort
        //std::cout<<"Sorted:"<<std::endl;
        std::sort(ip_pool.begin(), ip_pool.end(), [](const auto &lhs,
                                                     const auto &rhs) {
            return compare_lexic_reversed(lhs, rhs);
        });
        print_ip_list(ip_pool);

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // filter by first byte and output
        std::vector<ParsedIP> ips;
        std::copy_if(ip_pool.begin(), ip_pool.end(),
                     std::back_inserter(ips), [](auto &ip) {
                    return std::get<0>(ip) == 1;
                });
        print_ip_list(ips);

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // filter by first and second bytes and output
        // ip = filter(46, 70)
        std::vector<ParsedIP> ips2;
        std::copy_if(ip_pool.begin(), ip_pool.end(),
                     std::back_inserter(ips2), [](auto &ip) {
                    return std::get<0>(ip) == 46 && std::get<1>(ip) == 70;
                });
        print_ip_list(ips2);

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // filter by any byte and output
        // ip = filter_any(46)
        std::vector<ParsedIP> ips3;
        std::copy_if(ip_pool.begin(), ip_pool.end(),
                     std::back_inserter(ips3), [](auto &ip) {
                    return std::get<0>(ip) == 46 || std::get<1>(ip) == 46 ||
                           std::get<2>(ip) == 46 || std::get<3>(ip) == 46;
                });
        print_ip_list(ips3);


        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
