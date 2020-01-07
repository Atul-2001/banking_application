#ifndef operations_h_
#define operations_h_

typedef struct user_detail
{
   char acc_type[20];
   char acc_no[17]; 
   char name[200];
   char f_name[200];
   char m_name[200];
   int age;
   char dob[11];
   char city[20];
   char state[20];
   char country[20];
   char mobile[10];

} userDetail;

void gotoxy(int x,int y);
void logo(void);
void message(void);
void Home_Screen(void);
void openAccount(void);
void saveDetail(void);
void AccEdit(void);
void deposit(void);
void withdraw(void);
void transaction(void);
void activity(void);
char* remove_extra_space(char *str);
char *inputString();
void printRecord(int line_no);
void replace(int pos, char *str);
float balance(int location);
void history(char*);
long long int inputDigit();
char* inputAlpha();

#endif