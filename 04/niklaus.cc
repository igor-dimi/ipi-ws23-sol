#include "../code/fcpp.hh"

//helper functions abs, min and max to simplify syntax

//return absolute value of x
int abs(int x)
{
    return cond(x < 0, -x, x);
}

//returns minimum of i and j
int min(int i, int j)
{
    return cond(i > j, j, i);
}

// returns maximum of i and j
int max(int i, int j)
{
    return cond(i > j, i, j);
}


int kantenindex(int i, int j)
{
    return cond(
        i == j || abs(i - j) == 4 || (min(i, j) == 0 && max(i, j) == 3), 
        -1, //error code is -1
        cond(
            min(i, j) == 2 && max(i, j) == 3, 
            0, 
            i + j));
}


//0000 0100 & zzzz zzzz == 0000 0z00 
//somit i'te kante besucht <=> 2^i & z != 0
//wobei 2^i == 1 << i
bool kante_besucht(int kante, unsigned char zustand)
{
    return ((1 << kante) & zustand) != 0;
}

//0000 0100 | zzzz z0zz == zzz z1zz
//somit besuche i'te kante: z := z | 2^i
//wobei 2^i == 1 << i
unsigned char besuche_kante(int kante, unsigned char zustand)
{
    return zustand | (1 << kante);
}

int anzahl(int knoten, unsigned char zustand, int naechster)
{
    return 0;
}

int a(int v, unsigned char state, int vn)
{
    return 
    cond(vn > 4, 
        0, 
        cond(kantenindex(v, vn) != -1 && !(kante_besucht(kantenindex(v, vn), state)),
            1 + a(vn, besuche_kante(v, state), 0), 
            a(v, state, vn + 1))
    );
}

int main()
{
    int v, vn;
    unsigned char state;
    scanf("%d%hhu%d", &v, &state, &vn);
    printf("%d\n", a(v, state, vn));
    // int i, j;
    // scanf("%d%d", &i, &j);
    // printf("%d\n", kantenindex(i, j));

}