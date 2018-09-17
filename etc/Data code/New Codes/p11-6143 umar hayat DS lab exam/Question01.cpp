#include <iostream>
using namespace std;
int firstloop=0;
int equalsize=0;
void bubblesearch(int [],int);
void main()
{
	
	int *sequence;
	int n=0;
	int size=0;
	cout<<"ENTER your size  : ";
	cin>>size;
	sequence=new int[size];
	for(int i=0;i<size;i++)
	{	
		cout<<"ENTER YOUR Number : ";
			cin>>sequence[i];
	}
	equalsize=size;
	bubblesearch(sequence,0);
	cout<<"The sorted list is : "<<endl;
	for(int i=0;i<size;i++)
	cout<<"\t"<<sequence[i];
	cout<<endl;
    system("pause");
}

void bubblesearch(int sel[],int start)
{
	if(firstloop==equalsize)
		return;
	if(start==equalsize)
	{
		firstloop++;
		start=firstloop;
	}
	if(sel[firstloop]>sel[start])
	{
		int temp=sel[firstloop];
		sel[firstloop]=sel[start];
		sel[start]=temp;
	}
	bubblesearch(sel,start+1);
}
