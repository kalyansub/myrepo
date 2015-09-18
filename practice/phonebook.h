#ifndef __INCLUDE_PHONEBOOK_H__
#define __INCLUDE_PHONEBOOK_H__

//phonebook header: class declararion and member function definitions
enum {MAX=80};

class Name
{
    public:
        Name()
        {
            strcpy(m_Name, "");
        }
        Name(const char* str)
        {
            strcpy(m_Name, str);
        }
        ~Name() 
        {
        }
        char* getName()
        {
            return m_Name;
        }
    private: 
        char m_Name[MAX];
};

class PhoneNumber
{
    public:
         PhoneNumber()
         {
             strcpy(m_Number, "");
         }
         PhoneNumber(const char* numberStr)
         {
             strcpy(m_Number, numberStr);
         }
         char* getPhoneNumber()
         {
             return m_Number;
         }
         //~PhoneNumber()
    private:
       char m_Number[MAX];
};
#endif // __INCLUDE_PHONEBOOK_H__
