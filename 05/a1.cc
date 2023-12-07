#include <stdio.h>
#include "../code/fcpp.hh"



int g = 0;

int a_mod_b(int a, int b)
{
    int m = a % b;
    return m; //1
}

int gcd(int a, int b)
{
    g = g + 1;
    int Null = 0;
    if (b == Null) 
        return a;  //2
    else
        return gcd(b, a_mod_b(a, b));
}

int main()
{
    int a = 2;
    int b = 14;
    {
        int a = 7;
        int g = gcd(b, a);
        b = g;
    }
    a = g;
    print(a);
    return 0;  //3 
}