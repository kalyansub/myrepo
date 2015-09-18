// Simple Hash Table class methods : implement insert and find methods...

#include "hash.h"
#include <iostream>
#include <cassert>

// Implementation of the thread concurrency helpers

// Ctor
//////////////////////////////////////////////////
MutexLock::MutexLock()
{
    pthread_mutex_init(&m_MutexHandle, NULL);
    pthread_mutex_lock(&m_MutexHandle);
}

//MutexUnlock : private method ivoked by dtor
//////////////////////////////////////////////////
void MutexLock::MutexUnlock(void)
{
    pthread_mutex_unlock( &m_MutexHandle );
}

// Dtor
//////////////////////////////////////////////////
MutexLock::~MutexLock()
{
    MutexUnlock();
}


// Implementation of the HashTable methods:

// Ctor
//////////////////////////////////////////////////
HashTable::HashTable()
{
    if(tableEntry != NULL)
    {
        for(int i = 0; i < TABLESIZE; ++i)
        {
            assert(tableEntry != NULL);
            tableEntry[i] = 0;
            cout << "tableEntry[" << i << "] = " << tableEntry[i] << " \n";
        }
    }
    else
    {
        cout << "Memory clear operation failed for tableEntry!" << "\n";
    } 
}

// Dtor
//////////////////////////////////////////////////
HashTable::~HashTable()
{
    for ( int i = 0; i < TABLESIZE; ++i )
    {
        Item* item = tableEntry[i];
        while ( item != NULL )
        {
            Item* tmpItem = item;
            item          = item->m_next;
            delete tmpItem;
        }
    }
}

// Find : search hash table for a given string given its number
// Input parameters  : key, an integer, the number to match on
// Output parameters : tEntry, a reference to a table entry
// Return Value      : true - the string has been found, the data
//                            is available in the output parameter
//                      false - string not found
//////////////////////////////////////////////////
bool HashTable::Find( ULLONG key, TableEntry& tEntry )
{
    // determine the slot or "bucket" to look in the hash table:
    ULONG bucket = HashTable::HashFunction( key );

    { // Start critical region
        MutexLock( m_Mutex );

        // Use bucket to index into hash table
        Item* item = tableEntry[bucket];

        // walk the linked list till a match is found
        while ( item != NULL )
        {
            if ( item->numVal == key ) 
            {
                tEntry = *item; // match found
                item->accessCount++;
                return true;
            }

            item = item->m_next;
        }
        return false;
    }
}


// Insert : add a new entry to the hash table
// Input parameters  : key, an integer, the number to match on
// Output parameters : tEntry, a reference to a table entry
// Return Value      : true - the string has been found, the data

//////////////////////////////////////////////////
void HashTable::Insert( TableEntry& tEntry )
{
    MutexLock( m_Lock );

    // determine which bucket to insert the entry into
    ULONG bucket = HashTable::HashFunction( tEntry.numVal );
    cout << "Insert(): tableEntry.numVal = " << tEntry.numVal << "\n";
    cout << "bucket: " << bucket << "\n";

    // Check if item has already been inserted by another thread

    cout << "tableEntry[" << bucket << "]" << tableEntry[bucket] << "\n";
    Item* item = tableEntry[bucket];
    assert(item != NULL);

    while (item != NULL )
    {
        if ( item->numVal == tEntry.numVal )
        {
            return; // alerady there, no work to do !
        }
        item = item->m_next;
    }

    // Not found, so make a new entry
    item = new Item();
    *(static_cast<TableEntry*>(item)) = tEntry;
    item->m_next = tableEntry[bucket];
    tableEntry[bucket] = item;

    item->accessCount++;
}

// Display : dump the contents of the hash table to stdout
//////////////////////////////////////////////////
void HashTable::Display( )
{
    MutexLock( m_Lock );
    for ( int index = 0; index  = TABLESIZE; index++ )
    {
        Item* item = tableEntry[index];
        while ( item != NULL )
        {
            std::cout <<  "numeric value: " <<  item->numVal
                      << ", " << "name: "  << item->name;
            item = item->m_next;
        }
    }
}

// Test driver code to verify correct functionality of hash table:
int main ( int argc, char* argv[] )
{
   TableEntry dirEntry;
   HashTable ht;

   dirEntry.numVal = 8051234567;
   dirEntry.name = "Joe Bloe";
   ht.Insert(dirEntry);
   ht.Display();

   dirEntry.numVal = 8051233452;
   dirEntry.name = "Bob Blob";
   ht.Insert(dirEntry);
   ht.Display();

   dirEntry.numVal = 8051987645;
   dirEntry.name = "Jon Doe";
   ht.Insert(dirEntry);
   ht.Display();

   dirEntry.numVal = 50819874536;
   dirEntry.name = "John Smith";
   ht.Insert(dirEntry);
   ht.Display();

   dirEntry.numVal = 7653451276;
   dirEntry.name = "Dan theMan";
   ht.Insert(dirEntry);
   ht.Display();
   
   if(!ht.Find(9098765432, dirEntry))
       ht.Insert(dirEntry);
   ht.Display();
 
   return 0;
}
