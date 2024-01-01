#include <stdio.h>
#include <string.h>

#define MAX_WORDS 68
#define MAX_WORD_LENGTH 40

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;// keeps track of the number of words read
    char c;
    while(numWords < MAX_WORDS && scanf("%s", words[numWords]) == 1) //reading the sentence
    {
        numWords++;
        c = getchar();
        if(c == '\n') {
            break;
        }
    }
    for(int i = numWords - 1; i >= 0; i--)//reversing the sentences loop.
    {
        printf("%s ", words[i]);
    }
    printf("\n");
    return 0;
}
