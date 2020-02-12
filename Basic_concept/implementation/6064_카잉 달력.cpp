#include <cstdio>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    freopen("input.txt","r",stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int M,N,goalX, goalY;
        scanf("%d %d %d %d", &M,&N,&goalX, &goalY);
        int cnt = goalX % (M + 1);
        int tempY = goalX;
 
        for (int i = 0; i < N; i++) {
            if(tempY % N == 0)
                tempY = N;
            else
                tempY %= N;
            if(tempY == goalY)
                break;

            tempY += M;
            cnt += M;
        }

        printf("%d\n", cnt > lcm(M, N) ? -1 : cnt);
    }
}