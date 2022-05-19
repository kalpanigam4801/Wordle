#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void Compute(int,int);
void main()
{
 clrscr();
 int ch,LB,UB;
 cout<<"                                    WORDLE LEVEL                  "<<endl;
 cout<<"		                   --------------                  "<<endl;
 cout<<"1. Easy"<<endl;
 cout<<"2. Medium"<<endl;
 cout<<"3. Hard"<<endl;
 cout<<"Choose your level: ";
 cin>>ch;
 switch(ch)
 {
  case 1: cout<<"Assume a word whose length is between 2 to 5!"<<endl;
	  LB=2;
	  UB=5;
	  break;
  case 2: cout<<"Assume a word whose length is between 6 to 9!"<<endl;
	  LB=6;
	  UB=9;
	  break;
  case 3: cout<<"Assume a word whose length is greater than or equal to 10!"<<endl;
	  LB=10;
	  UB=45;
	  break;
  default: cout<<"Wrong Choice!"<<endl;
	   exit(0);
 }
 Compute(LB,UB);
}
void Compute(int lb,int ub)
{
 char c,arr[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
 int pos1[20],pos2[20],no,i,j,z;
 textattr(1<<4|14);
 cout<<"\n\n\rStep 1:\n\r=======\n\rTable-1:\n\n\r";
 textattr(1<<4|12);
 for(i=0;i<5;i++)
  cout<<i+1<<" ";
 textattr(7<<4);
 for(i=0;i<26;i++)
 {
  if(i%5==0)
   cout<<endl;
  cout<<arr[i]<<" ";
 }
 textattr(1<<4|14);
 gotoxy(1,20);
 cout<<"\n\n\rEnter Total Number of letters in word: ";
 cin>>no;
 if(no<lb || no>ub)
 {
  cout<<"Length of the word not in the specified range..."<<endl;
  cout<<"Want to Continue? Enter 'Y' for Yes and 'N' for No: ";
  cin>>c;
  if(c=='Y')
  {
   clrscr();
   cout<<"Assume a word whose length is between "<<lb<<" to "<<ub<<"!"<<endl;
   Compute(lb,ub);
  }
  exit(0);
 }
 for(i=0;i<no;i++)
 {
  gotoxy(1,21);
  cout<<"\n\n\rEnter Letter "<<i+1<<" Column number: ";
  cin>>pos1[i];
  pos1[i]--;
 }
 clrscr();
 cout<<"Step 2:\n\rTable-2:\n\r";
 textattr(1<<4|12);
 for(i=0;i<6;i++)
  cout<<i+1<<" ";
 textattr(7<<4);
 for(i=0;i<no;i++)
 {
  cout<<endl;
  for(j=pos1[i];j<26;j+=5)
   cout<<arr[j]<<" ";
 }
 textattr(1<<4|14);
 for(i=0;i<no;i++)
 {
  gotoxy(1,15);
  cout<<"\n\n\rEnter the "<<i+1<<" Letter's Column number: ";
  cin>>pos2[i];
  pos2[i]--;
 }
 clrscr();
 gotoxy(30,13);
 cout<<"We Got U! ";
 gotoxy(30,15);
 cout<<"SURPRISED!";
 textcolor(WHITE+BLINK);
 gotoxy(30,14);
 for(i=0;i<no;i++)
  cout<<arr[pos2[i]*5+pos1[i]];
 textcolor(YELLOW+BLINK);
 cout<<"\n\n\n\n\n\n\n\n\rPress Esc To Exit...";
 while(getch()!=27);
}
