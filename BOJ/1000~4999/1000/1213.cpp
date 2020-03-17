#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string temp;
int arr[100];

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    cin>>temp;
    for(int i = 0 ; i < temp.size() ; i++) {
        arr[temp[i] - 'A']++;
    }

    int justOneCnt = 0;
    int justOneIdx = -1;
    for(int i = 0 ; i < 30 ; i++) {
        if(arr[i] % 2 == 1) {
            justOneCnt++;
            justOneIdx = i;
        }
    }

    if(justOneCnt >= 2) cout<<"I'm Sorry Hansoo\n";
    else if (justOneCnt == 1) {
        for(int i = 0 ; i < 30 ; i++) {
            for(int j = 0 ; j < arr[i] / 2 ; j++)
                cout<<(char)(i + 'A');
        }
        cout<<(char)(justOneIdx + 'A');
        for(int i = 30 ; i >= 0 ; i--) {
            for(int j = 0 ; j < arr[i] / 2 ; j++)
                cout<<(char)(i + 'A');
        }
    } else { // 홀수인 것이 하나 인 경우
        for(int i = 0 ; i < 30 ; i++) {
            for(int j = 0 ; j < arr[i] / 2 ; j++)
                cout<<(char)(i + 'A');
        }
        for(int i = 30 ; i >= 0 ; i--) {
            for(int j = 0 ; j < arr[i] / 2 ; j++)
                cout<<(char)(i + 'A');
        }
    }
}