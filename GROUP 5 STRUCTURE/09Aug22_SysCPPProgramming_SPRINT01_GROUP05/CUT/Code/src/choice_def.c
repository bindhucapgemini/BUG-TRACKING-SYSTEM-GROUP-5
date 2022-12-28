#include"login_header.h"
#include"project_header.h"
#include"ticket_header.h"
#include"report_header.h"


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
        switch(option)
        {
			                case 1:
                        printf("\nManage Projects \n");
                        manage_projects();
                        break;
                case 2:
                        printf("\nManage Tickets \n");
                        manage_tickets();
                        break;
                case 3:
                        printf("\nManage Reports \n");
                        manage_reports();
                        break;
                case 4:
                        printf("\n EXIT \n");
                        break;
                default:
                        printf("\nWrong option");
        }//end_switch
}

//function definition for displaying menu of manage projects
void manage_projects()
{

        char choice;
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

void manage_tickets()
{
        int n, i=1;
        int id = 0;                  //ID intialised to 0
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
                        case ADDTICKET :
                                         addticket();
                                         break;
                        case DISPLAYTICKET :
                                            displayticket();
                                            break;
				                        case FILEBUG :
                                         id++;
                                         filebug(id);
                                         break;
                        case CHANGESTATUS :
                                          changestatus();
                                          break;
                        case REPORT :
                                          report();
                                          break;
                        case CLOSETICKET :
                                          closeticket();
                                          break;
                        case EXIT :
                                         exit(0);
                                         break;
                        default :
                                printf("\ninvalid entry");
                                break;
                }
        }
}

void manage_reports()
{
    char *eid;

    printf("(i)Prioritize list of reports not closed\nii)Prioritize list of reports assigned to logged in employee\niii)Prioritize list of reports created by logged in employee \n iv)quit\n");
        int j ;
        scanf("%d",&j);
        switch(j){
            case 1 : openReports();
                     break;
            case 2 : assigned(eid);
                     break;
            case 3 : created(eid);
                     break;
            default : printf("Quitted");
	   }
}

