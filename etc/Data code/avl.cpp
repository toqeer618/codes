// tree.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<conio.h>
using namespace std;

    struct node
    {
        int info;
        node *left,*right;
    };

class tree
{
    node *temp;
    node*temp1;
    public:
     node *root;
    bool y;
    int hight;
    void insert(node *temp,int num);
    void in_order(node*temp);
    void delet(int,node *temp);
    void find_hight(node *temp);
    int find_balance(node *temp);
    char menue();
    tree()
    {
        hight=0;
        y=false;
        temp=temp1=root=NULL;
    }
};
int tree::find_balance(node *temp)
{
    int h=0;
    int h1=0;
    if(temp->left!=NULL)
           {
                  hight++;
          find_hight(temp->left);
          h=hight;
      }
       hight=0;
      if(temp->right!=NULL)
      {
          hight++;
          find_hight(temp->right);
      }
   else 
   {
       hight=0;
   }
  
    h1=h-hight;
    hight=0;
    cout<<" the balance factor of "<<temp->info<<" is "<<h1<<endl;
    return h1;
}
node * successor(int num,node *temp2)
{
    if(temp2->left->left==NULL)
        return temp2;
    else 
        return successor(num,temp2->left);
}
void tree::delet(int key,node*temp)
{
    if(temp==NULL)
    {
        cout<<"\n\n\tTHE TREE IS EMPTY!!!!"<<endl;
        return;
    }
    if((temp->info==key) && (temp->left==NULL) && (temp->right==NULL))
    {
        delete temp;
        temp=NULL;
        root=NULL;
        return;
    }
    

    //for no child
    if(temp->left!=NULL)
    {
        if((temp->left->info==key) && (temp->left->left==NULL) && (temp->left->right==NULL))
        {
            delete temp->left;
            temp->left=NULL;
            return;
            
        }

    }
    
    if(temp->right!=NULL)
    {
        if((temp->right->info==key) && (temp->right->left==NULL) && (temp->right->right==NULL))
        {
            delete temp->right;
            temp->right=NULL;
            return;
        }
    }

    //for one child case 2
    if((temp->left!= NULL) && (key==temp->left->info))
    {
        if((temp->left->left!=NULL) && (temp->left->right==NULL))
        {
            temp1=temp->left;
            temp->left=temp1->left;
            delete temp1;
            return;
        }
        if((temp->left->left==NULL) && (temp->left->right!=NULL))
        {
            temp1=temp->left;
            temp->left=temp1->right;
            delete temp1;
            return;
        }
    }
    if((temp->right!=NULL) && (key==temp->right->info))
    {
        if((temp->right->left!=NULL) && (temp->right->right==NULL))
        {
            temp1=temp->right;
            temp->right=temp1->left;
            delete temp1;
            return;
        }
        if((temp->right->left==NULL) && (temp->right->right!=NULL))
        {
            temp1=temp->right;
            temp->right=temp1->right;
            delete temp1;
            return;
        }
    }
    if( (temp->info==key) && (( (temp->left!=NULL) && (temp->right==NULL) ) || ( (temp->left==NULL)&&(temp->right!=NULL) ) ))
    {
        if(temp->left!=NULL)
        {   
            temp1=temp->left;
            temp->info=temp->left->info;
            temp->left=temp1->left;
            temp->right=temp1->right;
            delete temp1;
            return;


            
        }
        if(temp->right!=NULL)
        {
            temp1=temp->right;
            temp->info=temp->right->info;
            temp->left=temp1->left;
            temp->right=temp1->right;
            delete temp1;
            return;

        }
    }



    //case 3 node having two childs
    if((temp->info==key) && (temp->left!=NULL) && (temp->right!=NULL))
    {
        if(temp->right->left==NULL)
        {
            temp->info=temp->right->info;
            delet(temp->right->info,temp);
                return;
        }
        if(temp->right->left!=NULL)
        {
        node *immed_success=successor(key,temp->right);
        temp->info=immed_success->left->info;
        delet((immed_success->left->info),immed_success);
        return;
        }
    }

    if(key>(temp->info))
        delet(key,(temp->right));
    else if(key<(temp->info))
        delet(key,(temp->left));
}
char tree::menue()
{
    char m;
    cout<<"\n\n\ta.TO INSERT"
        <<"\n\n\tb.TO PRINT IN in ORDER"
        <<"\n\n\tc.TO DELETE "
        <<"\n\n\te.exit";
    cin>>m;
    return m;
}

void tree::in_order(node*temp)
{
   if(temp==NULL)
     {    cout<<" Tree is empty.\n";       
            return;   
     }
   if( temp->left!=NULL )
             in_order(temp->left);
   cout<<temp->info<<" ";
   if( temp->right!=NULL )
             in_order(temp->right);

}
void tree::insert(node*temp,int num )
{
    int bal_factor=0;

   if(temp==NULL)
   {
       temp=new node;
       temp->info=num;
       temp->left=temp->right=NULL;
       root=temp;
       return  ;
   }
   if(temp->info==num)
   { 
       cout<<"number is repeated "<<endl;
       
   }
   else if(temp->left==NULL  && num<temp->info)
   {
       temp->left=new node;
       temp->left->info=num;
       temp->left->left=temp->left->right=NULL;
       
   }
   else if( temp->right==NULL && num>temp->info)
   {
       temp->right=new node;
       temp->right->info=num;
       temp->right->left=temp->right->right=NULL;
   }
   else if(temp->left!=NULL && num<temp->info)
   {
       insert(temp->left,num);
   }
   
   else if(temp->right!=NULL && num>temp->info)
   {
    insert(temp->right,num);
    
   }
    if(y==1)
   {
       if(num>temp->info)
           temp->right=temp1;
       else if(num<temp->info)
           temp->left=temp1;
   }
   bal_factor=find_balance(temp);
        
       
    if((bal_factor>1) || (bal_factor<-1))
    {
        if(num>temp->info)
        {
            //case four
            if(num>temp->right->info)
            {
                temp1=temp->right;
                temp->right=temp1->left;
                temp1->left=temp;
                
                if(temp==root)
                root=temp1;
                else
                {
                    temp=temp1;
                }
                y=1;
                cout<<"left rotate only!!!!!!!!!!!!"<<endl;
                return;
            }
            //right left rotation, case 3
            else if(num<temp->right->info)
            {
                //right rotate
                temp1=temp->right;
                temp->right=temp1->left;
                
                temp1->left=temp->right->right;
                temp->right->right=temp1;
                //left rotat
                temp1=temp->right;
                temp->right=temp1->left;
                temp1->left=temp;
                
                if(temp==root)
                root=temp1;
                else
                temp=temp1;
                cout<<"right left rotation$$$$$$$$"<<endl;
                y=1;
                return;
            }
        }
        if(num<temp->info)
        {
            //case one
            if(num<temp->left->info)
            {
                temp1=temp->left;
                temp->left=temp1->right;
                temp1->right=temp;
                
                if(temp==root)
                root=temp1;
                else
                  temp=temp1;
                cout<<"only right rotation "<<endl;
                y=1;
                return;
            }
        }
            //case 2
            if(num>temp->left->info)
            {
                temp1=temp->left;
                temp->left=temp1->right;
                temp1->right=temp->left->left;
                temp->left->left=temp1;

                temp1=temp->left;
                temp->left=temp1->right;
                temp1->right=temp;
                
                if(temp==root)
                root=temp1;
                else
                      temp=temp1;
                y=1;
                cout<<"lefth right rotation "<<endl;
                return;

            }
        }

   return ;
}
void tree::find_hight(node*temp)
{
    if((temp->left==NULL) && (temp->right==NULL))
        return;
    if(temp->left!=NULL)
    {
        hight++;
        find_hight(temp->left);
    }
    if(temp->right!=NULL)
    {
                hight++;
        find_hight(temp->right);
    }
    if((temp->left!=NULL) && (temp->right!=NULL))
    {
        hight--;
    }

}
int main()
{
    tree t;
    int n,key;
    char choice=0;
    char ch,c;

    
    do
    {
        char choice=t.menue();
        if(choice=='a')
        {
            cout<<"enter number ended with 0"<<endl;
            do
            {
                cin>>n;
                t.insert(t.root,n);
                t.y=false;
                cout<<"\n\n\tDO WANT TO INSET ANOTHER?"<<endl;
                cin>>c;
            }
            while(c=='y');
            system("cls");
        }
        else if(choice=='b')
            t.in_order(t.root);
        else if(choice=='c')
        {
            do
            {
            cout<<"\n\n\tENTER THE NUMBER YOU WANT TO DELETE:";
            cin>>key;
            t.delet(key,t.root);
            cout<<"\n\n\tDO YOU WANT TO DELETE ANOTHER?:";
             ch=getche();
            }
            while(ch=='y');
        }

    }
    while(choice!='e');
    
    getch();
}
