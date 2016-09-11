#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bundle{
    vector<int> item;
    vector<bool> appended;
    int price, appended_price, appended_item;

    Bundle(int _price){
        price = _price;
        appended_price = 0;
        appended_item = 0;
    }

    void sort_item(){
        sort(item.begin(), item.end());
    }

    // for sorting
    bool operator< (Bundle x){
        return this->item.size() < x.item.size();
    }

    bool having(int one_of_item){
        for(int i = 0; i < item.size(); i++){
            if(item[i] == one_of_item)
                return true;
        }
        return false;
    }

    void append(Bundle x){
        appended_price += x.price;
        int idx = 0;
        for(int i = 0; i < x.item.size(); i++){
            int next_item = x.item[i];
            while(this->item[idx] != next_item)
                idx++;
            appended[idx] = true;
            appended_item++;
        }

        if(appended_item == this->item.size()){
            this->price = min(this->price, appended_price);
        }
    }
};

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector<Bundle> bundles;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            bundles.push_back(Bundle(x));
            cin >> x;
            while(x--){
                int y;
                cin >> y;
                bundles[i].item.push_back(y);
                bundles[i].appended.push_back(false);
            }
            bundles[i].sort_item();
        }
        sort(bundles.begin(), bundles.end());

        // add a full set at the back
        bundles.push_back(Bundle(1<<30));
        for(int i = 1; i <= n; i++){
            bundles[m].item.push_back(i);
            bundles[m].appended.push_back(false);
        }

        for(int i = 0; i < m; i++){
            // this bundle will be a subset of 1 item after this item
            // until m as m+1 is a virtual bundle
            int one_of_item = bundles[i].item[0];
            for(int j = i+1; j < m+1; j++){
                if(bundles[j].having(one_of_item)){
                    // this is the bundle we looking
                    bundles[j].append(bundles[i]);
                    break;
                }
            }
        }

        cout << bundles[m].price << endl;
    }




    return 0;
}