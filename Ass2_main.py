from record import Record 
from Ass2_linear_probing import HashTable 
from Ass2_double_hashing import DoubleHashTable 
 
def input_record():     
    record = Record()     
    name = input("Enter name: ")     
    number = int(input("Enter contact number: "))     
    record.set_name(name)     
    record.set_number(number)     
    return record 
     
choice1 = 0 
 
while(choice1 != 3): 
    print("*"*8+" MAIN-MENU "+ "*"*8)     
    print("    1. Linear Probing") 
    print("    2. Double Hashing") 
    print("    3.     Exit") 
    print("*"*27) 
 
    choice1 = int(input("Enter your choice: "))     
    if choice1>3: 
        print("Invalid Choice. \n") 
 
    if choice1 == 1:         h1 = HashTable()         
    choice2 = 0         
    while(choice2 != 4):             print("*"*8+" MENU "+ "*"*8)             
    print("     1. Insert")             
    print("     2. Search") 
    print("     3. Display")             
    print("4. Return to Main-Menu") 
    print("*"*22) 
 
    choice2 = int(input("Enter your choice: "))             
    if choice2>4: 
        print("Invalid choice. \n") 
 
        if(choice2==1): 
            record = input_record()                 
            h1.insert(record) 
 
        elif(choice2 == 2): 
            record = input_record() 
            position = h1.search(record) 
 
        elif(choice2 == 3):                 h1.display() 
 
         
 
    elif choice1 == 2:         h2 = DoubleHashTable()         
    choice2 = 0         
    while(choice2 != 4):             print("*"*8+" MENU "+ "*"*8)             
    print("1. Insert")             
    print("2. Search")             
    print("3. Display")             
    print("4. Return to Main-Menu") 
    print("*"*22) 
 
    choice2 = int(input("Enter your choice: "))             
    if choice2>4: 
        print("Invalid choice. \n") 
 
    if(choice2==1):                 
        record = input_record() 
        h2.insert(record) 
 
    elif(choice2 == 2): 
        record = input_record() 
        position = h2.search(record) 
 
    elif(choice2 == 3):                 
        h2.display()