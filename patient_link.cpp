#include<iostream>
#include<string>
#include<limits>
using namespace std;
struct Patient
{
int id;
string name;
int age;
string disease;
Patient*Next;
Patient*hashNext;
};
Patient*head=NULL;
const int SIZE=10;
Patient*hashTable[SIZE]={NULL};
int hashFunction(int id)
{
return id %SIZE;
}
void registerPatient()
{
Patient*p=new Patient;
cout<<"Enter Patient ID:";
cin>> p->id;
int index = hashFunction(p->id);
Patient*temp = hashTable[index];
while(temp!=NULL)
{
if(temp->id==p->id)
{
cout<<"Patient ID already exits!\n";
delete p;
return;
}
temp=temp->hashNext; 
}
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"Enter Patient Name:";
getline(cin,p->name);
cout<<"Enter Age:";
cin>>p->age;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"Enter Disease:";
getline(cin,p->disease);
p->Next=head;
head=p;
p->hashNext=hashTable[index];
hashTable[index]=p;
cout<<"Patient Registerd Successfully!\n";
}
void searchPatient()
{
int id;
cout<<"Enter Patient ID to search:";
cin>>id;
int index=hashFunction(id);
Patient*temp=hashTable[index];
while(temp!=NULL)
{
if(temp->id==id)
{
cout<<"\nPatient Found!\n";
cout<<"ID:"<<temp->id<<endl;
cout<<"Name:"<<temp->name<<endl;
cout<<"Age:"<<temp->age<<endl;
cout<<"Disease:"<<temp->disease<<endl;
return;
}
temp=temp->hashNext;
}
cout<<"Patient not found!\n";
}
void displayPatients()
{
Patient*temp=head;
if(temp==NULL)
{
cout<<"No patient records available.\n";
return;
}
cout<<"\n---All Patient Reacords---\n";
while(temp!=NULL)
{
cout<<"\nPateient ID:"<<temp->id<<endl;
cout<<"Name:"<<temp->name<<endl;
cout<<"Age:"<<temp->age<<endl;
cout<<"Disease:"<<temp->disease<<endl;
temp=temp->Next;
}
}
int main()
{
int choice;
do
{
cout<<"\n---Hospital Management System---\n";
cout<<"1.Register Patient\n";
cout<<"2.Search Patient\n";
cout<<"3.Display All Patient\n";
cout<<"4.Exit\n";
cout<<"Enter your choice:";
cin>>choice;
switch(choice)
{
case 1:
registerPatient();
break;
case 2:
searchPatient();
break;
case 3:
displayPatients();
break;
case 4:
cout<<"Exiting program...\n";
break;
default:
cout<<"Invaild choice!\n";
}
}while(choice!=4);
return 0;
} 
