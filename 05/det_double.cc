#include "../code/fcpp.hh"

double determinante(
    double a,
    double b,
    double c,
    double d
)
{
    return a * d - b * c;
}

int main()
{
    return print(determinante(
        100, 0.01,
        -0.01, 100
    ));
}