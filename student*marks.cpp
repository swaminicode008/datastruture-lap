#include<iostream>
#include<string>
using namespace std;

int main()
{
int marks[5];
int found=0;
cout<<"Enter marks of 5 students:\n";
for(int i=0;i<5;i++)
{
cout<<"student"<<i+1<<":";
cin>>marks[i];
}
for(int i=0;i<5-1;i++)
{
for(int j=0;j<5-1;j++)
{
if(marks[j]<marks[j+1])
{
int temp=marks[j];
marks[j]=marks[j+1];
marks[j+1]=temp;
}
}
}
cout<<"marks in descending order:\n";
for(int i=0;i<5;i++)
{cout<<marks[i]<<" ";
}
return 0;
}
