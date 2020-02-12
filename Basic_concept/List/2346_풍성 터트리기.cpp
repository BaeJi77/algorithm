//  https://www.acmicpc.net/problem/2346
//  2346_풍성 터트리기.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 30..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <list>
using namespace std;

int N;
list<pair<int, int>> LL;
list<pair<int, int>>::iterator it;

int main(){
    scanf("%d" , &N);
    for(int i = 1 ; i <= N ; i++){
        int a;
        scanf("%d" , &a);
        LL.push_back({a,i});
    }
    
    it = LL.begin();
    
    
    
}
