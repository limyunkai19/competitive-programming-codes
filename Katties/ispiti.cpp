#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> ii;

vector<ii> input, knowledge, knowledge_ori;
map<ii, int> ori_index;
vector<int> max_st;

void update(int l, int r, int node, int idx){
    if(idx < l || idx > r || l > r){
        // out of range
        return;
    }

    if(l == r){
        max_st[node] = l;
        return;
    }

    int l_node = 2*node, r_node = 2*node+1, mid = (l+r)/2;

    update(l, mid, l_node, idx);
    update(mid+1, r, r_node, idx);

    int l_val = max_st[l_node], r_val = max_st[r_node];

    if(l_val == -1) max_st[node] = r_val;
    else if(r_val == -1) max_st[node] = l_val;
    else{
        if(knowledge[l_val].second > knowledge[r_val].second){
            max_st[node] = l_val;
        }
        else{
            max_st[node] = r_val;
        }
    }
}

void update(int idx){
    // knowledge.size() is n
    update(0, knowledge.size()-1, 1, idx);
}

int query(int l, int r, int node, int l_idx, int r_idx){
    if(r < l_idx || r_idx < l)
        return -1;

    if(l_idx <= l && r <= r_idx){
        // in range
        return max_st[node];
    }

    int l_node = 2*node, r_node = 2*node+1, mid = (l+r)/2;

    int l_val = query(l, mid, l_node, l_idx, r_idx);
    int r_val = query(mid+1, r, r_node, l_idx, r_idx);

    if(l_val == -1) return r_val;
    if(r_val == -1) return l_val;

    if(knowledge[l_val].second > knowledge[r_val].second)
        return l_val;
    return r_val;

}

int query(int l_idx, int r_idx){
    // knowledge.size() is n
    return query(0, knowledge.size()-1, 1, l_idx, r_idx);
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'D'){
            int a, b;
            cin >> a >> b;
            knowledge_ori.push_back(ii(b, a));
            input.push_back(ii(b, a));
            ori_index[ii(b, a)] = knowledge_ori.size();
        }
        else{
            int a;
            cin >> a;
            input.push_back(ii(0, a));
        }
    }
    knowledge = knowledge_ori;
    sort(knowledge.begin(), knowledge.end());
    max_st.assign(4*knowledge.size(), -1);

    for(int i = 0; i < n; i++){
        int a = input[i].first, b = input[i].second;
        if(a == 0){
            a = knowledge_ori[b-1].first;
            b = knowledge_ori[b-1].second;
            int idx = lower_bound(knowledge.begin(), knowledge.end(), ii(a, b)) - knowledge.begin();
            int query_idx = query(idx+1, knowledge.size()-1);
            if(query_idx == -1 || knowledge[query_idx].second < b){
                cout << "NE" << endl;
            }
            else{
                int lo = idx+1, hi = knowledge.size()-1, mid;

                while(hi > lo+1){
                    mid = (hi+lo)/2;

                    int query_idx = query(lo, mid);
                    if(query_idx == -1 || knowledge[query_idx].second < b){
                        lo = mid+1;
                    }
                    else{
                        hi = mid;
                    }
                }
                int query_idx = query(lo, lo);
                if(query_idx == -1 || knowledge[query_idx].second < b){
                    query_idx = query(hi, hi);
                }

                a = knowledge[query_idx].first;
                b = knowledge[query_idx].second;

                cout << ori_index[ii(a, b)] << endl;
            }
        }
        else{
            // get a, b index
            int idx = lower_bound(knowledge.begin(), knowledge.end(), ii(a, b)) - knowledge.begin();
            update(idx);
        }

    }

    return 0;
}