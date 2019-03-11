#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


struct stair{
    int x;
    int y;
    int time;
    stair(int x,int y, int t):x(x),y(y),time(t){};
};

struct person{
    int x;
    int y;
    int dist1;
    int dist2;
    person(int x, int y):x(x),y(y){};
};

const int inf = 987654321;

int N,map[14][14],ans;
vector<stair> vst;
vector<person> vpe;


int update(vector<int> v, int t){
    
    // printf("%d " , t);
    
    // for(int i = 0 ; i < v.size() ; i++)
    //     printf("%d " , v[i]);
    // puts("");

    if(v.size() == 0)
        return 0;
    
    sort(v.begin() , v.end());
    int use[3] = {0,};
    int time = 0;
    int checkCnt = 0;

    while(1){
        time++;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] == 0)
                continue;
            //도착한 시간이 된 경우
            if(v[i] <= time){
                //비어있는 것을 찾기
                for(int j = 0 ; j < 3 ; j++){
                    if(use[j] <= 0){
                        use[j] = t;
                        v[i] = 0;
                        checkCnt++;
                        break;
                    }
                }
            }
        }

        if(v.size() == checkCnt){
            break;
        }   

        for(int i = 0 ; i < 3 ; i++){
            use[i]--;
        }        
    }
    // printf("time: %d\n", time + t);
    return time + t + 1;
}

void dfs(int k, vector<int> a, vector<int> b){
    if(k == vpe.size()){
        int aresult = update(a, vst[0].time);
        int bresult = update(b, vst[1].time);
        // puts("");
        ans = min(ans, max(aresult, bresult)) ;
        return;
    }
    
    a.push_back(vpe[k].dist1);
    dfs(k+1, a, b);
    a.pop_back();

    b.push_back(vpe[k].dist2);
    dfs(k+1, a, b);
    b.pop_back();
}


int main() {
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d" , &t);
    for(int tc = 1 ; tc <= t ; tc++){
        scanf("%d",  &N);
        vst.clear();
        vpe.clear();
        for(int i = 0 ; i < N ; i++){
            for(int j = 0; j < N; j++){
                int x;
                scanf("%d", &x);
                if(x == 1)
                    vpe.push_back(person(j,i));
                else if (x > 1)
                    vst.push_back(stair(j,i,x));
            }
        }

        for(int i = 0 ; i < vpe.size() ; i++){
            vpe[i].dist1 = abs(vpe[i].x - vst[0].x) + abs(vpe[i].y - vst[0].y);
            vpe[i].dist2 = abs(vpe[i].x - vst[1].x) + abs(vpe[i].y - vst[1].y);
        }
        
        vector<int> a;
        vector<int> b;
        ans = inf;
        dfs(0, a, b);

        printf("#%d %d\n" , tc, ans);
    }
}