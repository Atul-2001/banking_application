#include "sources.h"
void activity(void)
{
    system("cls");
    logo();
    
    FILE *fp;
    char data[512];
    int count = 0;

    while(1)
    {
         fp = fopen("Application_history.txt","r");

         if(fp == NULL)
         {
             perror("Unable to show history.");
         }
         else
         {
             system("cls");
             logo();
             break;
         }
    }

     printf("\t\t\tApplication History\n");

     while(fgets(data,512,fp) != '\0')
     {
         ++count;
         printf("%s",data);
     }

     if(count == 3)
     {
         printf("\n\n\t\t\tNo histroy to show");
     }

    fclose(fp);
    getch();
}