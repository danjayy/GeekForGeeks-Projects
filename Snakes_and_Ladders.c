//Note that, in this game only Player 2 can loose a turn. Player 1 can't cuz he's the first to come in.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game ();

int main()
{
    printf("Welcome to Snakes and Ladders\n");
    printf("Note: This game is played by 2 people. Get a partner to play with. \n");
    int restart;
    do
    {
        game ();
        printf("Do you want to play again? (1 for YES ; 0 for NO): \n");
        scanf("%d", &restart);
    } while (restart == 1);
    printf("Thanks for visiting Snakes and Ladders. Come again soon!! \n");
    return 0;
}

void game ()
{
    int player1 = 0;
    int player2 = 0;
    
    do
    {
        char roll;
        printf("Roll the dice?(Y/N): \n");
        scanf(" %c", &roll);
        if (roll == 'Y' || roll == 'y')
        {
            srand(time(NULL));
            int dice1;
            int dice2;
            dice1 = rand() % 5 + 1;
            printf("Dice number is: %d \n", dice1);
            player1 += dice1;
            printf("Player 1 has %d points \n", player1);
            char roll2;
            printf("Roll the dice? (Y/N): \n");
            scanf(" %c", &roll2);
            if (roll2 == 'Y' || roll2 == 'y')
            {
              srand(time(NULL));
              dice2 = rand() % 5 + 1;
              printf("Dice number is: %d \n", dice2);
              player2 += dice2;
              printf("Player 2 has %d points \n", player2);
            }
            else
            {
                printf("If you still want to play, select Y. \n");
            }
        }

        else if (roll == 'N' || roll == 'n')
        {
            printf("Go get a partner and come back. See you soon to play!! \n");
        }
    
        else 
        {
            printf("Please enter either Y/N \n");
        }
        
    } while (player1 < 100 && player2 < 100);

    if (player1 == 100)
    {
        printf("Player 1 is the winner!!! \n");
    }
    else
    {
        printf("Player 2 is the winner!!! \n");
    }
         
}