#include <stdio.h>
#include <string.h>
#include "budget.h"

void calculateBudget(Budget * budget){
    budget->remainingBudget = budget->allocatedBudget - budget->expenditure;
    budget->isExceeded = (budget->expenditure > budget->allocatedBudget) ? 1 : 0;

}
void addBudget(Budget budgets[], int *count){
    if (*count >= MAX_DEPARTMENTS){
        printf("\n[ERROR] Maximum department limit reached!\n");
        return;
    }
    Budget budget;
    printf("\n-- Add / Update Department budget --\n");
    getchar();
    fgets(budget.department, DEPARTMENT_NAME_LENGTH, stdin);
    budget.department[strcspn(budget.department, "\n")] = 0;
    
    printf("Enter allocated budget (N$): ");
    while (scanf("%lf", &budget.allocatedBudget) != 1 || budget.allocatedBudget < 0) {
        printf("[ERROR] Invalid input. Please enter a non-negative number for allocated budget: ");
        while (getchar() != '\n');
    }
    printf("Enter expenditure (N$): ");
    while (scanf("%lf", &budget.expenditure) != 1 || budget.expenditure < 0){
        printf("[ERROR] Invalid input. Please enter a non-negative number for expenditure: ");
        while (getchar() != '\n'); 
    }
    calculateBudget(&budget);
    budgets[*count] = budget;
    (*count)++;

    printf("\n[SUCCESS] Budget for department '%s' added successfully!\n", budget.department);

}
void displayBudgets(const Budget budgets[], int count){
    if (count == 0){
        printf("\n[ERROR] No budget data available.\n");
        return;
    }
    printf("\n========== BUDGET MANAGEMENT REPORT ==========\n");
    printf("%-20s %-15s %-15s %-15s %-10s\n", "Department", "Allocated Budget", "Expenditure", "Remaining Budget", "Exceeded");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++){
        printf("%-20s N$%-14.2f N$%-14.2f N$%-14.2f %-10s\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               budgets[i].remainingBudget,
               budgets[i].isExceeded ? "Yes" : "No");
    }
    
}
