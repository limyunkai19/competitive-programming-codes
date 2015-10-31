#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

typedef double     ld;
typedef pair<ld, ld>    dd;
typedef pair<dd, ld>    xyp;

int main()
{
    vector<xyp> lines;
    vector<dd> ans;
    int tc;
    scanf("%d", &tc);
    int num_line;
    ld percent, x1, y1, x2, y2, index, pre;
    int zero_range;
    for(int i = 0; i < tc; i++){
        lines.clear();
        ans.clear();
        percent = 1;
        zero_range = 0;
        scanf("%d", &num_line);
        for(int i = 0; i < num_line; i++){
            scanf("%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &index);
            lines.push_back(xyp(dd(min(x1, x2), max(x1, x2)), index));
        }
        sort(lines.begin(), lines.end());
        priority_queue<dd> endpoint;
        //printf("-inf %0.3f 1.000\n%0.3f ", lines[0].first.first, lines[0].first.first);
        ans.push_back(dd(lines[0].first.first, percent));
        if(lines[0].second == 0){
            zero_range++;
        }
        else{
            percent *= lines[0].second;
        }
        endpoint.push(dd(-lines[0].first.second, lines[0].second));
        for(int i = 1; i < lines.size(); i++){
            //printf("loop: %d\n", i);
            while(-endpoint.top().first < lines[i].first.first && !endpoint.empty()){
                //printf("%0.3f %0.3f\n%0.3f", -endpoint.top().first, percent, -endpoint.top().first);
                if(zero_range != 0){
                    ans.push_back(dd(-endpoint.top().first, 0));
                }
                else{
                    ans.push_back(dd(-endpoint.top().first, percent));
                }
                if(endpoint.top().second == 0){
                    zero_range--;
                }
                else{
                    percent /= endpoint.top().second;
                }
                endpoint.pop();
            }
            //printf("%0.3f %0.3f\n%0.3f ", lines[i].first.first, percent, lines[i].first.first);
            if(zero_range != 0){
                ans.push_back(dd(lines[i].first.first, 0));
            }
            else{
                ans.push_back(dd(lines[i].first.first, percent));
            }
            if(lines[i].second == 0){
                zero_range++;
            }
            else{
                percent *= lines[i].second;
            }
            endpoint.push(dd(-lines[i].first.second, lines[i].second));

        }
        while(!endpoint.empty()){
            //printf("%0.3f %0.3f\n%0.3f ", -endpoint.top().first, percent, -endpoint.top().first);
            if(zero_range != 0){
                ans.push_back(dd(-endpoint.top().first, 0));
            }
            else{
                ans.push_back(dd(-endpoint.top().first, percent));
            }
            if(endpoint.top().second == 0){
                zero_range--;
            }
            else{
                percent /= endpoint.top().second;
            }
            endpoint.pop();
            //ans.push_back(dd(-endpoint.top().first, percent));
            //percent /= endpoint.top().second;
            //endpoint.pop();
        }
        printf("%d\n-inf ", ans.size()+1);
        for(int i = 0; i < ans.size(); i++){
            if(ans[i].first == 0){
                printf("%0.3f %0.3f\n%0.3f ", -ans[i].first, ans[i].second, -ans[i].first);
            }else{
                printf("%0.3f %0.3f\n%0.3f ", ans[i].first, ans[i].second, ans[i].first);
            }
        }
        if(i == tc-1){
            printf("+inf 1.000\n");
            return 0;
        }
        printf("+inf 1.000\n\n");
        /*for(int i = 0; i < lines.size(); i++){
            printf("%f %f %f\n", lines[i].first.first, lines[i].first.second, lines[i].second);
            //cout << lines[i].first.first << " " << lines[i].first.second << " " << lines[i].second << endl;
        }*/
    }

    return 0;
}
