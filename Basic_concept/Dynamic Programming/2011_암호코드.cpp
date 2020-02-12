#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e6;

string str;
int cache[5001];

int func(int idx){
    if(idx == -1)
        return 1;
    
    int& ret = cache[idx];
    if(ret != -1)
        return ret;
    
    ret = 0;
    if(str[idx] - '0' > 0)
        ret = func(idx - 1) % MOD;
    
    if(idx > 0){
        int number = str[idx]-'0' + (str[idx-1]-'0') * 10;
        if(number <= 26 && number >= 10)
            ret += func(idx - 2);
    }
    
    return ret % MOD;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>str;
    memset(cache,-1,sizeof(cache));
    int ans = func(str.size() - 1) % MOD;
    printf("%d", ans);
}