#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct Student
{
int roll;
string name;
string course[10];
int count;
Student*Next;
Student*hashNext;
};

Student*head=NULL;
const int SIZE=10;
Student*hashTable[SIZE]={NULL};

int hashFunction(int roll)
{
return roll % SIZE;
}

void registerStudent()
{
Student*s=new Student;
cout<<"Enter Roll Number:";
cin>>s->roll;

int index=hashFunction(s->roll);
Student*temp=hashTable[index];

while(temp!=NULL)
{
if(temp->roll==s->roll)
{
cout<<"Roll Number already exists!\n";
delete s;
return;
}
temp=temp->hashNext;
}

cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"Enter Student Name:";
getline(cin,s->name);

s->count=0;
s->Next=head;
head=s;

s->hashNext=hashTable[index];
hashTable[index]=s;

cout<<"Student Registered Successfully!\n";
}

void searchStudent()
{
int roll;
cout<<"Enter Roll Number to search:";
cin>>roll;

int index=hashFunction(roll);
Student*temp=hashTable[index];

while(temp!=NULL)
{
if(temp->roll==roll)
{
cout<<"\nStudent Found!\n";
cout<<"Roll Number:"<<temp->roll<<endl;
cout<<"Name:"<<temp->name<<endl;
cout<<"Courses:";

for(int i=0;i<temp->count;i++)
cout<<temp->course[i]<<" ";

cout<<endl;
return;
}
temp=temp->hashNext;
}

cout<<"Student not found!\n";
}

void displayStudents()
{
Student*temp=head;

if(temp==NULL)
{
cout<<"No Student records available.\n";
return;
}

cout<<"\n---All Student Records---\n";

while(temp!=NULL)
{
cout<<"\nRoll Number:"<<temp->roll<<endl;
cout<<"Name:"<<temp->name<<endl;
cout<<"Courses:";

for(int i=0;i<temp->count;i++)
cout<<temp->course[i]<<" ";

cout<<endl;
temp=temp->Next;
}
}

void updateStudent()
{
int roll;
cout<<"Enter Roll Number to update:";
cin>>roll;

int index=hashFunction(roll);
Student*temp=hashTable[index];

while(temp!=NULL)
{
if(temp->roll==roll)
{
cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"Enter New Student Name:";
getline(cin,temp->name);

cout<<"Student Updated Successfully!\n";
return;
}
temp=temp->hashNext;
}

cout<<"Student not found!\n";
}

void enrollCourse()
{
int roll;
cout<<"Enter Roll Number:";
cin>>roll;

int index=hashFunction(roll);
Student*temp=hashTable[index];

while(temp!=NULL)
{
if(temp->roll==roll)
{
if(temp->count==10)
{
cout<<"Course limit reached!\n";
return;
}

cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"Enter Course Name:";
getline(cin,temp->course[temp->count]);

temp->count++;

cout<<"Course Enrolled Successfully!\n";
return;
}
temp=temp->hashNext;
}

cout<<"Student not found!\n";
}

void withdrawCourse()
{
int roll;
cout<<"Enter Roll Number:";
cin>>roll;

int index=hashFunction(roll);
Student*temp=hashTable[index];

while(temp!=NULL)
{
if(temp->roll==roll)
{
cin.ignore(numeric_limits<streamsize>::max(),'\n');

string cname;
cout<<"Enter Course Name to withdraw:";
getline(cin,cname);

for(int i=0;i<temp->count;i++)
{
if(temp->course[i]==cname)
{
for(int j=i;j<temp->count-1;j++)
temp->course[j]=temp->course[j+1];

temp->count--;

cout<<"Course Withdrawn Successfully!\n";
return;
}
}

cout<<"Course not found!\n";
return;
}
temp=temp->hashNext;
}

cout<<"Student not found!\n";
}

void removeStudent()
{
int roll;
cout<<"Enter Roll Number to remove:";
cin>>roll;

int index=hashFunction(roll);
Student*temp=hashTable[index];
Student*prevHash=NULL;

while(temp!=NULL && temp->roll!=roll)
{
prevHash=temp;
temp=temp->hashNext;
}

if(temp==NULL)
{
cout<<"Student not found!\n";
return;
}

if(prevHash==NULL)
hashTable[index]=temp->hashNext;
else
prevHash->hashNext=temp->hashNext;

if(head==temp)
head=temp->Next;
else
{
Student*prev=head;
while(prev->Next!=temp)
prev=prev->Next;
prev->Next=temp->Next;
}

delete temp;
cout<<"Student Removed Successfully!\n";
}

int main()
{
int choice;

do
{
cout<<"\n----University Student Registration System----\n";
cout<<"1.Register Student\n";
cout<<"2.Search Student\n";
cout<<"3.Display All Students\n";
cout<<"4.Update Student\n";
cout<<"5.Enroll Course\n";
cout<<"6.Withdraw Course\n";
cout<<"7.Remove Student\n";
cout<<"8.Exit\n";
cout<<"Enter your choice:";
cin>>choice;

switch(choice)
{
case 1:
registerStudent();
break;

case 2:
searchStudent();
break;

case 3:
displayStudents();
break;

case 4:
updateStudent();
break;

case 5:
enrollCourse();
break;

case 6:
withdrawCourse();
break;

case 7:
removeStudent();
break;

case 8:
cout<<"Exiting program...\n";
break;

default:
cout<<"Invalid choice!\n";
}
}
while(choice!=8);

return 0;
}