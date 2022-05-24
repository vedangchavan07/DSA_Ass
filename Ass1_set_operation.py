class setpro: 
    def __init__(self,ec):    
        self.s = []      
        for i in range(ec):     
                e = int(input("\n    Enter the element: "))   
                self.s.append(e)      
                print("\n Set Successfully Initialized!") 
                print("\n******************************") 
 
 
    def add(self,e):     
        if e not in self.s:        
            self.s.append(e) 
            print("Added",e,"successfully!") 
 
    def trav(self):    
        print("\nSet: ",end=" ")   
        print(self.s) 
 
    def remov(self,a):    
        if a in self.s: 
            self.s.remove(a)     
        else: 
            print("Error:",a,"doesn't exist in the SET") 
 
    def sizeofset(self): 
        print("\nSize of the Set A is: ",len(self.s)) 
 
    def searchset(self,e):   
        n = 0     
        is_found=False    
        for i in self.s:     
                    if e == i: 
                        is_found=TRUE 
                    n = n+1 
 
        if(is_found==TRUE): 
            print("\n",e,"found at position:",n)     
        else: 
            print("\nElement not found") 
 
    def intersection(self,a): 
        q = []      
        for i in self.s:        
                for j in a:           
                        if i == j : 
                            q.append(i) 
                        break 
        print("\nIntersection of Set A and Set B: ",q) 
 
    def union(self,a): 
        for i in self.s:         
                for j in a:       
                    if i == j : 
                        a.remove(j) 
        q = self.s + a 
        print("\nUnion of Set A and Set B: ",q) 
 
    def difference(self,a):  
        diff=[]      
        for i in self.s:   
                if i not in a:    
                    diff.append(i) 
 
        print("\nDifference (Set A - Set B): ",diff) 
 
 
    def subset(self,a):   
        n = 0     
        for i in a : 
            for j in self.s:   
                if i == j:    
                    n+=1     
                    if n == len(a): 
                        print("\nSet B is subset of a Set A") 
        else: 
            print("\nSet B is not subset a of Set A") 
 
    def propersub(self,a):    
        if len(self.s)-1 >= len(a): 
            n = 0 
            for i in a: 
                for j in self.s:       
                    if i == j:         
                        n += 1 
            print("\nSet B is a Proper Subset of Set A") 
        else: 
            print("\nSet B is not a Proper Subset of Set A")
