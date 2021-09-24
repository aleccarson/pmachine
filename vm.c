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
    int IR;
    int IC = 0;
    int DP = 0;
    int FREE = 0;
    int BP = 0;
    int PC = 0;
    int SP = 0;
    int halt = 1;
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
    for(int i = 0; !feof(input); i++)  {
        // get current line
        fgets(buffer, 10, input);

        // split line into separate string tokens, set OP = first token
        token = strtok(buffer, " ");
        IRArray[i].OP = strtol(token, &ptr, 10);

        // set rest of tokens to values
        token = strtok(NULL, " ");
        IRArray[i].L = strtol(token, &ptr, 10);

        token = strtok(NULL, "");
        IRArray[i].M = strtol(token, &ptr, 10);

        IC += 3;
    }
    
    // close input file when done
    fclose(input);

    // setup reg based on location of IC
    GP = IC;
    DP = IC - 1;
    FREE = IC + 10;
    BP = IC;
    PC = 0;
    SP = 500;
 
    // print column eaders to console as well as initial values
    printf("                PC  BP  SP  DP  DATA\n");
    printf("Initial Values: %d  %d  %d  %d\n", PC, BP, SP, DP);



    // runs until halt flag is reached
    for(int i = 0; halt != 0; i++) {
        // fetch cycle
        IR = PAS[PC];
        PC += 3;

        // exec cycle
        if(IRAarray[i].OP == 1)  {
            if(BP == GP)    {
                DP++;
                PAS[SP] == M;
            }

        }  
        if(IRAarray[i].OP == 2)  {
            // RTN
            if(IRAarray[i].M == 0)  {
                SP == BP + 1;
                BP == PAS[SP - 2];
                PC == PAS[SP -3];
            }

            // NEG
            if(IRAarray[i].M == 1)  {
                if(BP == GP)
                    PAS[DP] == -1 * PAS[DP];

                else
                    PAS[SP] == -1 * PAS[SP]; 
            }

            // ADD
            if(IRAarray[i].M == 2)  {
                if(BP == GP)    {
                    DP--;
                    PAS[DP]++;
                }
            }
            if(IRAarray[i].M == 3)
            if(IRAarray[i].M == 4)
            if(IRAarray[i].M == 5)
            if(IRAarray[i].M == 6)
            if(IRAarray[i].M == 7)
            if(IRAarray[i].M == 8)
            if(IRAarray[i].M == 9)
            if(IRAarray[i].M == 10)
            if(IRAarray[i].M == 11)
            if(IRAarray[i].M == 12)
            if(IRAarray[i].M == 13)  

        }
        if(IRAarray[i].OP == 3)  {

        }
        if(IRAarray[i].OP == 4)  {
            
        }
        if(IRAarray[i].OP == 5)  {

        }
        if(IRAarray[i].OP == 6)  {

        }
        if(IRAarray[i].OP == 7)  {

        }
        if(IRAarray[i].OP == 8)  {

        }
        if(IRAarray[i].OP == 9)  {

        }

    }

    
    return 0;
}