#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream dict("dict.txt");
    ifstream in("namenum_in.txt");
    ofstream out("namenum_out.txt");

    string nam;
    string num;
    bool non=true, equal = true;

    in >> num;

    char alpha[24] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                      'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
    int first, k;
    first = (num[0]-'2');
    first*=3;

    while(dict >> nam)
    {
        if((nam[0] == alpha[first] || nam[0] == alpha[first + 1] || nam[0] == alpha[first + 2]) && nam.length() == num.length())
        {
            for(int i = 1; i < nam.length(); i++)
            {
                k = (num[i] - '2')*3;
                if(nam[i] != alpha[k] && nam[i] != alpha[k+1] && nam[i] != alpha[k+2])
                {
                    equal = false;
                    break;
                }
            }
            if(equal){out << nam << endl; non = false;}
            equal = true;
        }
    }

    if(non){out << "NONE" << endl;}
    return 0;
}
