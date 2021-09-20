// Alec Carson Fall 2021
// COP3402 HW 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// IR struct (obviously)
struct IR {
    long OP;
    long L;
    long M;
};

int main (int argc, char *argv[])   {
    // Initialize arrays and vars
    int GP;
    int IC = 0;
    int DP = 0;
    int FREE = 0;
    int BP = 0;
    int PC = 0;
    int SP = 0;
    int PAS[500] = {0};
    struct IR IRArray[150];

    // variable for holding string values obtained from file
    char buffer[10];
    // holds throwaway chars from string
    char *ptr;
    // holds token before transferring value
    char *token;

    // read the file from command line
    FILE *input = fopen(argv[1], "r");

    // check if file is empty before continuing
    if(input == NULL)
        return -1;

    // iterate over file, building IRArray as we go
    for(int i = 0; input != NULL; i++)  {
        printf("%d Loops\n", i);
        // get current line
        fgets(buffer, 10, input);

        // split line into separate string tokens, set OP = first token
        token = strtok(buffer, " ");
        IRArray[i].OP = strtol(token, &ptr, 10);

        printf("OP = %ld\n", IRArray[i].OP);

        // set rest of tokens to values
        token = strtok(NULL, " ");
        IRArray[i].L = strtol(token, &ptr, 10);

        printf("L = %ld\n", IRArray[i].L);

        token = strtok(NULL, "");
        IRArray[i].M = strtol(token, &ptr, 10);
        printf("M = %ld\n", IRArray[i].M);
    }

    
    return 0;
}