#include <iostream>
#include <stack> 
using namespace std; 
 
class Node 
{ 
public:     char data; 
    Node *left, *right; 
 
    Node(char data) 
    { 
        this->data = data;         this->left = NULL; 
        this->right = NULL; 
    } 
}; 
 
class StackNode  
{ 
public:     Node *treeNode; 
    StackNode *next; 
 
    StackNode(Node *treeNode) 
    { 
        this->treeNode = treeNode; 
        next = NULL; 
    } 
}; 
 
class ExpressionTree  
{ 
private: 
    StackNode *top; 
 
public: 
    ExpressionTree() 
    { 
        top = NULL; 
    } 
 
    void deleteTree(Node *);     void push(Node *);     Node *pop();     Node *peek();     void insert(char);     bool isDigit(char);     bool isOperator(char);     void buildTree(string); 
    void postOrderIterative(Node *); 
}; 
 
void ExpressionTree :: deleteTree(Node *root){ 
    if (root==NULL) 
    { 
        return; 
    } 
    deleteTree(root->left);     deleteTree(root->right); 
    cout<<"\n Deleted Node. "<<root->data;     free(root); 
} 
 
void ExpressionTree::push(Node *ptr) 
{ 
    if (top == NULL)         top = new StackNode(ptr);     else 
    { 
        StackNode *nptr = new StackNode(ptr); 
        nptr->next = top; 
        top = nptr; 
    } 
} 
 
Node *ExpressionTree ::pop() 
{ 
    if (top == NULL) 
    { 
        cout << "Underflow" << endl; 
    } 
    else 
    { 
        Node *ptr = top->treeNode; 
        top = top->next; 
        return ptr; 
    } 
} 
 
Node *ExpressionTree ::peek() 
{ 
    return top->treeNode; 
} 
 
void ExpressionTree ::insert(char val) 
{ 
    if (isDigit(val)) 
    { 
        Node *nptr = new Node(val); 
        push(nptr); 
    } 
    else if (isOperator(val)) 
    { 
        Node *nptr = new Node(val);         nptr->left = pop();         nptr->right = pop(); 
        push(nptr); 
    } 
    else 
    { 
        cout << "Invalid Expression" << endl; 
        return; 
    } 
} 
 
bool ExpressionTree ::isDigit(char ch) 
{ 
    return ch >= '0' && ch <= '9'; 
} 
 
bool ExpressionTree ::isOperator(char ch) 
{ 
    return ch == '+' || ch == '-' || ch == '*' || ch == '/'; 
} 
 
void ExpressionTree ::buildTree(string eqn) 
{ 
    for (int i = eqn.length() - 1; i >= 0; i--)         insert(eqn[i]); 
} 
 
void ExpressionTree ::postOrderIterative(Node *ptr) 
{ 
    stack<Node *> s1, s2; 
 
    s1.push(ptr); 
    Node *node; 
 
    while (!s1.empty()) 
    { 
        node = s1.top();         s1.pop(); 
        s2.push(node); 
 
        if (node->left!=NULL)             s1.push(node->left);         if (node->right) 
            s1.push(node->right); 
    } 
 
    while (!s2.empty()) 
    { 
        node = s2.top();         s2.pop(); 
        cout << node->data << " "; 
    } 
} 
 
int main() 
{     string s;     char ch; 
    int op; 
    ExpressionTree et; 
     x: 
    cout<<"\n\n****** MENU ******";     cout<<"\n1. Enter Prefix Expression and Traverse";     cout<<"\n2. Delete Tree";     cout<<"\n3. Exit";     cout<<"\n\nEnter your choice: ";     cin>>op; 
    if(op==1){ 
        cout<<"\nEnter your string: "; 
        cin>>s;         et.buildTree(s); 
        cout << "\nTraversing the trees using Iterative Postorder: ";         et.postOrderIterative(et.peek()); 
    } 
    if(op==2){ 
        et.deleteTree(et.peek()); 
    } 
    if(op==3){ 
        return 0; 
    } 
    goto x; 
 
    return 0; 
}