#include "../code/fcpp.hh"

//iterative Implementierung der Fakultaetsfunktion durch Tail-recursion 
// mit fakit und fak
int fakit(int res, int n)
{
    return cond(
        n > 1,
        fakit(res * n, n - 1),
        res
    );
}

int fak(int n)
{
    return fakit(1, n);
}

int binit(int n, int k)
{
    return fak(n) / (fak(k) * fak(n - k));
}

int main(int argc, char** argv)
{
    return print(binit(
        readarg_int(argc, argv, 1),
        readarg_int(argc, argv, 2)));
}