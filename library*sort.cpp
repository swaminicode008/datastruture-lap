#include<iostream>
#include<string>
using namespace std;
int main()
{
int Book[5];
int searchID;
int found=0;
cout<<"Enter 5 book IDS:\n";
for(int i=0;i<5;i++)
{
cin>>Book[i];
}
cout<<"\nEnter book ID to search:";
cin>>searchID;
for(int i=0;i<5;i++)
{ 
if(Book[i]==searchID);
{
found=1;
}
}
if (found==1)
{cout<<"Book ID found.\n";
}
else
{
cout<<"Book ID not found.\n";
} 
for(int i=0;i<4;i++)
{
for(int j=0;j<4-i;j++)
{
if(Book[j]>Book [j+1])
{
int temp=Book[j];
Book [j]=Book [j+1];
Book [j+1]=temp;
}
}
}
cout<<"\nBook after sorting:\n";
for(int i=0;i<5;i++)
{
cout<<Book[i]<<" ";
}
return 0 ;
}
