/* FB Interview problem: MCDonalds sells chicken McNuggets in packs of 6, 9, or 20. Given any positive integer n, is is possible to buy exactly 'n' McNuggets using these 3 combo packs? */

#include <iostream>

using namespace std; 

bool fastPossible(int sum)
{
    return (((sum%20)%9)%6) == 0;
}

bool possible(int sum, int sixpack, int ninepack, int twentypack)
{ 
    bool retVal = false;

    if(sum < 6) 
    {
        retVal = false; 
    }
    else
    {
        if(sum == 0 || sum == 6 || sum == 9 || sum ==20)
        {
            (sum == 6)? sixpack++:sixpack;
            (sum == 9)? ninepack++:ninepack;
            (sum == 20)? twentypack++:twentypack;

            cout << " You get sixpack = " << sixpack << " ninepack =  " << ninepack << " twentypack =  " << twentypack << "\n"; 
            retVal = true;
        }
        else
        {
            retVal = possible(sum - 20, sixpack, ninepack, twentypack+1) || \
                     possible(sum - 9, sixpack, ninepack+1, twentypack)  ||  \
                     possible(sum - 6, sixpack+1, ninepack, twentypack); 
        }
    }

    return retVal;
} 

int main(int argc, char* argv[])
{
    int sum; 
    bool ret;
    string answer;

    cout << "How many McNuggets do you want to buy? Enter the number: " << "\n";
    cin >> sum; 

    ret = possible(sum, 0, 0, 0); 
    answer = (ret)?"yes":"no";
    
    //cout << "fastPossible returned: " << fastPossible(sum) << "\n";

    if (ret)
        cout << answer << " , you can buy " << sum << " mcnuggets \n";
    else
        cout << answer << " mcnuggets for you, one year!\n";
    return 0;
}

