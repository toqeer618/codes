#include <iostream>
#include <conio.h>
using namespace std;

class queue
{
private:
     int *front, *rear,*temp;
     int tsize, length;
public:
     queue();
     ~queue();
     void menu();
     void enqueue();
     void dequeue();
     void display();
};

queue :: queue()
{
     front = rear = NULL;
     length = tsize = 0;
     cout << "\t Queues Using Array";
     cout << "\nEnter the total Queue size: ";
     cin >> tsize;
     temp = new int[tsize];
}

void queue :: menu()
{
     system("cls");
     cout << "\n=======================";
     cout << "\n\tQueue Menu";
     cout << "\n=======================";
     cout << "\n1 : Enqueue";
     cout << "\n2 : Dequeue";
     cout << "\n3 : Display";
     cout << "\n4 : exit";
}

void queue :: enqueue()
{
   
}

void queue :: dequeue()
{

}

void queue :: display()
{
     
}
queue :: ~queue()
{
     delete []temp;
     delete front, rear;
}

int main()
{
    char ch;
    int opt;   
    queue q;    
    while(1)
    {
         q.menu();
         cout << "\nEnter opertion which u perform with array: ";
         cin >> opt;    
         switch(opt)
         {
                    case 1:
                         q.enqueue();
                         break;
                    case 2:
                         q.dequeue();
                         break;
                    case 3:
                         q.display();
                         break;
                    case 4:
                         return;
                         break;
                    default:
                         cout << "\nEnter correct option...! ";
         }
         }
}
