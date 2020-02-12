#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

int N,ans;
int map[20][20];

bool isposs(int y, int x){
    return y >= 0 && x >= 0 && y < N && x < N;
}

void copyMap(int preMap[][20], int newMap[][20]){
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++){
            newMap[i][j] = preMap[i][j];
        }
    }
}

//같은게 있는 경우 1리턴
int matchSamePosition(vector<pair<int, int> > vt, int y, int x){
    for(int i = 0 ; i < vt.size(); i++){
        if(vt[i].first == y && vt[i].second == x)
            return 1;
    }
    return 0;
}

//대각선을 다 확인했을 때 
int checkGoodResult(vector<pair<int, int> > vt){
    bool result = 1;
    int temp[20][20] = {0,};
    printf("size: %d\n", vt.size());
    for(int k = 0 ; k < vt.size() ; k++){
        int y = vt[k].first;
        int x = vt[k].second;
        map[y][x] = 1;
        for(int i = y+1 ; i < N ; i++){
            for(int j = x+1 ; j < N ; j++){
                if(isposs(i, j) && matchSamePosition(vt, i, j)){
                    return 0;
                }
            }
        }

        for(int i = y-1 ; i >= 0 ; i--){
            for(int j = x-1 ; j >= 0 ; j--){
                if(isposs(i, j) && matchSamePosition(vt, i, j)){
                    return 0;
                }
            }
        }        

        for(int i = y+1 ; i < N ; i++){
            for(int j = x-1 ; j >= 0 ; j--){
                if(isposs(i, j) && matchSamePosition(vt, i, j)){
                    return 0;
                }
            }
        }

        for(int i = y+1 ; i < N ; i++){
            for(int j = x+1 ; j < N ; j++){
                if(isposs(i, j) && matchSamePosition(vt, i, j)){
                    return 0;
                }
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d " , map[i][j]);
        }
        puts("");
    }
    puts("");
    
    //괜찮으면 1, 좋지 않으면 0 리턴
    return 1;
}

//1 2 4 8 16

//y, x는 각 해당하는 비트를 가지고 있음
int solve(vector<pair<int, int> > vt ,int y, int x){
    if(vt.size() > N)
        return 0;
    
    printf("%d %d\n" , y, x);
    if(vt.size() == N){
        //중복체크
        if(y == (1<<N)-1 && x == (1<<N)-1)
            return checkGoodResult(vt);
        else 
            return 0;
    }

    int ret = 0;
    
    for(int i = 0 ; i < N ; i++){
        // for(int j = 0 ; j < N ; j++){
        //     int yBit = y | 1<<i;
        //     int xBit = x | 1<<j;
        //     vt.push_back(make_pair(i, j));
        //     ret += solve(vt, yBit, xBit);
        // }
        //false인 경우 선택이 안되어있음
        if(!(y & (1<<i))){
            int yBit = y | 1<<i;
            for(int j = 0 ; j < N ; j++){
                // vt.push_back(make_pair(i, j));
                // ret += solve()
                if(!(x & (1<<j))){
                    int xBit = x | 1<<j;
                    vt.push_back(make_pair(i,j));
                    ret += solve(vt, yBit, xBit);
                }
            }
        }
    }

    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    vector<pair<int, int> > vp;
    ans = solve(vp, 0, 0);
    printf("%d\n" , ans);
}