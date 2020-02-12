#include <cstdio>
#include <queue>
#include<iostream>

using namespace std;

int map[16][16];
int n;
int cnt;

bool isright(int x,int y)
{
    int nx = x; int ny=y+1;
    if(map[nx][ny]==0&&nx<n&&ny<n)return true;
    return false;
}

bool isdown(int x,int y)
{
    int nx = x+1; int ny = y;
    if(map[nx][ny]==0&&nx<n&&ny<n)return true;
    return false;
}

bool iscross(int x,int y)
{
    int nx =x+1;int ny = y+1;
    if(map[nx][ny]==0&&nx<n&&ny<n)return true;
    return false;
}

void bfs(int x,int y , int dir)
{
    queue<pair<pair<int,int> , int > >qu;
    qu.push( { { x, y }, dir } ) ;

    while(!qu.empty())
    {
        int nowx=qu.front().first.first;
        int nowy=qu.front().first.second;
        int d = qu.front().second;

        qu.pop();

        if(nowx==n-1&&nowy==n-1&&d!=2)cnt++;


        if(isright(nowx,nowy)&&d!=1)qu.push({{nowx,nowy+1},0});
        if(isdown(nowx,nowy)&&d!=0)qu.push({{nowx+1,nowy},1});
        if(iscross(nowx,nowy))qu.push({{nowx,nowy},2});
    }
}

//d=0 오른쪽 d=1 아래 d=2 대각선
int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>map[i][j];
        }
    }
    
    if(map[0][1]!=1)
    bfs(0,1,0);

    if(map[1][0]!=1)
    bfs(1,0,1);
    
    cout<<cnt;
    return 0;
}