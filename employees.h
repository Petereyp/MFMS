#ifndef EMPLOYEES_H
#define EMPLOYEES_H

struct Employee
{
    int employeeID;
    char name[50];
    char department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;

};

void addEmployee();
void displayEmployees();
void searchEmployees();
void employeeMenu();

double calculateSalary(double basicSalary, double housingAllowance, double transportAllowance);
int getValidPositiveInteger(const char prompt[]);
#endif