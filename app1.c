#include <stdio.h>
#include <stdlib.h>
#include "app1.h"
 
int main(void)
{
    char n;

    printf("\nPlease choose what would you like to do:");
    printf("\n\nPress 1 to print current database");
    printf("\nPress 2 to create new database");
    printf("\nPress 3 to add new record to current database");
    printf("\nPress 4 to edit current database");
    printf("\nPress ESC to close the program");

    do
    {
        printf("\n\nYour choice is: ");
        
        scanf(" %c", &n);

        switch(n)
        {
            case '1' : print_database();
            break;
            case '2' : create_database();
            break;
            case '3' : add_record();
            break;
            case '4' : edit();
            break;
            case 27 : exit(1);
            break;
            default : printf("\nInvalid option, choose again");
            break;
         }         
    }while(n!='1'&&n!='2'&&n!='3'&&n!='4'&&n!=27);

    return 0;
}