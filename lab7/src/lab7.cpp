//============================================================================
// Name        : ex7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class namedlist
{
	public: string buffer,l1[100];
			int i1;
	public:
		void load()
		{
			i1=0;
			fstream f1;
			f1.open("file1.txt",ios::in);
			while(!f1.eof())
			{
				getline(f1,buffer);
				cout<<buffer;
				l1[i1++]=buffer;
			}
			cout<<"\n";
			return;
		}
		
		void loading()
		{
			i1=0;
			fstream f1;
			f1.open("file2.txt",ios::in);
			while(!f1.eof())
			{
				getline(f1,buffer);
				cout<<buffer;
				l1[i1++]=buffer;
			}
		}

		string sort(string *l,int n)
		{
			int i,j;
			string temp;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(l[i]>l[j])
					{
						temp=l[i];		
						l[i]=l[j];	
						l[j]=temp;
					}
				}
			}
			for(i=0;i<n;i++)
			 cout<<l[i]<<"  ";
			return *l;
		}

		void cosequentialmatch(string l2[],int i2)
		{
			for(i=0;i<i1;i++)
			int i=0,j=0;
			 cout<<l1[i];
			for(i=0;i<i2;i++)
			 cout<<l2[i];
			while(i!=i1-1&&j!=i2-1)
			{		
				if(l1[i]<l2[j])
					i++;
				if(l1[i]==l2[j])
				{
					cout<<"String matched: ";
					cout<<l1[i]<<"\n";		
					i++; j++;
				}
				else
					j++;
			}
		}
};

int main()
{
	cout<<"test";
	//char* fname1,fname2;
	namedlist n1;
	namedlist n2;
	//cout<<"\nEnter the name of file1: ";
	//cin>>fname1;
	cout<<"test";
	n1.load();
	cout<<"test";
	*n1.l1=n1.sort(n1.l1,n1.i1);
	//cout<<"\nEnter the name of file2: ";
	//cin>>fname2;
	n2.loading();
	cout<<"test";
	*n2.l1=n2.sort(n2.l1,n2.i1);
	cout<<"test";
	n1.cosequentialmatch(n2.l1,n2.i1);
	cout<<"test"<<"\n";
	return 0;
}
