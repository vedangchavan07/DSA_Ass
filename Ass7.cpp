#include <iostream> 
using namespace std; 
 
int adjacency_matrix[50][50] = {0, 0}; 
 
void displayMatrix(int city_num, string arr[]) 
{ 
    for (int i = 0; i < city_num; i++)         cout << "\t" << arr[i] << "\t"; 
    for (int i = 0; i < city_num; i++) 
    { 
        cout << "\n"              << arr[i]; 
        for (int j = 0; j < city_num; j++) 
            cout << "\t" << adjacency_matrix[i][j] << "\t";         cout << endl; 
    } 
} 
 
int main() 
{ 
    cout<<"\n***** WELCEOME TO PRIM'S ALGORITHM *****";     cout << "\n\nEnter the total no. of Offices: ";     int n, u;     cin >> n; 
    string office_location[n]; 
    for (int i = 0; i < n; i++) 
    { 
        cout<< "\nOffice Code{"<<i<<"} |  Location: "; 
        cin >> office_location[i]; 
    } 
 
    cout << "\n\n**** Displaying Office Location ****" << endl;     
    
    for (int i = 0; i < n; i++) 
        cout << "\nOffice {" << i<<"} present in "<<office_location[i]<<" city."<<endl;      
    for (int i = 0; i < n; i++) 
    { 
        for (int j = i + 1; j < n; j++) 
        { 
            cout << "\nEnter the distance between Office present in City " << office_location[i] << " and " <<"City "<< office_location[j] << " : "; 
            cin >> adjacency_matrix[i][j]; 
            adjacency_matrix[j][i] = adjacency_matrix[i][j]; 
        } 
    } 
 
    cout<<"\n**** Displaying Graph using Adjacency Matrix ****"<<endl;     
    displayMatrix(n, office_location); 
 
    int no_edge;     int visit[n]; 
 
    for (int i = 0; i < n; i++)
    { 
        visit[i] = 0; 
    } 
 
    no_edge = 0; 
 
    visit[0] = true; 
 
    int x; //  row number 
    int y; //  col number 
 
    cout<<"\n\n**** Minimum Spanning Tree ****"<<endl; 
 
    cout << "Edge" 
         << "  : " 
         << "Weight";     cout << endl;     int minimumCost=0; 
    while (no_edge < n - 1) 
    { 
        int min = 999;         x = 0;         y = 0; 
 
        for (int i = 0; i < n; i++) 
        { 
            if (visit[i]) 
            { 
                for (int j = 0; j < n; j++) 
                { 
                    if (!visit[j] && adjacency_matrix[i][j]) 
                    { 
                        if (min > adjacency_matrix[i][j]) 
                        { 
                            min = adjacency_matrix[i][j];                             x = i;                             y = j; 
                        } 
                    } 
                } 
            } 
        } 
        cout << x << " - " << y << " :  " << adjacency_matrix[x][y];         cout << endl;         visit[y] = true;         no_edge++; 
        minimumCost+=adjacency_matrix[x][y]; 
    } 
 
    cout<<"\nMinimum cost of the Tree is: "<<minimumCost<<"\n"<<endl; 
 
    return 0; 
}