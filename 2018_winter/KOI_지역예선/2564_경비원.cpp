//https://www.acmicpc.net/problem/2564

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
vector<pair<int,int> > vt;

int main(){
    freopen("input.txt" , "r" , stdin);
    scanf("%d %d" , &N,&M);
    int q;
    scanf("%d" , &q);
    for(int i = 0 ; i < q ; i++){
        int a,b;
        scanf("%d %d" , &a,&b);
        if(a==1){
            vt.push_back(make_pair(0,b));
        }else if(a==2){
            vt.push_back(make_pair(M,b));
        }else if(a==3){
            vt.push_back(make_pair(b,0));
        }else if(a==4){
            vt.push_back(make_pair(b,N));
        }
    }   
    int z,w,x,y,flag;
    scanf("%d %d" , &z,&w);
    if(z==1){
        y=0;
        x=w;
        flag = 1;
    }else if(z==2){
        y=M;
        x=w;
        flag = 1;
    }else if(z==3){
        y=w;
        x=0;
        flag = 2;
    }else if(z==4){
        y=w;
        x=N;
        flag = 2;
    }

    int sum=0;
    for(int i = 0 ; i < q ; i++){
        int yy = vt[i].first;
        int xx = vt[i].second;
        if(flag == 1){
            if(yy == y){
                sum+=abs(xx-x); 
            }else if(xx == 0){
                sum+=x+abs(y-yy);
            }else if(xx == N){
                sum+=abs(xx-x)+abs(y-yy);
            }else{
                sum+= min(x+xx,abs(N-x)+abs(N-xx))+M;
            }
        }else{
            if(xx == x){
                sum+= abs(yy-y);
            }else if(yy == 0){
                sum+= y+abs(x-xx);
            }else if(yy == M){
                sum+=abs(yy-y)+abs(x-xx);
            }else {
                sum+=min(y+yy,abs(M-y)+abs(M-yy))+N;
            }
        }
    }
    printf("%d" , sum);
}