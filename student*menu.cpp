#include<iostream>
using namespace std;

int main()
{
int student[10];
int n=0;
int choice;
int marks;
int searchRollNo;

do
{
cout<<"\n\n====Student Managment System====";
cout<<"\n1.Add student";
cout<<"\n2.Display student";
cout<<"\n3.Search student";
cout<<"\n4.Exit";
cout<<"\nEnter your choice:";
cin>> choice;
if(choice==1)
{
cout<<"Enter student RollNo :";
cin>>student RollNo[n];
n++;
cout<<"student RollNo Added!";
}
else if(choice==2)
{
cout<<"\n student marks:\n";
for(int i=0;i<n;i++)
{
cout<<students marks[i]<<endl;
}
}
else if (choice==3)
{
cout<<"Enter student RollNo to search:";
cin>>searchRollNo;
bool found=false;
for(int i=0;i<n;i++)
{
if (student[i]==searchRollNo)
{
found=true;
}
}
if(found)
{
cout<<"student found !";
}
else
{
cout<<"student not found !";
{
{
else if(choice==4)
{
cout<<"Thank you!";
}
else
{
cout<<"Invalid choice !";
}
}
