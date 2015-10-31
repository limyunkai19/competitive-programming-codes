#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("gift1_in.txt");
    ofstream output("gift1_out.txt");
    int ppl;
    input >> ppl;
    int finalmoney[ppl], initialmoney[ppl];
    string name[ppl];

    for(int i = 0; i < ppl; i++)
    {   input >> name[i];   finalmoney[i]=0;    }


    for(int i = 0; i < ppl; i++)
    {
        string x;
        int divisor, num;
        input >> x;

        for(int n = 0; n < ppl; n++)
        {
            if(name[n] == x)
            {   num = n;    }
        }

        input >> initialmoney[num] >> divisor;
        if(divisor != 0){
        finalmoney[num] += initialmoney[num]%divisor;
        for(int k = 1; k <= divisor; k++)
        {
            int l;
            string y;
            input >> y;
            for(int n = 0; n < ppl; n++)
            {
                if(name[n] == y)
                {   l = n;    }
            }
            finalmoney[l] += initialmoney[num]/divisor;
        }
        }
    }

    for(int i = 0; i < ppl; i++)
    {
        output << name[i] << " " << finalmoney[i] - initialmoney[i] << endl;
    }

    return 0;
}
