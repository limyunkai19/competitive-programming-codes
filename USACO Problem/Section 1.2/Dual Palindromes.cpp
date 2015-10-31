#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("dualpal_in.txt");
ofstream out("dualpal_out.txt");

vector<int> baseB(int n, int base)
{
    vector<int> baseB;
    while(n > 0)
    {
        baseB.push_back(n%base);
        n /= base;
    }
    return baseB;
}

bool palindrome(vector<int> a)
{
    bool palindrome = true;
    for(int i = 0; i <= a.size()/2; i++)
    {
        if(a[i] != a[a.size() - 1 - i])
        {
            palindrome = false;
            break;
        }
    }
    if(palindrome){return true;}
    else{return false;}
}

int main()
{
    int count, limit;
    in >> count >> limit;
    int found = 0, palcount;
    while(found < count)
    {
        limit++;
        palcount = 0;
        for(int base = 2; base <= 10; base++)
        {
            if(palindrome(baseB(limit, base))){palcount++;}
        }
        if(palcount > 1)
        {
            out << limit << endl;
            found++;
        }
    }
    return 0;
}
