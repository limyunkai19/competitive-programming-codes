#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> prime, idx(1, -1);
    prime.push_back(1);
    idx.push_back(0);
    prime.push_back(2);
    idx.push_back(1);
    for(int i = 3; i <= 1000; i++){
        bool is_prime = true;
        for(int j = 1; j < prime.size(); j++){
            if(i%prime[j] == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            prime.push_back(i);
        }
        idx.push_back(prime.size()-1);
    }

    int n, c;
    while(cin >> n >> c){
        cout << n << ' ' << c << ':';
        if(idx[n] == -1){
            cout << endl << endl;
            continue;
        }
        int total = idx[n]+1;
        int middle = (total+1)/2 - c;
        if(middle < 0) middle = 0;
        for(int i = middle; i <= idx[n]-middle; i++){
            cout << ' ' << prime[i];
        }
        cout << endl << endl;
    }
}