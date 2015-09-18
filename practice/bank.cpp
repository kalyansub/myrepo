#include <iostream>
using namespace std;

enum { INVALID_ACCOUNT = -1};

class Account
{
   public:
     Account(long acctNum, long pin, float initialDeposit);
     ~Account();
      float draw(float input);
      float deposit(float input);
      inline float checkBalance(void) { return ((m_balance > 0.50)? m_balance: 0.0); }
      bool authenticate(long acct, long pin);
#ifdef __DEBUG
      inline long getacNum() { cout << "Acct Number: " << m_accountNumber << "\n";}
      inline long getpin() { cout << "PIN: " << m_Pin << "\n";}
#endif
    private:
      long m_accountNumber;
      long m_Pin;
      float m_balance;
      float m_transactionCharge;
};

Account::Account(long acctNum, long pin, float initialDeposit): 
                 m_accountNumber(acctNum), 
                 m_Pin(pin), 
                 m_balance(initialDeposit)  
{
                 m_transactionCharge = 0.50;
}

Account::~Account() 
{ 
   m_accountNumber = INVALID_ACCOUNT;
   m_Pin = INVALID_ACCOUNT;
   m_balance = 0.0; 
}

bool Account::authenticate(long acct, long pin) 
{
 //cout << "acct:" << acct << "pin:" << pin;
 return  ((acct == m_accountNumber) &&(pin == m_Pin))?true:false;

}

float Account::deposit(float input)
{
    m_balance += (input - m_transactionCharge);
    return m_balance;
}
float Account::draw(float input)
{
    float output = -1.0;

    if (input >= m_balance)
    {
        cout << "Insufficient funds for transaction!\n";
        output = 0.0;
    }
    else
    {
        output = input - m_transactionCharge;
        m_balance -= output; 
    }
    return output;
}

int main(int argc, char* argv[])
{
    Account myBankAcc(1234, 567, 0);

    #ifdef __DEBUG 
    cout << "Initialized accnum: " << myBankAcc.getacNum() << " and PIN: " << myBankAcc.getpin() << "\n";
    #endif

    cout << "***************************\n";
    cout << "*** Welcome to the ATM! ***\n";  
    cout << "***************************\n";

    long acctNum, pin;
    cout << "Enter account number: ";
    cin >> acctNum;
    //cout << "Got acctNum: " << acctNum << "\n";
    
    cout << "Enter PIN number: ";
    cin >> pin;
    //cout << "Got PIN num: " << pin << "\n";


    bool flag = myBankAcc.authenticate(acctNum, pin);
    //cout << "Flag: " << flag << "\n";
    if (flag)
    {  

       while (true)
       {
        cout << "Enter 'D' for Deposit, 'B' for Balance, 'W' for Withdrawal, 'Q' to quit" << endl;
        char ch;
        float amount;
        float balance;
        bool done = false;
        cin >> ch;
        switch (ch)
        {
            case 'D':
               cout << "Enter deposit amount: ";
               cin >> amount;
               balance = myBankAcc.deposit(amount);
               cout << "After deposit, your new balance is: " << balance << "\n";
               break;
            case 'B':
               balance = myBankAcc.checkBalance();
               cout << "Current balance: " << balance << "\n";
               break;
            case 'W':
               cout << "How much do you want to withdraw?" << endl;
               cin >> amount;
               balance = myBankAcc.draw(amount);
               cout << "After withdrawal, of : " << amount << " new balance: " << balance << "\n";
               break;
            case 'Q':
               cout << "Thanks, bye!\n";
               done = true;
               break;
               
            default:
               cout << "This ATM is dumb, please enter D, B, W or Q!\n";
               break;
        }
        if (done) 
           break;
        else
            continue;
      }
   }
   else
   {
       cout << "Invalid credentials, transaction aborted!\n";
   }

    return 0;
}
