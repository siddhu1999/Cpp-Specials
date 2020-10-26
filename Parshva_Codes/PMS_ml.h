#include<iostream>
#include<string.h>
#include<fstream>
#include<sstream>
using namespace std;
//*************************************************************************************
// For counting the number of rows in and csv file...

int row_size(char p[])   // char type because ifstream needs char array type
{
	string temp;    // temporary string variable for use in getline
	int count=0;    // counter variable .m.
	ifstream inf(p,ios::in);
	if(!inf.is_open()){        // shows and error if no such file is available .
		cout<<"error while opening the file\n";
		exit(0);
	}
	while(!inf.eof())
	{
		getline(inf,temp);   // takes one by one line .
		++count;
	}
	return(count-1);
}
//****************************************************************************************
// for counting the number of column in the csv file ...
int col_size(char p[])
{
	string temp,word;
	int count=0;
	ifstream inf(p,ios::in);
	if(!inf.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}
	getline(inf,temp);   // takes the first line of the file .
	stringstream s(temp);   // break the taken line into words .
	while(getline(s,word,','))
	{
		count++;
	}
	return(count);
}
//*******************************************************************************************
// for removing all the garbage value in the array and making all the value '0' .

template <class x>
void null(x a[],int n)     // here n is for passing the size of the array( sizeof ) as the argument .
{
	int i=0;
	n=n/(sizeof(x)); 
	while(i!=n)
	{
		a[i]=0;
		i++;
	}
}
//*************************************************************************************
