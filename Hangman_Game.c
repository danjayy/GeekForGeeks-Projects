#include <stdio.h>
#include <string.h>

void game ();

int main()
{
    char username[100];
    printf("Let's play Hangman! What's your name?: \n");
    scanf(" %s", &username);
    printf("Hi %s. These are the rules: \n", username);
    printf("1. I'll provide you a word with missing letters \n");
    printf("2. Provide the right letters and the man lives \n");
    printf("3. Provide the wrong letters and you get two more tries \n");
    printf("4. Three strikes and he gets hanged. You kill him \n");
    int restart;
    do
    {
        game ();
        printf("Do you want to save another man doomed for death? (1 for YES ; 0 for NO): \n");
        scanf("%d", &restart);
    } while (restart == 1);
        
    printf("Thanks for visiting the HANGMAN GAME!. Come play again soon!");

    return 0;
}

void game () 
{
    char username[100];
    char game_start;
    printf("Ready to save the man set to die?(Y/N): \n");
    scanf(" %c", &game_start);
    if (game_start == 'Y' || game_start == 'y')
    {
      /*char FWORD1[] = "HELICOPTER";
       char FWORD2[] = "SHERATON";
       char FWORD3[] = "BALTIMORE";
       char PWORD1[] = "H_L_C_PTER";
       char PWORD2[] = "SHE__TON";
       char PWORD3[] = "_ALT_M_RE";
       */
       
       char UWORD1[4];
       char UWORD2[3];
       char UWORD3[4];
       printf("First try: H_L_C_PTER. What letters are missing?: \n");
       scanf(" %s", &UWORD1);
       if (strcmp(UWORD1, "EIO") == 0 || strcmp(UWORD1, "eio") == 0)
       {
            printf("Hazzah! You saved him! Good job %s \n", username);
       }
       else
       {
            printf("One strike. Let's try again. \n");
            printf("Second try: SHE__TON. What letters are missing? \n");
            scanf(" %s", &UWORD2);
            if (strcmp(UWORD2, "RA") == 0 || strcmp(UWORD2, "ra") == 0)
            {
                printf("Hazzah! You saved him! Good job %s \n", username);
            }
            else 
            {
                printf("Two strikes. Let's try again. \n");
                printf("Third try: _ALT_M_RE. What letters are missing? \n");
                scanf(" %s", &UWORD3);
                if (strcmp(UWORD3, "BIO") == 0 || strcmp(UWORD3, "bio") == 0)
                {
                    printf("Hazzah! You saved him! Good job %s \n", username);
                }
                else 
                {
                    printf("He'll be hanged to the death. You failed to save him :( \n");
                }
            }
            
       }

    }
    else
    {
        printf("It seems he'll be hanged to the death then... \n");
    }
    
}