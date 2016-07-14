#include <iostream>
#include <map>

using namespace std;

struct Node{
    int count;
    char content;
    map<char, Node*> child;
    Node(char c){
        count = 0;
        content = c;
    }
};

int main() {
    Node* root = new Node('.');
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        Node* cur = root;
        for(int i = 0; i < s.size(); i++){
            cur->count++;
            if(!cur->child[s[i]]){
                cur->child[s[i]] = new Node(s[i]);
            }
            cur = (cur->child[s[i]]);
        }
        cout << cur->count << endl;
        cur->count++;
    }

    return 0;
}