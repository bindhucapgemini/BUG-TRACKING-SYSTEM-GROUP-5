//Definition file for Main Menu

//this file contains the function defination of the choices we will display in the main menu

#include"login_header.h"
#include"project_header.h"
#include"ticket_header.h"
#include"reports_header.h"


//function defination for displaying the main menu
void choiceMain() 
{
	int choice;

        printf("\nEnter the choice::\n1.Register\n2.Login\n");
        scanf("%d",&choice);


        if(choice ==1)
        {
                registration();
        }
        else if(choice ==2)
        {
                login();
        }
	mainMenu();

}

void mainMenu(void)
{
	int option;
	 			//step1::display menu
    	printf("\n---Menu---");
   	printf("\n1.One\
            \n2.Two\
            \n3.Three\
            \n4.Four");
            printf("\nEnter your option::"); //Step2:get option from user
            scanf("%d",&option);
    	switch(choice)
    	{
        	case 1:
            		printf("\nManage Projects \n");
			manageprojects();
            		break;
        	case 2:
            		printf("\nManage Tickets \n");
			managetickets();
            		break;
        	case 3:
            		printf("\nManage Reports \n");
			managereports();
            		break;
        	case 4:
            		printf("\n EXIT \n");
            		break;
    		default:
        		printf("\nWrong option");
    	}//end_switch
    	printf("\n\outside switch\n");
    	return 0;
}

//function definition for displaying menu of manage projects
void manageprojects()
{
	
        int choice;
        printf("\t---------MANAGE PROJECT-------");
        printf("\n'a': ADD PROJECT\
                \n'd': DELETE PROJECT\
                \n'm': MODIFY PROJECT\
                \n'e': QUIT");
        printf("\nEnter your choice: ");
        scanf("%s",&choice);

 

        switch(choice)
        {
                case ADD:
                        addProject();
                        break;
                case DELETE:
                        deleteProject();
                        break;
                case MODIFY:
                        modifyProject();
                        break;
                case EXIT:
                        printf("QUIT\n");
                default:
                        printf("Wrong choice");
        }
}

//function definition for displaying menu for manage tickets

void managetickets()
{
        int n, i=1;
        int id = 0;                  //ID intialised to 0
        printf("BUG TRACKING SYSTEM\n");
        while (1)
        {
 
                ("Enter choice\n");
                printf("1.ADDTICKET\n");
                printf("2.DISPLAYTICKET\n");
                printf("3.FILE A NEW BUG\n");
                printf("4.CHANGE THE STATUS OF THE BUG\n");
                printf("5.Get BUG REPORT\n");
                printf("6.Close Ticket\n");
                printf("0.EXIT\n");
                printf("ENTER YOUR CHOICE:\n");
                scanf("%d",&n);
                switch(n) {
                        case ADDTICKET:
                                addticket();
                                break;
                        case DISPLAYTICKET:
                                displayticket();
                                break;
                        case FILEBUG:
                                id++;
                                filebug(id);
                                break;
                        case CHANGESTATUS:
                                changestatus();
                                break;
                        case REPORT:
                                report();
                                break;
  			case CLOSETICKET:
                                closeticket();
                                break;
                        case EXIT:
                                exit(0);
                                break;
                        default:
                                printf("\ninvalid entry");
                                break;
                }
        }
}

void managereports()
{
	char *eid = "123456";
        printf("(i)Prioritize list of reports not closed\nii)Prioritize list of reports assigned to logged in employee\niii)Prioritize list of reports created by logged in employee \n iv)quit\n");
        int j;
        scanf("%d",&j);

 

        switch(j){

 

                case STATUS : openReports();
                         break;

 


                case ASSIGNED : assigned(eid);
                         break;

 


                case CREATED : created(eid);
                         break;

 


                default : printf("Quit");

 

        return 0;
        }
}

