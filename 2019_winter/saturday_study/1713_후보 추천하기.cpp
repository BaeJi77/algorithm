#include <cstdio>
#include <vector>


using namespace std;

int N, Q;

int main(){
    freopen("input.txt" ,"r" , stdin);
    scanf("%d" , &N);
    scanf("%d" , &Q);
    
    vector<pair<int,pair<int,int>>> vpii;
    for(int i = 0 ; i < Q ; i++){
        int in;
        scanf("%d" , &in);
        //첫번째 비었는지. -> 꽉찼다면 같은 수 있는지 체크 -> 
        // 같은 수가 나왔는지 확인
        bool nosame = false;
        for(int j = 0 ; j < vpii.size() ; j++){
            if(vpii[j].first == in){ //같은 숫자가 존재하는 경우 투표수 증가. 
                vpii[j].second.second++;
                nosame = true;
            }
        }

        if(nosame == false){
            if(vpii.size() != N) {
                vpii.push_back({in,{i,1}});
            }else{ //비교 시작
                for (int j = 0 ; j < N ; j++){
                    
                }
            }
        }

        if (i < N){ // 비어있는 경우
            

            if(nosame == false){
                
            }
        }else { // 비어있지 않은 경우지

        }
        else if(i < N){
                vpii.push_back({in,{i,1}});
            }else if(i >= N){ // 버릴 애들 생각해보자

            }
        }
    }
}
