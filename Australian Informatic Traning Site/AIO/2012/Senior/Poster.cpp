#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <fstream>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;



int main()
{
    //FILE* in;
    //FILE* out;
    //in = fopen("postin.txt", "r");
    //out = fopen("postout.txt", "w");
    freopen("postin.txt", "r", stdin);
    freopen("postout.txt", "w", stdout);

    int n, a, b, idx = 1, beg, end;
    scanf("%d %d %d", &n, &beg, &end);
    end += beg;

    for(int i = 2; i <= n; i++){
        scanf("%d %d", &a, &b);
        b += a;
        if(a < end){
            beg = a;
            end = b;
            idx = i;
        }
    }

    printf("%d\n", idx);

    //in >> n;
    //fscanf(in, "%d", &n);
    /*set<iii> active_set;
    set<iii>::iterator it, e_first, e_last;
    active_set.insert(iii(ii(2000000, 2000000), 0));
    active_set.insert(iii(ii(0, 0), 0));
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        //fscanf(in, "%d %d", &a, &b);
        //in >> a >> b;
        b += a;
        it = lower_bound(active_set.begin(), active_set.end(), iii(ii(a, b), 0));
        --it;
        //cout << "lower_bound " << a << "," << b << endl;
        //cout << "result: ii(" << it->first.first << "," << it->first.second << ")" << endl;
        if(it->first.second > a && it->first.first <= a){
            e_first = it;
            //while(it->first.first < b){
            //    it++;
            //}
            e_last = lower_bound(active_set.begin(), active_set.end(), iii(ii(b, 0), 0));
            //e_last = it;
            //cout << "erasea: ii(" << e_first->first.first << "," << e_first->first.second << ") until ii("
            //<<  e_last->first.first << "," << e_last->first.second << ")" << endl;
            active_set.erase(e_first, e_last);
        }
        else if( (++it)->first.first < b){
            e_first = it;
            //while(it->first.first < b){
            //    it++;
            //}
            //e_last = it;
            e_last = lower_bound(active_set.begin(), active_set.end(), iii(ii(b, 0), 0));
            //cout << "eraseb: ii(" << e_first->first.first << "," << e_first->first.second << ") until ii("
            //<<  e_last->first.first << "," << e_last->first.second << ")" << endl;
            active_set.erase(e_first, e_last);
        }

            //cout << "insert: ii(" << a << "," << b << ")," << i << endl;
            active_set.insert(iii(ii(a, b), i));

    }
    cout << (++active_set.begin())->second+1 << endl;
    */

    //fprintf(out, "%d\n", (++active_set.begin())->second+1);
    //fclose(in);
    //fclose(out);
    /*stack<ii> poster;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        poster.push(ii(a, b));
    }
    set<int> active;
    set<int>::iterator it;
    active.insert(2000000);
    int i = n, ans = n, left = 2000000;
    while(!poster.empty()){
        a = poster.top().first;
        b = a + poster.top().second;
        poster.pop();
        it = upper_bound(active.begin(), active.end(), a);
        if(*it == a){
            it++;
        }
        if(*it >= b && left > a){
            ans = i;
            left = a;
        }

        i--;
        active.insert(a);
        active.insert(b);

    }
    cout << ans << endl;
    cout << left << endl;
    */
    return 0;
}
