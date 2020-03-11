#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int p,w;

pair<int, int> calculateTypingLetterTime(char letter) {
    int p, pre;
    if(letter == ' ') {
        p = 1;
        pre = 0;
    }
    if('A' <= letter && letter <= 'C') {
        p = letter - 'A' + 1;
        pre = 1;
    }
    if('D' <= letter && letter <= 'F') {
        p = letter - 'D' + 1;
        pre = 2;
    }
        
    if('G' <= letter && letter  <= 'I'){
        p = letter - 'G' + 1;
        pre = 3;
    }
     
    if('J' <= letter && letter  <= 'L'){
        p = letter - 'J' + 1;
        pre = 4;
    }
     
    if('M' <= letter && letter  <= 'O'){
        p = letter - 'M' + 1;
        pre = 5;
    }
     
    if('P' <= letter && letter  <= 'S'){
        p = letter - 'P' + 1;
        pre = 6;
    }
     
    if('T' <= letter && letter  <= 'V'){
        p = letter - 'T' + 1;
        pre = 7;
    }
         
    if('W' <= letter && letter  <= 'Z'){
        p = letter - 'W' + 1;
        pre = 8;
    }
     
    return make_pair(p, pre);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>p>>w;
    getchar();
    string msg;
    getline(cin, msg);
    
    int length = msg.size();
    int pre = 0;
    int ans = 0;
    for(int i = 0 ; i < length ; i++){
        pair<int, int> nowCal = calculateTypingLetterTime(msg[i]);
        int nowP = nowCal.first;
        ans += p * nowP;
        if(pre != 0 && pre == nowCal.second) ans += w;
        pre = nowCal.second;
    }
    cout<<ans;
}