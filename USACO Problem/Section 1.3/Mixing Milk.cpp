#include <iostream>
#include <fstream>

using namespace std;

ifstream in("milk_in.txt");
ofstream out("milk_out.txt");

int partition(int* input1, int* input2, int p, int r)
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
            int tmp = input1[p];
            input1[p] = input1[r];
            input1[r] = tmp;

            int temp = input2[p];
            input2[p] = input2[r];
            input2[r] = temp;
        }
    }

    return r;
}

void quicksort(int* input1, int* input2, int p, int r)
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
    int need, n, money=0;
    in >> need >> n;
    int price[n], milk[n];
    for(int i = 0; i < n; i++){in >> price[i] >> milk[i];}
    quicksort(price, milk, 0, (n-1));
    int i = 0;
    while(need > 0)
    {
        if(need >= milk[i])
        {
            need -= milk[i];
            money += milk[i]*price[i];
        }
        else
        {
            money += need*price[i];
            need = 0;
        }
        i++;
    }
    out << money << endl;

    return 0;
}
