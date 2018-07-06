//
//  1697.cpp
//  11week_second
//
//  Created by Hoon on 2018. 6. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,k;
int ans;
int visited[200100];
bool po(int n){
    if(n>100002||n<0)
    return false;
    return true;
}
void func(int n){
    queue<int> q;
    
    q.push(n);
    while(int s = q.size()){
        while(s--){
            int xv = q.front();
            visited[xv] = 1;
            if(xv==k)
            return;
            q.pop();
            if(!visited[xv+1]&&po(xv+1))
            q.push(xv+1);
            if(!visited[xv-1]&&po(xv-1))
            q.push(xv-1);
            if(!visited[xv*2]&&po(xv*2))
            q.push(xv*2);
        }
        ans++;
    }
}
int main(){
    scanf("%d %d",&n,&k);
    if(n>=k)
    printf("%d",n-k);
    else{
        func(n);
        printf("%d",ans);
    }
}
