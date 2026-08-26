#include<iostream>
#include<string>

using namespace std;
int main()
{
int id1,id2,id3;
string title1,title2,title3;

//Book 1
cout<<"Enter Book 1 ID:";
cin>>id1;
cin.ignore();
cout<<"Enter Book 1 Title:";
getline(cin,title1);

cout<<"Enter Book 2ID:";
cin>>id2;
cin.ignore();
cout<<"Enter Book 2 Title:";
getline(cin,title2);

cout<<"Enter Book 3 ID:";
cin>>id3;
cin.ignore();
cout<<"Enter Book 3 Title:";
getline(cin,title3);
cout<<"\n====Book library====";
cout<<"\n..Enter id<<id1";
cout<<"\n..Enter title"<<title1;
cout<<"\n..Enter id<<id2";
cout<<"\n..Enter title"<<title2;
cout<<"\n..Enter id<<id3";
cout<<"\n..Enter title"<<title3;
return 0;
}
