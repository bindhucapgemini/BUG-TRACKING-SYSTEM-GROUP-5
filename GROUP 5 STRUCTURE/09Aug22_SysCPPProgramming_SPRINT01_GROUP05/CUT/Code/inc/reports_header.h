//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//declaration of macros used for making choices in the manage reports
#define STATUS 1
#define ASSIGNED 2
#define CREATED 3

struct pro
{
        int report_id;
        char report_desc[100];
};

struct Node
{
        int data;
        struct Node *next;
};

void addnode(struct Node **,int);
void openReports();  //To open the list of reports
void assigned(char*); //To assign the list of reports
void created(char*);  //To create the list of reports
void manage_reports(void);
