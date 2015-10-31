#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

vector<char> text;
vector<char> removed;
vector<int> index;
int line_num = 0;


int main()
{
    freopen("input.txt", "r", stdin);
    char temp;
    temp = getchar();
    while(temp != EOF){
        text.push_back(temp);
        if(temp >= 'A' && temp <= 'Z'){
            removed.push_back(temp + 'a' - 'A');
            index.push_back(line_num);
        }
        else if(temp >= 'a' && temp <= 'z'){
            removed.push_back(temp);
            index.push_back(line_num);
        }
        line_num++;
        temp = getchar();
    }

    int max = 1, first = index[0], last = index[0], a, b, length, size = removed.size();
    for(int i = 1; i < size; i++){
        if(removed[i-1] == removed[i]){ // even length
            length = 2;
            a = i-2;
            b = i+1;
            while(a >= 0 && b < size && removed[a] == removed[b]){
                length += 2;
                a--;
                b++;
            }
            if(length > max){
                max = length;
                first = index[a+1];
                last = index[b-1];
            }
        }
        a = i-1;
        b = i+1;
        length = 1;
        while(a >= 0 && b < size && removed[a] == removed[b]){                          // odd length
            length += 2;
            a--;
            b++;
        }
        if(length > max){
            max = length;
            first = index[a+1];
            last = index[b-1];
        }

    }

    cout << max << endl;
    for(int i = first; i <= last; i++){
        cout << text[i];
    }
    cout << endl;
    return 0;
}
