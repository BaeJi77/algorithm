#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str[20];
int strLenght[20];

int main(){
    freopen("input.txt","r",stdin);
    int maxLength = 0;
    int cnt = 0;
    for(int i = 0 ; i < 5 ; i++){
        cin>>str[i];
        maxLength = max(maxLength, (int)str[i].length());
    }

    for(int i = 0 ; i < maxLength ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(str[j].size() -1 < i)
                continue;
            
            cout<<str[j][i];
        }
    }
}