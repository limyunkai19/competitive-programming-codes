#include <iostream>
#include <fstream>

using namespace std;

void rotate90(char a[], int n)
{
    char c[n*n];
    char temp[2];
    int parity=0;
    for(int i = 0; i < n/2; i++)
    {
        for(int b = 0; b < (n - 2*i) - 1; b++){
        temp[(parity)%2]=a[i*n + i];
        for(int j = i; j < n - i - 1; j++)
        {
            parity++;
            temp[parity%2] = a[i*n + j + 1];
            a[i*n + j + 1] = temp[(parity+1)%2];

        }
        for(int j = i; j < n - i - 1; j++)
        {
            parity++;
            temp[(parity)%2] = a[(j+1)*n + n - i - 1];
            a[(j+1)*n + n - i - 1] = temp[(parity+1)%2];

        }
        for(int j = n - i - 1; j > i; j--)
        {
            parity++;
            temp[(parity)%2] = a[(n - i - 1)*n + j - 1];
            a[(n - i - 1)*n + j - 1] = temp[(parity+1)%2];

        }
        for(int j = n - i - 1; j > i; j--)
        {
            parity++;
            temp[parity%2] = a[(j-1)*n + i];
            a[(j-1)*n + i] = temp[(parity+1)%2];

        }
    }
    }
}

void reflect(char a[], int n)
{
    char temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n/2; j++)
        {
            temp = a[i*n + j];
            a[i*n + j] = a[i*n + n - j - 1];
            a[i*n + n - j - 1] = temp;
        }
    }
}

bool compare(char a[], char b[], int n)
{
    bool compare = true;
    for(int i = 0; i < n*n; i++)
    {
        if(a[i] != b[i]){compare = false; break;}
    }
    if(compare){return true;}
    else{return false;}
}

void print(char a[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i*n + j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    ifstream in("transform_in.txt");
    ofstream out("transform_out.txt");
    in >> n;
    char pattern[n*n], solution[n*n];
    for(int i = 0; i < n*n; i++){in >> pattern[i];}
    for(int i = 0; i < n*n; i++){in >> solution[i];}



    rotate90(pattern, n);
    if(compare(pattern, solution, n)){out << 1 << endl; return 0;}

    rotate90(pattern, n);
    if(compare(pattern, solution, n)){out << 2 << endl; return 0;}

    rotate90(pattern, n);
    if(compare(pattern, solution, n)){out << 3 << endl; return 0;}

    rotate90(pattern, n);
    reflect(pattern, n);
    if(compare(pattern, solution, n)){out << 4 << endl; return 0;}

    rotate90(pattern, n);
    if(compare(pattern, solution, n)){out << 5 << endl; return 0;}

    rotate90(pattern, n);
    if(compare(pattern, solution, n)){out << 5 << endl; return 0;}

    rotate90(pattern, n);
    if(compare(pattern, solution, n)){out << 5 << endl; return 0;}

    rotate90(pattern, n);
    if(compare(pattern, solution, n)){out << 6 << endl; return 0;}

    out << 7 << endl; return 0;
}
