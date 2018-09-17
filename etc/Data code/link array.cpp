#include <iostream>
#include <conio.h>
using namespace std;
class list
{
private:
     int *temp, *head;
     int length, size,location;
public:
     list();
     ~list();
     void option();
     void get();
     void view();
     void update();
     void tlength();
     void back();
     void next();
     void current();
     void start();
     void end();
     void add();
     void remove();
     void search();
};

list :: list()
{
     temp = head = NULL;
     length = size = location = 0;
     cout << "\t List Using Array";
     cout << "\nEnter the total list size: ";
     cin >> size;
     temp = new int[size];
     head = temp;
}

void list :: option()
{
     system("cls");
     cout << "\n=======================";
     cout << "\n\tList Menu";
     cout << "\n=======================";
     cout << "\n1 : Update List Element";
     cout << "\n2 : Length List Element";
     cout << "\n3 : Back List ELement";
     cout << "\n4 : Next List Element";
     cout << "\n5 : Start Element of List";
     cout << "\n6 : End Element of List";
     cout << "\n7 : Add List Element";
     cout << "\n8 : Remove List Element";
     cout << "\n9 : View All List Elements";
     cout << "\n10 : Search List Element";
     cout << "\n11 : Current Cursor Position";
}

void list :: get()
{
     cout << "\nHow Many Integer do u Want to Enter: ";
     cin >> length;
     if(size >= length)
     {
          for(int i=1; i<=length; i++)
          {
               cout << "\nEnter "<<i<<" integer: ";
               cin >> *temp;
               ++temp;
          }         
     }
     else
     {
          cout << "\nYou enter Unvalid list size";       
     }
     temp=head+length-1;
}

void list :: update()
{
     int update;
	 temp = head;
	 cout << "\nEnter the location where u want to add: ";
     cin >> location;
	 if((location<length) && (location>=0))
	 {
          cout<<"\nEnter value on that location "<<location<<" : ";
          cin >> update;
          temp = head + location-1;
          *temp = update;
     }
     else
		  cout << "\nInvalid Location";
}

void list :: start()
{
     temp = head;
     cout << "\nFirst element of List is " << *temp;
}

void list :: view()
{
     temp = head;
     if(length == 0)
     {cout << "\nNo element in List ...!";
     return;}
     else{
     cout << "\nElement of  array are " ;
     for(int i=0; i<length; i++)
     {
             cout << *temp << " ";
             ++temp;
     }
     cout << endl;}
}

void list :: end()
{
     temp = head + length - 1;
     cout << "\nLast element of List is " << *temp;
}

void list :: tlength()
{
     cout << "\nThe length of List is " << length;
}

void list :: current()
{
     cout << "\nCurrent position of Cursor is " << *temp;
}

void list :: remove()
{
     temp=head;
     cout << "\nEnter location where u want to remove: ";
     cin >> location;
     if(location<=length && location>=0)
     {
          for(int i=location; i<length; i++)
          {
               *(temp+i-1)=*(temp+i);
          }
     length--;
     temp = head+location;
     }
     else
         cout<<"\nInvalid Location";
}

void list :: add()
{
     if(length==size)
     {
                     cout<<"\nList is Already Full.....!";
     }
     else{
          temp=head+length;
             cout << "\nEnter location where u want to add: ";
             cin >> location;
             if(location<=length && location>=0)
             {
                  for(; temp>=head+location-1; temp--)
                  {
                       *(temp+1)=*temp;
                  }
             length++;
             temp=head+location-1;
             cout<<"\nEnter New value for "<<location<<" :";
             cin>>*temp;
             }
             else
                 cout<<"\nInvalid Location";
             }
}
void list :: search()
{
     temp=head;
     int seach;
     cout << "\nEnter integer which u wants of search:" ;
	 cin >> seach;
	 for(int i=0; i<=length; i++)
	 {
		if(*(temp+i)==seach)
		{   
			location=i+1;
			break;
		}
    }
    cout << "\nLocation of integer is =" << location;
}

void list :: next()
{
     if(temp==head+length-1)
     {
          cout << "\nCursor is already at last location...!"; 
     }
     else if(temp!=head+length-1)
     {
          temp = ++temp;
          cout << "\nThe next element of List is " << *temp;
     }
}

void list :: back()
{
     if(temp==head)
     {
            cout << "\nCursor is already at first location...!";
     }
     else if(temp!=head)
     {
            temp = --temp;
            cout << "\nThe back element of List is " << *temp;
     }
}

list :: ~list()
{
     delete []temp;
     delete temp, head;
}

int main()
{
    char ch;
    int opt;   
    list ingr;  
    ingr.get();
    
    do
    {
         ingr.option();
         cout << "\nEnter opertion which u perform with array: ";
         cin >> opt;    
         switch(opt)
         {
                    case 1:
                         ingr.update();
                         break;
                    case 2:
                         ingr.tlength();
                         break;
                    case 3:
                         ingr.back();
                         break;
                    case 4:
                         ingr.next();
                         break;
                    case 5:
                         ingr.start();
                         break;
                    case 6:
                         ingr.end();
                         break;
                    case 7:
                         ingr.add();
                         break;
                    case 8:
                         ingr.remove();
                         break;
                    case 9:
                         ingr.view();
                         break;
                    case 10:
                         ingr.search();
                         break;
                    case 11:
                         ingr.current();
                         break;
                    default:
                         cout << "\nEnter correct option...! ";
         }
         cout << "\nDo u perform more operation [y : n] : ";
         cin >> ch;
    }while((ch=='y')||(ch=='Y'));
}
