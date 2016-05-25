#include<iostream>
#include<stdlib.h>
#include<fstream> 
#include<sstream>
#include<string.h>
using namespace std;

class pk
{
	public: int count,add_list[100];
			string usn_list[100];
			void create_index(string fname);
			void sort_index();
			string get_usn(string buffer);
			void insert(string fname);
			int search(string fname,string key);
			void del(string fname);
};

void pk::create_index(string fname)
{
	int pos;
	count=0;
	string buffer,usn;
	fstream f;
	f.open(fname.c_str(),ios::in);
	if(!f)
		return;
	while(!f.eof())
	{
				pos=f.tellg();
		getline(f,buffer);
		usn=get_usn(buffer);
		if(usn.empty())
			break;
		if(usn[0]=='*')
			continue;
		usn_list[count]=usn;
		add_list[count]=pos;
		count++;
	}
	f.close();
	sort_index();
}

void pk::sort_index()
{
	int i,j,temp_add;
	string temp_usn;
	for(i=0;i<count;i++)
		for(j=i+1;j<count;j++)
		{
			if(usn_list[i]<usn_list[j])
			{
				temp_usn=usn_list[i];
				usn_list[i]=usn_list[j];
				usn_list[j]=temp_usn;
				temp_add=add_list[i];
				add_list[i]=add_list[j];
				add_list[j]=temp_add;
			}
		}
	cout<<"\nIndex is: ";
	for(i=0;i<count;i++)
	{
		cout<<usn_list[i]<<"\t";
	}
	cout<<"\nAddress is: ";
	for(i=0;i<count;i++)
	{
		cout<<add_list[i]<<"\t";
	}
}

string pk::get_usn(string buffer)
{
	int i=0;
	string usn;
	usn.erase();
	while(buffer[i]!='|')
	{
		usn[i]=buffer[i];
		i++;
	}
	return usn;
}

void pk::insert(string fname)
{
	string name,sem,branch,usn,buffer;
	cout<<"USN: ";
	cin>>usn;
	cout<<"Name: ";
	cin>>name;
	cout<<"Branch: ";
	cin>>branch;
	cout<<"Sem: ";
	cin>>sem;
	fstream f;
	f.open(fname.c_str(),ios::out|ios::app);
	buffer=usn+'|'+name+'|'+branch+'|'+sem;
	int pos=f.tellp();
	f<<buffer<<"\n";
	usn_list[count]=usn;
	add_list[count]=pos;
	count++;
	f.close();
	sort_index();
}

int pk::search(string fname, string key)
{
	string buffer;
	int pos,flag=0,i;
	for(i=0;i<count;i++)
	{
		if(key==usn_list[i])
		{
			fstream f;
			f.open(fname.c_str(),ios::in);
			pos=add_list[i];
			f.seekp(pos,ios::beg);
			getline(f,buffer);
			cout<<"\nRecord found: "<<buffer;
			f.close();
			return pos;
		}
	}
	cout<<"\nKey not found";
	return -1;
}

void pk::del(string fname)
{
	int pos,i;	
	string key;
	char d='*';	
	cout<<"\nEnter USN record to be deleted: ";
	cin>>key;
	pos=search(fname,key);
	cout<<"\nposition: "<<pos;
	if(pos==-1)
	 return;
	cout<<"\ntest";
	fstream f;
	f.open(fname.c_str());
	f.seekp(pos,ios::beg);
	f.put(d);
	f.close();
	for(i=pos;i<count;i++)
	{
		usn_list[i]=usn_list[i+1];
		add_list[i]=add_list[i+1];
	}
	count--;
} 

int main()
{
	pk p;
	int choice;
	string fname;
	string key;
	cout<<"\nEnter filename in which operations must be performed: ";
	cin>>fname;
	p.create_index(fname);
	while(1)
	{
		cout<<"\nEnter 1.Insert 2.Search 3.Delete 4.Exit";
		cin>>choice;
		switch(choice)
		{
			case 1: p.insert(fname);
					break;
			
			case 2: cout<<"\nEnter USN whose record details are to be searched for: ";
					cin>>key;
					p.search(fname,key); 
					break;
				
			case 3: p.del(fname);
					break;

			case 4: exit(0);
	
			default: cout<<"\nInvalid choice!";
		}
	}
	return 0;
}
