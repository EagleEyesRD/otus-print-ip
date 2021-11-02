#pragma once
#include <sstream>
//#include <utility>
#include <iostream>
#include <vector>
#include <list>
//#include <tuple>
#include <string>
#include <type_traits>
//#include <typeinfo>
//#include <initializer_list>
//#include <typeindex>

template <typename T>
struct is_container {};

template <typename T>
struct is_container<std::vector<T>> {
    static constexpr bool value = true;
};

template <typename T>
struct is_container<std::list<T>> {
    static constexpr bool value = true;
};

template<typename T>
T calc_ip(T& sum, int i, bool startPrint) {
    T XOctet = static_cast<T>(std::pow(256, i));
    int part = static_cast<unsigned int>(sum / XOctet);
    if (part > 0) startPrint = true;
    sum -= part * XOctet;
    if (i == 0 && part < 256)
        return (part >= 0 ? part : 256 + part);
    else {
        std::cout << (startPrint ? std::to_string(part) + "." : "");
        calc_ip(sum, i - 1, startPrint);
    }
}

template<typename T, 
    typename = typename std::enable_if<std::is_integral<T>::value, T>::type>
void print_ip(T&& ip) {
    T sum = ip;
    if (ip > 0)
        std::cout << calc_ip(sum, 7, false);
    else
        std::cout << (ip >= 0 ? ip : 256 + ip);

    std::cout << std::endl;
};

void print_ip(std::string ip) {
    std::cout << ip << std::endl;
};

template <typename T,
typename = typename std::enable_if<is_container<T>::value, T>::type>
void print_ip(T ip) {
    std::stringstream ss;
    for (auto item_ptr = ip.cbegin(); item_ptr != ip.cend(); item_ptr++) {
        if (item_ptr != ip.cbegin())
            ss << ".";
        ss << *item_ptr;
    }
    std::cout << ss.str() << std::endl;
}
