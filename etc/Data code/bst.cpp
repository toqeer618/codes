pehla code avl ka tha j wala bst ka ha
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
int tnodes=0;
struct node
{
  int info;
  node *left,*right;
}*cur,*pre;

class bst
{
   private :
	    node *temp;
   public  :
	    node *root;
	    int number;
	    bst();
	    void options();
	    void insertion(node *);
	    void deletion(node *,node*);
	    void in_order(node *);
	    void totalnodes(node *);
};
int main()
{
  system("cls");

  char ch;
  bst obj;
  while( 1 )
  {
    obj.options();
    ch=getch();
    switch(ch)
     {
       case '1':
		system("cls");
		cout<<"\n Enter number to add in a tree... \n";
		cin>>obj.number;
		obj.insertion( obj.root );
		break;
       case '2':
		system("cls");
		cout<<"\n Enter number to delete from the tree... \n";
		cin>>obj.number;
		obj.deletion( obj.root,obj.root );
		break;
       case '3':
		system("cls");
		obj.in_order(obj.root);
		break;
		case '4':
		system("cls");
		obj.totalnodes(obj.root);
		cout<<"Total nodes in tree are :"<<tnodes;
		tnodes=0;
		break;
       case '5':
		exit(0);
		break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------

bst :: bst()
{
  root=temp=NULL;
}
//--------------------------------------------------------

void bst :: insertion(node *temp)
{
  if( root==NULL )
   {
     temp=new node;
     temp->info = number;
     temp->left=NULL;
     temp->right=NULL;
     root=temp;
     return;
   }

  if( temp->info==number )
   {
      cout<<" \n Given number is already present in tree.\n";
      return;
    }
if(temp->info > number)
   {
      if( temp->left!=NULL )
       {
		 insertion(temp->left);
		 return;
       }
      else
       {
	 temp->left=new node;
	 temp->left->info = number;
	 temp->left->left=NULL;
	 temp->left->right=NULL;
	 return;
       }
   }
if(temp->info < number)
   {
      if( temp->right!=NULL )
       {
		 insertion(temp->right );
		 return;
       }
      else
       {
	 temp->right=new node;
	 temp->right->info = number;
	 temp->right->left=NULL;
	 temp->right->right=NULL;
	 return;
       }
   }

} //--------------------    Insertion Function  Ends    --------------------------
void bst:: deletion(node* temp,node *pretemp)
{
     if( root==NULL )
   {
     system("cls");
     cout<<"\nBst is already NULL ";
     return;
   }
   if( temp->info==number)
   {
                          if(temp->left==NULL && temp->right==NULL)
                          {
                                              if(temp==root)
                                                 root=NULL;
                                              delete temp;
                                              if(pretemp->left==temp)
                                                  pretemp->left=NULL;
                                              else
                                                  pretemp->right=NULL;
                                              return;
                                              }
                          if(temp->left!=NULL && temp->right!=NULL)
                          {
                                             cur=temp->right;
                                             if(cur->left!=NULL)
                                             {
                                                                while(cur->left!=NULL)
                                                                {
                                                                pre=cur;
                                                                cur=cur->left;}
                                                                temp->info=cur->info;
                                                                pre->left=NULL;
                                                                delete cur;
                                                                cur=NULL;
                                             }
                                             else {
                                                  temp->info=cur->info;
                                                  temp->right=cur->right;
                                                  delete cur;
                                                  cur=NULL;
                                                  }
                                             return;
                                             }
                          if(temp->left!=NULL)
                          {
                                              if(temp==root)
                                              {
                                                            delete root;
                                                            root =temp->left;
                                                            }
                                              else{
                                                   pretemp->left=temp->left;
                                                   delete temp;
                                                   }
                          return;
                          }
                          if(temp->right!=NULL)
                          {
                                              if(temp==root)
                                              {
                                                            delete root;
                                                            root =temp->right;
                                                            }
                                              else{
                                                   pretemp->right=temp->right;
                                                   delete temp;
                                                   }
                          return;
                          }                                                                                    
   }
   else if(temp->info > number)
   {
                deletion(temp->left,temp);
   }
   else if(temp->info < number)
   {
                deletion(temp->right,temp);
   }
}
void bst :: options()
{
 cout<<"\n\n ************** Select Option *****************.\n";
 cout<<"\n Enter any of choices.\n";
 cout<<"\n 1 : Adding (inserting) node in BST.\n";
 cout<<"\n 2 : Deleting node from BST.\n";
 cout<<"\n 3 : Print the whole BST .\n";
 cout<<"\n 4 : Total Nodes in BST .\n";
 cout<<"\n 5 : Quitting the Program.\n";
}//--------------------------------------------------------------
void bst :: in_order(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if( temp->left!=NULL )
    		 in_order(temp->left);
  cout<<temp->info<<"  ";
  if( temp->right!=NULL )
		 in_order(temp->right);
  return;
}
void bst :: totalnodes(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if( temp->left!=NULL )
    		 totalnodes(temp->left);
  if( temp->right!=NULL )
		 totalnodes(temp->right);
  tnodes ++;
  return;
}//----------------------------    PROGRAM ENDS HERE  ---------------------------------------
