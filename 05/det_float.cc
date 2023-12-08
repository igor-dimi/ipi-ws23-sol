#include "../code/fcpp.hh"

float determinante(
    float a,
    float b,
    float c,
    float d
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