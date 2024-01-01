//how to insert a element from array in c?
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * numbers = malloc(6*sizeof(int));

    for(int ii = 0; ii < 6; ++ii) {
        numbers[ii] = 5;
    }

    numbers = realloc(numbers, 7*sizeof(*numbers));
    if(!numbers) {
        printf("Memory allocation failed, sorry dude!\n");
        exit(1);
    }

    numbers[6] = 7;

    for(int ii = 0; ii< 7; ++ii) {
        printf("%d\n", numbers[ii]);
    }

    free(numbers);
}




//Source: https://stackoverflow.com/questions/27736461






