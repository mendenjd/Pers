/*
 *C++ Program to Implement Hash Tables
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 100;
 
/*
 * HashEntry Class Declaration
 */
class HashEntry
{
    public:
        int key;
        string value;
        HashEntry(int key, string value)
        {
            this->key = key;
            this->value = value;
        }
};
 
/*
 * HashTable Class Declaration
 */
class HashTable
{
    private:
        HashEntry **table;
    public:
        int size = 0;
        HashTable(){
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        int HashAscII(string value){
            int sum = 0;
            int AsciiCount = 0;
            for (unsigned int i = 0; i < value.length(); i++) {
                AsciiCount = int(value[i]);
                sum += AsciiCount;
            }
            return sum % TABLE_SIZE;
        }
        /*
         * Hash Function
         */
        int HashFunc(int key){
            return key % TABLE_SIZE;
        }
        /*
         * Insert Element at a key
         */
    	void Insert(int key, string value){
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key){
                hash = HashFunc(hash + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
            size++;
    	}
        /*
         * Search Element at a key
         */
        string Search(int key){
    	    int hash = HashFunc(key);
    	    while (table[hash] != NULL && table[hash]->key != key)
    	    {
    	        hash = HashFunc(hash + 1);
    	    }
    	    if (table[hash] == NULL){
    	        cout << "Value Not Found" << endl;
    	        return ""; //should be nullptr 
    	    }
    	    else{
    	        cout << table[hash]->value << " Found!" << endl; 
    	        return table[hash]->value;
    	    }
        }
 
        /*
         * Remove Element at a key
         */
        string Remove(int key){
    	    int hash = HashFunc(key);
    	    string temp; 
    	    while (table[hash] != NULL)
    	    {
    	        if (table[hash]->key == key)
    	            break;
    	        hash = HashFunc(hash + 1);
    	    }
                if (table[hash] == NULL)
    	    {
                    cout<<"No Element found! "<<endl;
                    return "";//should be nullptr
                }
                else
                {
                    temp = table[hash]->value;
                    delete table[hash];
                    size--;
                    cout << temp << " Deleted!" << endl;
                    return "";//should be table[hash]->value
                }
            }
            int sizeofHash()
            {
                return size;
            }
        ~HashTable(){
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};
/*
 * Main Contains Menu
 */
int main()
{
    HashTable hash;
    int key;
    string value, removed;
    int choice;
    while (1)
    {   cout << endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element at a key"<<endl;
        cout<<"4.Size of the table"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            key = hash.HashAscII(value);
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"Enter element to be searched: ";
            cin>>value;
            key = hash.HashAscII(value);
            cout << hash.Search(key) << endl;
            break;
        case 3:
            cout<<"Enter the element to be deleted: ";
            cin>>key;
            key = hash.HashAscII(value);
            removed = hash.Remove(key);
            break;
        case 4:
            cout << "The Number of Elements in the Table are: " << hash.sizeofHash() << endl;
            break;
        case 5:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}