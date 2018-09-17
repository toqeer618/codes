data cbt meaning is complete binary tree
#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;
struct node
{
    double info;
    node *left;
    node *right;
    double level;
};
class tree
{
private:
    double g_hight;
    
    double num_nodes;
public:
    node *root,*temp;
    bool y;
    double number;
    char menue();
    double find_hight(node *temp);
    double x;
    void insert(node *temp);
    void pre_order(node*temp);
    tree()
    {
        //y=false;
        number=x=0;
        root=temp=NULL;
        g_hight=0;
        num_nodes=0;
    }
};
void tree::pre_order(node*temp)
{
    if(temp==NULL)
    {
        cout<<"\n\n\tTREE IS EMPTY ";
        return;
    }
    cout<<temp->info<<" ";
    if(temp->left!=NULL)
        pre_order(temp->left);
     if(temp->right!=NULL)
        pre_order(temp->right);
}

void tree::insert(node *temp)
{
    if(temp==NULL)
    {
        cout<<"first node "<<endl;
        temp=new node;
        temp->info=number;
        temp->level=g_hight;
        temp->left=temp->right=NULL;
        root=temp;
        num_nodes++;
        cout<<temp->level;
        return;
        
    }
     
    x=(pow(2,(g_hight+1)))-1;
    if(x==num_nodes)
    {
        g_hight++;
        temp=root;
    }
    if(temp->left==NULL)
    {
        cout<<"khadija@@@@@@@@"<<endl;
        temp->left=new node;
        temp->left->info=number;
        temp->left->left=temp->left->right=NULL;
        num_nodes++;
        temp->left->level=g_hight;
        y=true;
        return;
    }
    if((temp->left!=NULL) && (temp->right==NULL))
    {
        cout<<"snay!!!!!!!!!!"<<endl;
        temp->right=new node;
        temp->right->info=number;
        temp->right->left=temp->right->right=NULL;
        temp->right->level=g_hight;
        num_nodes++;
        y=true;
        return;
    }
     
     if((temp->right!=NULL)&&(temp->left!=NULL)&&(((g_hight)-(temp->level))!=1))
    {
        insert(temp->left);
        if(y==0)
        {
            insert(temp->right);
            return;
        }
        else 
            return;
     }
     else
        return;
}
char tree::menue()
{
    char m;
    cout<<"\n\n\ta.TO INSERT"
        <<"\n\n\tb.TO PRINT IN PRE ORDER"
        <<"\n\n\tc.TO PRINT IN IN ORDER"
        <<"\n\n\td.TO PRINT IN POST ORDER"
        <<"\n\n\tf.TO DELETE "
        <<"\n\n\tg.TO PRINT THE DUBLICATED ENTERD "
        <<"\n\n\te.exit";
    cin>>m;
    return m;
}
int main()
{
    tree t;
    char choice=NULL;
    char c;

    
    do
    {
        char choice=t.menue();
        if(choice=='a')
        {
            cout<<"enter number "<<endl;
            do
            {
                cin>>t.number;
                t.insert(t.root);
                //loc_hight=0;
                t.y=false;
                cout<<"\n\n\tDO WANT TO INSET ANOTHER?"<<endl;
                cin>>c;
            }
            while(c=='y');
            system("cls");
        }

        else if(choice=='b')
            t.pre_order(t.root);
    }
    while(choice!='e');
    
    getch();
    
}
