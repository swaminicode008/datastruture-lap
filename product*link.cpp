#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct Product

{
int id;
string name;
float price;
int quantity;
Product*Next;
Product*hashNext;
};

Product*head=NULL;
const int SIZE=10;
Product*hashTable[SIZE]={NULL};
int hashFunction(int id)
{
return id %SIZE;
}

void addProduct()
{
Product*p=new Product;
cout<<"Enter Product ID:";
cin>> p->id;
int index = hashFunction(p->id);
Product*temp = hashTable[index];
while(temp!=NULL)
{
if(temp->id==p->id)
{
cout<<"Product ID already exists!\n";
delete p;
return;
}
temp=temp->hashNext; 
}

cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"Enter Product Name:";
getline(cin,p->name);
cout<<"Enter Price:";
cin>>p->price;
cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"Enter Quantity:";
cin>>p->quantity;
p->Next=head;
head=p;
p->hashNext=hashTable[index];
hashTable[index]=p;
cout<<"Product Registered Successfully!\n";
}

void searchProduct()
{
int id;
cout<<"Enter Product ID to search:";
cin>>id;
int index=hashFunction(id);
Product*temp=hashTable[index];
while(temp!=NULL)
{
if(temp->id==id)
{
cout<<"\nProduct Found!\n";
cout<<"ID:"<<temp->id<<endl;
cout<<"Name:"<<temp->name<<endl;
cout<<"Price:"<<temp->price<<endl;
cout<<"Quantity:"<<temp->quantity<<endl;
return;
}
temp=temp->hashNext;
}

cout<<"Product not found!\n";
}
void displayProducts()
{
Product*temp=head;
if(temp==NULL)
{
cout<<"No Product records available.\n";
return;
}
cout<<"\n---All Product Records---\n";
while(temp!=NULL)
{
cout<<"\nProduct ID:"<<temp->id<<endl;
cout<<"Name:"<<temp->name<<endl;
cout<<"Price:"<<temp->price<<endl;
cout<<"Quantity:"<<temp->quantity<<endl;
temp=temp->Next;
}
}

void updateProduct()
{
int id;
cout<<"Enter Product ID to update:";
cin>>id;
int index=hashFunction(id);
Product*temp=hashTable[index];
while(temp!=NULL)
{
if(temp->id==id)
{ 
cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"Enter New Product Name:";
getline(cin,temp->name);

cout<<"Enter New Price:";
cin>>temp->price;

cout<<"Enter New Quantity:";
cin>>temp->quantity;
cout<<"Product Updated Successfully!\n";
return;
}
 temp=temp->hashNext;
}
cout<<"Product not found!\n";
}

int main()
{
int choice;
do
{
cout<<"\n----E-Commerce Product Catalog System---\n";
cout<<"1.Add Product\n";
cout<<"2.Search Product\n";
cout<<"3.Display All Products\n";
cout<<"4.Update Product\n";
cout<<"5.Exit\n";
cout<<"Enter your choice:";
cin>>choice;
switch(choice)
{
case 1:
addProduct();
break;
case 2:
searchProduct();
break;
case 3:
displayProducts();
break;
case 4:
updateProduct();
break;
case 5:
cout<<"Exiting program...\n";
break;
default:
cout<<"Invalid choice!\n";
}
}while(choice!=5);
return 0;
} 
