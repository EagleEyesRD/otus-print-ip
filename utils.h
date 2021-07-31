#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <string>
#include <type_traits>
#include <typeinfo>


template<typename T>
std::ostream& operator <<(std::ostream& s, std::vector<T> vec) {
    for (auto const& elem : vec) { s << elem << "."; }
    return s;
};

template<typename T>
std::ostream& operator <<(std::ostream& s, std::list<T> list) {
    for (auto const& elem : list) { s << elem << "."; }
    return s;
};

std::ostream& operator <<(std::ostream& s, std::tuple<int, int, int, int> t) {
    s << std::get<0>(t) << "." << std::get<1>(t) << "." << std::get<2>(t) << "." << std::get<3>(t);
    return s;
};

template<typename T>
T calc_ip(T &sum, int i, bool startPrint) {
    T XOctet = static_cast<T>(std::pow(256, i));
    int part = static_cast<unsigned int>(sum / XOctet);
    if (part > 0) startPrint = true;
    sum -= part * XOctet;
    if (i == 0 && part < 256) 
        return (part >= 0 ? part : 256 + part);
    else {
        std::cout << (startPrint ? std::to_string(part) + "." : "");
        calc_ip(sum, i - 1,startPrint);
    }
}

template<typename T, typename = std::enable_if_t<std::is_fundamental<T>::value, T>>
void print_ip(const T &ip) {
    T sum = ip;
    if (ip > 0)
        std::cout << calc_ip(sum, 7, false);
    else
        std::cout << (ip >= 0 ? ip : 256 + ip);

    std::cout << std::endl;
};

template<typename T, typename = std::enable_if_t<!std::is_fundamental<T>::value, T>>
void print_ip(T&& ip) {
    std::cout << ip << std::endl;
}


