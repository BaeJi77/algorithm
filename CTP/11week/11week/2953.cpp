//
//  2953.cpp
//  11week
//
//  Created by Hoon on 2018. 6. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[5][4];
int s[5];
int pc = 0;

int main(){
    for(int k =0;k<5;k++){
        for(int i =0;i<4;i++)
        {cin>>a[k][i];
            s[k] = s[k]+a[k][i];
        }
    }
    int min = s[0];
    for(int j=1;j<5;j++){
        if(min<s[j])
        {    min = s[j];
            pc = j;}
        
    }
    cout<<pc+1<<" "<<min;
}
