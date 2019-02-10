//CLOCKSYNC(https://algospot.com/judge/problem/read/CLOCKSYNC)

#include <iostream>

using namespace std;

const int SWITCHS = 10;
int n , T[10]; 

void func(int pos){
    if(pos == SWITCHS){
        //배열 T는 각 스위치가 얼마나 눌렸는지 기록한 배열
        //1. T를 이용해서 모든 시계가 12시인지 확인가능
        //2 . T를 이용해서 스위치가 총 몇번 눌렀ㅈ는지 확인 가능
    }

    //**전역변수 하나를 가지고 모든 완전 탐색을 이루어지도록 접근하는 방법이 중요**
    //pos에서 선택할 수 있는 네 가지의 경우의 수
    //0번, 1번, 2번, 3번 누른다.
    for(int i = 0 ; i < 4 ; i++){
        T[pos] = i;
        func(pos+1);
        T[pos] = -1;
    }
}

int main(){

}