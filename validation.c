#include <stdio.h>
#include "validation.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    
    }      
}

int getValidMenuChoice(int min, int max)
{
    int choice;

    while (1)
    {
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (choice < min || choice > max)
        {
            printf("Invalid choice. Please enter a number between %d and %d.\n",
                   min, max);
            continue;
        }

        return choice;
    }
}

double getValidPositiveNumber(const char prompt[])
{
    double value;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%lf", &value) != 1)
        {
            printf("Invalid input. Please enter a numerical value.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value < 0)
        {
            printf("Invalid value. Negative values are not allowed.\n");
            continue;
        }

        return value;
    }
}
int getValidPositiveInteger(const char prompt[])
{
    int value;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input. Please enter a numerical value.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value < 0)
        {
            printf("Invalid value. Negative values are not allowed.\n");
            continue;
        }

        return value;
    }
}