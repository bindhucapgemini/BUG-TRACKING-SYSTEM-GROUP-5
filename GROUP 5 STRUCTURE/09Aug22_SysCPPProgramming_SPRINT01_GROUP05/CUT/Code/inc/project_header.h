/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declaration of macros used for making choices in the manage projects
#define DESC 1
#define STARTDATE 2
#define ENDDATE 3
#define NUMBEROFEMPLOYEES 4
#define EXIT 0
#define ADD 'a'
#define DELETE 'd'
#define MODIFY 'm'
#define EXITT 'e'


/*declaration of functions and structures for manage projects */


struct p_date
{
        int day,month,year;
};

//structure declaration Project to store attributes
typedef struct Project
{
        char p_name[20],p_desc[50];
        int p_id,p_numberofemployees,p_employeeid;
        struct p_date start_date;
        struct p_date end_date;
        struct Project *next;

}pro;

void addProject(void);//To add details
void add_employee_to_project(int);
pro* createNode(); //To create newnode
pro* addNode(pro *, pro *); //To add newnode in linkedlist
void deleteProject(); //To delete project
void displayList(pro *);
void modifyProject(void); //To modify details
void updateNode();
void manage_projects(void);
