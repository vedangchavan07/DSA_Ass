from record import Record 
 
class DoubleHashTable:     
    def __init__(self): 
        self.size = int(input("Enter the size of the hash table: "))         
        self.table = list(None for i in range(self.size)) 
        self.element_count = 0 
        self.comparisons = 0 
 
    def is_full(self):         
        if self.element_count == self.size: 
            return True         
        else: 
            return False 
     
    def h1(self, element): 
        return element % self.size 
     
    def h2(self, element):         return 5-(element % 5) 
     
    # method to resolve collision     
    def double_hashing_collision(self, record): 
        position_found = False 
        i = 1         
        while i <= self.size: 
            new_position = (self.h1(record.get_number()) + i*self.h2(record.get_number())) % self.size             
            if self.table[new_position] == None: 
                position_found = True                 
                break          
            else:                 
                i += 1 
        return position_found, new_position 
 
def insert(self, record): 
    if self.is_full(): 
        print("Hash Table Full!!") 
        return False 
            
        position_found = False 
        
        position = self.h1(record.get_number()) 
            
        if self.table[position] == None:             
            self.table[position] = record             
            print("Contact number of "+record.get_name()+" is at position: "+str(position))             
            position_found=True 
            self.element_count += 1 
        else: 
            print("Collision has occured for " + record.get_name() + "'s contact number at position " + str(position) + " finding new position.")             
        while not position_found: 
                position_found, position = self.double_hashing_collision(record)                 
                if position_found: 
                    self.table[position] = record                     
                self.element_count += 1 
                print("Phone number of " + record.get_name() + " is at position " + str(position)) 
  
        return position_found 
     
    def search(self, record): 
        found = False 
        position = self.h1(record.get_number())         
        self.comparisons =0 
 
        if(self.table[position] != None): 
 
            if (self.table[position].get_name() == record.get_name() and self.table[position].get_number() != record.get_number()):                 found = False 
                 
            if (self.table[position].get_name() != record.get_name() and self.table[position].get_number() != record.get_number()):                 found = False 
 
            if(self.table[position].get_name() == record.get_name()): 
                found=True 
                print("Contact number found at position {}".format(position) + "| Total comparisons: " + str(1)) 
                return position 
             
            else: 
                self.comparisons+=1  
                i = 1                 
                while i <= self.size: 
                    position = (self.h1(record.get_number()) + i*self.h2(record.get_number())) % self.size                     
                    if(self.table[position] != None):                         
                        if self.table[position].get_name() == record.get_name():                             found = True                             
                        self.comparisons+=1 
                        break 
                        
                    elif self.table[position].get_name() == None: 
                            found = False 
                            break                                                     
                    else: 
                            self.comparisons+=1                             
                            i += 1 
                             
 
        if found: 
            print("Phone number found at position {}".format(position) + " and total comparisons are " + str(i+1))             
            return found         
        else: 
            print("Record not Found") 
            return found           
         
 
     
    def display(self):         print("\n")         
    for i in range(self.size): 
            print("Hash Value{"+str(i)+"}" + "\t\t" + str(self.table[i]))         
            print("The number of phonebook records in the Table are : " + str(self.element_count))