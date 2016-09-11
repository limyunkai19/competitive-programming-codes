#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct Node{
    bool ended;
    map<char, Node*> child;
    Node(){ended = false;}

};

int main(){
    Node* trieRoot = new Node();

    string s;
    while(cin >> s && s != "#"){
        // build trie;
        Node* curNode = trieRoot;
        for(int i = 0; i < s.size(); i++){
            if(curNode->child[s[i]] == NULL){
                curNode->child[s[i]] = new Node();
            }
            curNode = curNode->child[s[i]];
        }
        curNode->ended = true;
    }

    while(cin >> s && s != "#"){
        string x;
        while(s[s.size()-1] != '|'){
            cin >> x;
            s += x;
        }

        vector<int> dp(s.size(), 0);

        for(int i = 0; i < s.size()-1; i++){
            Node * curNode = trieRoot;
            int j = i;
            while(curNode->child[s[j]] != NULL){
                curNode = curNode->child[s[j]];
                j++;
                if(curNode->ended){
                    dp[j] = max(dp[j], dp[i]+1);
                    break;
                }
            }
            dp[i+1] = max(dp[i+1], dp[i]);
        }
        cout << dp[s.size()-1] << endl;
    }

    return 0;
}