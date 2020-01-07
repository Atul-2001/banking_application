
#include "sources.h"


int main(void)
{
    char ch;
   /* HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 1200, 600, TRUE); // 800 width, 100 height */

    SetConsoleTitle("Signature Bank Of India");    //Title of Screen

    logo();        //Print the welcome logo

    message();   //Print the Welcome message and note of features

    gotoxy(30,25);
    printf("Press Escape(esc) to exit or any other key to continue..... ");
        fflush(stdin);
         ch=getch();
         if(ch==27)    //27 Ascii code of esc key
         {
             exit(0);
         }
         else
         {
             Home_Screen();
         }    /* code */

    return 0;
}


void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void logo(void)
{
    int r=2,c=1;
    char ch[120];
    FILE *fp;

    fp = fopen("logo.txt","r");
    if(fp==NULL)
    {
        printf("File Not Found!");
        exit(1);
    }

    while(!(fgets(ch,120,fp))=='\0')
    {
        gotoxy(c,r);
        printf("%s",ch);
        r++;
    }

    printf("\n\n");
    gotoxy(42,15);
    printf("Welcome to Signature bank of India");
    printf("\n\n");

    fclose(fp);

}


void message(void)
{
    int r=18,c=2;
    char ch[120];
    FILE *fp;

    fp = fopen("message.txt","r");
    if(fp==NULL)
    {
        printf("File Not Found!");
        exit(1);
    }

    while(!(fgets(ch,120,fp))=='\0')
    {
        gotoxy(c,r);
        printf("%s",ch);
        r++;
    }

    printf("\n\n");

    fclose(fp);
}


void Home_Screen(void)
{
    int op;
    while (1)
    {
         system("cls");
         logo();
         gotoxy(28,18);
         printf("Service:\n\n");
         gotoxy(28,20);
         printf("1. Open Account\n");
         gotoxy(28,21);
         printf("2. Account Modification\n");
         gotoxy(28,22);
         printf("3. Withdraw\n");
         gotoxy(28,23);
         printf("4. Deposit\n");
         gotoxy(28,24);
         printf("5. Money Transfer\n");
         gotoxy(28,25);
         printf("6. History\n");
         gotoxy(28,26);
         printf("7. Exit\n\n");
         gotoxy(28,28);
         
         printf("Choose the task: ");
         fflush(stdin);
         scanf("%d",&op);

         switch (op)
         {
             case 1:
                 openAccount();
                 break;

             case 2:
                 AccEdit();
                 break;

             case 3:
                 withdraw();
                 break;

             case 4:
                 deposit();
                 break;

             case 5:
                 transaction();
                 break;

             case 6:
                 activity();
                 break;

             case 7:
                 exit(0);
                 break;                  
    
            default:
                 gotoxy(28,29);
                 printf("Choose a valid task!");
                 gotoxy(28,30);
                 printf("Press any key to reselect...");
                 getch();
                break;
         }/* code */
    }
}