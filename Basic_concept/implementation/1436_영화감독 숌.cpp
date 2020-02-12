#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> vt;

void init(){
    for(int i = 666 ; i < 3e6 ;i++){
        int temp = i;
        int contiNumber = 0;
        while(temp != 0){
            int remain = temp % 10;
            if(remain == 6){
                contiNumber++;
            }else{
                contiNumber = 0;
            }
            temp /= 10;
            if(contiNumber == 3){
                vt.push_back(i);
                break;
            }
        }
    }
}


int main(){
    freopen("input.txt","r",stdin);
    init();
    scanf("%d", &N);
    printf("%d", vt[N-1]);
}