// Simple hash table object: it takes a number as a key and a struct called "item" that is indexed by the key. The "item" is really a tableEntry, which is a associative map of integer numbers to a set of strings, much like a phone book: (number, name);

#ifndef HASH_H
#define HASH_H

#ifdef _WIN32
#include <windows.h> // For mutex handle definition on Win32 machines
#endif 
#include <iostream>
#include <string>
#include <cstring>
#include <pthread.h> // POSIX thread support on Linux and UNIX machines

using namespace std;
typedef unsigned long ULONG;
typedef unsigned long ULLONG;

// A helper class for thread concurrency 
class MutexLock
{
public:
    MutexLock();
    ~MutexLock();
    
private:
    // Disallow copy ctor and = operator:
    MutexLock( const MutexLock& from );
    MutexLock& operator=( const MutexLock &rhs );

    void MutexUnlock(void);
#ifdef _WIN32
    HANDLE m_MutexHandle; // This is a Win32 Handle
#else
    pthread_mutex_t m_MutexHandle;
#endif
};

enum { MAXLEN = 10 };

struct TableEntry
{
    ULLONG numVal;
    string name;
};

class HashTable
{
public:
    HashTable( );
    ~HashTable();

    inline static ULONG HashFunction( ULLONG key )
    {
        cout << "In HashFunction(), key: " << key << "hash value: " << key%MAXKEY << "\n";
        return key%MAXKEY; // choose MAXKEY close to the largest power of two and preferably a prime
    }

    bool Find( ULLONG key, TableEntry& tEntry );

    void Insert( TableEntry& tEntry );

    void Display( );

private:
    // Disallow copy ctor and assignment operator:
    HashTable( const HashTable& from );
    HashTable& operator=( const HashTable& source );

    struct Item: public TableEntry
    {
        Item( Item* next = 0 )
            : m_next( next), accessCount(0) 
        { }

        Item* m_next;
        ULONG accessCount;

    };

    enum { MAXKEY = 2^31-1, TABLESIZE = 16384 };

    Item* tableEntry[TABLESIZE];
    MutexLock m_Lock;
};
#endif
