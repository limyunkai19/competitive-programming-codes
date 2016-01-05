#include <iostream>

using namespace std;

int main(){
    string s;
    while(cin >> s && s != "0"){
        cout << s << ' ';
        int sum = 0, deg = 1;
        for(int i = 0; i < s.size(); i++){
            sum += s[i]-'0';
        }
        if(sum%9 != 0){
            cout << "is not a multiple of 9." << endl;
        }
        else{
            while(sum != 9){
                int tmp = sum;
                sum = 0;
                while(tmp > 0){
                    sum += tmp%10;
                    tmp /= 10;
                }
                deg++;
            }
            cout << "is a multiple of 9 and has 9-degree " << deg << '.' << endl;
        }
    }

    return 0;
}