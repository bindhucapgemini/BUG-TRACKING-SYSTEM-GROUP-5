//Definition file for Login and Registration

#include"login_header.h"

/*Function to accept details from user for login
parameter:No parameters
return-type: int */


int login(void)                                 //Existing user
{
        char temp[100];
        int flag=0,count=0;
        FILE *file;
        struct login log;
        char *token=NULL;
        printf("\n--------------------------------------LOGIN-----------------------------------------\n\n");

        printf("Please enter your login credentials below: \n");

        while(count<5 && flag==0)
        {
                printf("\n. UserId: ");
                scanf("%s",log.user_id);
                printf("\n.User_role: ");
                scanf("%s",log.user_role);
                strcpy(log.password,getpass("\n password: "));
                file = fopen("login.txt","r");
                if(file==NULL)
                {
                        printf("Error at opening File!\n");
                        exit(0);
                }

                while(fgets(temp,sizeof(temp),file))
                {
                        token=strtok(temp,",");
                        while(token!=NULL)
                        {
                                
                                if(strcmp(token,log.user_id)==0)
                                        flag = 1;
                                else
                                {
                                        count++;
                                        printf("UserID doesn't match");
                                }
                                token=strtok(NULL,"\n");
                                if(strcmp(token,log.password)==0)
                                        flag = 1;
                                else
                                {
                                        count++;
                                        printf("Password doesn't match");
                                        printf("\nPlease enter correct Details\n");
                                        flag = 0;
                                }
                                token=strtok(NULL,",");
                        }
                }
        }
        if(flag == 0)
                printf("\nLogin UnSuccessful\n\n");
        else
        {
                printf("\nLogin Successful\n\n");
                mainMenu();
        }
                fclose(file);
}

/*Function to accept details from user for registration
parameters: No parameters
return-type:void */

void registration(void)                                              //New User
{
        char *token=NULL;
        char temp[30];
                int ch, ret = 0;

        FILE *file;
        Emp e;
        file=fopen("login.txt","w");
        if(file==NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }
        printf("---------------------------------------REGISTER------------------------------------\n");

        printf("\nEnter Employeename::");
        scanf("%s",e.employeeName);

        printf("\nEnter Employee EmailId::");
        scanf("%s",e.employeeEmail);

        printf("\nEnter Employee ID::");
        scanf("%d",&e.employeeId);

        printf("\nEnter Employee mobile number::");
        scanf("%d",&e.employeeMobile_no);

        //fprintf(file,"%s,%s,%d,%d\n",e.employeeName,e.employeeEmail,e.employeeId,e.employeeMobile_no);

        printf("\nUsername should no more than 30 characters\n");


        printf("\n UserId: ");
        scanf("%s",e.log.user_id);


        printf("\nYour password should be atleast 8 characters where it should have 1 uppercase letter, 1 lowercase letter, a digit and a special character \n");

        printf("\n Password: ");
        scanf("%s",e.log.password);

        fprintf(file,"%s,%s\n",e.log.user_id,e.log.password);
        
        printf("\nSuccessfully Registered !! \n");

        printf("\nPress key to continue (1/0)...\n");
        scanf("%d",&ch);
        fclose(file);

        file=fopen("login.txt","r");
        if(file==NULL)
        {
                printf("Error at opening file!\n");
                exit(0);
        }
        while(fgets(temp,30,file)!=NULL)
        {
                printf("\nRecord:");
                token=strtok(temp,",");
                while(token!=NULL)
                {
                        printf("%s\t",token);
                        token=strtok(NULL,",");
                }
                printf("\n");
        }
        fclose(file);

        do
        {
                ret = login();
        }while(ret == 1);
}
