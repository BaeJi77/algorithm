#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int N;
int maxsize;
vector<int> vt;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);

    for(int i = 0 ; i < N ; i++){
        vector<int> newVt;
        int pre = N;
        int after = N-i;
        while(pre >= 0){
            // printf("%d %d %d\n" , pre, after, pre-after);
            newVt.push_back(pre);
            int tempMinus = pre-after;
            pre = after;
            after = tempMinus;
        }

        // printf("size: %d %d\n" , newVt.size(), maxsize);

        if(newVt.size() > maxsize){
        
            maxsize = newVt.size();
            vt = newVt;
        }

        // puts("");
    }

    printf("%d\n" , maxsize);
    for(int i = 0 ; i < maxsize ; i++){
        printf("%d " , vt[i]);
    }
}