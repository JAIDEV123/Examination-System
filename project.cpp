//Examination System
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<Windows.h>
const int USERS=10;
const int S=50;

struct account
{
	char username[15];
   char password[25];
};

struct subject
{
	char name[25];
	double theo;
	double prac;
	double term;
	char grade[3];
};

struct data
{
	char adno[10];
	int roll,cla;
	char sec,name[25];
	int mobile;
	char term[12];
	subject sub[5];
	double total;
	double agg;
};
/*
List of Functions:
void printFAIPS();

void inputdata(data a[],int &n);
void inputgrade(data a[],int n,int k);

void searchmenu(data a[],int n);
void searchadno(data a[],int n);
void searchrollno(data a[],int n);
void searchname(data a[],int n);
void searchclass(data a[],int n);
void searchsection(data a[],int n);

void deletemenu(data a[],int &n);
void deleteadno(data a[],int &n);
void deleterollno(data a[],int &n);
void deletename(data a[],int &n);
void deletemobile(data a[],int &n);

void updatemenu(data a[],int n);
void updatesubjectdata(data a[],int studindex,int n);

void sortmenu(data a[],int n);
void sortadno(data a[],int n);
void sortname(data a[],int n);
void sortmarkstot(data a[],int n);

void reportmenu(data a[], int n);
void report(data a[],int n);

void protection(account sample[], int n);
void inpacc(account sample[],int &n);
*/
void report(data a[],int n);
void printFAIPS(int n=9+random(7))                                             //PRINTS "FAIPS" 9 ROWS TALL
{
   textbackground(n);
   for(int k=0;k<80;k++)
   	cprintf(" ");
	textbackground(BLACK);
	cout<<"\n\n       \t\t\t  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<'\n';
   cout<<"       \t\t\t  "<<char(219)<<"     "<<char(219)<<"   "<<char(219)<<"    "<<char(219)<<"   "<<char(219)<<"   "<<char(219)<<" "<<char(219)<<'\n';
   cout<<"       \t\t\t  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"    "<<char(219)<<"   "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<'\n';
   cout<<"       \t\t\t  "<<char(219)<<"     "<<char(219)<<"   "<<char(219)<<"    "<<char(219)<<"   "<<char(219)<<"        "<<char(219)<<'\n';
   cout<<"       \t\t\t  "<<char(219)<<"     "<<char(219)<<"   "<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<"     "<<char(219)<<char(219)<<char(219)<<char(219)<<"\n\n";
	textbackground(n);
	for(int k=0;k<80;k++)
   	cprintf(" ");
	textbackground(BLACK);
}
void inputgrade(data a[],int n,int k)                                           //Calculates Grade
{
	if(a[n].sub[k].term>91)
   	strcpy(a[n].sub[k].grade,"A1");
   else
   if(a[n].sub[k].term>81)
   	strcpy(a[n].sub[k].grade,"A2");
   else
   if(a[n].sub[k].term>71)
   	strcpy(a[n].sub[k].grade,"B1");
   else
   if(a[n].sub[k].term>61)
   	strcpy(a[n].sub[k].grade,"B2");
   else
   if(a[n].sub[k].term>51)
   	strcpy(a[n].sub[k].grade,"C1");
   else
   if(a[n].sub[k].term>41)
   	strcpy(a[n].sub[k].grade,"C2");
   else
   if(a[n].sub[k].term>33)
   	strcpy(a[n].sub[k].grade,"D1");
   else
   	strcpy(a[n].sub[k].grade,"E");
}

void inputdata(data a[],int &n)                                                 //Input a new students Information
{
   if(n==S)
   	cout<<"Maximum Limit reached\n";
   else
   {
   cout<<"Enter Admission Number-";cin>>a[n].adno;
   cout<<"Enter Roll Number-";cin>>a[n].roll;
   cout<<"Enter Class(11 or 12)-";cin>>a[n].cla;
   cout<<"Enter Section-";cin>>a[n].sec;
   if(a[n].sec>='a' && a[n].sec<='z')
   	a[n].sec=char(a[n].sec-32);
	int exist=1;
   if( a[n].sec>='E' || a[n].sec<'A')
   {
   	exist=0;
      cout<<"Inexistent Section\n";
   }
   if(exist)
   {
	   cout<<"Enter Name-";gets(a[n].name);
	   strupr(a[n].name);
	   cout<<"Enter Mobile No-";cin>>a[n].mobile;
      int term;
      cout<<"Enter term [1-2]";cin>>term;
   	if(term==1)
   		strcpy(a[n].term,"First Term");
   	else if(term==2)
   		strcpy(a[n].term,"Second Term");
      strcpy(a[n].sub[0].name,"English");
	   switch(a[n].sec)
	   {
			case 'A':
					strcpy(a[n].sub[1].name,"Math");
				   strcpy(a[n].sub[2].name,"Physics");
				   strcpy(a[n].sub[3].name,"Chemistry");
				   strcpy(a[n].sub[4].name,"Computer Science");
				   break;
			case 'B':
					strcpy(a[n].sub[1].name,"Math");
				   strcpy(a[n].sub[2].name,"Physics");
				   strcpy(a[n].sub[3].name,"Chemistry");
				   strcpy(a[n].sub[4].name,"Biology");
				   break;
		  case 'C':
					strcpy(a[n].sub[1].name,"Math");
				   strcpy(a[n].sub[2].name,"Physics");
				   strcpy(a[n].sub[3].name,"Chemistry");
				   strcpy(a[n].sub[4].name,"Economics");
				   break;
		  case 'D':
					strcpy(a[n].sub[1].name,"Math");
				   strcpy(a[n].sub[2].name,"Economics");
				   strcpy(a[n].sub[3].name,"Accountancy");
				   strcpy(a[n].sub[4].name,"Business Studies");
				   break;
	   }
	   for(int k=0;k<5 && exist;k++)
	   {
		if(strcmpi(a[n].sub[k].name,"Physics")==0 ||
			strcmpi(a[n].sub[k].name,"Chemistry")==0 ||
			 strcmpi(a[n].sub[k].name,"Biology")==0 ||
			 strcmpi(a[n].sub[k].name,"Computer Science")==0)
		  {
			 cout<<endl<<a[n].sub[k].name<<':'<<endl;
			cout<<"Enter Theory Marks(out of 70)-";cin>>a[n].sub[k].theo;
			 cout<<"Enter Practical Marks(out of 30)-";cin>>a[n].sub[k].prac;
			 a[n].sub[k].term=a[n].sub[k].theo+a[n].sub[k].prac;
			 inputgrade(a,n,k);
		  }
		  else
		  if(strcmpi(a[n].sub[k].name,"Accountancy")==0 ||
			strcmpi(a[n].sub[k].name,"Business Studies")==0)
		  {
			 cout<<endl<<a[n].sub[k].name<<':'<<endl;
				cout<<"Enter Theory Marks(out of 80):";cin>>a[n].sub[k].theo;
			 cout<<"Enter Practical Marks(out of 20):";cin>>a[n].sub[k].prac;
			 a[n].sub[k].term=a[n].sub[k].theo+a[n].sub[k].prac;
			 inputgrade(a,n,k);
		  }
		  else
		  if(strcmpi(a[n].sub[k].name,"English")==0 ||
			strcmpi(a[n].sub[k].name,"Math")==0 ||
			 strcmpi(a[n].sub[k].name,"Economics")==0)
		  {
			 cout<<endl<<a[n].sub[k].name<<':'<<endl;
			 cout<<"Enter Marks-";cin>>a[n].sub[k].term;
			 a[n].sub[k].theo=0;a[n].sub[k].prac=0;
			 inputgrade(a,n,k);
		  }
	   }
	   a[n].total=0;
	   for(int k=0;k<5;k++)
		a[n].total+=a[n].sub[k].term;
	   a[n].agg=a[n].total/5;
	   n++;
   }
	}
}

void searchadno(data a[],int n)
{
	char chkno[11];
   int found=0;
   cout<<"\nEnter the admission number of the student-";cin>>chkno;
   for(int k=0;k<n && found!=1;k++)
   	if(strcmp(a[k].adno,chkno)==0)
      	found=1;
   if(found==1)
   	cout<<"Admission number found.\n";
   else
   	cout<<"Admission number not found.\n";
}

void searchrollno(data a[],int n)
{
	int chkroll;
   int found=0;
   cout<<"\nEnter the roll number of the student-";cin>>chkroll;
   for(int k=0;k<n && found!=1;k++)
   	if(a[k].roll==chkroll)
      	found=1;
   if(found==1)
   	cout<<"Roll number found.\n";
   else
   	cout<<"Roll number not found.\n";
}

void searchname(data a[],int n)
{
	char chkname[25];
   int found=0;
   cout<<"\nEnter the name of the student-";gets(chkname);
   for(int k=0;k<n && found!=1;k++)
   	if(strcmpi(a[k].name,chkname)==0)
      	found=1;
   if(found==1)
   	cout<<"Name found.\n";
   else
   	cout<<"Name not found.\n";
}

void searchclass(data a[],int n)
{
	int chkclass;
   char chksec;
   int found=0;
   cout<<"\nEnter the class of the student-";cin>>chkclass;
   cout<<"Enter the section of the student-";cin>>chksec;
   for(int k=0;k<n && found!=1;k++)
		if(a[k].cla==chkclass && a[k].sec==chksec)
      	found=1;
   if(found==1)
   	cout<<"Class found.\n";
   else
   	cout<<"Class not found.\n";
}

void deleteadno(data a[],int &n)
{
	int pos=-1;
   char chkno[10];
   cout<<"\nEnter the admission number of the student-";cin>>chkno;
   if(n==0)
   	cout<<"Underflow\n";
   else
   	for(int k=0;k<n && pos==-1;k++)
	      if(strcmp(a[k].adno,chkno)==0)
      		pos=k;
   if(pos<0)
   	cout<<"Not found\n";
   else
   {
   	cout<<"Deleted.\n";
      for(int x=pos+1;x<n;x++)
      	a[x-1]=a[x];
      n--;
   }
}

void deleterollno(data a[],int &n)
{
	int pos=-1;
   int chkroll;
   cout<<"\nEnter the roll number of the student-";cin>>chkroll;
   if(n==0)
   	cout<<"Underflow\n";
   else
   	for(int k=0;k<n && pos==-1;k++)
   		if(a[k].roll==chkroll)
      		pos=k;
   if(pos<0)
   	cout<<"Not found\n";
   else
   {
   	cout<<"Deleted.\n";
      for(int x=pos+1;x<n;x++)
      	a[x-1]=a[x];
      n--;
   }
}
//XI-A
void deletename(data a[],int &n)
{
	int pos=-1;
   char chkname[25];
	cout<<"\nEnter the name of the student-";gets(chkname);
	for(int k=0;k<n && pos==-1;k++)
		if(strcmpi(a[k].name,chkname)==0)
			pos=k;
   if(pos<0)
   	cout<<"Not found\n";
   else
   if(n==0)
   	cout<<"Underflow";
   else
   {
      cout<<"Deleted.\n";
      for(int x=pos+1;x<n;x++)
      	a[x-1]=a[x];
      n--;
   }
}

void deletemobile(data a[],int &n)
{
	int pos=-1;
   int chkmob;
   cout<<"\nEnter the mobile number of the student-";cin>>chkmob;
   if(n==0)
   	cout<<"Underflow";
   else
   	for(int k=0;k<n && pos==-1;k++)
   		if(a[k].mobile==chkmob)
      		pos=k;
   if(pos<0)
   	cout<<"Not found\n";
   else
   {
		cout<<"Deleted.\n";
      for(int x=pos+1;x<n;x++)
      	a[x-1]=a[x];
      n--;
   }
}

void updatesubjectdata(data a[],int studindex)
{
	int subind=-1;
   char tempsub[25];
   cout<<"Enter Subject to modify-"; gets(tempsub);
   for(int k=0;k<5;k++)
   	if(strcmpi(a[studindex].sub[k].name,tempsub)==0)
      {
      	cout<<"Subject found."<<endl;
      	subind=k;
      }
	if(subind==-1)
   {
   	cout<<"Subject not present\n";
   }
   else
   {
   	int ch;
   	cout<<"Enter subject data to be modified-"<<endl;
      cout<<"Enter 1: Name."<<endl;
      cout<<"Enter 2: Theory Marks."<<endl;
      cout<<"Enter 3: Practical Marks."<<endl;
      cout<<"Enter Choice[1-3]-"; cin>>ch;
      switch(ch)                                                                //In each case required data is over-written with new inputted data
      {
      	case 1:
         	cout<<"Enter name-";
            gets(a[studindex].sub[subind].name);
            break;
         case 2:
         	cout<<"Enter Theory Marks-";
            cin>>a[studindex].sub[subind].theo;
			a[studindex].total-=a[studindex].sub[subind].term;
			a[studindex].sub[subind].term=a[studindex].sub[subind].theo+a[studindex].sub[subind].prac;
			a[studindex].total+=a[studindex].sub[subind].term;
         inputgrade(a,studindex,subind);
			a[studindex].agg=a[studindex].total/5;

            break;
         case 3:
         	cout<<"Enter Practical Marks-";
         	cin>>a[studindex].sub[subind].prac;
         a[studindex].total-=a[studindex].sub[subind].term;
			a[studindex].sub[subind].term=a[studindex].sub[subind].theo+a[studindex].sub[subind].prac;
			a[studindex].total+=a[studindex].sub[subind].term;
                  inputgrade(a,studindex,subind);
			a[studindex].agg=a[studindex].total/5;
            break;
      }
      cout<<"Updated\n";
   }
}

void sortadno(data a[],int n)
{
   data sorted[S];
   for(int x=0;x<n;x++)
   	sorted[x]=a[x];                                                           //creates a copy of main array of data
   for(int x=1;x<n;x++)
   	for(int k=0;k<n-x;k++)
      	if(strcmpi(sorted[k].adno,sorted[k+1].adno)>0)
         {
         	data t=sorted[k];
            sorted[k]=sorted[k+1];
            sorted[k+1]=t;
         }                                                                      //sorted on basis of admission number.
   cout<<"Sort complete."<<endl;
   cout<<"[Enter any character to display]";
   getch();
   clrscr();                                                                    // [n] elements are displayed.
   report(sorted,n);
}

void sortname(data a[],int n)
{
	data sorted[S];                                                              //creates a copy of main array of data
	int sortcla;
   char sortsec;
	cout<<"Enter Class-";cin>>sortcla;
   cout<<"Enter Section-";cin>>sortsec;
   if(sortsec>90)
   	sortsec=char(sortsec-32);                                                 //Class and section of students to be sorted is inputted
   int match=0;
   for(int i=0;i<n;i++)
   	if(a[i].cla==sortcla && a[i].sec==sortsec)
   		sorted[match++]=a[i];                                                  //No. of students in specified class is found
   for(int x=1;x<match;x++)
   	for(int k=0;k<match-x;k++)
      	if(strcmpi(sorted[k].name,sorted[k+1].name)>0)
         {
         	data t=sorted[k];
            sorted[k]=sorted[k+1];
            sorted[k+1]=t;                                                      //First [match] no. of elements having students with mathced class is now sorted on basis of name.
         }
   if(match==0)       //checked here for convinience
   {
   	cout<<"No such students found."<<endl;
      cout<<"[Enter any character to exit]";
   	getch();
   	clrscr();
   }
   else
   {
		cout<<"Sort complete."<<endl;
   	cout<<"[Enter any character to display]";
   	getch();
   	clrscr();
   	report(sorted,match);                                                     //First [match] no. of students is displayed.
   }
}

void sortmarkstot(data a[],int n)
{
	data sorted[S];                                                              //creates a copy of main array of data
	int sortcla;
   char sortsec;
	cout<<"Enter Class-";cin>>sortcla;
   cout<<"Enter Section-";cin>>sortsec;
   if(sortsec>90)
   	sortsec=char(sortsec-32);                                                              //Class and section of students to be sorted is inputted
   int match=0;
   for(int i=0;i<n;i++)
   	if(a[i].cla==sortcla && a[i].sec==sortsec)
   		sorted[match++]=a[i];
   for(int x=1;x<match;x++)
   	for(int k=0;k<match-x;k++)
      	if(sorted[k].total<sorted[k+1].total)
         {
         	data t=sorted[k];
            sorted[k]=sorted[k+1];
            sorted[k+1]=t;                                                      //First [match] no. of elements having students with mathced class is now sorted on basis of total marks.
         }
   if(match==0)       //checked here for convinience
   {
   	cout<<"No such students found."<<endl;
      cout<<"[Enter any character to exit]";
   	getch();
   	clrscr();
   }
   else
   {
		cout<<"Sort complete."<<endl;
   	cout<<"[Enter any character to display]";
   	getch();
   	clrscr();
   	report(sorted,match);                                                     //First [match] no. of students is displayed.
   }
}

void report(data a[],int n)                                                     //REPORT FUNCTION
{
   int ch;
   for(int k=0;k<n;k++)
   {
      if(a[k].agg==100)
      	textbackground(GREEN);
      else
      if(a[k].agg<33)
      	textbackground(RED);
      clrscr();
	   cprintf("\n\n\r           %50s\n\r","Fahaheel Al-Watanieh Indian Private School");
      cprintf("           %26s%17s\n\n\r",a[k].term,"Examination 2016");
      cprintf("           Admission No:%9s%24s Roll:%3i \n\r",a[k].adno," ",a[k].roll);
	   cprintf("           Name:%-25s               Class:%3i%c\n\r           ",a[k].name,a[k].cla,a[k].sec);
      for(int x=1;x<=56;x++)
      	cprintf("-");
      cout<<endl;
      cprintf("           %-23s %-5s  %-4s    %-6s   %-6s\n\r           ","Subject","Theo","Prac","Term","Grade");
      for(int x=1;x<=56;x++)
      	cprintf("-");
      cout<<endl;
      for(int x=0;x<5;x++)
      	if(strcmpi(a[k].sub[x].name,"English")==0 ||
		   	strcmpi(a[k].sub[x].name,"Math")==0 ||
		   	strcmpi(a[k].sub[x].name,"Economics")==0)
					cprintf("           %-23s %-5s  %-5s   %-6.2f   %3s\n\r",
      				a[k].sub[x].name,"     ","     ",a[k].sub[x].term,a[k].sub[x].grade);
         else
         		cprintf("           %-23s %-5.2f  %-5.2f   %-6.2f   %3s\n\r",
      				a[k].sub[x].name,a[k].sub[x].theo,a[k].sub[x].prac,a[k].sub[x].term,a[k].sub[x].grade);
      cprintf("           ");
      for(int x=1;x<=56;x++)
      	cprintf("-");
      cout<<endl;
      cprintf("           %5s%32s%6.2f(%6.2f%c)\n\r           ","Total"," ",a[k].total,a[k].agg,'%');
      for(int x=1;x<=56;x++)
      	cprintf("-");
      cout<<endl<<endl<<endl;
      cprintf("            %-25s%25s\n\r","Class Teacher","Principal");
      cout<<"\n\nControls:\n\rEsc-Return to menu\n\rBackspace-Previous Student\n\rAny Key-Next Student\n\r[Enter Control]:";
      ch=getch();
      if(ch==8 && k>0)
      	k-=2;
      else
      if(ch==27)
      	k=n;
      textbackground(BLACK);
   	clrscr();
   }
	if(n==0)
   {
   	cout<<"\nUnderflow\n";
      cout<<"[Enter any character to return to menu]";
      getch();
   }
   textbackground(BLACK);
   clrscr();
}

void protection(account sample[], int n)                                        //PASSWORD PROTECTION
{
   char user[10], pass[25];
   int found=1;
   printFAIPS();
   while(found)
   {
   	cout<<"\n\n\t\t\tWelcome to the FAIPS DPS registry\n";
   	cout<<"\tHere you can edit and view information on students in the school\n";
   	cout<<"\t   (This data can only be accessed by authorized personnel)\n";
		cout<<"\n\n\tPlease enter your username and password\n";
		cout<<"\tUsername-";gets(user);
		cout<<"\tPassword-";
      //password hashing taken from http://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1045691686&id=1043284392
      int ch;
      int i = 0;
      fflush(stdout);

      while ((ch = getch()) != EOF && ch != '\n' && ch != '\r' && i < sizeof(pass) - 1)
      {
      	if (ch == '\b' && i > 0)
        {
          printf("\b \b");
          fflush(stdout);
          i--;
          pass[i] = '\0';
        }
        else if (isalnum(ch))
        {
          putchar('*');
          pass[i++] = (char)ch;
        }
      }

      pass[i] = '\0';


      cout<<"\n\n\t\n\nLoading Please Wait";Sleep(500);cout<<'.';Sleep(500);cout<<'.';Sleep(500);cout<<'.';Sleep(500);cout<<'.'<<endl;
		for(int k=0;k<n && found;k++)
			if(strcmpi(sample[k].username,user)==0 && strcmp(sample[k].password,pass)==0)
				found=0;
		if(found==1)
		{
			cout<<"\n\a\tIncorrect Password\n";
			cout<<"\t[Enter any character to retry]"; getch();
			clrscr();
         printFAIPS(12);
		}
      else
      {
      	cout<<"\n\a\tAccess Granted";
         Sleep(1000);
         cout<<"\n\tLogging In";
         Sleep(250);cout<<'.';Sleep(250);cout<<'.';Sleep(250);cout<<'.';Sleep(250);cout<<'.'<<endl;
         clrscr();
      }
   }
}
//XI-A
void inpacc(account sample[],int &n)                                                                                 //INPUT ACCOUNT FUNCTION
{
   clrscr();
   printFAIPS();
	int ch;
   cout<<"----------------------------------\n";
   cout<<"1. Settings"<<endl;
   cout<<"----------------------------------\n";
	cout<<"Enter  1: Display all accounts."<<endl;
   cout<<"Enter  2: Create new account."<<endl;
   cout<<"----------------------------------\n";
   cout<<"2. Information"<<endl;
   cout<<"----------------------------------\n";
   cout<<"Enter  3: Display Project Background\n";
   cout<<"Enter  4: Display School Information\n";
   cout<<"----------------------------------\n";
   cout<<"3. Contact/Help\n";
   cout<<"----------------------------------\n";
   cout<<"Enter  5:Display Contact details for assistance\n";
   cout<<"\nEnter Choice[1-7]-"; cin>>ch;
   cout<<endl;
   for(int k=0;k<80;k++)
   		cout<<"-";
   cout<<endl;
   int x; char master[20];
   switch(ch)
   {
      case 1:
         cout<<"Enter Master Password:";cin>>master;
         if(strcmp(master,"SCHOOLFAIPS")==0)
         {
      		printf("S.no|  Username          |  Password\n");
      		for(x=0;x<n;x++)
   				printf("%4i|  %-15s   |  %-25s\n",(x+1),sample[x].username,sample[x].password);
         }
         else
         {
         	cout<<"\aAccess Denied";Sleep(250);cout<<'.';Sleep(250);cout<<'.';Sleep(250);cout<<'.';Sleep(250);cout<<'.'<<'\a'<<"INTRUDER ALERT\n";
         }
         break;

      case 2:if(n!=USERS)
     		 	{
               int exist=0;
               while(exist==0)
               {
   					cout<<"Username-"; gets(sample[n].username);
   					cout<<"Password-"; gets(sample[n].password);
						for(int k=0;k<n && exist==0;k++)
							if(strcmpi(sample[k].username,sample[n].username)==0)
									exist=1;
                  if(exist==1)
               		cout<<"Username Taken\n\n";
                  exist==1? exist=0 : exist=1;
               }
         		cout<<"Account created."<<endl;
               n++;
      		}
            else
            	cout<<"Account Limit has been reached\n";
            break;

      case 3:
      	cout<<"\nC++ is a programming language that is widely used and regarded as the creator of many popular applications.";
         cout<<"The school DPS has hence adopted this language and has been teaching it to students for several years.";
         cout<<"This program was made by students in an effort to assist in the digitalization of school records.\n\n";
         break;
   	case 4:
      	cout<<"FAIPS DPS, Ahmadi, Kuwait\n";
         cout<<"Fahaheel Al-Watanieh Indian Private School, also known as FAIPS, is an Indian CBSE affiliated school in Kuwait.\n";
         cout<<" Founded on 11 September 1995, in collaboration with the Delhi Public School, India\n";
         cout<<"Email: faipsdps@gmail.com\n";
         cout<<"Phone: 55918400\n";
         cout<<"Number of students:5000\n";
         cout<<"Staff:200\n";
         cout<<"Motto:Service Before Self\n";
         break;
      case 5:
      	cout<<"HELP\n";
         cout<<"JAIDEV SHRIRAM: jaidevtrumpet@gmail.com | 97112602\n\n";
	}
}

//MENUS OF ALL THE FUNCTIONS
void searchmenu(data a[],int n)                                                 //SEARCH FUNCTION
{
	int opt;
   cout<<"\nEnter 1: to search by admission number.";
   cout<<"\nEnter 2: to search by roll number.";
   cout<<"\nEnter 3: to search by name.";
   cout<<"\nEnter 4: to search by class and section.";
   cout<<"\nEnter Choice[1-4]-"; cin>>opt;
   switch(opt)
   {
	  	case 1:searchadno(a,n);break;
      case 2:searchrollno(a,n);break;
      case 3:searchname(a,n);break;
      case 4:searchclass(a,n);break;
	  	default:cout<<"Invalid option.\n";
   }
}

void deletemenu(data a[],int &n)                                                //DELETE FUNCTION
{
	int opt;
   cout<<"\nEnter 1: to delete by admission number.";
   cout<<"\nEnter 2: to delete by roll number.";
   cout<<"\nEnter 3: to delete by name.";
   cout<<"\nEnter 4: to delete by mobile number.\n";
   cout<<"Enter Choice[1-4]-"; cin>>opt;
   switch(opt)
   {
   	case 1:deleteadno(a,n);break;
      case 2:deleterollno(a,n);break;
      case 3:deletename(a,n);break;
      case 4:deletemobile(a,n);break;
   	default:cout<<"Invalid option.\n";break;

   }
}

void sortmenu(data a[],int n)                                                   //SORT FUNCTION
{
	int ch;
	cout<<"\nEnter basis of sorting students:"<<endl;
   cout<<"Enter 1: Sort by Admission number"<<endl;
   cout<<"Enter 2: Sort by Name (for a particular class and section)"<<endl;
   cout<<"Enter 3: Sort by Marks (for a particular class and section)"<<endl<<endl;
   cout<<"Choice[1-3]-"; cin>>ch;
   switch(ch)
   {
   	case 1:sortadno(a,n); break;
      case 2:sortname(a,n); break;
      case 3:sortmarkstot(a,n); break;
      default:cout<<"Invalid option.\n";break;
   }
}

void updatemenu(data a[],int n)                                                 //UPDATE FUNCTION
{
	int ch;
   int studindex=-1;
   cout<<endl<<"Enter means through which required student is found-"<<endl;
   cout<<"Enter 1: Admission number"<<endl;
   cout<<"Enter 2: Roll number"<<endl;
   cout<<"Enter 3: Name"<<endl;
   cout<<"Enter Choice[1-3]-"; cin>>ch;
   char chkno[11];
   int chkroll;
   char chkname[25];
   int k;
   switch(ch)                                                                   // In each case, INDEX of the student required is
   {                                                                            // inputted and passed to the updatesubjectdata function.
   	case 1:
   		studindex=-1;
   		cout<<"\nEnter the admission number of the student-";cin>>chkno;
   		for(k=0;k<n && studindex==-1;k++)
	         if(strcmp(a[k].adno,chkno)==0)
   	   		studindex=k;
         break;
      case 2:
   		studindex=-1;
   		cout<<"\nEnter the roll number of the student-";cin>>chkroll;
   		for(k=0;k<n && studindex==-1;k++)
   			if(a[k].roll==chkroll)
      			studindex=k;
         break;
      case 3:
   		studindex=-1;
   		cout<<"\nEnter the name of the student-";gets(chkname);
   		for(k=0;k<n && studindex==-1;k++)
   			if(strcmpi(a[k].name,chkname)==0)
      			studindex=k;
         break;
      default: cout<<"Invalid Option\n";
   }
	if(studindex==-1)
		cout<<"Student not found."<<endl;
   else
   {
   	cout<<"Student found."<<endl;
   	updatesubjectdata(a,studindex);
   	a[studindex].total=0;
   	for(int k=0;k<5;k++)
   		a[studindex].total+=a[studindex].sub[k].term;
   	a[studindex].agg=a[studindex].total/5;
   }
}
void reportmenu(data a[], int n)
{
	data divergent[S];
	int ch;
   int term;
   char cterm[14];
   cout<<"\nEnter 1: Display complete data\n";
   cout<<"             OR\n";
	cout<<"Choose the grades to display:\n";
   cout<<"Enter 2: Class 11\n";
   cout<<"Enter 3: Class 12\n";;
   cout<<"Choice[1-3]-";cin>>ch;
   int found=0;
   if(ch==1)
   {
   	report(a,n);found=1;
   }
   else
   {
   	cout<<"\nEnter term [1-2] or Enter [3]:All terms-";cin>>term;
   	if(term==1)
   		strcpy(cterm,"First Term");
   	else
   		strcpy(cterm,"Second Term");

   	int x;
      int count=0;
   	switch(ch)
   	{
   		case 2:
         	if(term!=3)
            {
      			for(x=0;x<n;x++)
         			if(a[x].cla==11 && strcmpi(cterm,a[x].term)==0)
            		{
            			divergent[count]=a[x];
                  	count++;found=1;
            		}
               report(divergent,count);
            }
            else
            {
      			for(x=0;x<n;x++)
         			if(a[x].cla==11)
            		{
            			divergent[count]=a[x];
                  	count++;found=1;
            		}
               report(divergent,count);
            }
				break;
      	case 3:
      		if(term!=3)
            {
      			for(x=0;x<n;x++)
         			if(a[x].cla==12 && strcmpi(cterm,a[x].term)==0)
            		{
            			divergent[count]=a[x];
                  	count++;found=1;
            		}
               report(divergent,count);
            }
            else
            {
      			for(x=0;x<n;x++)
         			if(a[x].cla==12)
            		{
            			divergent[count]=a[x];
                  	count++;found=1;
            		}
               report(divergent,count);
            }
				break;
      }
   }
   if(found==0)
   	cout<<endl<<"No such students."<<endl;
}

void main()                                                                                                              //MAIN FUNCTION
{
   randomize();
	account sample[USERS]={{"user","pass"},{"Jordan","jj123"},{"Jaidev","hello!@#"},{"BIKRAM","1234abc"},{"FAIPS","P@ssw0rd"}};
	data arr[S]={
   				{"3141/2001",13,11,'A',"HARI PUTHAR",97112602,"Second Term",{{"English",70,30,100,"A1"},{"Math",68,30,98,"A1"},{"Economics",64,30,94,"A1"},{"Accountancy",69,29,98,"A1"},{"Buisness Studies",65,30,95,"A1"}},485,10},
   				{"2678/2000",3,12,'B',"ALICIA THOMAS",60063112,"First Term",{{"English",69,29,98,"A1"},{"Math",69,27,96,"A1"},{"Physics",40,29,69,"B2"},{"Computer Science",65,30,95,"A1"},{"Chemistry",40,30,70,"B2"}},428,85.6},
               {"3964/2001",25,11,'C',"PABI DENN",68015778,"First Term",{{"English",70,30,100,"A1"},{"Math",0,0,100,"A1"},{"Physics",70,30,100,"A1"},{"Chemistry",70,30,100,"A1"},{"Biology",70,30,100,"A1"}},500,100},
               {"3330/2000",19,12,'D',"HEERA JAMES",99541793,"Second Term",{{"English",70,30,100,"A1"},{"Math",70,30,100,"A1"},{"Physics",70,30,100,"A1"},{"Chemistry",70,30,100,"A1"},{"Economics",70,30,100,"A1"}},500,100},
               {"1234/2003",17,11,'B',"TRISHA ANN",99721808,"Second Term",{{"English",60,30,90,"A2"},{"Math",64,30,94,"A1"},{"Physics",65,30,95,"A1"},{"Chemistry",70,30,100,"A1"},{"Computer Science",70,30,100,"A1"}},479,95.8},
               {"3142/2000",30,11,'A',"SAM MATHEW",98015771,"Second Term",{{"English",65,30,95,"A1"},{"Math",68,30,98,"A1"},{"Economics",64,30,94,"A1"},{"Accountancy",69,29,98,"A1"},{"Buisness Studies",65,30,95,"A1"}},480,96},
   				{"2688/2009",6,12,'D',"RUEL GEORGE",60054492,"First Term",{{"English",68,28,96,"A1"},{"Math",69,27,96,"A1"},{"Physics",40,29,69,"B2"},{"Computer Science",65,30,95,"A1"},{"Chemistry",40,30,70,"B2"}},426,85.2},
               {"3241/2006",16,12,'A',"RUTH MAANA",97456782,"Second Term",{{"English",70,30,100,"A1"},{"Math",62,30,92,"A1"},{"Economics",64,30,94,"A1"},{"Accountancy",69,29,98,"A1"},{"Buisness Studies",65,30,95,"A1"}},479,95.8},
   				{"2578/2000",2,11,'A',"SIDHANTH SHARMA",60230941,"First Term",{{"English",69,29,98,"A1"},{"Math",69,27,96,"A1"},{"Physics",40,29,69,"B2"},{"Computer Science",65,30,95,"A1"},{"Chemistry",40,30,70,"B2"}},428,85.6},
               {"1234/2000",14,11,'A',"SALMAN KHAN",97112602,"Second Term",{{"English",70,20,80,"B1"},{"Math",64,30,94,"A1"},{"Physics",65,30,95,"A1"},{"Chemistry",70,30,100,"A1"},{"Computer Science",70,30,100,"A1"}},469,93.8},
 					{"1235/2001",10,11,'A',"SACHIN TENDULKAR",97122602,"Second Term",{{"English",58,18,76,"B2"},{"Math",44,10,54,"C2"},{"Physics",25,30,55,"C2"},{"Chemistry",62,30,92,"A2"},{"Computer Science",45,30,75,"B2"}},352,70.4},
 					{"1237/1999",11,11,'B',"ANSH SUBRAMANIUM",97112603,"Second Term",{{"English",40,20,60,"C2"},{"Math",72,20,94,"B1"},{"Physics",46,30,76,"B2"},{"Chemistry",54,22,76,"B2"},{"Biology",55,30,85,"B2"}},391,78.2},
               {"1110/2002",13,11,'B',"AKSHAY KUMAR",97112552,"Second Term",{{"English",55,18,73,"B2"},{"Math",63,26,89,"B1"},{"Physics",65,20,85,"B1"},{"Chemistry",59,30,89,"B1"},{"Biology",65,30,95,"A1"}},431,86.2},
               {"1030/2002",12,11,'C',"MOHANLAL",52112602,"Second Term",{{"English",56,20,86,"B1"},{"Math",33,19,52,"C2"},{"Physics",33,30,63,"C1"},{"Chemistry",40,30,70,"B1"},{"Economics",70,20,90,"A2"}},361,72.2},
               {"3330/1232",9,11,'D',"DOPING BOY",99641793,"Second Term",{{"English",0,0,0,"E"},{"Math",0,0,0,"E"},{"Physics",0,0,0,"E"},{"Chemistry",0,0,0,"E"},{"Economics",0,0,0,"E"}},0,0},
               {"1200/2002",22,11,'C',"BIKRAM BANNERJEE",97112602,"Second Term",{{"English",72,17,89,"B1"},{"Math",48,22,70,"B2"},{"Physics",57,30,97,"A1"},{"Chemistry",69,15,84,"B1"},{"Economics",79,20,99,"A1"}},439,87.8},
 					{"1250/2004",13,11,'C',"PRASANTH SHARMA",97322602,"Second Term",{{"English",79,18,97,"A1"},{"Math",64,35,99,"A1"},{"Physics",50,30,80,"B1"},{"Chemistry",35,30,65,"C1"},{"Economics",80,20,100,"A1"}},441,88.2},
 					{"1256/2006",16,11,'D',"ALOK.K.MUKHERJEE",97112591,"Second Term",{{"English",30,16,46,"D1"},{"Math",64,27,91,"A2"},{"Physics",69,30,99,"A1"},{"Chemistry",45,30,75,"B2"},{"Economics",68,20,88,"B1"}},399,79.8},
 					{"1208/2010",18,11,'D',"OSAMA BIN QUTOOB",97117787,"Second Term",{{"English",35,18,53,"C2"},{"Math",56,39,95,"A1"},{"Accounts",63,19,82,"B1"},{"Buisness St.",77,20,97,"A1"},{"Economics",55,15,70,"B2"}},397,79.4},
 					{"1090/2010",19,11,'D',"BENNEDICT CUMBERBATCH",91234876,"Second Term",{{"English",36,17,53,"C2"},{"Math",42,22,64,"C1"},{"Accounts",77,20,97,"A1"},{"Buisness St.",60,19,79,"B2"},{"Economics",75,20,95,"A1"}},388,77.6}
               };
   int ch,n=20,nusers=5; //n is no. of student data, nusers is no. of accounts
   protection(sample,nusers);
   do
   {
      printFAIPS();
      cout<<"\nOPTIONS:\n----------\n";
		cout<<"Enter 1: Add data\n";
		cout<<"Enter 2: Delete data\n";
		cout<<"Enter 3: Search data\n";
		cout<<"Enter 4: Sort data\n";
		cout<<"Enter 5: Update/Modify data\n";
		cout<<"Enter 6: Display Report\n";
      cout<<"Enter 7: Settings and Information\n";
      cout<<"Enter 8: Log out and Switch user\n";
		cout<<"Enter 0: Exit the program\n";
		cout<<"Choice[0-8]-"; cin>>ch;
      for(int k=0;k<80;k++)
   		cout<<"-";
		switch (ch)
		{
			case 1: inputdata(arr, n); break;
			case 2: deletemenu(arr, n); break;
			case 3: searchmenu(arr, n); break;
			case 4: sortmenu(arr, n); break;
			case 5: updatemenu(arr, n); break;
			case 6: reportmenu(arr, n); break;
         case 7: inpacc(sample, nusers); break;
         case 8: clrscr();printFAIPS();
         			cout<<"\nLogging Out";Sleep(250);cout<<'.';Sleep(250);cout<<'.';Sleep(250);cout<<'.';Sleep(250);cout<<'.'<<'\a';
                  clrscr();protection(sample,nusers);
                  break;
         case 0:break;
         default:cout<<"Invalid option.\n";break;
 		}
      if(ch!=6 && ch!=8 && ch!=0)
      {
    		cout<<"[Enter any character to return to menu]";
   		getch();
   		clrscr();
      }
	}
   while(ch);
}
