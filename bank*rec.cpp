#include<iostream>
using namespace std;

void menu()
{
int choice;
cout<<"\n\n====BANK MANAGEMENT====";
cout<<"\n1.Issue a token";
cout<<"\n2.Display all tokens";
cout<<"\n3.serve a token";
cout<<"\n4.Exit";
cout<<"\nEnter your choice:";
cin>>choice;
if(choice==1)
{
cout<<".Issue a token.";
menu();
}
else if(choice==2)
{
cout<<"Display all tokens.";
menu();
}
else if(choice==3)
{
cout<<"serve a token.";
menu();
}
else if(choice==4)
{
cout<<"\nThank you!";
}
else
{
cout<<"\nInvalid choice!";
menu();
}
}
int main()
{
menu();
return 0;
}
