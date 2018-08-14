//
//  main.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 8. 13..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;

int test,outNumber;
vector<int> vt;

int main(){
    scanf("%d" , &test);
    while(test--){
        double sum=0;
        vt.clear();
        for(int i = 0 ; i < 10 ; i++){
            double a;
            scanf("%lf" , &a);
            sum+=a;
        }
        sum /= 10;
        outNumber++;
        printf("#%d %d\n" , outNumber,(int)(sum+0.5));
    }
}
