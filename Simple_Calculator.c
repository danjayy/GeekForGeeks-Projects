#include <stdio.h>
#include <math.h>
#include <string.h>


int main()
{
    printf("-- YOUR CALCULATOR FOR SIMPLE ARITHMETIC OPERATIONS -- \n");
    
    printf("Basic symbols for operation (With double values): \n");
    printf("Addition: + \n");
    printf("Subtraction: - \n");
    printf("Multiplication: * \n");
    printf("Division: / \n");
    printf("Basic symbols for operation (With single value): \n");
    printf("Logarithm: Log() \n");
    printf("Square root: sqrt() \n");

    int numValue;
    printf("How many values does your expression have? (1 or 2): \n");
    scanf("%d", &numValue);
    if (numValue == 2)
    {
        int x;
        int y;
        char opr;
        int result; //result of operations with double values
        printf("Input expression: \n");
        scanf("%d %c %d", &x, &opr, &y);
        if (opr == '+')
        {
            result = x + y;
            printf("Result: %d \n", result);
        }
        else if (opr == '-')
        {
            result = x - y;
            printf("Result: %d \n", result);
        }
        else if (opr == '*')
        {
            result = x * y;
            printf("Result: %d \n", result);
        }
        else if (opr == '/')
        {
            result = x / y;
            printf("Result: %d \n", result);
        }
    }
    else if (numValue == 1)
    {
        int z = 0;
        char opr2[50];
        char cb; //Close bracket character
        double result; //result of operations with single values
        printf("Input expression: \n");
        scanf("%s%d%c", &opr2, &z, &cb);
        if (strcmp(opr2, "Log(") == 0 || strcmp(opr2, "log(") == 0)
        {
            result = log((double)z);
            printf("Result: %lf \n", result);
        }
        else if (strcmp(opr2, "sqrt(") == 0 || strcmp(opr2, "SQRT(") == 0)
        {
            result = sqrt((double)z);
            printf("Result: %lf \n", result);
        }
        else 
        {
            printf("Sorry, this expression is not supported \n");
        }
        
    }
    else 
    {
        printf("Please choose between 1 or 2. Restart calculator. \n");
    }
    

    return 0;
}