#include "sources.h"

void deposit(void)
{
    FILE *fp;
    time_t t;
    time(&t);
    char ch[512] = "\0" , amt[20] = "\0" , acc_no[17] = "\0" , ht[200] = "\0 ";
    char str[34] = {"Account Number: "};
    char newValue[100] = {"Balance:        "};
    int count=0,depositAmt = 0;
    float bal = 0.0;
    system("cls");
    logo();
    printf("\t\t\tDeposit Money\n\n");

    while (1)
    {
        printf("Enter Account No: ");
        sprintf(acc_no,"%lld",inputDigit());

        if(strlen(acc_no) != 16)
        {
            printf("Please enter correct 16 digit account no.\n");
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

    strcat(str,acc_no);
    strcat(str,"\n");

    while (!(fgets(ch,512,fp)) == '\0')
    {
        count++;
        if(strcmp(ch,str) == 0)
        {
             fclose(fp);
             fp = NULL;
             printf("\n\n");
             printRecord(count-1);
             bal = balance(count);
            break;
        }
    }

    while (fp != NULL)
    {
        printf("\n\n\tNo account found. Please try again");
        printf("\nPress any key to retry....");
        getch();
        withdraw();/* code */
    }
    

    while (1)
    {
         printf("\n\nEnter the amount to deposit: ");
         depositAmt = inputDigit();

              bal = bal+depositAmt;
             sprintf(amt,"%f",bal);
             strcat(newValue,amt);
             strcat(newValue,"\n");

             char dA[20];
             sprintf(dA,"%d",depositAmt);

             strcat(ht,ctime(&t));
             strcat(ht,"                        "); 
             strcat(ht,dA);
             strcat(ht,"Rs. deposited to account: ");
             strcat(ht,acc_no);
  
             replace(count+1,newValue);
             history(ht);

             printf("\n\n\tAmount deposited Successfully!");
             printf("\n\tCurrent Balance = %f",bal);

             printf("\n\nPress 'Enter' to return to main menu...");
             getch();
             Home_Screen();
    }
}