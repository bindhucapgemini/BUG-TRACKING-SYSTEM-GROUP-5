//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>
#include <math.h>

//declaration of macros used for making choices in the manage tickets
#define FILEBUG 1
#define CHANGESTATUS 2
#define REPORT 3
#define EXIT 0
#define TRUE 1
#define FALSE 0


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

 struct t_date
   {
     int day,month,year;
   };

//structure declaration ticket to store attributes
typedef struct ticket        //declaring structure
{
	 char emp_name[20];
        int project_id ,tkt_id;
        struct t_date start_date;
        struct t_date end_date;
}tkt;

void addticket(void);
void displayticket(void);
void closeticket(void);

