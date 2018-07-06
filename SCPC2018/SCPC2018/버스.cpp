//
//  main.cpp
//  SCPC2018
//
//  Created by Hoon on 2018. 6. 23..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <queue>
using namespace std;
int peo , K;
int T;
int input;
queue<int> qu;
vector<int> vt;

int main(int argc, const char * argv[]) {
    scanf("%d" , &T);
    int test_case = 0;
    while (T--) {
        scanf("%d %d" , &peo, &K);
        for (int i = 0 ; i < peo; i++) {
            scanf("%d" , &input);
            vt.push_back(input);
        }
        sort(vt.begin(),vt.end());
        qu.push(vt[0]);
        for (int i = 1; i < vt.size(); i++) {
            if(vt[i] - qu.front() > K){
                qu.pop();
                qu.push(vt[i]);
            }else{
                qu.push(vt[i]);
            }
        }
        cout << "Case #" << test_case+1 << endl;
        cout << qu.size() << endl;
        test_case++;
        
        while (qu.size() != 0) {
            qu.pop();
        }
        vt.clear();
    }
    return 0;
}


