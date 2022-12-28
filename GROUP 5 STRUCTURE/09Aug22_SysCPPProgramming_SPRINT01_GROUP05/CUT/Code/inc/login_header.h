//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


//declaration of macros used for making choices in the main menu
#define REGISTER 1
#define LOGIN 2

#define TRUE 1
#define FALSE 0


/*declaration of functions and structures for  login and registration */

struct login                            //declaring attributes for login
{
        char user_id[20];
        char password[20];
        char user_role[20];
};

typedef struct Employee
{
        char employeeName[20];          //declaring  attributes for registration
        char employeeEmail[20];
        int employeeId;
        int employeeMobile_no;
        struct login log;
}Emp;

void registration(void);
int login(void);
void choiceMain(void);
void mainMenu(void);
