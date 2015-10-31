#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream indigit("1000 digit.txt");
    string digit;
    indigit >> digit;
    int array[1000], product, maxproduct=0;
    for(int i = 0; i < 1000; i++){
        array[i] = digit.at(i) - '0';
    }
    for(int i = 0; i < 995; i++){
        product = array[i]*array[i+1]*array[i+2]*array[i+3]*array[i+4];
        if(product > maxproduct){
            maxproduct = product;
        }
    }
    cout << maxproduct << endl;
    return 0;
}
