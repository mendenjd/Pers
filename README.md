# EECE-2080C-Lab10
Class: Engineering Data Structures<br/>
Date: 7/26/18<br/>
Contributors: Jonathan Menden, Kevin Ruggiero, Quintin Vosper

### Objectives
    
    To build a HashTable that includes a group of determined functions(get,insert,remove). We also had to implement the code 
    in a way that used the ASCII vlaue of pushed values to complete the code. Part 2 of Task 1 asks toimplement a menu 
    into the program that allows the user to use these funstions. For Tasks 3 and 4 we are asked to document the 
    time for the add and search functions. 
    
### Analysis:

    The user should be able to choose between inserting an item and removing an item from the hashtable. Our program begins at a max 
    size of 100 values as instructed in the directions.  
    
### Notes:
    
    Our program does not push nullptr like the directions ask for the remove and get functions. We tried multple ways to implemet the       code but we couldn't determine a way to return nullptr. The code works and finds/removes the searched item but doesn't return       
    nullptr.  Also for Tasks 3 and 4 to view the time taken for the functions you must scroll up because there is a invalid pointer     
    error that only exists after the program has finished running.
    
    
### Ouptut of Menu:
    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 1
    Enter element to be inserted: 3

    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 2
    Enter element to be searched: 3
    3 Found!
    3

    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 3
    Enter the element to be deleted: 3
    3 Deleted!

    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 2
    Enter element to be searched: 3
    Value Not Found


    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 3
    Enter the element to be deleted: 3
    No Element found! 

    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 4
    The Number of Elements in the Table are: 0

    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 1
    Enter element to be inserted: 3

    1.Insert element into the table
    2.Search element from the key
    3.Delete element at a key
    4.Size of the table
    5.Exit
    Enter your choice: 4
    The Number of Elements in the Table are: 1
    
    
### Group Member Contributions:

    Jon - Implementation of the hashtable and its functions.
    
    Kevin - Assisted with implementation of specific functions within the hashtable file. Assisted with
    implementation of tasks 3 and 4. Writing of README.md.
    
    Quintin - Helped with changes to the hash table. Assisted with structure of code.
