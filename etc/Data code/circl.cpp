circular ring list
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
      node *head, *temp, *temp1;
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
         head=temp=temp1=NULL;
}
linklist::~linklist(){
          while(temp!=NULL)
          {
                           temp1=temp;
                           temp=temp->next;
                           delete temp1;
          }              
          delete head,temp,temp1;
}
void linklist::insertion(){
                      temp=head;
                      if(head==NULL)
                      {
                                    head=new node;
                                    head->next=head;
                                    temp=head;
                                    cout<<"\nEnter value for new node :";
                                    cin>>temp->info;
                                    return;
                      }
                      int key;
                      cout<<"\nEnter Key :";
                      cin>>key;
                      while(temp->info!=key && temp->next!=head)
                      {
                                            temp=temp->next;
                      }
                      if(temp->info==key)
                      {
                                         temp1= new node;
                                         temp1->next=temp->next;
                                         temp->next=temp1;
                                         cout<<"\nEnter value for new node :";
                                         cin>>temp1->info;
                                         }
                      else
                          cout<<"\nNo Result Found";
                                            
}                      
                      
void linklist :: menu()
{
     system ("cls");
     cout << "\nLinklist Menu";
     cout << "\n-------------" ;
     cout << "\n1: Insertion" ;
     cout << "\n2: Deletion";
     cout << "\n3: Searching";
     cout << "\n4: Printing";
     cout << "\n5: Emptiness";
} 

void linklist :: printing()
{
     temp = head;
     if(head==NULL)
          cout << "\nList is empty?" ;
     else
     {
          cout << "\ninteger are: ";
               
                        while(temp!=head)
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
}
