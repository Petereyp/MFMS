#include<stdio.h>
#include<string.h>
#include "employees.h"

struct Employee employees[100];

int employeeCount = 0;
void addEmployee()
{
    printf("\n--Add Employee--\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].employeeID);
    
    getchar();

    printf("Enter Employee Name");
    fgets(employees[employeeCount].name,sizeof(employees[employeeCount].name),stdin);

    employees[employeeCount].name[strcspn(employees[employeeCount].name, "\n")] = '0\n';


    printf("Enter Department: ");
    fgets(employees[employeeCount].department,sizeof(employees[employeeCount].department),stdin);

    employees[employeeCount].department[strcspn(employees[employeeCount].department, "\n")] = '0\n';

    do
    {
    
        printf("Enter Basic Salary: ");
        scanf("%f", &employees[employeeCount].basicSalary);

    if (employees[employeeCount].basicSalary < 0)
    {
        printf("Salary cannot be negative. Try again. \n");
    }

    } while (employees[employeeCount].basicSalary < 0);

    do
    {
        printf("Enter Housing Allowance: ");
        scanf("%lf", &employees[employeeCount].housingAllowance);

        if (employees[employeeCount].housingAllowance < 0)
        {
            printf("Housing alllowance cannot be negative. Try again.\n");

        }
    } while (employees[employeeCount].housingAllowance < 0);

    do
    {
        printf("Enter Transport Allowance: ");
        scanf("%lf", &employees[employeeCount].transportAllowance);

        if (employees[employeeCount].transportAllowance < 0)
        {
            printf("Transport allowance cannot be negative. Try again.\n");

        }
    } while (employees[employeeCount].transportAllowance < 0);

    employeeCount++;

    printf("\nEmployee added successfully\n");



} 

void dislpayEmployees()
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
void searchEmployee()
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
