// Alec Carson Fall 2021
// COP3402 HW 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int base(int L, int *PAS, int BP);

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
    int HALT = 1;
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
    for(int i = 0; HALT != 0; i++) {
        // fetch cycle
        IR = PAS[PC];
        PC += 3;

        // exec cycle
        if(IRArray[i].OP == 1)  {
            // if bp == gp then dp++, PAS(DP) = M
            if(BP == GP)    {
                DP++;
                PAS[DP] == IRArray[i].M;
            }
            // else sp --, PAS[SP] = m
            SP--;
            PAS[SP] == IRArray[i].M;

        }  
        // 02 OPR
        if(IRArray[i].OP == 2)  {
            // RTN
            if(IRArray[i].M == 0)  {
                SP == BP + 1;
                BP == PAS[SP - 2];
                PC == PAS[SP - 3];
            }

            // NEG
            if(IRArray[i].M == 1)  {
                if(BP == GP)
                    PAS[DP] == -1 * PAS[DP];

                else
                    PAS[SP] == -1 * PAS[SP]; 
            }

            // ADD
            if(IRArray[i].M == 2)  {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] += PAS[DP + 1]; 
                }

                else    {
                    SP++;
                    PAS[SP] += PAS[SP - 1]; 
                }
            }

            // SUB
            if(IRArray[i].M == 3)   {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] -= PAS[DP + 1]; 
                }
            }

            // MUL
            if(IRArray[i].M == 4)   {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] * PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[SP] = PAS[SP] * PAS[SP - 1];
                }
            } 

            // DIV
            if(IRArray[i].M == 5)   {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] / PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[SP] = PAS[SP] / PAS[DP - 1];
                }
            }

            // ODD
            if(IRArray[i].M == 6)   {
                if(BP == GP)
                    PAS[DP] == PAS[DP] % 2;

                else
                    PAS[SP] == PAS[SP] % 2;
            }

            // MOD
            if(IRArray[i].M == 7)   {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] % PAS[DP + 1];                   
                }

                else    {
                    SP++;
                    PAS[SP] == PAS[SP] % PAS[SP - 1];
                }
            }

            // EQL            
            if(IRArray[i].M == 8)   {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] == PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[SP] == PAS[SP] == PAS[SP - 1];
                }
            }

            // NEQ
            if(IRArray[i].M == 9)   {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] != PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[DP] == PAS[SP] != PAS[SP - 1];
                }
            }

            // LSS
            if(IRArray[i].M == 10)  {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] < PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[SP] == PAS[SP] < PAS[SP - 1];
                }
            }

            // LEQ
            if(IRArray[i].M == 11)  {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] <= PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[SP] == PAS[SP] <= PAS[SP - 1];
                }
            }
            
            // GTR
            if(IRArray[i].M == 12)  {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] > PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[SP] == PAS[SP] > PAS[SP - 1];
                }
            }
            
            // GEQ
            if(IRArray[i].M == 13)  {
                if(BP == GP)    {
                    DP--;
                    PAS[DP] == PAS[DP] >=  PAS[DP + 1];
                }

                else    {
                    SP++;
                    PAS[SP] == PAS[SP] >= PAS[SP - 1];
                }
            }

        }

        // LOD 
        if(IRArray[i].OP == 3)  {
            if(BP == GP)    {
                DP++;
                PAS[DP] == PAS[GP+IRArray[i].M];
            }

            if(base(IRArray[i].L, PAS, BP) == GP)    {
                SP--;
                PAS[SP] == PAS[GP + IRArray[i].M]; 
            }

            else    {
                SP--;
                PAS[SP] == PAS[base(IRArray[i].L, PAS, BP) - IRArray[i].M];
            }
        }

        // STO
        if(IRArray[i].OP == 4)  {
            if(BP == GP)    {
                PAS[GP + IRArray[i].M];
                DP--;
            }

            if(base(IRArray[i].L, PAS, BP) == GP)    {
                PAS[GP + IRArray[i].M] == PAS[SP];
                SP++;
            }

            else    {
                PAS[base(IRArray[i].L, PAS, BP) - IRArray[i].M] == PAS[SP];
                SP++;
            }
            
        }

        // CAL
        if(IRArray[i].OP == 5)  {
            PAS[SP - 1] == base(IRArray[i].L, PAS, BP);
            PAS[SP - 2] == BP;
            PAS[SP - 3] == PC;

            BP == SP - 1;
            PC == IRArray[i].M;
        }

        // INC
        if(IRArray[i].OP == 6)  {
            if(BP == GP)
                DP += IRArray[i].M;
            
            else
                SP -= IRArray[i].M;
        }

        // JMP
        if(IRArray[i].OP == 7)  {
            PC == IRArray[i].M;
        }

        // JPC
        if(IRArray[i].OP == 8)  {
            if(BP == GP && PAS[DP] == 0)    {
                    PC == IRArray[i].M;
                    DP--;
            }

             
                if(PAS[SP] == 0)    {
                    PC == IRArray[i].M;
                    SP++;
        }

        }

        //  SYS
        if(IRArray[i].OP == 9)  {
            
            // SYS 01 
            if(IRArray[i].M == 1)   {
                if(BP == GP)    {
                    printf("%d", PAS[DP]);
                    DP--;
                }

                else    {
                    printf("%d", PAS[SP]);
                    SP--;
                }
            }

            // SYS 02
            if(IRArray[i].M == 2)    {
                if(BP == GP)    {
                    DP++;
                    scanf("%d", PAS[DP]);
                }

                else    {
                    SP--;
                    scanf("%d", PAS[SP]);
                }
            }

        // SYS 03
        if(IRArray[i].M == 3)
            HALT == 0;

        }

    }

    
    return 0;
}

// Find base L levels down
int base(int L, int *PAS, int BP) {
    int arb = BP;
    
    while(L > 0)    {
        arb == PAS[arb];
        L--;
    }

    return arb;
}