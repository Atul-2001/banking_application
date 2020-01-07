#include "sources.h"

void transaction(void)
{
    time_t t;
    time(&t);    
    char accS[17] = "\0" , accR[17] = "\0" , data[512] = "\0" , temp[20] = "\0" , ht[200] = "\0";
    int balS = 0 , balR = 0 , statusR = 0 , statusS = 0 , CS = 0 , CR = 0 , transAmt = 0;
    char strS[34] = {"Account Number: "};
    char strR[34] = {"Account Number: "};
    char newBalS[100] = {"Balance:        "};
    FILE *fp;

    system("cls");
    logo();
    printf("\t\t\tMoney Transfer\n\n");

    while (1)
    {
        printf("Enter the Sender Account number: ");
        sprintf(accS,"%lld",inputDigit());

        if(strlen(accS) != 16)
        {
            printf("Please enter correct 16 digit account no.\n\n");
        }
        else
        {
            break;
        }
        /* code */
    }

    while (1)
    {
        printf("\nEnter the Receiver Account number: ");
        sprintf(accR,"%lld",inputDigit());

        if(strlen(accR) != 16)
        {
            printf("Please enter correct 16 digit account no.\n\n");
        }
        else
        {
            break;
        }
        /* code */
    }

    strcat(strS,accS);
    strcat(strS,"\n");

    strcat(strR,accR);
    strcat(strR,"\n");

    while(1)
    {
        fp = fopen("Account_holder_data.txt","r");

        if(fp == NULL)
        {
            perror("Unable to open file.\n");
        }
        else
        {
            break;
        }   
    }

    while(fgets(data,512,fp) != '\0')
    {
        ++CS;
        if(strcmp(data,strS) == 0)
        {
            ++statusS;
            balS = balance(CS);
            break;
        }
    }

    while (fgets(data,512,fp) != '\0')
    {
        ++CR;
        if(strcmp(data,strR) == 0)
        {
            ++statusR;
            fclose(fp);
            fp == NULL;
            balR = balance(CR);
            break;
        }
    }

    while (1)
    {
        if(statusS == 1)
        {
            break;
        }
        else
        {
            printf("\t\t\tFailed to find Sender Account! Please try again with correct account number...\n");
            while (1)
            {
                 printf("Enter the Sender Account number: ");
                 sprintf(accS,"%lld",inputDigit());

                 if(strlen(accS) != 16)
                 {
                     printf("Please enter correct 16 digit account no.\n\n");
                 }
                 else
                 {
                     break;
                 }
             }
           break;  
        }
    }
    

    while (1)
    {
         printf("\nEnter Amount to Transfer: ");
         transAmt = inputDigit();

         if(transAmt > balS)
         {
             printf("\n\t\tInsufficient Balance\n");
             printf("\t\tWould you like to try again. Press 'Enter' to continue or 'ESC' to return to Main Menu...");
             
             while (1)
             {
                 char ch = getch();

                 if(ch == 13)
                 {
                     printf("\n");
                     break;
                 }
                 else if(ch == 27)
                 {
                     Home_Screen();                         
                 }
             }
             
         }
         else
         {
             if(statusR == 0)
             {
                 sprintf(temp,"%f",balS-transAmt);
                 strcat(newBalS,temp);
                 strcat(newBalS,"\n");

                 char tA[20];
                 sprintf(tA,"%d",transAmt);

                 strcat(ht,ctime(&t));
                 strcat(ht,"                        "); 
                 strcat(ht,"Transaction:: From:- ");
                 strcat(ht,accS);
                 strcat(ht," To:- ");
                 strcat(ht,accR);
                 strcat(ht,"\n                          ");
                 strcat(ht,"Amount:- ");
                 strcat(ht,tA);

                 replace(CS+1,newBalS);
                 history(ht);

                 printf("\n\n\t\tTransaction Completed Successfully!");

                 printf("\n\nPress 'Enter' for next transaction or 'ESC' to return to Main Menu...");
                 while (1)
                 {
                     char op = getch();     /* code */

                     if(op == 13)
                     {
                         transaction();
                     }
                     else
                     {
                         Home_Screen();
                     }
                 }
             }
             else
             {
                 char newBalR[100] = {"Balance:        "} , temp2[20];

                 sprintf(temp,"%f",balS-transAmt);
                 strcat(newBalS,temp);
                 strcat(newBalS,"\n");

                 sprintf(temp2,"%f",balR+transAmt);
                 strcat(newBalR,temp2);
                 strcat(newBalR,"\n");                 

                 char tA[20];
                 sprintf(tA,"%d",transAmt);

                 strcat(ht,ctime(&t));
                 strcat(ht,"                        "); 
                 strcat(ht,"Transaction:: From:- ");
                 strcat(ht,accS);
                 strcat(ht," To:- ");
                 strcat(ht,accR);
                 strcat(ht,"\n                          ");
                 strcat(ht,"Amount:- ");
                 strcat(ht,tA);

                 replace(CS+1,newBalS);
                 replace(CR+1,newBalR);
                 history(ht);

                 printf("\n\n\t\tTransaction Completed Successfully!");

                 printf("\n\nPress 'Enter' for next transaction or 'ESC' to return to Main Menu...");
                 while (1)
                 {
                     char op = getch();     /* code */

                     if(op == 13)
                     {
                         transaction();
                     }
                     else
                     {
                         Home_Screen();
                     }
                 }                 
             }
         }
    }
}