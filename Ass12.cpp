#include <iostream> 
#include <fstream> 
using namespace std; 
 
class student 
{ 
public: 
    int roll; 
    char name[20];     char addr[20];     char div; 
    string filename = "main.dat"; 
 
    void gInfo();     void pInfo();     void mod();     void apnd();     void display();     void search();     void del(); 
}; 
 
void student::gInfo() 
{ 
    cout << "Roll Number->"; 
    cin >> roll; 
cout << "Division->"; 
cin >> div;     cout << "Name->";     cin >> name;     cout << "Address->";     cin >> addr; 
} 
 
void student::pInfo() 
{ 
    cout << roll << "\t\t\t" << div << "\t\t\t" << name << "\t\t\t" << addr << "\n"; 
} 
 
void student::apnd() 
{ 
    ofstream outfile;     student stud;     outfile.open("main.dat", ios::app | ios::binary);     stud.gInfo();     outfile.write((char *)&stud, sizeof(stud));     outfile.close(); 
} 
 
void student::display() 
{ 
    ifstream infile;     student stud;     char ch;     infile.open("main.dat", ios::out | ios::binary); while (infile.read((char *)&stud, sizeof(stud))) 
{ 
        stud.pInfo(); 
    } 
    infile.close();     cout << endl; 
} 
 
void student::search() 
{ 
    ifstream infile;     student stud;     char ch;     int srroll, flag = 0; 
    cout << "Enter Roll number To Be Searched: "; 
    cin >> srroll; 
    infile.open("main.dat", ios::out | ios::binary);     while (infile.read((char *)&stud, sizeof(stud))) 
    { 
        if (stud.roll == srroll) 
        { 
            stud.pInfo();             flag = 1;             break; 
        } 
    } 
    if (flag == 0) 
    { 
        cout << "Roll Number Not Found !!" << endl; 
} 
infile.close();     cout << endl; 
} 
 
void student::del() 
{ 
    fstream mainfile;     fstream tempfile("temp.dat");     student stud; 
    string str;     int srroll; 
    cout << "Enter Roll number To Be Deleted: "; 
    cin >> srroll; 
    mainfile.open("main.dat", ios::in | ios::binary);     tempfile.open("temp.dat", ios::out | ios::binary); 
 
    while (!mainfile.eof()) 
    { 
 
        mainfile.read((char *)&stud, sizeof(stud)); 
 
        if (mainfile) 
        { 
 
            if (stud.roll == srroll) 
            { 
                cout << "The deleted record is \n"; 
                stud.pInfo(); 
            } 
            else 
            { 
                tempfile.write((char *)&stud, sizeof(stud)); 
            } 
        } 
    } 
 
    mainfile.close();     tempfile.close(); 
     
    remove("main.dat"); 
 
    rename("temp.dat", "main.dat"); 
} 
 
 
void student::mod(){ 
     fstream mainfile;     fstream tempfile("temp.dat");     student stud; 
    string str;     int srroll; 
    cout << "Enter Roll number To Be Modified: "; 
    cin >> srroll; 
    mainfile.open("main.dat", ios::in | ios::binary);     tempfile.open("temp.dat", ios::out | ios::binary); 
 
    while (!mainfile.eof()) 
    { 
        mainfile.read((char *)&stud, sizeof(stud)); 
 
        if (mainfile) 
        { 
 
            if (stud.roll == srroll) 
            { 
                stud.gInfo(); 
                tempfile.write((char *)&stud, sizeof(stud)); 
            } 
            else 
            { 
                tempfile.write((char *)&stud, sizeof(stud)); 
            } 
        } 
    } 
 
    mainfile.close();     tempfile.close(); 
     
    remove("main.dat"); 
 
    rename("temp.dat", "main.dat"); 
 
} 
 
 
int main() 
{     char choice; 
    do 
    { 
        int ch; 
        student stud; 
        cout << "\n---FILE OPERATIONS---\n1.Append Data\n2.Display \n3.Search Data\n4.Delete Data\n5.Modify Data\n\n Enter your choice: "; 
        cin >> ch; 
 
        switch (ch) 
        { 
        case 1:             stud.apnd();             break;         case 2:             stud.display();             break;         case 3:             stud.search();             break;         case 4:             stud.del();             break;         case 5:             stud.mod();             break;         default:             break; 
        } 
        cout << "Do you want to continue!? "; 
        cin >> choice; 
    } while (choice = 'y' || choice == 'Y'); 
 
    return 0; 
} 
