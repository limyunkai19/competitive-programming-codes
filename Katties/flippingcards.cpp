// observation:
// if a card have frequency of 1, it must face up (greedy)
// suppose that now, no card have frequency of 1, there are 2 cases
// case 1:  number of unique number < n
//          in this case, it is trivially impossible
// case 2:  number of unique number >= n
//          since no number have fre = 1, fre >= 2,
//          some math will lead to all number have fre = 2, unique = n
//          can do something similar to bipartite check


#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> ii;

bool dfs_card(int u, map<ii, int>& card_faces, map<int, multiset<int> >& cards){
    set<int>::iterator its = cards[u].begin();
    int a = *its, b = *(++its);

    if(card_faces[ii(u, a)] == card_faces[ii(u, b)])
        return false;
    if(card_faces[ii(u, a)] == card_faces[ii(b, u)])
        return true;

    if(card_faces[ii(u, a)] == 0){
        card_faces[ii(u, a)] = -card_faces[ii(u, b)];
        card_faces[ii(a, u)] = -card_faces[ii(u, a)];
    }
    if(card_faces[ii(u, b)] == 0){
        card_faces[ii(u, b)] = -card_faces[ii(u, a)];
        card_faces[ii(b, u)] = -card_faces[ii(u, b)];
    }

    return dfs_card(a, card_faces, cards) && dfs_card(b, card_faces, cards);
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        map<int, multiset<int> > cards;

        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            cards[a].insert(b);
            cards[b].insert(a);
        }

        int unique = cards.size();
        queue<int> fre1;

        for(auto it = cards.begin(); it != cards.end(); it++){
            if((it->second).size() == 1)
                fre1.push(it->first);
        }

        while(!fre1.empty()){
            int u = fre1.front(); fre1.pop();
            if(cards[u].size() == 0){
                unique--;
                continue;
            }
            int opposite = *cards[u].begin();
            cards[u].clear();
            unique--;
            n--;
            cards[opposite].erase(cards[opposite].find(u));
            if(cards[opposite].size() == 1)
                fre1.push(opposite);
        }

        if(unique < n){
            cout << "impossible" << endl;
        }
        else{
            // all card have fre = 2, perform kinda bipartite check
            map<ii, int> card_faces;
            string ans = "possible";

            for(auto it = cards.begin(); it != cards.end(); it++){
                if((it->second).size() == 0)
                    continue;

                set<int>::iterator its = (it->second).begin();
                int u = it->first, a = *its, b = *(++its);
                if(a == b) continue;

                if(card_faces[ii(u, a)] == 0){
                    card_faces[ii(u, a)] = 1;
                    card_faces[ii(a, u)] = -1;
                    card_faces[ii(u, b)] = -1;
                    card_faces[ii(b, u)] = 1;

                    if(!dfs_card(u, card_faces, cards)){
                        ans = "impossible";
                    }
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}