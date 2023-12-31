#include <stdio.h>
#define N 10

int buffer [N];

int w = 0; //write index
int r = 0; //read index 

int use_size = 0; //count of the elements in buffer

int read()
{
    if (use_size == 0) //buffer empty, return error code -1
        return -1;
    int i = r; //i holds current read index 
    r = (r + 1) % N; //increment read index modulo N
    use_size--; //one less element in the buffer, decrement size
    int output = buffer[i];
    buffer[i] = 0; //0 value corresponds to an empty slots, i.e. deletion of an element
    return output;
}

void write (int item)
{
    if (use_size == N){ //buffer full, overwrite with warning. 
        printf("Warning: buffer full, overwriting oldest element!\n");
        buffer[w] = item;
        w = (w + 1) % N; //increment write index modulo N
        r = w; //when buffer full w == r is true
    } 
    else {
        buffer[w] = item;
        w = (w + 1) % N;
        use_size++;
    } 
}

void print_buffer()
{
    printf("buffer = [\n");
    for (int i = 0; i < N; i++){
        if (w != i && r != i) printf("  %d\n", buffer[i]);
        if (w != i && r == i) printf("< %d\n", buffer[i]);
        if (w == i && r != i) printf("> %d\n", buffer[i]);
        if (w == i && r == i) printf("><%d\n", buffer[i]);
    }
    printf("]\n\n");
};

int main()
{
    //initialize buffer
    for (int i = 0; i < N; i++) buffer[i] = 0; //since buffer contains only positive
                                               // set everything initially to 0 representing empty slots
    int i = 13497 % N; //or any other initial random index
    buffer[i] = 1; //set the slot in this index to 1, everything else is 0
    r = i; //initial read index 
    w = (i + 1) % N; //initial write index 
    use_size = 1; //initially one element in buffer

    int input; //menu option
    do {
        printf("input: ");
        scanf("%d", &input);
        if (input == -1) break;
        else if (input == 0){
            int item = read();
            if (item == -1) printf("buffer is empty\n");
            else {
                printf("\nout: %d\n", item);
                print_buffer();
            }
        } else if (input > 0){
                write(input);
                print_buffer();
        } else printf("invalid option!\n");
 
    } while (input != -1);
    return 0;
}