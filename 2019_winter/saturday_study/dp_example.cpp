#include <iostream>
#include <algorithm>

using namespace std;

long long cache[100];

//인자 만으로 모든 상태를 표현가능해야함.
//이전 상태와 다음 상태와는 전혀 달라야함. 인자는 반드시 독립적으로 되어야함.
long long func(int n){
    if(n ==1 || n== 2){
        return 1;
    }

    long long &ret = cache[n];
    if(ret != -1){
        return ret;
    }

    return ret = func(n-1) + func(n-2);
}

int main(){
    fill(cache, cache + 100, -1);
    cout<<func(50)<<endl;
}