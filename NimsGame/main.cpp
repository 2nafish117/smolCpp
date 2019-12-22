#include <cstdio>

int main()
{
    int n = 25, playerInput, i, compInput, playGood = 1;
    printf("The rules of the game :\n**************************\n\n\n\n");
    printf("1. there are 25 dots on screen\n");
    printf("2.a play means picking out either 1 or 2 or 3 or 4 or 5 dots by a player\n");
    printf("3.the last player to play loses \n");
    printf("  ie the player to pick out the last dot loses\n");
    printf("4.the player starts first\n");
    printf("5.the player has to type in the number\n\n\n\n\n");

    do
    {
        if(playGood)
        {
            for(i = 0;i < n;i++)
            printf("o   ");
        }

        printf("\nenter your play!\n\n");
        playGood = 1;

        scanf("%d", &playerInput);
        /*
        switch(playerInput)
        {
        case 1:
            compInput = 5;
            n = n - 6;
            break;

        case 2:
            compInput = 4;
            n = n - 6;
            break;

        case 3:
            compInput = 3;
            n = n - 6;
            break;

        case 4:
            compInput = 2;
            n = n - 6;
            break;

        case 5:
            compInput = 1;
            n = n - 6;
            break;

        default:
            printf("foul play");
            playGood = 0;
            break;
        }
        */
        if(playerInput > 6 || playerInput <= 0)
        {
            playGood = 0;
            printf("foul play scum!!");
        }
        if(playGood == 1)
            n = n - 6;
        
        compInput = 6 - playerInput;


    } while(n > 1);

    printf("o\n\n");

    printf("you lose!!");

}
