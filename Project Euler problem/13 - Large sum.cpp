#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream number ("50 digit number.txt");
    string k;
    int num[100][50];
    for(int i = 0; i < 100; i++){
        number >> k;
        for(int j = 49; j >= 0; j--){
            num[i][j] = k.at(49 - j) - '0';
        }
    }
    vector <int> sum;
    for(int i = 0; i < 50; i++){
        sum.push_back(0);
        for(int j = 0; j < 100; j++){
            sum[i] += num[j][i];
        }
    }
    for(int i = 0; i < sum.size(); i++){
        if(i != sum.size() - 1){
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
        else if((i == sum.size() - 1) && sum[i] >= 10){
            sum.push_back(sum[i]/10);
            sum[i] %= 10;
        }
    }
    for(int i = sum.size() - 1; i >= 0; i--){
        cout << sum[i];
    }
    cout << endl;
    return 0;
}
