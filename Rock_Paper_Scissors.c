#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game ();

int main()
{   
    int restart;
    do
    {
        game ();
        printf("Do you still want to play? (1 for YES ; 0 for NO): \n");
        scanf("%d", &restart);
    } while (restart == 1);
        
    printf("Thanks for visiting ROCK-PAPER-SCISSORS!. Play again soon!");
    return 0;
}

void game ()
{
    char username[100];
        char game_start;
        printf("Ready to play Rock-Paper-Scissor? (Y/N): \n");
        scanf(" %c", &game_start);
    if (game_start == 'Y' || game_start == 'y')
    {
        printf("Input your name: \n");
        scanf(" %s", &username);
        printf("Welcome %s! \n", username);
        printf("The rules are simple: \n");
        printf("Rock = 0 \n");
        printf("Paper = 1 \n");
        printf("Scissor = 2 \n");

        srand(time(NULL));
        int randomValue = rand() % 3;

        int userValue;
        printf("Rock, Paper, Scissors! Which do you choose?: \n");
        scanf("%d", &userValue);
        printf("We choose %d \n", randomValue);

        if (userValue == randomValue)
        {
            printf("It's a  Tie \U0001FAE0 \n");
        }
        else if (userValue == 0 && randomValue == 1)
        {
            printf("We win! \U0001F601, You lose \U0001F606! \n");
        }
        else if (userValue == 1 && randomValue == 0)
        {
            printf("You win! \U0001F973 \n");
        }
        else if (userValue == 0 && randomValue == 2)
        {
            printf("You win! \U0001F973 \n");
        }
        else if (userValue == 2 && randomValue == 0)
        {
           printf("We win! \U0001F601, You lose \U0001F606! \n");
        }
        else if (userValue == 1 && randomValue == 2)
        {
            printf("We win! \U0001F601, You lose \U0001F606! \n");
        }
        else if (userValue == 2 && randomValue == 1)
        {
            printf("You win! \U0001F973 \n");
        } 
    }
        else 
        {
            printf("It's sad to see you leave the game \U0001F614 \n");
        }
}