#include "../code/fcpp.hh"

int binrek(int n, int k)
{
    return cond(k == 0 || k == n, 
            1,
            binrek(n - 1, k - 1) + binrek(n - 1, k));
}

int main(int argc, char** argv)
{
    return print(binrek(
        readarg_int(argc, argv, 1),
        readarg_int(argc, argv, 2)));
}