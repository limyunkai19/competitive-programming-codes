#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

vector<int> pset;

void initialize(int k){
    pset.resize(k);
    for(int i = 0; i < k; i++){
        pset[i] = i;
    }
}

int parent(int j){
    if(pset[j] != j){
        return pset[j] = parent(pset[j]);
    }
    else{
        return j;
    }
}

void uni(int i, int j){
    pset[parent(j)] = parent(i);
}

bool is_same_set(int i, int j){
    return parent(i) == parent(j);
}

int main()
{
    int tc;
    cin >> tc;
    int n, a, b, Y, N;
    string q;
    char k;
    while(tc--){
        cin >> n; getchar();
        initialize(n+1);
        Y = 0; N = 0;
        getline(cin, q);
        while(q != ""){
            stringstream ss(q);
            ss >> k >> a >> b;
            if(k == 'c'){
                uni(a, b);
            }
            else{
                if(is_same_set(a, b)){
                    Y++;
                }
                else{
                    N++;
                }
            }
            getline(cin, q);
        }
        printf("%d,%d\n", Y, N);
        if(tc){
            printf("\n");
        }

    }

    return 0;
}
