#include "utils.h"
//#include <cstdlib>



int main()
{
    print_ip(char{ -1 });
    print_ip(short{ 0 });
    print_ip(int{2130706433 });
    print_ip(long long{ 8875824491850138409});
    print_ip("Hello, World!");
    print_ip(std::vector<int>{ 100, 200, 300, 400 });
    print_ip(std::list<short>{ 400, 300, 200, 100 });
    print_ip(std::make_tuple(123, 456, 789, 0));
    
    return 0;
}

