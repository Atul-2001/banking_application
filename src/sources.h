#ifndef sources_h_
#define sources_h_

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "operations.h"   // declarations of all the functions

#include "openAccount.c"   //definition of function openAccount
#include "AccEdit.c"       //definition of function AccEdit
#include "withdraw.c"      //definition of function withdraw
#include "deposit.c"       //definition of function deposit
#include "activity.c"      //definition of function activity
#include "transaction.c"          //definition of function loan


// function of remove extra spaces from between the string and before and after the string
char* remove_extra_space(char *str)
{
    char *p;
    int i = 0,j = 0;

    p=malloc(strlen(str)+1);

    while(*(str+i) != '\0')
    {
        while(*(str+i) == ' ')
        {
            i++;
        }
        while(*(str+i) != ' ' && *(str+i) != '\0')
        {
            *(p+j) = *(str+i);
             i++;
             j++;
        }

        if(*(str+i) == '\0' && *(p+j-1) == ' ')
        {
             j--;
        }

        *(p+j) = *(str+i);
        j++;
    }

    return p;
    free(p);
    p = NULL;
}

// function to input varaiable length string
char *inputString()
{
    char *p,*q,ch;
    int len=1,i;

    p=(char*)malloc(len);
    ch=getche();
    *p=ch;

    do
    {
       q=(char*)malloc(len+1);
       for(i=0;i<len;i++)
       {
           *(q+i)=*(p+i);
       }
       *(q+i)='\0';
       len++;
       free(p);

       p=(char*)malloc(len);
       for(i=0;i<len;i++)
       {
           *(p+i)=*(q+i);
       }
       free(q);
       ch=getche();
       *(p+len-1)=ch;

    }while(ch!=13);
     q=(char*)malloc(len);
     for(i=0;i<len;i++)
     {
       *(q+i)=*(p+i);
     }
     *(q+i-1)='\0';


    return p;
    free(p);
    free(q);
}

// Function to print detail of given account number.
void printRecord(int line_no)
{
    FILE *fp;
    char res[512];
    int count = 0;

    while(1)
    {
        fp = fopen("Account_holder_data.txt","r");

        if(fp == NULL)
        {
            perror("Unable to open File");
        }
        else
        {
            break;
        }
    }

    while(!(fgets(res,512,fp)) == '\0')
    {
        count++;

        if(count >= line_no && count <= line_no + 12 )
        {
            printf("%s",res);
            if(count == line_no + 12)
            {
                break;
            }
        }
    }

   fclose(fp);
   fp = NULL; 

}

//function to edit the record in the file
void replace(int pos, char *str)
{
    FILE *fp,*tFp;
    int count=0;
    char rec[512];

    while(1)
    {
         fp = fopen("Account_holder_data.txt","r");
         tFp = fopen("temp.tmp","w"); 

         if(fp == NULL && tFp == NULL)
         {
             perror("Unable to open file");
         }   
         else
         {
             break;
         }
    }

    while(!(fgets(rec,512,fp))=='\0')
    {
        count++;
        if(count == pos)
        {
            fputs(str,tFp);
        }
        else
        {
            fputs(rec,tFp);
        }
    }

    fclose(fp);
    fclose(tFp);

     remove("Account_holder_data.txt");
     rename("temp.tmp","Account_holder_data.txt");
    
}

//function to get the balance of any account
float balance(int location)
{
    FILE *fp;
    char res[512];
    int count = 0;
    char *bal;
    float balance = 0;

    while(1)
    {
        fp = fopen("Account_holder_data.txt","r");

        if(fp == NULL)
        {
            perror("Unable to open File");
        }
        else
        {
            break;
        }
    }

    while(!(fgets(res,512,fp)) == '\0')
    {
        count++;

        if(count == location + 1)
        {
            int len = strlen(res),n=0,i;
            bal = (char*)malloc(len-16);

            for( i = 0; i < len; i++ )
            {
                if(i >= 16 && i < len)
                {
                    *(bal+n) = res[i];
                    n++;
                }
            }

            balance = (float)atof(bal);
            free(bal);

            if(count == location + 1)
            {
                break;
            }
        }
    }

   fclose(fp);
   fp = NULL;
   bal = NULL; 

   return balance;
}

//function to store history
void history(char *h)
{
     FILE *fp;

     fp = fopen("Application_history.txt","a+");

     if(fp == NULL)
     {
         perror("Unable to create history!");
     }

        fputs("-------------------------------------------------------------------------------------\n",fp);
        fprintf(fp,"%s\n",h);
        fputs("-------------------------------------------------------------------------------------\n",fp);

        fclose(fp);
     
}

// function to input digit only
long long int inputDigit()
{
    long long int num = 0;
    int ch;

    do
    {
        fflush(stdin);
        ch = getch();
        if(ch >= 48 && ch <= 57)
        {
            printf("%c",ch);
            num = num*10+(ch-48);
        }

        if(ch == 8)
        {
            char c = '\0';
            printf("%c%c%c",ch,c,ch);
            if(num != 0)
            {
                num = num/10;
            }
        }

        if(ch == 13)
        {
            break;
        }
    }while(1);

    return num;
}

// function to input alphabetical string only
char* inputAlpha()
{
    static int count = 0;
    static char word[512] = "\0",ch[2] = "\0",c;
    strcpy(word,"\0");

    do
    {
        fflush(stdin);
        c = getch();
        ch[0] = c;
        ch[1] = '\0';
        if(c >= 'a' && c <= 'z')
        {
            ++count;
            printf("%c",c);
            strcat(word,ch);
        }

        if(c >= 'A' && c <= 'Z')
        {
            ++count;
            printf("%c",c);
            strcat(word,ch);
        }

        if(c == ' ')
        {
            if(count != 0)
            {
                if(word[count-1] != ' ')
                {
                     ++count;
                     printf("%c",c);
                     strcat(word,ch);
                }
            }
        }

        if(c == 8)
        {
            char n = 0;
            printf("%c%c%c",c,n,c);

            word[count-1] = '\0';
            --count;
        }

        if (c == 13)
        {
            if(word[count-1] == ' ')
            {
                word[count-1] = '\0';
            }
            break;
        }
    }while(1);

    return word;
}


#endif