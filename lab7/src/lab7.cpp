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
	public: string buffer,l1[100],l2[100];
			int i1,i2,i;
	public:
		void load()
		{
			i1=-1;
			fstream f1;
			f1.open("1.txt",ios::in);
			while(!f1.eof())
			{
				getline(f1,buffer);
				//cout<<buffer;
				l1[i1++]=buffer;
			}
			cout<<i1;
			cout<<"\nloaded file: \n";
			for(i=-1;i<i1-1;i++)
				cout<<l1[i]<<"\t";
	cout<<"\n";
			return;
		}
		
		void loading()
		{
			i2=-1;
			fstream f1;
			f1.open("2.txt",ios::in);
			while(!f1.eof())
			{
				getline(f1,buffer);
				//cout<<buffer;
				l2[i2++]=buffer;
			}
			cout<<i2<<endl;
			cout<<"\nloaded file: \n";
			for(i=-1;i<i2-1;i++)
				cout<<l2[i]<<"\t";
			cout<<"\n";
			return;
		}

		void sort1()//string *l,int n)
		{
			int i,j;
			string temp;
			/*for(i=0;i<n;i++)
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
			cout<<"\nsorted file is:\n";
			for(i=0;i<n;i++)
			 cout<<l[i]<<"\t"; */ 
			for(i=-1;i<i1-1;i++)
			{
				for(j=i+1;j<i1;j++)
				{
					if(l1[i]>l1[j])
					{
						temp=l1[i];		
						l1[i]=l1[j];	
						l1[j]=temp;
					}
				}
			}
			cout<<"\nsorted file is:\n";
			for(i=-1;i<i1-1;i++)
			 cout<<l1[i]<<"\t";
			
		}
		
		void sort2()
		{	
			int i,j;
			string temp;
			for(i=-1;i<i2-1;i++)
			{
				for(j=i+1;j<i2;j++)
				{
					if(l2[i]>l2[j])
					{
						temp=l2[i];		
						l2[i]=l2[j];	
						l2[j]=temp;
					}
				}
			}
			cout<<"\nsorted file is:\n";
			for(i=-1;i<=i2-1;i++)
			 cout<<l2[i]<<"\t";
		}

		void cosequentialmatch(string l2[],int i2)
		{
			int i,j,c=0;
			//for(i=0;i<i1;i++)
			 //cout<<l1[i];
			//for(i=0;i<i2;i++)
			 //cout<<l2[i]; 
			i=-1; j=-1;
			cout<<"i1 in match"<<i1;
			cout<<"i2 in match"<<i2;
			while(i<=i1&&j<=i2)
			{		
				if(l1[i]<l2[j])
					i++;
				if((l1[i]==l2[j])&&(l1[i]!="\n"))
				{
					cout<<"\nString matched: ";
					cout<<l1[i]<<"\n";		
					i++; j++;
					c++;
				}
				else
					j++;
			} 
			/*for(i=0;i<i1;i++)
				for(j=0;j<i2;j++)
					if(l1[i]==l2[j])
					{	
						c++;
						cout<<"\nString matched: ";
						cout<<l1[i];		
					}*/
			cout<<"\nNumber of strings matched: "<<c;
		}
};

int main()
{
	//char* fname1,fname2;
	namedlist n1;
	namedlist n2;
	//cout<<"\nEnter the name of file1: ";
	//cin>>fname1;
	n1.load();
	//n1.sort(n1.l1,n1.i1);
	n1.sort1();
	//cout<<"\nEnter the name of file2: ";
	//cin>>fname2;
	n2.loading();
	n2.sort2();
	//n2.sort(n2.l1,n2.i1);
	//cout<<"test";
	n1.cosequentialmatch(n2.l2,n2.i2);
	//cout<<"test"<<"\n";
	return 0;
}
