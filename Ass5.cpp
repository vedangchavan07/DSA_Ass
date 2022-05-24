#include <iostream> 
#include <string.h> 
using namespace std; 
 
struct node{     char keyword[20];     char meaning[20];     node *left; 
    node *right; 
}; 
 
class dictionary{ public: 
    node *root;     void create();     void display(node *);     void displayAscending(node *); 
    void displayDescending(node *); 
 
    void insert(node *root, node *temp);     int search(node *, char[]);     int update(node *, char[]);     node *del(node *, char[]); 
    node *min(node *); 
}; 
 
void dictionary ::create() 
{     char ch; 
 
    do 
    { 
        node * temp = new node;         cout << "\nEnter Keyword: ";         cin >> temp->keyword;         cout << "\nEnter Meaning: "; 
        cin >> temp->meaning; 
 
        temp->left = NULL; 
        temp->right = NULL; 
 
if (root == NULL) 
        { 
            root = temp; 
        }         else 
        { 
            insert(root, temp); 
        } 
        cout<<"\nDo you want to continue? (Y/N) ";         cin>>ch; 
    } while (ch == 'Y' || ch == 'y'); 
} 
 
void dictionary ::insert(node *root, node *temp) 
{ 
    if (strcmp(temp->keyword, root->keyword) < 0) 
    { 
        if (root->left == NULL)             root->left = temp; 
        else 
            insert(root->left, temp); 
    } 
    else 
    { 
        if (root->right == NULL) 
            root->right = temp; 
        else 
            insert(root->right, temp); 
    } 
} 
 
void dictionary :: display(node *root){ 
    char ch; 
    int op; 
 
    do 
    { 
        cout<<"\n^^^^^^Display Operations ^^^^^^";         cout<<"\n1 . Ascending order \n2 . Descending order";         cout<<"\nEnter your choice: "; 
        cin>>op; 
 
        switch (op) 
        { 
case 1: 
            displayAscending(root); 
            break; 
         
        case 2: 
            displayDescending(root);             break;         default:             cout<<"Invalid option."; 
            break; 
        } 
        cout<<"\nDo you want to continue? (Y/N) ";         cin>>ch; 
    } while (ch=='y' || ch=='Y'); 
} 
 
void dictionary::displayAscending(node *root){ 
    if (root != NULL){         displayAscending(root->left);         cout << "\n Key Word: " << root->keyword;         cout << "\t Meaning: " << root->meaning; 
        displayAscending(root->right); 
    } 
} 
 
void dictionary ::displayDescending(node *root){ 
    if(root !=NULL){         displayDescending(root->right);         cout << "\n Key Word: " << root->keyword;         cout << "\t Meaning: " << root->meaning; 
        displayDescending(root->left); 
    } 
} 
 
int dictionary ::search(node *root, char k[20]){ 
    int c = 0;     while (root != NULL){ 
        c++; 
        if (strcmp(k, root->keyword) == 0){ 
            cout << "\nNo of Comparisons:" << c;             return 1; 
        } 
        if (strcmp(k, root->keyword) < 0)             root = root->left; if (strcmp(k, root->keyword) > 0) 
            root = root->right; 
    } 
    return -1; 
} 
 
int dictionary ::update(node *root, char k[20]){ 
    while (root != NULL){ 
        if (strcmp(k, root->keyword) == 0){ 
            cout << "\nEnter New Meaning of Keyword " << root->keyword<< " ";             cin >> root->meaning; 
            return 1; 
        } 
        if (strcmp(k, root->keyword) < 0)             root = root->left;         if (strcmp(k, root->keyword) > 0) 
            root = root->right; 
    } 
    return -1; 
} 
 
node *dictionary ::del(node *root, char k[20]){     node *temp; 
 
    if (root == NULL){ 
        cout << "\nElement No Found"; 
        return root; 
    } 
 
    if (strcmp(k, root->keyword) < 0){         root->left = del(root->left, k);         return root; 
    } 
    if (strcmp(k, root->keyword) > 0){         root->right = del(root->right, k); 
        return root; 
    } 
 
    if (root->right == NULL && root->left == NULL){         temp = root;         delete temp; 
        return NULL; 
    } 
    if (root->right == NULL){ temp = root; 
        root = root->left;         delete temp; 
        return root; 
    } 
    else if (root->left == NULL){         temp = root;         root = root->right;         delete temp; 
        return root; 
    } 
    temp = min(root->right);     strcpy(root->keyword, temp->keyword);     root->right = del(root->right, temp->keyword);     return root; 
} 
 
node *dictionary ::min(node *q){     while (q->left != NULL){ 
        q = q->left; 
    } 
    return q; 
} 
 
int main() 
{     int ch;     char op;     dictionary d; 
    d.root = NULL; 
 
    do 
    { 
        cout << "\n^^^^^^^^^^^^^ MENU ^^^^^^^^^^^^^\n1 . Create\n2 . Display\n3 . Search\n4 . Update\n5 . Delete\nEnter your choice: ";
         cin >> ch; 
        switch (ch) 
        { 
        case 1: 
            d.create();             break;         case 2: 
            if (d.root == NULL){ 
                cout << "\nDictionary is Empty."; 
            } 
            else{ 
                d.display(d.root); 
            }             break;         case 3: 
            if (d.root == NULL){ 
                cout << "\nDictionary is Empty."; 
            }             else{ 
                cout << "\nEnter the Keyword that you want to search: ";                 char k[20]; 
                cin >> k; 
 
                if (d.search(d.root, k) == 1) 
                    cout << "\nKeyword Found";                 else 
                    cout << "\nKeyword Not Found"; 
            }             break;         case 4: 
            if (d.root == NULL){ 
                cout << "\nDictionary is Empty."; 
            }             else{ 
                cout << "\nEnter the Keyword whose meaning you want to update: ";                 char k[20]; 
                cin >> k; 
                if (d.update(d.root, k) == 1) 
                    cout << "\nMeaning Updated";                 else 
                    cout << "\nKeyword Not Found"; 
            }             break;         case 5: 
            if (d.root == NULL){ 
                cout << "\nDictionary is Empty."; 
            }             else 
            { 
                cout << "\nEnter Keyword which u want to delete: ";                 char k[20];                 cin >> k;                 if (d.root == NULL){ 
                    cout << "\nKeyword not found."; 
                } 
                else{ 
                    d.root = d.del(d.root, k); 
                } 
            } 
            break; 
 
        default:             break; 
        } 
    cout<<"\nDo you want to visit main menu? (Y/N) ";     cin>>op; 
    } while (op == 'y' || op=='Y');     return 0; 
}