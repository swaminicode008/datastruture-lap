#include<iostream>
#include<string>
using namespace std;
int main()
{
int rollNo[5];
int searchRoll;
cout<<"Enter roll number 5 students:\n";
for(int i=0;i<5;i++)
{
cin>>rollNo[i];
}
cout<<"Enter roll number to search:\n";
cin>>searchRoll;
for(int i=0;i<5;i++)
{
if(rollNo[i]==searchRoll)
{
cout<<"roll number found:";
return 0;
}
}
cout<<"roll number not found:";
return 0;
}
