#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// A = 0 B = 1 C = 2 D = 3 E = 4 F = 5 G = 6 H = 7 I = 8

int c[9];
vector<int> curr;
vector<int> ans;
int mini = 1000000, cur=0, k;

void print_(){
    for(int i = 0; i < 9; i++){
        cout << c[i] << " ";
        if(i%3 == 2){
            cout << endl;
        }
    }
}

bool done(){
    for(int i = 0; i < 9; i++){
        if(c[i]%4 != 0){
            return false;
        }
    }
    return true;
}

void t2(int i);
void t3(int i);
void t4(int i);
void t5(int i);
void t6(int i);
void t7(int i);
void t8(int i);
void t9(int i);

void t1(int i){if(cur >= mini)return;c[0]+=i;c[1]+=i;c[3]+=i;c[4]+=i;cur+=i;k=i;while(k--){curr.push_back(1);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t2(0);t2(1);t2(2);t2(3);
    c[0]-=i;c[1]-=i;c[3]-=i;c[4]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}
void t2(int i){if(cur >= mini)return;c[0]+=i;c[1]+=i;c[2]+=i;cur+=i;k=i;while(k--){curr.push_back(2);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t3(0);t3(1);t3(2);t3(3);
    c[0]-=i;c[1]-=i;c[2]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}
void t3(int i){if(cur >= mini)return;c[1]+=i;c[2]+=i;c[4]+=i;c[5]+=i;cur+=i;k=i;while(k--){curr.push_back(3);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t4(0);t4(1);t4(2);t4(3);
    c[1]-=i;c[2]-=i;c[4]-=i;c[5]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}
void t4(int i){if(cur >= mini)return;c[0]+=i;c[3]+=i;c[6]+=i;cur+=i;k=i;while(k--){curr.push_back(4);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t5(0);t5(1);t5(2);t5(3);
    c[0]-=i;c[3]-=i;c[6]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}
void t5(int i){if(cur >= mini)return;c[1]+=i;c[3]+=i;c[4]+=i;c[5]+=i;c[7]+=i;cur+=i;k=i;while(k--){curr.push_back(5);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t6(0);t6(1);t6(2);t6(3);
    c[1]-=i;c[3]-=i;c[4]-=i;c[5]-=i;c[7]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}
void t6(int i){if(cur >= mini)return;c[2]+=i;c[5]+=i;c[8]+=i;cur+=i;k=i;while(k--){curr.push_back(6);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t7(0);t7(1);t7(2);t7(3);
    c[2]-=i;c[5]-=i;c[8]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}
void t7(int i){if(cur >= mini)return;c[3]+=i;c[4]+=i;c[6]+=i;c[7]+=i;cur+=i;k=i;while(k--){curr.push_back(7);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t8(0);t8(1);t8(2);t8(3);
    c[3]-=i;c[4]-=i;c[6]-=i;c[7]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}
void t8(int i){if(cur >= mini)return;c[6]+=i;c[7]+=i;c[8]+=i;cur+=i;k=i;while(k--){curr.push_back(8);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    t9(0);t9(1);t9(2);t9(3);
    c[6]-=i;c[7]-=i;c[8]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}void t9(int i){if(cur >= mini)return;c[4]+=i;c[5]+=i;c[7]+=i;c[8]+=i;cur+=i;k=i;while(k--){curr.push_back(9);}
    if(done()){
        if(cur < mini){
            mini = cur;
            ans = curr;
        }
    }
    c[4]-=i;c[5]-=i;c[7]-=i;c[8]-=i;cur-=i;k=i;while(k--){curr.pop_back();}
}

void turn(){
    t1(0);t1(1);t1(2);t1(3);
}

int main()
{
    for(int i = 0; i < 9; i++){
        cin >> k;
        c[i] = k/3;
    }
    turn();
    for(int i = 0; i < ans.size(); i++){
        if(i){cout << " ";}
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
