#include <iostream>

#define mod 1000000007

using namespace std;

long long question[1001000], pos[1001000];

int main(){
    long long n, limit;
    cin >> n >> limit;

    long long a, b, c, t;
    cin >> a >> b >> c >> t;

    int cycle, head;
    for(cycle = 0; question[t] == 0 && cycle < n; cycle++){
        pos[t] = cycle;
        question[t]++;
        t = ((a*t + b)%c)+1;
    }
    if(cycle != n){
        head = pos[t];
        cycle -= head;

        n -= head;

        int repeat = n/cycle, overhead = n%cycle;
        for(int i = 0; i < cycle; i++){
            question[t] += repeat + (i<=overhead-1 ?0:-1);
            t = ((a*t + b)%c)+1;
        }
    }
    // loop through question to find solution
    long long now = 0, penalty = 0, solved = 0;
    for(long long i = 1; i <= c; i++){
        if(now + question[i]*i <= limit){
            // add all
            penalty = (  penalty%mod + question[i]*(now%mod) + i*(((question[i])*(question[i]+1)/2)%mod) )%mod;
            now += question[i]*i;
            solved += question[i];
        }
        else{
            // add some
            for(int j = 0; j < question[i] && now + i <= limit; j++, solved++){
                now += i;
                penalty = (penalty+now)%mod;
            }
            break;
        }
    }

    cout << solved << ' ' << penalty << endl;
    return 0;
}