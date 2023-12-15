#include <stdio.h>
#include <iostream>
#define N 52

int deck[N];

//we need this division operation to cover cases when n is odd
//because for odd n we want to get ceiling(n/2) and use it when copying arrays in the shuffle functions
//otherwise the indices don't quite work for odd cases the way we implement shuffle functions
int div2(int n)
{
    if (n & 1) return n/2 + 1;
    return n/2;
}

bool deck_check(int deck[], int n)
{
    for (int i = 0; i < n; i++){
        if(i != deck[i]) return false;
    }
    return true;
}

void out_shuffle(int deck[], int n)
{
    int temp[n];
    //write shuffled values to temp
    for (int i = 0; i < div2(n); i++) temp[2*i] = deck[i]; //even indices get upper half of deck
    for (int i = 0; i < div2(n); i++) temp[2*i + 1] = deck[div2(n) + i]; //odd indices get lower half of deck
    //write temp to deck
    for (int i = 0; i < n; i++) deck[i] = temp[i];
}

void in_shuffle(int deck[], int n)
{
    int temp[n];
    for (int i = 0; i < n/2; i++) temp[2*i + 1] = deck[i]; //odd indices get upper half of the deck
    for (int i = 0; i < div2(n); i++) temp[2*i] = deck[n/2 + i]; //odd indices get upper half of the deck
    for (int i = 0; i < n; i++) deck[i] = temp[i];
}

int main()
{
    //initialize deck for out-shuffling
    for (int i = 0; i < N; i++) deck[i] = i;

    out_shuffle(deck, N); //deck out-shuffled once
    int count = 1; //how many times have the deck been shuffled? 
    while (!deck_check(deck, N)){
        out_shuffle(deck, N);
        count++;
    }
    printf("how many times to repeat out-shuffle to get initial configuration? %d\n", count);


    //initialize deck for in-shuffling
    for (int i = 0; i < N; i++) deck[i] = i;

    in_shuffle(deck, N); //deck in-shuffled once
    count = 1; //how many times have the deck been shuffled? 
    while (!deck_check(deck, N)){
        in_shuffle(deck, N);
        count++;
    }
    printf("how many times to repeat in-shuffle to get initial configuration? %d\n", count);

    // some simple tests below, not relevant to the problem
    // for (int i = 0; i < N; i++) deck[i] = i;
    // for (int i = 0; i < N; i++) printf("%d %d\n", i, deck[i]);
    // printf("\n\n");
    // in_shuffle(deck, N);
    // for (int i = 0; i < N; i++) printf("%d %d\n", i, deck[i]);
    // printf("\n\n");

    return 0;
}