#include "../code/fcpp.hh"

int quadrat (int x)
{
  return x*x;
}

int potenz(int x, int n)
{
    return cond(n == 0, 
            1, 
            cond(n % 2 == 0, 
                quadrat(potenz(x, n / 2)), 
                x * potenz(x, n - 1)));
}


int main(int argc, char** argv)
{
    return print(potenz(
      readarg_int(argc, argv, 1), 
      readarg_int(argc, argv, 2)));
}