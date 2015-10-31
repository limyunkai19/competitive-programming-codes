/*
ID: yunkai91
LANG: C++
TASK: heritage
*/

#include <iostream>
#include <cstdio>

using namespace std;

string inorder, preorder;

void postorder(int inx, int iny, int prex, int prey){
    if(inx == iny){
        cout << inorder[inx];
        return;
    }
    if(inx > iny) return;

    char root = preorder[prex];
    int rootin;
    for(int i = inx; i <= iny; i++){
        if(root == inorder[i]){
            rootin = i;
            break;
        }
    }
    int leftsize = rootin-inx, rightsize = iny-rootin;
    postorder(inx, inx+leftsize-1, prex+1, prex+leftsize);
    postorder(rootin+1, iny, prey-rightsize+1, prey);
    cout << preorder[prex];
}

int main(){
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);

    cin >> inorder >> preorder;
    postorder(0, inorder.size()-1, 0, preorder.size()-1);
    cout << endl;
    return 0;
}