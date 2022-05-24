from Ass1_set_operation import setpro
 
print("\n             SET A")
def create(): 
    print("\n****** Initializing Set ******")     
    n = int(input("\n Enter number of elements: ")) 
    S = setpro(n) 
    return S 
 
S1 = create() 
 
while (True): 
    print("\n------------ MENU ------------\n")     
    print(" 1. Add Element\n 2. Remove Element\n 3. Size\n 4. Search Element\n 5. Intersection of SETS\n 6. Union of SETS\n 7. Difference of SETS\n 8. Subset\n 9. Proper Subset\n10. Traverse\n11. Exit") 
    a = int(input("\nEnter your choice: ")) 
 
    if a == 1: 
        e = int(input("\nEnter the number you want to add in the set: ")) 
        S1.add(e)
        S1.trav()
    elif a == 2: 
        e = int(input("\nEnter the element you want to remove: ")) 
        S1.remov(e) 
        S1.trav()     
    elif a == 3: 
        S1.sizeofset() 
 
    elif a == 4: 
        e = int(input("\nEnter the number you want to search: "))         
        S1.searchset(e) 
    elif a == 5:         
        print("\n             SET B")         
        S2 = create() 
        S1.intersection(S2.s) 
 
    elif a == 6:         
        print("\n             SET B")         
        S2 = create() 
        S1.union(S2.s) 
 
    elif a == 7:         
        print("\n             SET B")         
        S2 = create() 
        S1.difference(S2.s) 

    elif a == 8:         
        print("\n             SET B")         
        S2 = create() 
        S1.subset(S2.s) 
 
    elif a == 9:         
        print("\n             SET B")         
        S2 = create() 
        S1.propersub(S2.s) 
 
    elif a == 10:         
        print("\n  ---- Set A ----") 
        S1.trav() 
 
    elif a == 0:         
        break     

    elif a==11:         
        break 