#include <stdio.h>
/*
You are participating in a game in which players collect points for various solved puzzles. 
In the end, the player with the highest score wins. You would like to know how far behind the highest-scoring 
person everyone else is in order to know whether you still have a chance at winning.

Please write a C program that uses a function "behind()" (which you also have to write) in order to help with this task.
Your program should first read, from the user input, the number of players participating in the game. 
There are never more than 10 players in the game. Next, your program should read the current scores of each player and store them 
in an array. Then you should call the function behind(), to which you pass as a first argument, the array holding the player's scores,
and as a second argument the number of players in the game. The function behind should replace the scores stored in the array with the 
number of points by which each individual player is behind the top-scoring player.

To help you out, the main function of the program has already been written, so your job is simply to write the function behind(),
 whose protype is also given to you.
*/

void behind(int scores[], int numPlayers) {
    int maxScore = scores[0];
    for(int i = 1; i < numPlayers; i++) {
        if(scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }
    for(int i = 0; i < numPlayers; i++) {
        scores[i] = maxScore - scores[i];
    }
}

int main() {
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    int scores[numPlayers];
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter the score of player %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
    behind(scores, numPlayers);
    printf("Number of points behind the top-scoring player:\n");
    for(int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
    return 0;
}