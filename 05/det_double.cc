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
    printf("%.25f\n", 10000 + 0.0001);
    return print(determinante(
        100, 0.01,
        -0.01, 100
    ));
}