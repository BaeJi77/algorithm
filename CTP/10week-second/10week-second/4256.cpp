//
//  4256.cpp
//  10week-second
//
//  Created by Hoon on 2018. 6. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int T,n,ns;
vector<int> preord;
vector<int> inord;

vector<int> slice(const vector<int>& vt,int a,int b){
    return vector<int>(vt.begin()+a,vt.begin()+b);
}

void printpost(int a,int b,int fix){
    if(a>b)
    return;
    if(fix>ns)
    return;
    
    int root = preord[fix];
    const int N = b-a;
    const int L = find(inord.begin(),inord.end(),root)-inord.begin();
    
    //cout<<a<<" "<<L-1<<" "<<fix+1<<endl;
    //cout<<L+1<<" "<<b<<" "<<fix+L+1<<endl;
    if(a!=b){
        printpost(a,L-1,fix+1);
        printpost(L+1,b,fix+L-a+1);
    }
    printf("%d ",root);
    
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int temp;
        for(int i=0;i<n;i++) {
            scanf("%d",&temp);
            preord.push_back(temp);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&temp);
            inord.push_back(temp);
        }
        ns = preord.size();
        printpost(0,ns-1,0);
        printf("\n");
        preord.clear();
        inord.clear();
    }
    
}
