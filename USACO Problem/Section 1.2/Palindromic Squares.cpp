#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream in("palsquare_in.txt");
ofstream out("palsquare_out.txt");

void print(vector<int> a)
{
    char k;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        if(a[i]<10){out << a[i];}
        else{k = a[i] + 55; out << k;}
    }
}

vector<int> baseB(int n, int base)
{
    vector<int> baseB;
    while(n != 0)
    {
        baseB.push_back(n%base);
        n /= base;
    }
    return baseB;
}

bool palindrome(vector<int> b)
{
    bool palindrome = true;
    for(int i = 0; i <= b.size()/2; i++)
    {
        if(b[i] != b[b.size() - 1 - i])
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
    int base;
    in >> base;
    vector<int> num;

    for(int i = 1; i <= 300; i++)
    {
        if(palindrome(baseB(i*i, base)))
        {
            print(baseB(i, base));
            out << " ";
            print(baseB(i*i, base));
            out << endl;
        }
    }
    return 0;
}
