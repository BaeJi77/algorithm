//  https://www.acmicpc.net/problem/10448
//  10448_유레카이론.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;


int test,input;
vector<int> vt;

void makeThree(){
    int sum = 0;
    for (int i = 1; i <= 50; i++) {
        sum += i;
        vt.push_back(sum);
    }
    
}

int search(int number){
    for (int i = 0; i < vt.size(); i++) {
        for (int j = 0; j < vt.size(); j++) {
            for (int k = 0 ; k < vt.size(); k++) {
                int sum = vt[i] + vt[j] + vt[k];
                if(number == sum){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    makeThree();
    scanf("%d" , &test);
    while (test--) {
        scanf("%d" , &input);
        int ans = search(input);
        printf("%d\n" , ans);
    }
}
