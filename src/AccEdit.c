#include "sources.h"

userDetail viewEdit;

void editRecord(int line_no);

void AccEdit(void)
{
    FILE *fp;
    char ch[512];
    char str[34] = {"Account Number: "};
    int count=0;
    system("cls");
    logo();
    printf("\t\t\tView or Edit Account Detail\n\n");

    while (1)
    {
        printf("Enter Account No: ");
        sprintf(viewEdit.acc_no,"%lld",inputDigit());

        if(strlen(viewEdit.acc_no) != 16)
        {
            printf("\nPlease enter correct 16 digit account no.\n\n");
        }
        else
        {
            break;
        }
        /* code */
    }

     while(1)
     {
         fp=fopen("Account_holder_data.txt","r");

         if(fp == NULL)
         {
             perror("Unable to access file\n");
         }
         else
         {
             break;
         }
     } 

    strcat(str,viewEdit.acc_no);
    strcat(str,"\n");

    while (!(fgets(ch,512,fp)) == '\0')
    {
        count++;
        if(strcmp(remove_extra_space(ch),str) == 0)
        {
             fclose(fp);
             fp = NULL;
             printf("\n\n");
            printRecord(count-1);
            editRecord(count);
            break;
        }
    }


    while (fp != NULL)
    {
        printf("\n\n\tNo account found. Please try again");
        printf("\nPress any key to retry....");
        getch();
        AccEdit();/* code */
    }
    
    getch();

}


void editRecord(int line_no)
{
    time_t t;
    time(&t);
    char ch,temp_data[100] = "\0" , ht[200] = "\0";
    printf("\n\n\t\tEdit Details of Customer....");
    printf("\n\nChange Name (Y/N): ");
    while(1)
    {
        fflush(stdin);
        ch = getche();

        if(ch == 'Y' || ch == 'y')
        {
            printf("\nEnter New Name: ");
            strcpy(viewEdit.name,inputAlpha());
            if(strcmp(viewEdit.name,"\0") == 0)
            {
                break;
            }
            else
            {
                strcpy(temp_data,"Name:           ");
                strcat(temp_data,viewEdit.name);
                strcat(temp_data,"\n");
                replace(line_no+2,temp_data);
            }
            break;
        }
        else if(ch == 'N' || ch == 'n')
        {
            break;
        }  
    }

    printf("\n\nChange Father Name (Y/N): ");
    while (1)
    {
        fflush(stdin);
        ch = getche();

        if(ch == 'Y' || ch == 'y')
        {
            printf("\nEnter Father Name: ");
            strcpy(viewEdit.f_name,inputAlpha());
            if(strcmp(viewEdit.f_name,"\0") == 0)
            {
                break;
            }
            else
            {
                strcpy(temp_data,"Father Name:    ");
                strcat(temp_data,viewEdit.f_name);
                strcat(temp_data,"\n");
                replace(line_no+3,temp_data);
            }
            break;
        }
        else if(ch == 'N' || ch =='n')
        {
            break;
        }
    }

    printf("\n\nChange Mother Name (Y/N): ");
    while (1)
    {
        fflush(stdin);
        ch = getche();

        if(ch == 'Y' || ch == 'y')
        {
            printf("\nEnter Mother Name: ");
            strcpy(viewEdit.m_name,inputAlpha());
            if(strcmp(viewEdit.m_name,"\0")==0)
            {
                break;
            }
            else
            {
                strcpy(temp_data,"Mother Name:    ");
                strcat(temp_data,viewEdit.m_name);
                strcat(temp_data,"\n");
                replace(line_no+4,temp_data);
            }
            break;
        }
        else if(ch == 'N' || ch == 'n')
        {
            break;
        }
    }

    printf("\n\nChange Date of Birth (Y/N): ");
    while (1)
    {
        fflush(stdin);
        ch = getche();

        if(ch == 'Y' || ch == 'y')
        {
            printf("\nEnter Date of Birth: ");
            gets(viewEdit.dob);
            if(strcmp(viewEdit.dob,"\0")==0)
            {
                break;
            }
            else
            {
                strcpy(temp_data,"Date of Birth:  ");
                strcat(temp_data,viewEdit.dob);
                strcat(temp_data,"\n");
                replace(line_no+6,temp_data);
            }
            break;
        }
        else if(ch == 'N' || ch == 'n')
        {
            break;
        }
    }

    printf("\n\nChange Mobile No (Y/N): ");
    while (1)
    {
        fflush(stdin);
        ch = getche();

        if(ch == 'Y' || ch == 'y')
        {
            printf("\nEnter New Mobile No: ");
            sprintf(viewEdit.mobile,"%lld",inputDigit());
            if(strcmp(viewEdit.mobile,"\0")==0)
            {
                break;
            }
            else
            {
                strcpy(temp_data,"Mobile:         ");
                strcat(temp_data,viewEdit.mobile);
                strcat(temp_data,"\n");
                replace(line_no+11,temp_data);
            }
            break;
        }
        else
        {
            break;
        }
    }

    strcat(ht,ctime(&t));
    strcat(ht,"                        "); 
    strcat(ht,"Account Detail Modified of Acc_no:- ");
    strcat(ht,viewEdit.acc_no);

    history(ht);

    printf("\n\nRecord Updated Successfully!!");
    printf("\nPress 'Escape (ESC)' to return to main menu....");
    while (1)
    {
        fflush(stdin);
        ch = getch();

        if(ch == 27)
        {  
            Home_Screen();
        }
    }     
}
