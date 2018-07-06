//
//  2667.cpp
//  11week
//
//  Created by Hoon on 2018. 6. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
int numb[30][30];
int visited[30][30];
int nextx[4] = {0,0,-1,1};
int nexty[4] = {1,-1,0,0};
queue <pair<int,int>> q;
vector<int> flower;
bool notgood(int y,int x){
    if(x<0||y<0||x>=N||y>=N)
    return true;
    return false;
}
void func(int y,int x){
    int floer = 0;
    q.push(make_pair(y, x));
    while(int s = q.size()){
        while(s--){
            int yv = q.front().first;
            int xv = q.front().second;
            visited[yv][xv] = true;
            floer++;
            q.pop();
            for(int i =0;i<4;i++)
            {int ny = yv + nexty[i];
                int nx = xv + nextx[i];
                if(notgood(ny,nx))
                continue;
                if(!visited[ny][nx]&&numb[ny][nx]==1)
                q.push(make_pair(ny,nx));
                visited[ny][nx] = 1;
            }
        }
    }
    flower.push_back(floer);
}
int main(){
    cin>>N ;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        for(int j=0;j<N;j++){
            numb[i][j] = temp[j]-'0';
        }}
    
    int answer =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(numb[j][i]==1&&visited[j][i]==0)
            {func(j,i);
                answer++;
            }}}
    cout<<answer<<endl;
    
    sort(flower.begin(),flower.end());
    for(int i=0;i<flower.size();i++){
        cout<<flower[i]<<endl;
    }
    
}
