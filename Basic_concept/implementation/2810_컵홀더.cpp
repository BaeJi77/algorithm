#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int N,cnt;
string str;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    cin>>str;
    for(int i = 0 ; i < str.size(); i++){
        if(str[i] == 'S'){
            cnt++;
        }else if(str[i] == 'L'){
            cnt++;
            i++;
        }
    }
    
    printf("%d", N < cnt + 1 ? N : cnt+1);
}