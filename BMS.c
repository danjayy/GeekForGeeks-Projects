#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void NewAccountFile(char *accPurpose, char *accName, int pin, int acc_type, int deposit);
void OldAccountFile(int pin, int deposit);
void OldAccountFileW(int pin, int withdrawal);
struct UserAccount
{
    char account_name[200];
    int pin;
    int current;
    int savings;
};


int main()
{
    const int null_deposit = 0;
    struct UserAccount s1;
    struct UserAccount s2;
    printf("Welcome to the Ele bank app. \n");
    char signin;
    printf("Do you have an account?(Y/N):");
    scanf(" %c", &signin);
    if (signin == 'Y' || signin == 'y')
    {
                printf("What do you want to do? (Choose a number from the list below): \n");
                printf("1. Withdraw money\n");
                printf("2. Deposit money\n");
                printf("3. Check account balance\n");
                int trans;
                scanf("%d", &trans);
                if (trans == 1)
                {
                    printf("PIN: \n");
                    scanf("%d", &s2.pin);
                    int withdrawal;
                    char account_choice;
                    printf("Savings (S) or current (C)? \n");
                    scanf(" %c", &account_choice);
                    if (account_choice == 'S' || account_choice == 's')
                    {
                        printf("Withdrawal amount: \n");
                        scanf("%d", &withdrawal);
                        OldAccountFileW(s2.pin, withdrawal);
                    }
                    else if (account_choice == 'C' || account_choice == 'c')
                    {
                        printf("Withdrawal amount: \n");
                        scanf("%d", &withdrawal);
                        OldAccountFileW(s2.pin, withdrawal);
                    }
                    else {
                        printf("Please input a valid account choice. Log in again to continue. \n");
                    } 
                }
                else if (trans == 2)
                {
                    printf("PIN: \n");
                    scanf("%d", &s2.pin);
                    int deposit;
                    char account_choice;
                    printf("Savings (S) or current (C)? \n");
                    scanf(" %c", &account_choice);
                    if (account_choice == 'S' || account_choice == 's')
                    {
                        printf("Deposit amount: \n");
                        scanf("%d", &deposit);
                       OldAccountFile(s2.pin, deposit);
                    }
                    else if (account_choice == 'C' || account_choice == 'c')
                    {
                        printf("Deposit amount: \n");
                        scanf("%d", &deposit);
                        OldAccountFile(s2.pin, deposit);
                    }
                    else {
                        printf("Please input a valid account choice. Log in again to continue. \n");
                    }
                }
                else if (trans == 3)
                {
                    printf("PIN: \n");
                    scanf("%d", &s2.pin);
                    char account_choice;
                    printf("Savings (S) or current (C)? \n");
                    scanf(" %c", &account_choice);
                    if (account_choice == 'S' || account_choice == 's')
                    {
                        OldAccountFile(s2.pin, null_deposit);
                    }
                    else if (account_choice == 'C' || account_choice == 'c')
                    {
                        OldAccountFile(s2.pin, null_deposit);
                    }
                    else {
                        printf("Please input a valid account choice. Log in again to continue. \n");
                    } 
                }
                
                else
                {
                    printf("Please choose an option from the list. Log in again to continue. \n");
                }
    }
    else {
        printf("You're welcome to create an account with us! \n");
        char accPurpose;
        printf("Is your acount Business (B) or Personal (P)? \n");
        scanf(" %c", &accPurpose);
        char *accPurposeS;
        switch (accPurpose)
        {
        case 'b':
            accPurposeS = "Business";
            break;
        case 'B':
            accPurposeS = "Business";
            break;
        case 'p':
            accPurposeS = "Personal";
            break;
        case 'P':
            accPurposeS = "Personal";
            break;
        default:
            printf("Please input a valid account type (B or P)");
            exit(1);
            break;
        }
        printf("Input the name you would like for your account: \n");
        scanf("%s", &s1.account_name);
        printf("Set a four-digit pin for your account: \n");
        scanf("%d", &s1.pin);
        printf("Would you like to pay into your account now?(Y/N): \n");
        char pay;
        scanf(" %c", &pay);
        if (pay == 'Y' || pay == 'y')
        {
            int deposit;
            char account_choice;
            s1.savings = 0;
            s1.current = 0;
            printf("Savings (S) or current (C)? \n");
            scanf(" %c", &account_choice);
            if (account_choice == 'S' || account_choice == 's')
            {
                printf("Deposit amount: \n");
                scanf("%d", &deposit);
                s1.savings += deposit;
                printf("Your Savings account balance is now: %d \n", s1.savings);
                NewAccountFile(accPurposeS, s1.account_name, s1.pin, s1.savings, deposit);
            }
            else if (account_choice == 'C' || account_choice == 'c')
            {
                printf("Deposit amount: \n");
                scanf("%d", &deposit);
                s1.current += deposit;
                printf("Your Current account balance is now: %d \n", s1.current);
                NewAccountFile(accPurposeS, s1.account_name, s1.pin, s1.current, deposit);
            }
            else {
                printf("Please input a valid account choice. Log in again to continue. \n");
            }
        }
        else
        {
            printf("That's okay. When you get some cash, come bank with us! \n");
            NewAccountFile(accPurposeS, s1.account_name, s1.pin, s1.savings, null_deposit);
        }
        printf("Your account has been successfully created. \n");
    }
    
    printf("Thank you for choosing Ele bank. Do contact us if you have any enquiries at (+234) 83 8367 0312. \n");
    

    return 0;
}

void NewAccountFile(char *accPurpose, char *accName, int pin, int acc_type, int deposit)
{
    FILE *fptr;
    fptr = fopen("Account_details.txt", "w");
    if (fptr == 0)
    {
        printf("Could not save your account details. Please try again.");
        exit (1);
    }
    else 
    {
        fputs(accPurpose, fptr);
        fputs("\n", fptr);
        fputs(accName, fptr);
        fputs("\n", fptr);
        fprintf(fptr, "%d\n", pin);
        if (deposit != 0)
        {
            acc_type = acc_type + deposit;
            fprintf(fptr, "%d", acc_type);
        }
        else
        {
            fprintf(fptr, "%d", acc_type);
        }
        
    }
    fclose(fptr);
}

void OldAccountFile(int pin, int deposit)//For making deposit
{
    int acc_balance;
    FILE *fptr;
    fptr = fopen("Account_details.txt", "r");
    if (fptr == 0)
    {
        printf("Sorry, there was an error accessing your account. Please log in again.");
        exit(1);
    }
    else
    {
        int acc_pin;
        fscanf(fptr, "%*s\n%*s\n%d", &acc_pin);
        // printf("Pin: %d", acc_pin);
        if (pin == acc_pin)
        {
            char accdetail[100];
            printf("Account Purpose: %s", fgets(accdetail, sizeof(accdetail), fptr));
            printf("Account Name: %s\n", fgets(accdetail, sizeof(accdetail), fptr));
            fgets(accdetail, sizeof(accdetail), fptr);
            if (deposit != 0)
            {
                fgets(accdetail, sizeof(accdetail), fptr);
                acc_balance = atoi(accdetail);
                acc_balance = acc_balance + deposit;
                printf("Account Balance: %d\n", acc_balance);
            }
            else
            {
                fgets(accdetail, sizeof(accdetail), fptr);
                acc_balance = atoi(accdetail);
                printf("Account Balance: %d", acc_balance);
            }  
        }  
        else
        {
            printf("Incorrect pin.\n");
            exit(1);
        }
    }
    fclose(fptr);

    //Saving new account balance
    // FILE *fptr1;
    fptr = fopen("Account_details.txt", "a");
    if (fptr == 0)
    {
        printf("Sorry, there was an error displaying your updated account details. Please log in again.");
        exit(1);
    }
    else
    {
        fputs("Updated account balance: ", fptr);
        fprintf(fptr, "%d", acc_balance);
        char buffer[200];
        while (!feof(fptr))
        {
            fread(buffer, sizeof(buffer), 1, fptr);
            printf("%s", buffer);
        }
    }
    fclose(fptr);
}
void OldAccountFileW(int pin, int withdrawal)//For making withdrawal
{
    int acc_balance;
    FILE *fptr;
    fptr = fopen("Account_details.txt", "r");
    if (fptr == 0)
    {
        printf("Sorry, there was an error accessing your account. Please log in again.");
        exit(1);
    }
    else
    {
        int acc_pin;
        fscanf(fptr, "%*s\n%*s\n%d", &acc_pin);
        if (acc_pin == pin)
        {
            char accdetail[100];
            printf("Account Purpose: %s", fgets(accdetail, sizeof(accdetail), fptr));
            printf("Account Name: %s\n", fgets(accdetail, sizeof(accdetail), fptr));
            fgets(accdetail, sizeof(accdetail), fptr);
            if (withdrawal != 0)
            {
                fgets(accdetail, sizeof(accdetail), fptr);
                acc_balance = atoi(accdetail);
                acc_balance = acc_balance - withdrawal;
                printf("Account Balance: %d", acc_balance);
            }
            else
            {
                fgets(accdetail, sizeof(accdetail), fptr);
                acc_balance = atoi(accdetail);
                printf("Account Balance: %d", acc_balance);
            }  
        }  
        else
        {
            printf("Incorrect pin.\n");
        }
    }
    fclose(fptr);

    //Saving new account balance
    // FILE *fptr;
    fptr = fopen("Account_details.txt", "a");
    if (fptr == 0)
    {
        printf("Sorry, there was an error displaying your updated account details. Please log in again.");
        exit(1);
    }
    else
    {
        fputs("Updated account balance: ", fptr);
        fprintf(fptr, "%d", acc_balance);
        char buffer[200];
        while (!feof(fptr))
        {
            fread(buffer, sizeof(buffer), 1, fptr);
            printf("%s", buffer);
        }
    }
    fclose(fptr);
}