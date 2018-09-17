#include <cstdlib>
#include <iostream>
#include<conio.h>

using namespace std;

class linklist
{
private:
      struct node
      {
             int info;
             node *next;
      };
      node *head, *temp, *cur;
      int count;
public:
       void menu();
      linklist();
      void insertion();
      void deletion();
      void searching();
      void printing();
      void emptiness();
      ~linklist();
};
linklist::linklist(){
         head=temp=cur=NULL;
         count=0;
}
linklist::~linklist(){
          delete head,temp,cur;
}
void linklist::insertion(){
                      if(head==NULL)
                      {
                                    temp=new node;
                                    temp->next=NULL;
                                    head=temp;
                                    cout<<"\nEnter value for new node :";
                                    cin>>temp->info;
                                    return;
                      }
                      int choice;
                      cout<<"\n1: At Start";
                      cout<<"\n2: At End";
                      cout<<"\n3: After specified Location";
                      cout<<"\nWhere you want to add new node :";
                      cin>>choice;
                      
                      switch(choice)
                      {
                                    case 1:
                                          temp=new node;
                                          temp->next=head;
                                          head=temp;
                                          break;
                                    case 2:
                                         cur=head;
                                         while(cur->next!=NULL)
                                         {
                                                                cur=cur->next;
                                         }
                                         temp=new node;
                                         temp->next=NULL;
                                         cur->next=temp;
                                         break;
                                    case 3:
                                         int pos,chk=1;
                                         cout<<"\nAfter which location you want to add new node :";
                                         cin>>pos;
                                         cur=head;
                                         while(chk!=pos)
                                         {
                                                        cur=cur->next;
                                                        chk++;
                                         }
                                         temp=new node;
                                         temp->next=cur->next;
                                         cur->next=temp;
                                         break;
                                    
                          
                      }
                      cout<<"\nEnter value for new node :";
                      cin>>temp->info;
}                      
                      
void linklist :: menu()
{
     cout << "\nLinklist Menu";
     cout << "\n-------------" ;
     cout << "\ni: Insertion" ;
     cout << "\nd: Deletion";
     cout << "\ns: Searching";
     cout << "\np: Printing";
     cout << "\ne: Emptiness";
} 

void linklist :: printing()
{
     temp = head;
     if(head==NULL)
          cout << "\nList is empty?" ;
     else
     {
          cout << "\ninteger are: ";
               
                        while(temp!=NULL)
                            {
                                 cout << " " << temp->info;
                                 temp = temp->next;
                                 }
                        cout << endl;
                        }
     }
int main()
{
    char ch, opt;
    linklist function;
    do
    {
             function.menu();
             cout << endl << "\tenter choice: ";
             cin >> opt;
             switch(opt)
              {
                     case 'i':
                             function.insertion();
                             break;
                    // case 'd':
                      //   
                        //     function.deletion();
                          //   break;
                             
                  //   case 's':
                              
                    //          function.searching();
                     //         break;
                     case 'p':
                          
                            function.printing();
                            break;
                   //  case 'e':
                     //         function.emptiness();
                      //        break;
                     default:
                         cout << "\tenter correct option...! " << endl;
                     }
         cout << endl << "\tdo u perform more opertion [y : n] : ";
         cin >> ch;
         }while((ch=='y')||(ch=='Y'));
    getch();
}
