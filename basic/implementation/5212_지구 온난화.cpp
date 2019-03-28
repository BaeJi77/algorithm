#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char map[11][11] = {'.',};
int N,M;
vector<pair<int, int> > vt;
vector<pair<int, int> > point;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};


bool isSea(int y,int x){
    if(y < 0 || x < 0 || y >= N || x >= M)
        return true;
    if(map[y][x] == '.')
        return true;
    return false;
}


//섬으로 살아 남으면 true
void isIsland(int y, int x){
    int cnt = 0;
    for(int i = 0 ; i < 4 ; i++){
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        if(isSea(yy, xx))
            cnt++;
    }
    if(cnt > 2)
        point.push_back(make_pair(y,x));
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i <10 ; i++){
        for(int j = 0 ; j < 10 ; j++)
            map[i][j] = '.';
    }
    for(int i = 0 ; i < N ; i++){
        getchar();
        for(int j = 0 ; j < M ; j++){
            scanf("%c", &map[i][j]);
            if(map[i][j] == 'X')
                vt.push_back(make_pair(i,j));
        }
    }

    for(int i = 0 ; i < vt.size() ; i++){
        isIsland(vt[i].first, vt[i].second);
    }
    
    for(int i = 0 ; i < point.size(); i++){
        map[point[i].first][point[i].second] = '.';
    }

    int sy,ey, sx, ex;
    int checky[11] = {0,};
    int checkx[11] = {0,};
    bool flag = 0;
    for(int i = 0 ; i < 10 ; i++){
        int cnt = 0;
        for(int j = 0 ; j < 10 ; j++){
            if(map[i][j] == '.')
                cnt++;
        }
        if(cnt != 10){
            checky[i] = i; 
        }else{
            checky[i] = -1;
        }
        // printf("%d %d\n", cnt, checky[i]);
        cnt = 0;

        for(int j = 0 ; j < 10 ; j++){
            if(map[j][i] == '.')
                cnt++;
        }
        if(cnt != 10){
            checkx[i] = i; 
        }else{
            checkx[i] = -1;
        }
    }

    int miny = 11;
    int maxy = -1;
    int minx = 11;
    int maxx = -1;
    for(int i = 0 ; i < 10 ; i++){
        if(checky[i] != -1){
            miny = min(miny, checky[i]);
            maxy = max(maxy, checky[i]);
        }
        
        if(checkx[i] != -1){
            minx = min(minx, checkx[i]);
            maxx = max(maxx, checkx[i]);
        }
    }


    for(int i = miny ; i <= maxy ; i++){
        for(int j = minx ; j <= maxx ; j++){
            printf("%c", map[i][j]);
        }
        puts("");
    }
}