#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    cin>>str;
    int sum = 0;
    for(int i = 0 ; i < N ; i++){
        sum += str[i] - '0';
    }
    printf("%d", sum);
}