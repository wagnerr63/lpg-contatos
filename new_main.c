#include <stdio.h>
#include <string.h>
// <---------------------------------------------->
// Entities
typedef struct
{
        int ID;
        char Name[60];
        char Email[80];
        char Phone[20];
} Contact;
// <---------------------------------------------->

// <---------------------------------------------->
// Repository
Contact Contacts[10];

void initMockRepository()
{
        Contacts[0].ID = 1;
        strcpy(Contacts[0].Name, "Wagner");
        strcpy(Contacts[0].Email, "wagner@mail.com");
        strcpy(Contacts[0].Phone, "47997922841");
}

// <---------------------------------------------->

int main()
{

        initMockRepository();

        // printf() displays the string inside quotation
        printf("%s", Contacts[0].Name);
        return 0;
}