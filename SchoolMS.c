#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void enterDetails (char fname[15], char sname[15], char course[10], int rollnum);//Function to receive and store student data
void findWithFname(char fname[15]);//Function to find student data using first name
void findWithNumber(int rollnum);//Function to find student data using roll number
void getData (char course[10]);//Function to get details of students registered for each course


typedef struct std_details
{
    char course[10];
    char stdFname[15];
    char stdSname[15];
    int rollnum; 
}std_details;


int main()
{
    //Creating file to store student details with data headers. Use this code section if you do not have student details in file already.
    //After first run of the program, comment out this section so that inputted data in the file will not be overwritten
    FILE *fptr;
    fptr = fopen("StudentDetails.xls", "w");
    fprintf(fptr, "FIRST NAME\tSECOND NAME\tCOURSE\tRoll Number\n");
    fclose(fptr);
    //End of file creation

    printf("Welcome to Ele University portal\n");
    printf("What do you want to do? (Choose the number from the options below):\n");
    int choice;
    printf("1. Log my details\n");
    printf("2. Find my details\n");
    printf("3. Find my coursemates\n");
    printf("Option: ");
    scanf("%d", &choice);
    std_details s1;
    std_details s2;
    std_details s3;
    switch (choice)
    {
    case 1:
        printf("FIRST NAME (Should not be more than 10 letters): \n");
        scanf("%s", &s1.stdFname);
        printf("SURNAME (Should not be more than 10 letters): \n");
        scanf("%s", &s1.stdSname);
        printf("COURSE OF STUDY (Use the abbreviated form): \n");
        scanf("%s", &s1.course);
        printf("ROLL NUMBER: \n");
        scanf("%d", &s1.rollnum);
        enterDetails (s1.stdFname, s1.stdSname, s1.course, s1.rollnum);
        break;
    
    case 2:
        int search_type;
        printf("1. ROLL NUMBER \t 2. FIRST NAME \n");
        printf("How do you want to search for your details? (Choose an option above): ");
        scanf("%d", &search_type);
        if (search_type == 1)
        {
            printf("Input your Roll Number: ");
            scanf("%d", &s2.rollnum);
            findWithNumber(s2.rollnum);
        }
        else if (search_type == 2)
        {
            printf("Input your First name as used in your registration: ");
            scanf("%s", &s2.stdFname);
            findWithFname(s2.stdFname);
        }
        else
        {
            printf("Please choose a search method from the options above");
        }
        break;
    
    case 3:
        const int key = 1021;
        int user_key;
        printf("Input the pass key to access this function: ");
        scanf("%d", &user_key);
        if (user_key == key)
        {
            printf("Which course student data do you need? (Use the course abbreviation): ");
            scanf("%s", s3.course);
            getData (s3.course);
        }
        else
        {
            printf("Incorrect pass key. You do not have access to this function");
        }
        
        break;
    default:
        printf("Please choose one of the options (1, 2, or 3). Thank you.\n");
        break;
    }
    

    return 0;
}


void enterDetails (char fname[15], char sname[15], char course[10], int rollnum)//Function to receive and store student data
{
    FILE *fptr;
    fptr = fopen("StudentDetails.xls", "a");
    if (fptr != NULL)
    {
        fprintf(fptr, "%s\t%s\t%s\t%d\n", fname, sname, course, rollnum);
        printf("You have been registered successfully");
    }
    else
    {
        printf("Your details could not be added to the database. Reload the application and try again.");
    }
    fclose(fptr);
}

void findWithFname(char fname[15]) // Function to find student data using first name
{
    char col1[15], col2[15], col3[10];
    char col4[10];
    FILE *fptr;
    fptr = fopen("StudentDetails.xls", "r");
    if (fptr != NULL)
    {
        char ch;
        while (ch = fscanf(fptr, "%s\t%s\t%s\t%s", col1, col2, col3, col4))
        {
            if (ch == EOF)
            {
                break;
            }
            if (strcmp(fname, col1) == 0)
            {
                printf("Your details:\n"
                        "%s\t%s\t%s\t%s\n", col1, col2, col3, col4);
                break;
            }
            else
            {
                printf("Loading data...\n");
            }
        }
    }
    else 
    {
        printf("The database could not be accessed. Please try again later.\n");
    }

    printf("\n*NOTE*:\n");
    printf("If your details were not displayed, this means you have not registered yet. Please do so by reloading the app and choosing the first option. Thank You\n");
    fclose(fptr);
}

void findWithNumber(int rollnum)//Function to find student data using roll number
{
    char col1[15], col2[15], col3[10];
    char col4[10];
    FILE *fptr;
    fptr = fopen("StudentDetails.xls", "r");
    if (fptr != NULL)
    {
        char ch;
        while (ch = fscanf(fptr, "%s\t%s\t%s\t%s", col1, col2, col3, col4))
        {
            if (ch == EOF)
            {
                break;
            }
            if (rollnum == atoi(col4))
            {
                printf("Your details:\n"
                        "%s\t%s\t%s\t%s\n", col1, col2, col3, col4);
                break;
            }
            else
            {
                printf("Loading data...\n");
            } 
        }
    }
    else 
    {
        printf("The database could not be accessed. Please try again later.\n");
    }

    printf("\n*NOTE*:\n");
    printf("If your details were not displayed, this means you have not registered yet. Please do so by reloading the app and choosing the first option. Thank You\n");
    fclose(fptr);
}

void getData (char course[10])//Function to get details of students registered for each course
{
    char col1[15], col2[15], col3[10];
    char col4[10];
    FILE *fptr;
    fptr = fopen("StudentDetails.xls", "r");
    if (fptr != NULL)
    {
        int ch;
        while (ch = fscanf(fptr, "%s\t%s\t%s\t%s", col1, col2, col3, col4))
        {
            if (ch == EOF)
            {
               break;
            }  
            if (strcmp(course, col3) == 0)
            {
                printf("%s\t%s\t%s\t%s\n", col1, col2, col3, col4);
            }
            else
            {
                printf("Loading data...\n");
            }
        }
    }
    else 
    {
        printf("The database could not be accessed. Please try again later.\n");
    }

    printf("\n*NOTE*:\n");
    printf("If the details of students in the course were not displayed, this means they have either not registered yet, \nor the course in not offered in the university. Please check the course name spelling, or inform students to register. Thank You\n");
    fclose(fptr);
}