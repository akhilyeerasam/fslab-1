//============================================================================
// Name        : lab4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class student
{
	public: int semester,count,rrn_list[100];
			string buffer,usn,branch,name,sem;
			
			void read();
			void pack();
			void write(char* fname);
			void unpack();
			void create_rrn(char * fname);
			void search_by_rrn(int rrn,char* fname);
};

void student::read()
{
	cout<<"USN: ";
	cin>>usn;
	cout<<"Name: ";
	cin>>name;
	cout<<"Branch: ";
	cin>>branch;
	cout<<"Semester: ";
	cin>>semester;
}

void student::pack()
{
	stringstream out;
	out<<semester;
	sem=out.str();
	buffer.erase();
	buffer+=usn+'|'+name+'|'+branch+'|'+sem+'$'+'\n';
}

void student::write(char* fname)
{
	int pos;
	fstream f;
	f.open(fname,ios::out|ios::app);
	f<<buffer;
	pos=f.tellp();
	f.close();	
	rrn_list[++count]=pos;
}

void student::unpack()
{
	int i=0;
	usn.erase();
	while(buffer[i]!='|')
		usn+=buffer[i++];
}

void student::create_rrn(char* fname)
{
	fstream f;
	int pos;
	count=0;
	f.open(fname,ios::in);
	while(!f.eof())
	{
		pos=f.tellg();
		buffer.erase();
		getline(f,buffer);
		if(buffer.empty())
			continue;
		rrn_list[++count]=pos;
	}	
	f.close();
}

void student::search_by_rrn(int rrn,char* fname)
{
	int pos=-1;
	fstream f;
	if(rrn>count)	
		cout<<"\nRecord number does not exist!";
	else
	{
		buffer.erase();
		f.open(fname);
		pos=rrn_list[rrn];
		f.seekp(pos,ios::beg);
		getline(f,buffer);
		cout<<"\nRecord is: "<<buffer<<"\n";
	}
}

int main()
{
	int choice,rrn;
	student s;
	char* fname;
	cout<<"\nEnter the file name to search for records: ";
	cin>>fname;
	s.create_rrn(fname);
	cout<<"\nEnter 1.Add records\t2.Search\n";
	cin>>choice;
	switch(choice)
	{
		case 1: s.read();
				s.pack();
				s.write(fname);
				break;
				
		case 2: cout<<"\nEnter RRN value: ";
				cin>>rrn;
				s.search_by_rrn(rrn,fname);
				break;
				
		default:exit(0);
	}	
	return 0;
}
