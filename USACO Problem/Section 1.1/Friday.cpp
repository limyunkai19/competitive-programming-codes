#include <iostream>

using namespace std;

int main()
{
    int leap[12], normal[12], day[7];
    leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    normal = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    day = {0, 0, 0, 0, 0, 0, 0};
    int N, totalday = 13;
    cin >> N;

    for(int i = 1900; i < 1900+N; i++)
    {
        if(i%100 == 0)
        {
            if(i%400 == 0)
            {
                for(int k = 0; k < 12; k++)
                {
                    day[totalday%7]++;
                    totalday += leap[k];
                }
            }
            else
            {
                for(int k = 0; k < 12; k++)
                {
                    day[totalday%7]++;
                    totalday += normal[k];
                }
            }
        }
        else if(i%100 != 0)
        {
            if(i%4 == 0)
            {
                for(int k = 0; k < 12; k++)
                {
                    day[totalday%7]++;
                    totalday += leap[k];
                }
            }
            else
            {
                for(int k = 0; k < 12; k++)
                {
                    day[totalday%7]++;
                    totalday += normal[k];
                }
            }
        }
    }

    for(int i = 6; i <= 11; i++)
    {   cout << day[i%7] << " ";    }
    cout << day[5] << endl;
    return 0;
}
