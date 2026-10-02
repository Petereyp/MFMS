
#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 100

typedef struct {
    int SupplierID;
    char supplierName[70];
    char Email[70];
    char phone[35];
    char Town[30];
} Supplier;

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter Supplier ID: ");
    scanf("%d", &suppliers[*count].SupplierID);
    getchar();

    printf("Enter Supplier name: ");
    fgets(suppliers[*count].supplierName, 70, stdin);

    printf("Enter Email: ");
    fgets(suppliers[*count].Email, 70, stdin);

    printf("Enter Phone: ");
    fgets(suppliers[*count].phone, 35, stdin);

    printf("Enter Town: ");
    fgets(suppliers[*count].Town, 30, stdin);

    (*count)++;
}

void displaySuppliers(Supplier suppliers[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\n--- Supplier Details ---\n");
        printf("Supplier ID: %d\n", suppliers[i].SupplierID);
        printf("Name: %s", suppliers[i].supplierName);
        printf("Email: %s", suppliers[i].Email);
        printf("Phone: %s", suppliers[i].phone);
        printf("Town: %s", suppliers[i].Town);
    }
}

void searchSupplier(Supplier suppliers[], int count) {
    int searchID, found = 0;

    printf("Enter Supplier ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (suppliers[i].SupplierID == searchID) {
            printf("Supplier ID: %d\n", suppliers[i].SupplierID);
            printf("Name: %s", suppliers[i].supplierName);
            printf("Email: %s", suppliers[i].Email);
            printf("Phone: %s", suppliers[i].phone);
            printf("Town: %s", suppliers[i].Town);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Supplier not found.\n");
}

void compareSuppliers(Supplier suppliers[], int count) {
    int ID1, ID2;

    printf("Enter First Supplier ID: ");
    scanf("%d", &ID1);

    printf("Enter Second Supplier ID: ");
    scanf("%d", &ID2);

    for (int i = 0; i < count; i++) {
        if (suppliers[i].SupplierID == ID1 || suppliers[i].SupplierID == ID2) {
            printf("\nSupplier ID: %d\n", suppliers[i].SupplierID);
            printf("Name: %s", suppliers[i].supplierName);
            printf("Email: %s", suppliers[i].Email);
            printf("Phone: %s", suppliers[i].phone);
            printf("Town: %s", suppliers[i].Town);
        }
    }
}

#endif