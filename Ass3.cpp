#include <iostream>
using namespace std; 
 
struct node
{
    int data; 
    node *left, *right; 
}; 
 
class BinarySearchTree{ public: 
    node *root;     void create();     void insert(node *, node*);     void traverse(node *);     void recursiveInorder(node *);     void recursivePreorder(node *);     void recursivePostorder(node *);     int minData(node *);     void maxData(node *);     void globalSearch();     node * search(node *, int);     int height(node *);     void sw();     void swap(node *); 
    node *deleteNode(node *,int); 
 
    BinarySearchTree(){ 
        root = NULL; 
    } 
}; 
 
void BinarySearchTree::create(){     char ch; 
 
    do
    { 
        node *temp= new node;         cout<<"Enter data of node: ";         cin>>temp->data;         temp->left=NULL; 
        temp->right=NULL; 
 
        if(root==NULL){ 
            root=temp; 
        }         else{ 
            insert(root, temp); 
        } 
        cout<<"\nDo you want to insert more Nodes? (Y/N) ";         cin>>ch; 
    } while (ch=='y' ||  ch=='Y'); 
} 
 
void BinarySearchTree :: insert(node *root, node* temp)
{     
    if(temp->data<root->data)
    {         
        if(root->left==NULL){ 
        root->left=temp; 
    } 
    else{ 
            insert(root->left, temp); 
        } 
    } 
    else{ 
        if(root->right==NULL){ 
            root->right=temp; 
        } 
        else{ 
            insert(root->right,temp); 
        } 
    } 
} 
 
void BinarySearchTree:: recursiveInorder(node *root)
{ 
    if(root!=NULL)
    {         
        recursiveInorder(root->left);         
        cout<<root->data<<" ";
        recursiveInorder(root->right); 
    } 
} 
 
void BinarySearchTree :: recursivePreorder(node *root){ 
    if(root!=NULL){         cout<<root->data<<" ";         recursivePreorder(root->left); 
        recursivePreorder(root->right); 
    } 
} 
 
void BinarySearchTree :: recursivePostorder(node *root){     if(root!=NULL){         recursivePostorder(root->left);         recursivePostorder(root->right); 
        cout<<root->data<<" "; 
    } 
} 
 
void BinarySearchTree :: traverse(node *root)
{     
    int op; 
    char ch; 
 
    do 
    { 
 
        cout<<"***** Displaying Traversing Methods *****"; 
        cout<<"\n1. Inorder";         cout<<"\n2. Preorder";         cout<<"\n3. Postorder"; 
        cout<<"\nWhich traversing operation would you like to perform: ";         cin>>op; 
 
    switch (op) 
    { 
    case 1:         recursiveInorder(root); 
        break;     
    case 2:         recursivePreorder(root); 
        break;     
    case 3:         recursivePostorder(root); 
        break;     
        default: 
        cout<<"Check what you entered :( ";         break; 
    } 
    cout<<"\nDo you want to perform other traversing operations? (Y/N) ";     cin>>ch; 
    } while (ch == 'y' || ch=='Y'); 
} 
 
int BinarySearchTree :: minData(node *root)
{ 
    while (root->left!=NULL) 
    { 
        root=root->left; 
    } 
    cout<<root->data<<" "; 
    return root->data; 
} 
 
void BinarySearchTree :: maxData(node *root)
{ 
    while (root->right!=NULL) 
    { 
        root=root->right; 
    } 
    cout<<root->data<<" "; 
} 
 
void BinarySearchTree :: globalSearch()
{ 
    int op, key;     char ch; 
    node  * isFound; 
 
    do 
    { 
        cout<<"\n^^^^^^Search Operations ^^^^^^";         cout<<"\n1 . Smallest \n2 . Largest \n3 . Search Key";         cout<<"\nEnter your choice: "; 
        cin>>op;         switch (op) 
        { 
        case 1:             minData(root);             break;         
        case 2:             maxData(root);             break;         
        case 3:  
            cout<<"Enter the key to be searched: "; 
            cin>>key;             
            isFound = search(root, key);             
            if(isFound==NULL)
            { 
                cout<<"Key not found"; 
            }             
            else
            {                 
                cout<<"Key found"; 
            }             
            break;         
            default:             cout<<"Invalid option."; 
            break; 
        } 
 
        cout<<"\nDo you want to continue? (Y/N) ";         cin>>ch; 
    } while (ch=='y' || ch=='Y'); 
} 
 
node * BinarySearchTree :: search(node *root, int key)
{ 
    if(root==NULL)
    { 
        return NULL; 
    } 
    else if(root->data==key)
    { 
        return root; 
    } 
    else if (key<root->data) 
    { 
        return search(root->left,key); 
    } 
    else if (key>=root->data) 
    { 
        return search(root->right, key); 
    } 
} 
 
int BinarySearchTree :: height(node * root){ 
    if(root==NULL)
    { 
        return 0; 
    } 
    else
    { 
        return max(height(root->left),height(root->right))+1; 
    } 
} 
 
 void BinarySearchTree::sw()  
 {   
    if(root==NULL) 
    {  cout<<"\nTree does not exist "; 
} 
else 
    { 
       swap(root); 
    } 
} 
 
void BinarySearchTree::swap(node *q) 
{ 
   if(q->left!=NULL)    swap(q->left);    
   if(q->right!=NULL)    swap(q->right);    
   node *t=q->left;    
   q->left=q->right; 
   q->right=t; 
}  
 
node * BinarySearchTree ::  deleteNode(node *root, int x){ 
    if(root == NULL) return root; 
 
    if(root->data>x) 
        root->left = deleteNode(root->left,x);     
    else if (root->data<x) 
    { 
        root->right = deleteNode(root->right, x); 
    }     
    else 
    { 
        if(root->left==NULL)
        {             
            node *temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if(root->right==NULL){             node *temp=root->left;             delete root; 
            return temp; 
        } 
        else{ 
            int temp = minData( root -> right);             root -> data = temp; 
            root -> right = deleteNode(root -> right , temp); 
        } 
    return root; 
    }  
} 
 
int main()
{     
    int ch, key,height;     
    char op; 
    BinarySearchTree a; 
 
    do 
    { 
        cout<<"\n^^^^^^^^^^^^^ MENU ^^^^^^^^^^^^^";         cout<<"\n1 . Create a Binary Tree \n2 . Traverse  \n3 . Search  \n4 . Delete \n5 . Swap \n6 . Height Of BST \n7 . Enter Your choice: ";         cin>>ch; 
 
        switch (ch) 
        { 
        case 1: 
            a.create();             break;         case 2: 
            a.traverse(a.root); 
            break;         case 3: 
            a.globalSearch(); 
            break;         case 4: 
            cout<<"Enter the key of that is to be deleted: ";             cin>>key; 
            a.deleteNode(a.root, key); 
            break;         case 5: 
            a.swap(a.root); 
            break;         case 6: 
            height = a.height(a.root); 
            cout<<" Height / Number of nodes on the longest path: ";             cout<<height;             break;         default:     
            cout<<"Invalid choice."; 
            break; 
        } 
 
cout<<"\nDo you want to visit main menu? (Y/N) "; 
    cin>>op; 
 
    } while (op=='y' || op=='Y'); 
    return 0; 
}