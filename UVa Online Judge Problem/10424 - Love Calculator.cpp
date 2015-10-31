#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	string a, b;
	int suma, sumb, temp;
	while(getline(cin, a), getline(cin, b)){
	    suma = 0; sumb = 0;
        for(int i = 0; i < a.size(); i++){
            if(isalpha(a[i])){
                a[i] = tolower(a[i]);
                suma += a[i] - 'a' + 1;
            }
        }
        for(int i = 0; i < b.size(); i++){
            if(isalpha(b[i])){
                b[i] = tolower(b[i]);
                sumb += b[i] - 'a' + 1;
            }
        }
        while(suma >= 10){
            temp = 0;
            while(suma > 0){
                temp += suma%10;
                suma /= 10;
            }
            suma = temp;
        }
        while(sumb >= 10){
            temp = 0;
            while(sumb > 0){
                temp += sumb%10;
                sumb /= 10;
            }
            sumb = temp;
        }
        //cout << suma << " " << sumb << endl;
        if(suma > sumb){
            swap(suma, sumb);
        }
        printf("%0.2lf %%\n", ((double)(suma)/(double)(sumb))*100.0);

	}
	return 0;
}
