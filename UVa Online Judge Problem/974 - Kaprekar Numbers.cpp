#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int power_10[13];
vector<int> kelp;
vector<int>::iterator it;

bool test_kelp(int n){
    int a = n*n;
    //cout << a << endl;
    int exp = log10(n) -1;
    while(power_10[exp] <= a){
        if(a/power_10[exp] + a%power_10[exp] == n){
            if(a%power_10[exp] == 0){
                exp++;
                continue;
            }
            return true;
        }
        exp++;
        if(exp > 12){return false;}
    }
    return false;

}

int main(){
    power_10[0] = 1;
    for(int i = 1; i < 13; i++){
        power_10[i] = 10*power_10[i-1];
        //cout << power_10[i] << endl;
    }
    for(int i = 2; i <= 40000; i++){
        if(test_kelp(i)){
            kelp.push_back(i);
            //cout << i << endl;
        }
    }
    int n, a, b; int start, end;
    bool found;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        /*scanf("%d %d", &a, &b);
        it = lower_bound(kelp.begin(), kelp.end(), a);
        if(*it > b){
            printf("case #%d\nno kaprekar numbers\n", i);
        }
        else{
            printf("case #%d\n", i);
            while(it != kelp.end() && *it <= b){
                printf("%d\n", *it);
                it++;
            }
        }
        if(n-i){
            printf("\n");
        }*/


        if (i > 0)
      cout << endl;

    cin >> start >> end;
    found = false;

    cout << "case #" << i + 1 << endl;
    for (int j = 0, sz = kelp.size(); j < sz; j++) {
      if (kelp[j] >= start && kelp[j] <= end) {
        found = true;
        cout << kelp[j] << endl;
      }
    }

    if (!found) {
      cout << "no kaprekar numbers" << endl;
    }
   }




    return 0;
}
