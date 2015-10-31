#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> product;
    product.push_back(1);
    for(int i = 0; i < 1000; i++){
        for(int k = 0; k < product.size(); k++){
            product[k] *= 2;
        }
        int temp = product.size();
        for(int k = 0; k < temp; k++){
            while(product[k] >= 10){
                if(k != temp - 1){
                    product[k+1] += product[k]/10;
                    product[k] %= 10;
                }
                else if(k == temp - 1){
                    product.push_back(product[k]/10);
                    product[k] %= 10;
                }
            }
        }
    }
    int sumOfdigit=0;
    for(int i = product.size()-1; i >= 0; i--){
        sumOfdigit += product[i];
    }
    cout << sumOfdigit << endl;

    return 0;
}
