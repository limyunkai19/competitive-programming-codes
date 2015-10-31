#include <iostream>

using namespace std;

int main()
{
    int word[20]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
    int wordvpower[8]={6,6,5,5,5,7,6,6};
    int hundred = 7, andz = 3, temp;
    unsigned long long int sum = 0;
    for(int i = 1; i < 1000; i++){
        if(i >= 100){
            sum += word[i/100] + hundred + andz;
            temp = i%100;
            if(temp < 20)
                sum += word[temp];
            else if(temp >= 20)
                sum += wordvpower[temp/10-2] + word[temp%10];
        }
        else if(i < 100){
            if(i < 20)
                sum += word[i];
            else if(i >= 20)
                sum += wordvpower[i/10-2] + word[i%10];
        }
    }
    sum += 3 + 8;
    cout << sum << endl;
    return 0;
}
