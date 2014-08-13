#ifndef __CPPTEST_H__
#define __CPPTEST_H__

using namespace std;
enum { MAX = 10};

class MyTest
{
    public:
       MyTest();
       MyTest(int numArray[], char Words[]);
       void printNum(void);
       void printWords(void);
       ~MyTest();

    private: //Disallow copy constructor and assignment operator...
       MyTest& operator=(const MyTest& mt);
       MyTest(const MyTest& other);
       
       int m_Numbers[MAX];
       char m_Words[MAX];
       
};



#endif //__CPPTEST_H__
