/*
 *C++ Program to Implement Hash Tables
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <chrono>
#include <ctime>
using namespace std;
const int TABLE_SIZE = 3000;

int getRandomNumber(int maxVal) {
    return random() % maxVal;
}
 
/*
 * HashEntry Class Declaration
 */
class HashEntry
{
    public:
        int key;
        int value;
        HashEntry(int key, int value)
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
        HashTable()
	{
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        /*
         * Hash Function
         */
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
        /*
         * Insert Element at a key
         */
	void Insert(int key, int value)
	{
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key)
            {
                hash = HashFunc(hash + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
	}
        /*
         * Search Element at a key
         */
        int Search(int key)
	{
	    int  hash = HashFunc(key);
	    while (table[hash] != NULL && table[hash]->key != key)
	    {
	        hash = HashFunc(hash + 1);
	    }
	    if (table[hash] == NULL)
	        return -1;
	    else
	        return table[hash]->value;
        }
 
        /*
         * Remove Element at a key
         */
        void Remove(int key)
	{
	    int hash = HashFunc(key);
	    while (table[hash] != NULL)
	    {
	        if (table[hash]->key == key)
	            break;
	        hash = HashFunc(hash + 1);
	    }
            if (table[hash] == NULL)
	    {
                cout<<"No Element found at key "<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Element Deleted"<<endl;
        }
        ~HashTable()
	{
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};
    double computeRunTimeInsert(), computeRunTimeSearch();
    HashTable hash;
int main(){
    int key;
    string value, removed;
    int choice;
    double timelapse = 0, timelapse2 = 0;
    for(int i=0; i<20; i++) {
        timelapse = computeRunTimeInsert();
        timelapse2 = computeRunTimeSearch();
        cout << i+1 << ". " << timelapse << endl;
        cout << i+1 << " Search. " << timelapse2 << endl;
    }
    return 0;
}
double computeRunTimeInsert(){
        int key = 0, value = 0;
        auto start = chrono::system_clock::now();
        // BEGIN: Code for run-time analysis
        for(int y = 0; y < 100; y++){
            key = value = getRandomNumber(9999);
            ::hash.Insert(key,value);
        }
        // END
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsedTimeSeconds = end-start;
        return elapsedTimeSeconds.count()*1000;
    }
    double computeRunTimeSearch(){
        int key = 0, value = 0;
        auto start = chrono::system_clock::now();
        // BEGIN: Code for run-time analysis
        for(int y = 0; y < 100; y++){
            key = value = getRandomNumber(9999);
            ::hash.Search(key);
        }
        // END
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsedTimeSeconds = end-start;
        return elapsedTimeSeconds.count()*1000;
    }