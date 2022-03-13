#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <memory>

using namespace std;

class Hasher {
    long long base, mod;

public:
    Hasher(long long base, long long mod) : base(base), mod(mod) {}

    int hash(string s) {
        if(s.size() == 0)
            return 0;

        long long h = s[0];
        for(int i = 1; i < s.size(); i++) {
            h = (h * base + s[i]) % mod;
        }

        return h;
    }
};

class TrieNode {
    int count = 0;
    unordered_map<int, shared_ptr<TrieNode>> child;

public:
    void insert(const vector<int>& s, int i) {
        count++;
        if(i == s.size()) {
            return;
        }

        if(child[s[i]] == nullptr) {
            child[s[i]] = make_shared<TrieNode>();
        }

        child[s[i]]->insert(s, i+1);
    }

    int get(const vector<int>& s, int i) {
        if(i == s.size()) {
            return count;
        }

        if(child.count(s[i]) == 0) {
            return 0;
        }

        return child[s[i]]->get(s, i+1);
    }
};

int main() {
    Hasher hasher(131, 1000000007);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":\n";

        int n, q;
        string line, word;
        TrieNode root;

        cin >> n >> q;
        getline(cin, line); // the endl

        for(int i = 0; i < n; i++) {
            getline(cin, line);
            stringstream ss(line);

            vector<int> hash;
            while(ss >> word) {
                hash.push_back(hasher.hash(word));
            }

            for(int i = 0; i < hash.size(); i++) {
                root.insert(hash, i);
            }
        }

        for(int i = 0; i < q; i++) {
            getline(cin, line);
            stringstream ss(line);

            vector<int> hash;
            while(ss >> word) {
                hash.push_back(hasher.hash(word));
            }

            cout << root.get(hash, 0) << '\n';
        }

    }

    return 0;
}
