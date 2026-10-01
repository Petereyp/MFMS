#include <stdio.h>
#include <string.h>

 int main() {
    int SupplierID[65];
    char supplierName[100][70];
    char Email[100][70];
    char phone[100][35];
    char Town[100][30];
    int count=0;
    int choice;

    while(1) {
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search for Suppliers\n");
        printf("4. Compare Suppliers\n");
        printf("5. Exit\n");

          printf("Enter choice: ");
          scanf("%d",&choice);

          getchar();

             switch (choice){
                case 1:
                 printf("Enter Supplier ID: ");
                 scanf("%d",&SupplierID[count]);
                 getchar();

                 printf("Enter Supplier's name: ");
                 fgets(supplierName[count], sizeof(supplierName[count]), stdin);

                 printf("Enter email: ");
                 fgets(Email[count],sizeof(Email[count]), stdin);

                 printf("Enter phone: ");
                 fgets(phone[count], sizeof(phone[count]), stdin);

                 printf("Enter Town: ");
                 fgets(Town[count], sizeof(Town[count]),stdin);

                 count++;
                 break;

                case 2:
                for(int i=0; i<count; i++){
                    
                     printf("_____Supplier Details_____\n");
                     printf("Supplier ID: %d\n",SupplierID[i]);
                     printf("Supplier Name: %s\n",supplierName[i]);
                     printf("email: %s\n",Email[i]);
                     printf("Phone: %s\n",phone[i]);
                     printf("Town: %s\n",Town[i]);
                }
                case 3:
                 int SearchID;

                 printf("Enter Supplier's name to searh: ");
                 scanf("%d",&SearchID);

                 for(int i=0; i<count; i++){
                  if(SupplierID[i]==SearchID){
                     printf("____SUPPLIER DETAILS____\n");
                     printf("Supplier ID: %d\n",SupplierID[i]);
                     printf("Supplier's name: %s\n",supplierName[i]);
                     printf("Email: %s\n",Email[i]);
                     printf("Phone: %s\n",phone[i]);
                     printf("Town: %s",Town[i]);
                  }
                 }
                break;

                case 4:
                 int ID1, ID2;
                 printf("Enter First Supplier ID: ");
                 scanf("%d\n",&ID1);

                 printf("Enter Second Supplier ID: ");
                 scanf("%d",&ID2);

                 for(int i=0; i<count; i++){
                     if(SupplierID[i]==ID1 || SupplierID[i]==ID2){
                        
                         printf("_____SUPPLIER DETAILS_____\n");
                         printf("Supplier ID: %d\n",SupplierID[i]);
                         printf("Supplier's name: %s\n",supplierName[i]);
                         printf("Email: %s\n",Email[i]);
                         printf("Phone: %s\n",phone[i]);
                         printf("Town: %s\n",Town[i]);
                     }
                 }
                break;

                case 5:
                 return 0;

                default:
                   break;
             }
        }
return 0;
}        



   

      

