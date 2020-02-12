#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include<iostream>

#define MAX 100000000
using namespace std;

int map[54][54];
bool visited[54][54];
vector<pair<int,int> > chi;
vector<pair<int,int> > home;

int N,M;

int dist(int a,int b,int c, int d){
    return abs(a-c) + abs(b-d);
}

int calDist(int chiNumber){
    int ret = 0;
    // cout<<chiNumber<<endl;
    bool flag = false;
    vector<pair<int,int> > temp;
    // for(int i = 0 ; i <= 1<<chi.size() ; i++){
    //     for(int j = 0 ; j < chi.size() ; j++){
    //         // cout<<i<<" "<<j<<endl;
    //         if((i & (1<<j)) != 0){
    //             // cout<<j<<" "<<endl;
    //             temp.push_back(make_pair(chi[j].first,chi[j].second));
    //             // if(temp.size() == M)
    //             //     flag = true;
    //             //     break;
    //         }
    //     }
    //     // if(flag)
    //     //         break;
    // }

    // cout<<chiNumber<<" "<<temp.size()<<endl;
    // for(int j = 0 ; j < temp.size() ; j++){
    //     cout<<temp[j].first<<" "<<temp[j].second<<endl;
    // }

    for(int j = 0 ; j < chi.size() ; j++){
        if((chiNumber & (1<<j)) != 0)
            temp.push_back(make_pair(chi[j].first,chi[j].second));
    }

    for(int i = 0 ; i < home.size() ; i++){
        int mindist = MAX;
        for(int j = 0 ; j < temp.size() ; j++){
            mindist = min(mindist , dist(home[i].first,home[i].second,temp[j].first,temp[j].second));
        }
        ret += mindist;
    }

    return ret;
}

int main(){
    freopen("input.txt", "r",stdin);
    scanf("%d %d" , &N,&M);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d" , &map[i][j]);
            if(map[i][j] == 1)
                home.push_back(make_pair(i,j));
            if(map[i][j] == 2){
                chi.push_back(make_pair(i,j));
            }
        }
    }

    int minChidist = MAX;
    for(int i = 0 ; i <= 1<<chi.size() ; i++){
        int cnt = 0;
        for(int j = 0 ; j < chi.size() ; j++){
            if((i & (1<<j)) != 0)
                cnt++;
        }

        if(cnt == M){
            int ret = calDist(i);
            minChidist = min(minChidist , ret);
        }
    }

    printf("%d" , minChidist);
}