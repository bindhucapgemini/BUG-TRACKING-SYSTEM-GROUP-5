#include"project_header.h"
#include"ticket_header.h"
//Function header::
/*This function is used to accept project details from the user
parameter:No Parameters
return-type:void as it returns nothing
*/



void addProject(void)  //To add project
{
        int i;
        FILE *fp;
        pro p;
        printf("\t------------ADD PROJECT--------------");
        fp = fopen("project.txt","a");
        if(fp==NULL)
        {
                printf("\nFile not available");
                exit(0);
        }
        printf("\nEnter project name: ");
        scanf("%s",p.p_name);
        printf("\nEnter project id: ");
        scanf("%d",&p.p_id);
        printf("\nEnter project description: ");
        scanf("%s",p.p_desc);
        printf("\nEnter project start date dd/mm/yyyy: ");
        scanf("%d/%d/%d",&p.start_date.day ,&p.start_date.month ,&p.start_date.year);
        printf("\nEnter project end date dd/mm/yyyy: ");
        scanf("%d/%d/%d",&p.end_date.day ,&p.end_date.month ,&p.end_date.year);
        printf("\nEnter number of employees:");
        scanf("%d",&p.p_numberofemployees);
        fprintf(fp,"%s,%d,%s,%d/%d/%d,%d/%d/%d,%d",p.p_name,p.p_id,p.p_desc,p.start_date.day,p.start_date.month,p.start_date.year,p.end_date.day,p.end_date.month,p.end_date.year,p.p_numberofemployees);
        printf("\nDo you want to continue(0/1):");
        scanf("%d",&i);
        add_employee_to_project(p.p_id);
        fclose(fp);
	}


void add_employee_to_project( int project_id)
{
   int employee_id;
   int ch;
   FILE *fp;
   fp = fopen("emp_project.txt","a");
   do
   {
     printf("Enter emp_id for this project:");
     scanf("%d",&employee_id);
     fprintf(fp,"%d,%d",project_id,employee_id);
     printf("Do you want to add more employees to the project(0/1):");
     scanf("%d",&ch);
    }while(ch!=0);
   manage_projects();
}
//creating newnode for LinkList with data fetched from file in formal parameter n
pro* createNode()
{
  pro p;
  pro *newnode = (pro*)malloc(sizeof(p));
  newnode->p_id = p.p_id;
  newnode->next=NULL;
  return newnode;
}//end of createNode()
/*adding node in LL containing emp_details
paramters: *head pointing to 1st node of LL, *rear pointing to last node, *newnode containing new record fetched from file*/
pro* addNode( pro *head,pro *newnode)
{
        pro *q;

        q = head;
        while(q->next !=NULL)
        {
                q = q->next;
        }
        q = newnode;
	}
//display LL on screen
void displayList(pro *head)
{
    pro *temp=head;
    tkt r;
    if(temp==NULL)
         printf("\n\n\tLinked List is empty.......!!!!!");
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->p_employeeid);
            temp = temp->next;    //this will shift temp to next node
        }
    }
}
/*This function is used to delete the project
parameter:No Parameters
return-type:void as it returns nothing
*/
void deleteProject()
{
        FILE *fp;
        pro *temp = NULL;
        pro *tag = NULL;
        pro *head =NULL;
        pro *newnode = NULL;
        pro *rear = NULL;
        char data[50];   //string to read data from file
        char *token,*context=NULL;   //pointers for tokeninzing
        char token_list[1][10];     //array of strings to store tokens from one record
        int i=0;                    //for iteration in looping
        int tempproject_id;
        pro p;
        fp = fopen("ticket.txt","r");  //reads from a existing file
        if(fp == NULL) //file not existing then fopen returns NULL
        {
                printf("\nFile not available.......:");
                manage_projects();
		                manage_projects();
                exit(0);
        }
        //reading from file and adding all data in linked  list
        while( fgets(data,50,fp) != NULL)
        {
                i=0;
                data[strlen(data)-1] ='\0';
                printf("\nData fetched from file::%s  ",data);
                token=NULL;
                token = strtok_r(data,",",&context);
                while(token!=NULL)
                {
                        strcpy(token_list[i],token);
                        i++;
                        token = strtok_r(NULL,",",&context);
                }
                //store data in struct variable after tokenizing
                p.p_id = atoi(token_list[0]);
                //write data to LL
                newnode = createNode(p);
                addNode(head,newnode);
        }
        fclose(fp); //closing file to release resources allocated for the file
        printf("\n\tEnter the project id: ");//taking user enter data to delete a note
        scanf("%d",&tempproject_id);
        temp = head;
        tag = temp;
        if(temp == NULL)
        {
                printf("\n\n\tLinked list is empty.........!!!!!\n");
                exit(0);
        }
        else
        {
                while(temp != NULL)
                {
                        if(tempproject_id == temp->p_id) //comparing the user entered data with the existing projectid in file
				                        {
                                if(temp == head)
                                {
                                        head = temp->next;
                                        free(temp);
                                        break;
                                }
                                else
                                {
                                        tag -> next = temp -> next;   //connecting tag with temp's neighbour node
                                        free(temp);
                                        break;
                                }
                        }
                        else
                        {
                                tag = temp;
                                temp = temp->next;
                        }
                }
        }
        temp = head;
        if(temp == NULL)
        {
                printf("\n\n\tLinked list is empty.........!!!!!\n");
                exit(0);
        }
        else
        {
                while(temp != NULL)
                {
                        fprintf(fp,"%d",temp->p_id);
                        temp=temp->next;
                }
                printf("\t\tProject deleted successfully");
        }
        fclose(fp);  //closing file to release resources allocated for the file
        manage_projects();
}//end of deletenote()
/*This function is used to modify the project
parameter:No Parameters
return-type:void as it returns nothing
*/
void modifyProject(void)  //To modify project
{
        int ch,id,temp_numberofemployees;
        struct temp_date
        {
                int day,month,year;
        };
        struct temp_date new_start_date;
        struct temp_date new_end_date;
        char temp_desc[100];
        FILE *fp;
        pro p;
        pro *temp;
        fp = fopen("project.txt","r");
        if(fp ==NULL)
        {
                printf("\nFile not available.:");
                manage_projects();
                exit(0);
        }
        printf("\nEnter the project id to modify the details: ");
        scanf("%d",&id);
        while(temp != NULL)
        {
                if(temp->p_id==id)
                {
                        printf("\n----------Choose the option to be modified-----------\n");
                        printf("\n\t1.Update project description\
                        \n\t2.Update project start date\
                        \n\t3.Update project end date\
                        \n\t4.Update number of employees\
                        \n\t0.Exit\n");
                        printf("\nEnter your choice:");
                        scanf("%d",&ch);
                        switch(ch)
                        {
                        case DESC:
					                                printf("\nEnter the project description to be modified: ");
                                while(getchar()!='\n');
                                fgets(temp_desc,100,stdin);
                                temp_desc[strlen(temp_desc)-1]='\0';
                                strcpy(temp->p_desc,temp_desc);
                                break;
                        case STARTDATE:
                                printf("Change project start date:");
                                scanf("%d/%d/%d",&new_start_date.day,&new_start_date.month,&new_start_date.year);
                                temp->start_date.day = new_start_date.day;
                                temp->start_date.month = new_start_date.month;
                                temp->start_date.year = new_start_date.year;
                                break;
                        case ENDDATE:
                                printf("Change project end date:");
                                scanf("%d/%d/%d",&new_end_date.day,&new_end_date.month,&new_end_date.year);
                                temp->end_date.day = new_end_date.day;
                                temp->end_date.month = new_end_date.month;
                                temp->end_date.year = new_end_date.year;
                                break;
                        case NUMBEROFEMPLOYEES:
                                printf("Change number of employees:");
                                scanf("%d",&temp_numberofemployees);
                                temp->p_numberofemployees = temp_numberofemployees;
                                break;
                        case EXIT:
                                exit(0);
                        default:
                               printf("Invalid option");
                        }
                        break;
                }
                else
                  {
                        temp = temp->next;
                  }
        }

        if(temp == NULL)
                {
                printf("\nProject ID not found to modify\n");
                return;
        }
        updateNode();
}
/*This function is used to update the project details
parameter:No parameters
retrun-type:nothing
*/
void updateNode()
{
        FILE *fp;
        pro *newnode;
        fp = fopen("project.txt","w");
        while(newnode != NULL)
        {
                fprintf(fp,"%s,%d/%d/%d,%d/%d/%d,%d",newnode->p_desc,newnode->start_date.day,newnode->start_date.month,newnode->start_date.year,newnode->end_date.day,newnode->end_date.month,newnode->end_date.year,newnode->p_numberofemployees);
                newnode = newnode->next;
        }
        fclose(fp);
}




#include "ticket_header.h"
//function to add the ticket into the bug tracking system
void addticket(void)
{
        int projectid=0,ticketid=0,enddate=0,startdate=0;
        FILE *fptr;
        tkt t;
        //struct date start_date
        //struct date end_date;
        //printf("\t-----ADD TICKET------");
        fptr = fopen("ticket.txt","a");
        if(fptr==NULL)
        {
                printf("\nfile not available");
                exit(0);
        }
        system("clear");
        printf("\nEnter emp_name:");
        scanf("%s",t.emp_name);
        printf("\nEnter project_id:");
        scanf("%d",&t.project_id);
        if(project_id_validation(t.project_id)==1)
                projectid++;
        else
                printf("Incorrect project id\n");
        printf("\nEnter tkt_id:");
        scanf("%d",&t.tkt_id);
        if(ticket_id_validation(t.tkt_id)==1)
                ticketid++;
        else
                printf("Incorrect ticket id\n");
        printf("\nEnter tkt start_date(dd/mm/yyyy):");
        scanf("%d/%d/%d",&t.start_date.date,&t.start_date.month,&t.start_date.year);
        if(date_validation(t.start_date.date,t.start_date.month,t.start_date.year)==1)
                startdate++;
        else
                printf("Incorrect start date\n");
        printf("\nEnter tkt end_date(dd/mm/yyyy):");
        if(date_validation(t.end_date.date,t.end_date.month,t.end_date.year)==1)
                enddate++;
	        else
                printf("Incorrect end_date\n");
        //fprintf(fptr,"%s",t.emp_name);
        fprintf(fptr,"%s,%d,%d",t.emp_name,t.project_id,t.tkt_id);
        fprintf(fptr,"\n\n\n");
        fclose(fptr);
}
void displayticket(void)
{
        FILE *fptr;
        char display[100];
        fptr = fopen("ticket.txt", "r");
        while(fscanf(fptr, "%s",display)!= -1)
        {
                printf("%s",display);
        }
        fclose(fptr);
}

//function to file the bug into the bug tracking system
void filebug(int id)
{
        int bug=0;
        int j;
        scanf("%d", &j);
        struct report r;
        printf("Reporting a bug\n");
        time_t CurrentTime;
        time(&CurrentTime);
        FILE *fptr;

        fptr = fopen("ticket.txt","a");

        //BugID
        printf("Enter BugID\n");
        scanf("%d", &r.BugID);
        if(bug_id_validation(r.BugID)==1)
                bug++;
        else
                printf("Incorrect Bug ID");
	
        //Bug description
        printf("Enter description\n");
        while(getchar()!='\n');
        fgets(r.bugdescription,500,stdin);
        r.bugdescription[strlen(r.bugdescription)-1]='\0';
        //Bug name
        printf("Enter BugName\n");
        scanf("%s", r.bugname);
        //bug type
        printf("Enter bug type:\n");
        while(getchar()!='\n');
        fgets(r.bugtype,50,stdin);
        r.bugtype[strlen(r.bugtype)-1]='\0';
        //bug priority
        printf("Enter bug priority:\n");
        scanf("%s", r.bugpriority);

        //if(ticket==1 && bug==1 && project==1)

        fprintf(fptr, "%s,%s,%s,%s", r.bugdescription, r.bugname, r.bugtype, r.bugpriority);
        fprintf(fptr, "\n");
        //if ticketID cannot be found
        if (fptr == NULL)
               printf("Ticket not created!!!\n");
        fprintf(fptr, "\n");
        fprintf(fptr, "DATE AND TIME : %s",ctime(&CurrentTime));

        printf("\nStatus of bug:\n");
        printf("1. ASSIGNED\n");
        printf("2.IN PROCESS\n 3. FIXED\n");
        printf("4. SUBMITTED\n 5.QUALITY CHECK\n ENTER YOUR CHOICE:");

        //Date and time of bug creation
        fprintf(fptr, "DATE AND TIME:%s", ctime(&CurrentTime));
 //fprintf(ptr, "BUG STATUS:");

        //switching to the status of the bug
        switch (j) {
                case 1:
			                        fprintf(fptr, "ASSIGNED\n");
                        break;
                case 2:
                        fprintf(fptr, "IN PROCESS\n");
                        break;
                case 3:
                        fprintf(fptr, "FIXED\n");
                        break;
                case 4:
                        fprintf(fptr, "SUBMITTED\n");
                        break;
                case 5:
                        fprintf(fptr, "QUALITY CHECK\n");
                default:
                        printf("invalid choice\n");
                        break;
        }
        fclose(fptr);
}

//function to change the status of the bug
void changestatus()
{
        printf("Change status\n");
        struct report r;
        //Current time
        time_t CurrentTime;
        time(&CurrentTime);
        FILE *fptr;
        char bugname[50];
        printf("Enter bug name:\n");
        scanf("%s", r.bugname);
        while(getchar()!='\n');
  fgets(r.bugname,50,stdin);
        r.bugname[strlen(r.bugname)-1]='\0';
        fprintf(fptr, "Bug name:%s\n", r.bugname);
        //fprintf(ptr, "\n");
        //opening the bug in append mode
        fptr = fopen("ticket.txt", "a");
        printf("\n1.ASSIGNED\n");
	        printf("2.IN PROCESS\n 3.FIXED\n");
        printf("4.SUBMITTED\n 5.QUALITY CHECK\n ENTER YOUR CHOICE:");
        //CHANGE THE STATUS
        int k;
        scanf("%d", &k);
        fprintf(fptr, "\n");
        fprintf(fptr, "DATE AND TIME : %s",ctime(&CurrentTime));
        //changing the status
        switch (k) {
                case 1:
                        fprintf(fptr, "ASSIGNED\n");
                        break;
                case 2:
                        fprintf(fptr, "IN PROCESS\n");
                        break;
                case 3:
                        fprintf(fptr, "FIXED\n");
                        break;
                case 4:
                        fprintf(fptr, "SUBMITTED\n");
                        break;
                case 5:
                        fprintf(fptr, "QUALITY CHECK\n");
                        break;
                default:
                        printf("invalid choice\n");
                        break;
        }
        fclose(fptr);
}

//function to report the bug
void report()
{
        printf("REPORT");
        FILE *fptr;
        struct report r;
        char name[50];
        //asking bug name to report the bug of the file
        printf("Enter bug name:\n");
	        scanf("%s", r.bugname);
        fprintf(fptr, "Bugname:%s\n", r.bugname);
        fprintf(fptr, "\n");
        fptr = fopen("ticket.txt", "a");
        //fp = fopen(bugname, "r");
        char ch;
        ch = getc(fptr);
        //character of the file
        while (ch != EOF) {
                printf("%c", ch);
                ch = getc(fptr);
        }
        fclose(fptr);
}
void closeticket(void)
{
        int close;
        FILE *fptr;
        {
                fptr=fopen("ticket.txt","r");
                if(fptr == NULL)
                {
                        printf("BUG RESOLVED");
                }
                else
                        printf("CLOSE");
        }
        if(fptr != NULL)
        {
                printf("BUG NOT RESOLVED");
        }
 else
        {
                printf("NOT CLOSE");
        }
        exit(1);
}

#include"report_header.h"

void addnode(struct Node ** head_ref,int new_data)
{

        struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
        struct Node *last = *head_ref;
        new_node->data = new_data;
        new_node->next = NULL;
        if (*head_ref == NULL)
        {
                *head_ref = new_node;
                return;
        }
        while (last->next != NULL)
                last = last->next;
        last->next = new_node;
}

void openReports()
{
    struct Node **head = NULL;
    struct pro p;
    char *token = NULL;
    char temp[20];
    FILE *fptr;
    //reading formatted data from file::
    fptr = fopen("projects.txt","r");
    if(fptr==NULL)
    {
      printf("\nCannot open file");
          exit(0);
    }
    while( fgets(temp,sizeof(struct pro),fptr) != NULL)  //EOF=-1
   {

           token = strtok(p.report_desc,"status:"); //to fetch multiple token from same string
         while(token!=NULL)
         {
              token = strtok(NULL," ");
		               if(token == "Open" )
              {
                           addnode(head,p.report_id);
              }
         }
    }

   fclose(fptr);
}
void assigned(char* eid)
{
    struct pro p;
    struct Node **head = NULL;
    char *token = NULL;
    char temp[20];
    FILE *fptr;
    //reading formatted data from file::
    fptr = fopen("projects.txt","r");
    if(fptr==NULL)
    {
      printf("\nCannot open file");
          exit(0);
    }
    while( fgets(temp,sizeof(struct pro),fptr) != NULL)  //EOF=-1
   {

        token = strtok(p.report_desc,"ASSIGNED TO:"); //to fetch multiple token from same string
         while(token!=NULL)
         {
              token = strtok(NULL," ");
              if(token == eid )
              {
                 addnode(head,p.report_id);
	      }
         }
    }
   fclose(fptr);
}
void created(char* eid)
{
    struct pro p;
    struct Node **head = NULL;
    char *token = NULL;
    char temp[20];
    FILE *fptr;
    //reading formatted data from file::
    fptr = fopen("projects.txt","r");
    if(fptr==NULL)
    {
      printf("\nCannot open file");
          exit(0);
    }
    while( fgets(temp,sizeof(struct pro),fptr) != NULL)  //EOF=-1
   {

        token = strtok(p.report_desc,"CREATED BY:"); //to fetch multiple token from same string
         while(token!=NULL)
         {
              token = strtok(NULL," ");
              if(token == eid )
              {
                addnode(head,p.report_id);
              }
         }
    }
