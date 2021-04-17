#pragma once
#include <any>
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

template <typename T>
auto calc_ip(T ip) {
    std::vector<int> res;
    long long sum = (long long)ip;
    bool IsBeginIp = false;
    for (int i = 7; i > -1; i--) {
        long long XOctet = static_cast<long long>(std::pow(256, i));
        if (sum > XOctet || i == 0)
            IsBeginIp = true;

        if (IsBeginIp) {
            int part = static_cast<int>(sum / XOctet);
            sum -= part * XOctet;
            res.push_back(part);
        }
    }
    return res;
};

template <>
auto calc_ip(char ip) {
    std::vector<int> res;
    long long sum = (long long)ip;
    bool IsBeginIp = false;
    for (int i = 7; i > -1; i--) {
        long long XOctet = static_cast<long long>(std::pow(256, i));
        if (sum > XOctet || i == 0)
            IsBeginIp = true;

        if (IsBeginIp) {
            int part = static_cast<int>(sum / XOctet);
            sum -= part * XOctet;
            res.push_back(part);
        }
    }
    return res;
};

template <>
auto calc_ip(int ip) {
    std::vector<int> res;
    long long sum = (long long)ip;
    bool IsBeginIp = false;
    for (int i = 7; i > -1; i--) {
        long long XOctet = static_cast<long long>(std::pow(256, i));
        if (sum > XOctet || i == 0)
            IsBeginIp = true;

        if (IsBeginIp) {
            int part = static_cast<int>(sum / XOctet);
            sum -= part * XOctet;
            res.push_back(part);
        }
    }
    return res;
};

template <>
auto calc_ip(long long ip) {
    std::vector<int> res;
    long long sum = (long long)ip;
    bool IsBeginIp = false;
    for (int i = 7; i > -1; i--) {
        long long XOctet = static_cast<long long>(std::pow(256, i));
        if (sum > XOctet || i == 0)
            IsBeginIp = true;

        if (IsBeginIp) {
            int part = static_cast<int>(sum / XOctet);
            sum -= part * XOctet;
            res.push_back(part);
        }
    }
    return res;
};

template<typename ContainerType>
void print_ip(const ContainerType& t) {
    std::any x = t;
    if (std::is_fundamental<ContainerType>::value) {
        if (typeid(ContainerType).name() == typeid(long long).name()) {
            try
            {
                long long y = std::any_cast<long long>(x);
                std::cout << calc_ip<long long>(y);
            }
            catch (const std::bad_any_cast& e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        if (typeid(ContainerType).name() == typeid(char).name()) {
            char xxx = std::any_cast<char>(x);
            if (xxx < 0) {
                unsigned char xx = (unsigned char)(xxx);
                std::cout << (int)xx;
            }
        }

        if (typeid(ContainerType).name() == typeid(short).name())
            std::cout << t;

    }
    else
        std::cout << t;

    std::cout << std::endl;
};



