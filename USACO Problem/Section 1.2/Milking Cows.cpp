#include <iostream>
#include <fstream>

using namespace std;

void print(long int *input, int n)
{
    for ( int i = 0; i < n; i++ )
        cout << input[i] << " ";
    cout << endl;
}

int partition(long int* input1, long int* input2, int p, int r)
{
    int pivot = input1[r];

    while ( p < r )
    {
        while ( input1[p] < pivot )
            p++;

        while ( input1[r] > pivot )
            r--;

        if ( input1[p] == input1[r] )
            p++;
        else if ( p < r )
        {
            long int tmp = input1[p];
            input1[p] = input1[r];
            input1[r] = tmp;

            long int temp = input2[p];
            input2[p] = input2[r];
            input2[r] = temp;
        }
    }

    return r;
}

void quicksort(long int* input1, long int* input2, int p, int r)
{
    if ( p < r )
    {
        int j = partition(input1, input2, p, r);
        quicksort(input1, input2, p, j-1);
        quicksort(input1, input2, j+1, r);
    }
}

int main()
{
    long int n, maxIdle=0, maxMilk= 0, idle, milk, idleS, idleE, milkS, milkE, begin, end, preBegin, preEnd;
    ifstream in("milk2_in.txt");
    ofstream out("milk2_out.txt");
    in >> n;
    long int timeB[n], timeE[n];
    for(long int i = 0; i < n; i++){in >> timeB[i] >> timeE[i];}
    quicksort(timeB, timeE, 0, (n - 1));

    maxMilk = timeE[0] - timeB[0];
    milkS = timeB[0];
    milkE = timeE[0];
    for(long int i = 1 ; i < n; i++)
    {
        if(timeB[i] <= milkE && timeE[i] > milkE)
        {
            milkE = timeE[i];
            milk = milkE - milkS;
            if(milk > maxMilk){maxMilk = milk;}
        }
        else if(timeB[i] > milkE)
        {
            idle = timeB[i] - milkE;
            if(idle > maxIdle){maxIdle = idle;}
            milkS = timeB[i];
            milkE = timeE[i];
        }
    }

    out << maxMilk << " " << maxIdle << endl;

    return 0;
}
