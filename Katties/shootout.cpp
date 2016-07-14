#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

#define ERR 1e-13

struct probablity{
    vector<double> p;
    probablity(){}
    probablity(int n){
        p.assign(n, 0);
    }
    probablity(int n, int i){
        p.assign(n, 0);
        p[i] = 1;
    }

    void print(){
        if(!p.size()) return;
        //cout.precision(12);
        //cout << p[0]*100;
        printf("%0.10lf", p[0]*100);
        for(int i = 1; i < p.size(); i++){
            //cout << ' ' << p[i]*100;
            printf(" %0.10lf", p[i]*100);
        }
        //cout << endl;
        printf("\n");
    }

    probablity operator*(double x){
        probablity ans = *this;
        for(int i = 0; i < p.size(); i++){
            ans.p[i] *= x;
        }
        return ans;
    }

    void operator+=(probablity b){
        for(int i = 0; i < b.p.size(); i++){
            this->p[i] += b.p[i];
        }
    }

};

probablity survive[1<<14][14];
double accuracy[14];
int n, mask, debug_start, debug;

int compute_next_start(int state, int start){
    start = (start+1)%n;
    for(int i = 0; i < n; i++, start = (start+1)%n){
        if((1<<start) & state){
            return start;
        }
    }
}


// observation:
// p(state, start) = shoot * max(p(kill 1 ppl, next start))
//                  + miss * p(same state, next start)
//                              = [   shoot * max(p(kill 1 ppl, next start))
//                                   + miss * p(same state, next start)         ]
//                                              = ......
// p(state, start1) = shoot1 * max(p(start1 kill 1 ppl, start2))
//                   + miss1 * shoot2 * max(p(start2 kill 1 ppl, start3))
//                   + miss1 * miss2 * shoot3 * max(p(start3 kill 1 ppl, start4))
//                   + .....
//                   + miss1 * miss2 * miss3 * .... (all miss) * p(same state, start1)
//
// solve above and, we get p(state, start1) = ...... / (1-miss_all)

probablity kill_best(int state, int start);

probablity solve(int state, int start){
    if(survive[state][start].p.size()){
        return survive[state][start];
    }

    probablity ans = probablity(n);
    double miss = 1;
    int tmp_start = start;

    // apply formular above
    do{
        ans += kill_best(state, tmp_start)*( miss*accuracy[tmp_start] );
        miss *= 1.0-accuracy[tmp_start];
        tmp_start = compute_next_start(state, tmp_start);

    } while(tmp_start != start);

    return survive[state][start] = ans * (1.0/(1.0-miss));
}

probablity kill_best(int state, int start){
    probablity ans;
    int same = 0;
    // for start to select best one to kill
    for(int i = 0; i < n; i++){
        if( (1<<i & state) && i != start){
            // try kill i
            probablity tmp = solve(state&(~(1<<i))&mask, compute_next_start(state&(~(1<<i))&mask,start));

            // a > b => a-b > 0 => a-b > ERR
            if(same == 0 || tmp.p[start] - ans.p[start]/same > ERR){
                ans = tmp;
                same = 1;
            }
            else if( abs(tmp.p[start] - ans.p[start]/same) < ERR ){
                ans += tmp;
                same++;
            }
        }
    }
    // divide for random cases
    return ans * (1.0/same);
}

int main(){
    int t;
    //cin >> t;
    scanf("%d", &t);

    while(t--){
        //cin >> n;
        scanf("%d", &n);
        mask = (1<<(n)) - 1;

        for(int i = 0; i <= mask; i++){
            for(int j = 0; j < n; j++){
                survive[i][j].p.resize(0);
            }
        }

        for(int i = 0; i < n; i++){
            //cin >> accuracy[i];
            scanf("%lf", accuracy+i);
            accuracy[i] /= 100.0;
            // set base case
            survive[1<<i][i] = probablity(n, i);
        }

        probablity ans = solve(mask, 0);
        ans.print();
    }


    return 0;
}