#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e5;

int arr[MAX+1];

int main(){
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--){
        bool error = false;
        vector<int> vt;
        string q;
        int N;
        cin>>q;
        scanf("%d", &N);
        getchar();
        for(int i = 0 ; i < N ; i++){
            char temp;
            int a;
            scanf("%c%d",&temp ,&a);
            vt.push_back(a);
        }
        getchar();
        
        int reverCnt = 0;
        int eraseCnt = 0;
        int order = 0; // 0: 정방향 -> frontCersor < backCursor, 1: 반대방향 backCursor < frontCersor
        int frontCursor = 0;
        int backCursor = vt.size();
        for(int i = 0 ; i < q.size(); i++){
            if(q[i] == 'R'){
                int temp = frontCursor;
                frontCursor = backCursor;
                backCursor = temp;
                if(order == 0){
                    frontCursor--;
                    backCursor--;
                }else{
                    frontCursor++;
                    backCursor++;
                }

                order++;
                order %= 2;
            }else{
                if(order == 0)
                    frontCursor++;
                else if(order == 1)
                    frontCursor--;
                if(order == 0 && frontCursor > backCursor){
                    error = true;
                    break;
                }else if(order == 1 && frontCursor < backCursor){
                    error = true;
                    break;
                }
            }

            // if(q[i] == 'R'){
            //     if(eraseCnt > 0)
            //         vt.erase(vt.begin(), vt.begin() + eraseCnt);
            //     reverCnt++;
            //     reverCnt %= 2;
            //     eraseCnt = 0;
            // }else{
            //     if(vt.size() == 0){
            //         error = true;
            //         break;
            //     }
            //     if(reverCnt)
            //         reverse(vt.begin(), vt.end());
            //     eraseCnt++;
            //     reverCnt = 0;
            // }
        }
        // if(vt.size() < eraseCnt)
        //     error = true;

        if(error){
            printf("error");
        }else{
            // if(eraseCnt != 0)
            //     vt.erase(vt.begin(), vt.begin() + eraseCnt);
            if(frontCursor == backCursor)
                printf("[]");
            if(order == 0){
                for(int i = frontCursor ; i < backCursor ; i++){
                    if(i == frontCursor)
                        printf("[%d", vt[i]);
                    else
                        printf(",%d",vt[i]);
                    if(i == backCursor-1)
                        printf("]");
                }
            }else{
                for(int i = frontCursor ; i > backCursor ; i--){
                    if(i == frontCursor)
                        printf("[%d", vt[i]);
                    else
                        printf(",%d",vt[i]);
                    if(i == backCursor+1)
                        printf("]");
                }
            }
            // for(int i = 0 ; i < vt.size(); i++){
            //     if(i == 0)
            //         printf("[%d", vt[i]);
            //     else if(i == vt.size()-1)
            //         printf(",%d]", vt[i]);
            //     else
            //         printf(",%d",vt[i]);
            // }   
        }
        puts("");
    }
}