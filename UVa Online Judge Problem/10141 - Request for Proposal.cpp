#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string rubbish;
string name;
string lol;
double price, min_price;
int comp, max_comp=0;

int main()
{
    int p, n, tc=1;
    cin >> n >> p;
    while(n != 0){
        if(tc > 1){
            cout << endl;
        }
        max_comp = 0;
        getline(cin, rubbish);
        for(int i = 0; i < n; i++){
            getline(cin, rubbish);
        }
        for(int i = 0; i < p; i++){
            getline(cin, lol);
            cin >> price >> comp;
            getline(cin, rubbish);
            for(int j = 0; j < comp; j++){
                getline(cin, rubbish);
            }
            if(comp > max_comp){
                name = lol;
                min_price = price;
                max_comp = comp;
            }else if(comp == max_comp && price < min_price){
                name = lol;
                min_price = price;
            }
        }
        printf("RFP #%d\n", tc++);
        cout << name << endl;
        cin >> n >> p;
    }
    return 0;
}

