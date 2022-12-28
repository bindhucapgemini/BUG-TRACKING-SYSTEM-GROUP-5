#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>
#include <math.h>

//declaration of macros used for making choices in the manage tickets
#define FILEBUG 3
#define CHANGESTATUS 4
#define REPORT 5
#define EXIT 0
#define TRUE 1
#define FALSE 0
#define ADDTICKET 1
#define DISPLAYTICKET 2
#define CLOSETICKET 6


/*declaration of functions and structures for manage tickets */


struct report
{
        char bugname[50];
        char bugtype[50];
        char bugdescription[100];
        char bugpriority[30];
        int TicketID;
        int BugID;
        int ProjectID;
};

void filebug(int);           //function to file the bug in bugtracking system
void changestatus();         //function to change the status of bug
void report();               //function to report the bug in bugtracking system
int ticket_id_validation(int);
int project_id_validation(int);
int bug_id_validation(int);

//structure declaration ticket to store attributes


struct t_date
{
        int date,month,year;
};

typedef struct ticket        //declaring structure
{
         char emp_name[20];
        int project_id ,tkt_id;
        struct t_date start_date;
        struct t_date end_date;
        struct ticket *next;
}tkt;

void addticket(void);
void displayticket(void);
void closeticket(void);
void manage_tickets(void);

