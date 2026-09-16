#include<iostream>
using namespace std;
int main()
{
int rollNo[5];
cout<<"Enter roll numbers of 5 students:\n";
for(int i=0;i<5;i++)
{
cout<<"student"<<i+1<<";";
cin>>rollNo[i];
}
cout<<"\n Roll numbers of all students are:\n";
for(int i=0;i<5;i++)
{
cout<<rollNo[i]<<endl;
}
return 0;
}
