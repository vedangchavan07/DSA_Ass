#include <iostream> 
#include <queue> 
using namespace std; 
 
int adjacent_matrix[50][50] = {0, 0}; 
int visited[50] = {0}; 
 
void displayMatrix(int ctnum, string arr[]) 
{ 
    for (int i = 0; i < ctnum; i++)         cout << "\t" << arr[i] << "\t"; 
    for (int i = 0; i < ctnum; i++) 
    { 
        cout << "\n"              << arr[i];         for (int j = 0; j < ctnum; j++)             cout << "\t" << adjacent_matrix[i][j] << "\t";         cout << endl; 
    } 
} 
 
void depthFirstSearch(int s, int ctnum, string arr[]) 
{     visited[s] = 1;     cout << arr[s] << " "; 
    for (int i = 0; i < ctnum; i++) 
    { 
        if (adjacent_matrix[s][i] && !visited[i]) 
            depthFirstSearch(i, ctnum, arr); 
    } 
} 
 
void breadthFirstSearch(int s, int ctnum, string arr[]) 
{ 
    bool visited[ctnum];     for (int i = 0; i < ctnum; i++)         visited[i] = false;     int v; 
    queue<int> bfsq;     if (!visited[s]) 
    { 
        cout << arr[s] << " "; 
        bfsq.push(s);         visited[s] = true; 
        while (!bfsq.empty()) 
        { 
            v = bfsq.front(); 
            for (int i = 0; i < ctnum; i++) 
            { 
                if (adjacent_matrix[v][i] && !visited[i]) 
                { 
                    cout << arr[i] << " ";                     visited[i] = true; 
                    bfsq.push(i); 
                } 
            } 
            bfsq.pop(); 
        } 
    } 
} 
 
void depthFirstSearch2(int s, int ctnum, string arr[]) 
{     visited[s] = 1;     for (int i = 0; i < ctnum; i++) 
    { 
        if (adjacent_matrix[s][i] && !visited[i]) 
            depthFirstSearch2(i, ctnum, arr); 
    } 
} 
 
int isConnected(int u, int n, string arr[]) 
{ 
 
    for (int i = 0; i < n; i++)         visited[i] = 0;     depthFirstSearch2(u, n, arr); 
    for (int i = 0; i < n; i++) 
    { 
        if (!visited[i]) 
        { 
            return 0; 
        } 
    } 
    return 1; 
} 
int main() 
{ 
    int ctnum, u, ch; 
    char choice; 
 
    cout << "\n\t\t---- WELCOME ----\t\t\n";     cout << "\nPlease Enter the Number Of Cities-> ";     cin >> ctnum; 
    string cts[ctnum]; 
 
    for (int i = 0; i < ctnum; i++) 
    { 
        cout << "Enter " << i << " city -> "; 
        cin >> cts[i]; 
    } 
 
    cout << "\nYour cities are-> " << endl; 
    for (int i = 0; i < ctnum; i++) 
        cout << "City " << i << ": " << cts[i] << endl;     for (int i = 0; i < ctnum; i++) 
    { 
        for (int j = i + 1; j < ctnum; j++) 
        { 
            cout << "Enter distance between " << cts[i] << " and " << cts[j] << " -> ";             cin >> adjacent_matrix[i][j]; 
            adjacent_matrix[j][i] = adjacent_matrix[i][j]; 
        } 
    } 
    cout << endl; 
 
    do 
    { 
        cout << "\n---SEARCH OPERATIONS---\n1.Display Adjecency Matrix\n2.Traversal Operation(Using DFS)\n3.Traversal Operation(Using BFS)\n4.Check Graph Connection\n\n Enter your choice: ";         cin >> ch; 
        int a; 
 
        switch (ch) 
        { 
 
        case 1: 
            displayMatrix(ctnum, cts); 
            break;         case 2: 
            cout << "Please Specify the Starting Vertex-> ";             cin >> u; 
            cout << "<----DFS Traversal Result-----> \n";             depthFirstSearch(u, ctnum, cts); 
            cout << endl;             break;         case 3: 
            cout << "Please Specify the Starting Vertex: ";             cin >> u; 
            cout << "<----BFS Traversal Result-----> \n";             breadthFirstSearch(u, ctnum, cts); 
            cout << endl;             break;         case 4: 
            a= isConnected(u, ctnum, cts);             if(a==1){ 
                cout<<"Graph is connected!"<<endl; 
            } 
            else if(a==0){ 
                cout<<"Graph is not connected!"<<endl; 
            }             break;         default:             break; 
        } 
        cout << "Do you want to continue!? ";         cin >> choice; 
    } while (choice = 'y' || choice == 'Y'); 
 
    return 0; 
}
