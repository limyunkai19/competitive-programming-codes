#include <iostream>
#include <fstream>

using namespace std;

ifstream in("barn1_in.txt");
ofstream out("barn1_out.txt");

int partition(int* input, int p, int r)
{
    int pivot = input[r];

    while ( p < r )
    {
        while ( input[p] < pivot )
            p++;

        while ( input[r] > pivot )
            r--;

        if ( input[p] == input[r] )
            p++;
        else if ( p < r )
        {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }

    return r;
}

void quicksort(int* input, int p, int r)
{
    if ( p < r )
    {
        int j = partition(input, p, r);
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

int main()
{


    int limit, stall, cow;
    in >> limit >> stall >> cow;

    int maxfree[limit - 1], free, temp[2], parity=0, num[cow], covered;
    for(int i = 0; i < limit - 1; i++){maxfree[i]=0;}
    for(int i = 0; i < cow; i++){in >> num[i];}
    quicksort(num, 0, (cow-1));
    for(int i = 1; i < cow; i++)
    {
        free = num[i] - num[i-1] - 1;
        if(free > maxfree[limit - 2])
        {
            for(int j = 0; j < limit - 1; j++)
            {
                if(free > maxfree[j])
                {
                    temp[parity%2] = maxfree[j];
                    for(int k = j; k < limit - 2 ; k++)
                    {
                        if(k != limit - 2)
                        {
                            parity++;
                            temp[parity%2] = maxfree[k + 1];
                            maxfree[k+1] = temp[(parity+1)%2];
                        }
                    }
                    maxfree[j] = free;
                    break;
                }
            }
        }
    }
    covered = num[cow-1];
    covered -= (num[0] - 1);
    for(int i = 0; i < limit - 1; i++)
    {
        covered -= maxfree[i];
    }
    out << covered << endl;

    return 0;
}
