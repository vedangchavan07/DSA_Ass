from record import Record 
 
class HashTable: 
 
    def __init__(self): 
        self.size = int(input("Enter the size of the hash table: "))         
        self.table = list(None for i in range(self.size)) 
        self.element_count = 0 
        self.comparisons = 0 
 
    def is_full(self): 
        if self.element_count==self.size: return True 
        else: return False 
 
    def hash_function(self,element): 
        return element%self.size 
     
    def insert(self,record):         
        if self.is_full(): 
            print("HashTable is Full!!") 
            return False 
 
        is_stored = False 
         
        position = self.hash_function(record.get_number()) 
 
        if self.table[position]==None:             
            self.table[position]=record             
            print("Contact number of "+record.get_name()+" is at position: "+str(position))             
            is_stored=True             
            self.element_count += 1 
        else: 
            print("Collision occured for "+record.get_name()+"'s contact number at position: "+str(position))             
        while self.table[position]!=None: 
                position += 1                 
                if position >=self.size-1: 
                    position=0 
 
        self.table[position]=record             
        print("Contact number of "+record.get_name()+" stored at postition: "+str(position))             
        is_stored=True 
        self.element_count+=1 
         
        return is_stored 
 
    def search(self, record): 
        is_found=False 
        position = self.hash_function(record.get_number())         
        self.comparisons=0 
         
        if(self.table[position]!=None): 
             
            if (self.table[position].get_name() == record.get_name() and self.table[position].get_number() != record.get_number()):                 is_found = False 
 
            if (self.table[position].get_name() != record.get_name() and self.table[position].get_number() != record.get_number() ):                 is_found = False 
 
            if(self.table[position].get_name() == record.get_name() and self.table[position].get_number() == record.get_number()):                is_found=True 
            print("Contact number found at position: "+str(position)+" | Total comparisons are: "+str(1))                  
            return position 
        else: 
            position+=1                 
            self.comparisons+=1                 
            if position >=self.size-1: 
                    position=0 
             
            while self.table[position] != None or self.comparisons <= self.size:                     
                if(self.table[position].get_name() == record.get_name() and self.table[position].get_number() == record.get_number()):                         is_found=True                         
                self.comparisons+=1 
                print("Contact number found at position: "+str(position)+" | Total comparisons are: "+str(self.comparisons)) 
                return position 
                 
                position+=1 
 
                if position>=self.size-1: 
                        position=0 
 
                 
                self.comparisons+=1 
             
        if is_found==False:             print("Record not found.")             
        return is_found 
 
     
    def display(self):         
        print("\n")         
        for i in range(self.size):             
            print("Hash Value{"+str(i)+"}" + "\t\t" + str(self.table[i])) 
         
        print("The number of phonebook records in the Table are : " + str(self.element_count))
