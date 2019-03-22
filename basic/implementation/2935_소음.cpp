#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    string a,b;
    char oper;
    getline(cin, a);
    oper = getchar();
    cin>>b;
    if(oper == '+'){
        //같은 자리수라고 한다면
        if(a.length() == b.length()){
            a[0] = '2';
            for(int i = 0 ; i < a.length() ; i++){
                printf("%c", a[i]);
            }
        } else if(a.length() > b.length() ) {
            int minus = a.length() - b.length();
            a[minus] = '1';
            for(int i = 0 ; i < a.length() ; i++){
                printf("%c", a[i]);
            }
        } else {
            int minus = b.length() - a.length();
            b[minus] = '1';
            for(int i = 0 ; i < b.length() ; i++){
                printf("%c", b[i]);
            }
        }
        //다른 자리수라고 한다면
    }else if('*'){
        int length = a.length() + b.length() - 2;
        printf("1");
        for(int i = 0 ; i <length ; i++){
            printf("0");
        }
    }
}

// 10000 // 5
// + 
// 10   // 2