#include "../code/fcpp.hh"
#include <iostream>

int main()
{
    // int a[7] = {1, 2, 3, 4, 5, 6, 7};
    // int *b = &a[3] + 2;
    // int c = b[1];
    // std::cout << c << std::endl;
    int *a = new int[7];
    int b = a[0];
    int c = a[200];

    std::cout << b << " " << c << std::endl;
    *(char*)nullptr = 0;
}


