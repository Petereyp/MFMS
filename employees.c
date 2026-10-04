#include<stdio.h>
#include<string.h>
#include "employees.h"
#include "validation.h"

struct Employee employees[100];

int employeeCount = 0;
void addEmployee()
{
    printf("\n--Add Employee--\n");

   employees[employeeCount].employeeID = 
       getValidPositiveInteger("Enter Employee ID: ");
    
 do {
    printf("Enter Employee Name: ");
        fgets(employees[employeeCount].name, sizeof(employees[employeeCount].name), stdin);

        employees[employeeCount].name[strcspn(employees[employeeCount].name, "\n")] = '\0';

        if (strlen(employees[employeeCount].name) == 0)
        {
            printf("Invalid input. Name cannot be empty. Please try again.\n");
        }
    } while (strlen(employees[employeeCount].name) == 0);

 do 
  {
        printf("Enter Employee Department: ");
        fgets(employees[employeeCount].department, sizeof(employees[employeeCount].department), stdin);

        employees[employeeCount].department[strcspn(employees[employeeCount].department, "\n")] = '\0';

        if (strlen(employees[employeeCount].department) == 0)
        {
            printf("Invalid input. Department cannot be empty. Please try again.\n");
        }
    } while (strlen(employees[employeeCount].department) == 0);
    

   employees[employeeCount].basicSalary = 
       getValidPositiveNumber("Enter Basic Salary: ");

   employees[employeeCount].housingAllowance = 
       getValidPositiveNumber("Enter Housing Allowance: ");

    employees[employeeCount].transportAllowance = 
       getValidPositiveNumber("Enter Transport Allowance: ");

    employeeCount++;

    printf("\nEmployee added successfully\n");



} 

void displayEmployees()
{
    if (employeeCount == 0)
    {
        printf(" No employees registered");
        return;

    }
    printf("\n------Employee List------");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("Employee %d", i + 1);
        printf("ID: %d", employees[i].employeeID);
        printf("Name: %s", employees[i].name);
        printf("Department: %s", employees[i].department);
        printf("Basic Salary: %.2lf", employees[i].basicSalary);
        printf("Housing Allowance: %.2lf", employees[i].housingAllowance);
        printf("Transport Allowance: %.2lf", employees[i].transportAllowance);
        

    }


}
void searchEmployees()
{
    char searchName[50];
    int found = 0;
    printf("\nEnter employee name to search: ");
    fgets(searchName, sizeof(searchName), stdin);

    searchName[strcspn(searchName, "\n")] = '\0';

    for(int i = 0; i < employeeCount; i++)
    {
        if(strcmp(employees[i].name, searchName) ==0)
        {
            printf("\nEmployee Founf!\n");
            printf("ID: %d\n", employees[i].employeeID);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2lf\n", employees[i].basicSalary);
            printf("Housing Allowance: %.2lf\n", employees[i].housingAllowance);
            printf("Trabsport Allowance: %.2lf\n", employees[i].transportAllowance);

            found = 1;
            break;

        }
    }
    if(found == 0)
    {
        printf("\nEmployee not found\n");

    }
}

double calculateSalary(double basicSalary, double housingAllowance, double transportAllowance)
{
    double grossSalary;

    grossSalary = basicSalary
                + housingAllowance
                + transportAllowance;

    return grossSalary;

}
void employeeMenu()
{
    int choice;

    do
    {
        printf("\n--- Employee Management Menu ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");

        choice = getValidMenuChoice(1, 4);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployees();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;
        }

    } while (choice != 4);
}
