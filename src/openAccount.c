#include "sources.h"

userDetail detail;

void openAccount(void)
{
    time_t t;
    time(&t);
    int ch;
    char ht[200] = "\0";
    FILE *fpS;
    system("cls");
    logo();
    printf("\t\t\tOpen a new Account\n\n");

    while (1)
    {
         printf("Account type (Saving/Current): ");
         //while ((getchar()) != '\n');
         strcpy(detail.acc_type,inputAlpha());

         if(strcmp(detail.acc_type,"Saving") == 0 || strcmp(detail.acc_type,"saving") == 0)
         {
             break;
         }
         else if(strcmp(detail.acc_type,"Current") == 0 || strcmp(detail.acc_type,"current") == 0)
         {
             break;
         }
         else
         {
             printf("\n\t\tPlease select valid account type (Saving / Current)...\n\n");
         }
         
    }
    
;

    while (1)
    {
         printf("\n\nAccount Number (16 digit): ");
         sprintf(detail.acc_no,"%lld",inputDigit());
         if(strlen(detail.acc_no)!=16)
         {
             printf("\n\t\tPlease input correct 16 digit account number !");
         } 
         else
         {
             char search[34] = {"Account Number: "},SD[126];
             strcat(search,detail.acc_no);
             strcat(search,"\n");
              
             while(1)
             {
                 fpS = fopen("Account_holder_data.txt","r");

                 if(fpS == NULL)
                 {
                     perror("\nUnable to open file.\n");
                 }
                 else
                 {
                     break;
                 }   
             }

             while(fgets(SD,126,fpS) != '\0')
             {
                 if(strcmp(SD,search) == 0)
                 {
                     fclose(fpS);
                     fpS = NULL;
                     printf("\n\t\t\tAccount already exist! Please try again...");
                     break;
                 }
             }
         }
         
         if(fpS != NULL)
         {
             fclose(fpS);
             fpS = NULL;
             break;
         }  /* code */
    }
    
    

    printf("\n\nName: ");
    strcpy(detail.name,inputAlpha());

    printf("\n\nFather name: ");
    strcpy(detail.f_name,inputAlpha());

    printf("\n\nMother name: ");
    strcpy(detail.m_name,inputAlpha());

    printf("\n\nAge: ");
    detail.age = inputDigit();

    printf("\n\nDate of Birth: ");
    fflush(stdin);
    gets(detail.dob);

    printf("\nCity: ");
    strcpy(detail.city,inputAlpha());

    printf("\n\nState: ");
    strcpy(detail.state,inputAlpha());

    printf("\n\nCountry: ");
    strcpy(detail.country,inputAlpha());

    while (1)
    {
         printf("\n\nMobile no: ");
         sprintf(detail.mobile,"%lld",inputDigit());
         if(strlen(detail.mobile)!=10)
         {
             printf("\n\t\tPlease enter correct 10 digit mobile number !");
         }
         else
         {
             break;
         }
             /* code */
    }
    
    strcat(ht,ctime(&t));
    strcat(ht,"                        "); 
    strcat(ht,"New Account Created: Acc_No:- ");
    strcat(ht,detail.acc_no);

    saveDetail();
    history(ht);

    printf("\n\n Account created successfully!!\n\n");
    while (1)
    {
        printf("Press 'Enter' to open new account or 'Escape (ESC)' to return to main menu: ");
        fflush(stdin);
        ch=getch();
    
        switch (ch)
        {
        case 27:
            Home_Screen();
            break;  
    
        case 13: 
            openAccount();  
            break;

        default:
            printf("\nPlease press correct key Escape or Enter\n"); 
            break;   
        }        /* code */
    }
    

    

}

void saveDetail(void)
{
    time_t t;
    time(&t);
    FILE *fp;

    while (1)
    {
         fp=fopen("Account_holder_data.txt","a+");

         if(fp==NULL)
         {
             perror("Failed to open file!");
         }
         else
         {
             break;
         }
            /* code */
    }
    
    
    fprintf(fp,"+-----------------------------------------------------------------+\n");
    fprintf(fp,"Date & Time:    %s\n",ctime(&t));
    fprintf(fp,"Account type:   %s\n",detail.acc_type);
    fprintf(fp,"Account Number: %s\n",detail.acc_no);
    fprintf(fp,"Balance:        0.0\n");
    fprintf(fp,"Name:           %s\n",detail.name);
    fprintf(fp,"Father Name:    %s\n",detail.f_name);
    fprintf(fp,"Mother Name:    %s\n",detail.m_name);
    fprintf(fp,"Age:            %d\n",detail.age);
    fprintf(fp,"Date of Birth:  %s\n",detail.dob);
    fprintf(fp,"City:           %s\n",detail.city);
    fprintf(fp,"State:          %s\n",detail.state);
    fprintf(fp,"Country:        %s\n",detail.country);
    fprintf(fp,"Branch:         %s\n",detail.city);
    fprintf(fp,"Mobile:         %s\n",detail.mobile);
    fprintf(fp,"+-----------------------------------------------------------------+");
    fprintf(fp,"\n\n");

    fclose(fp);

}