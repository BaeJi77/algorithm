//
//  1976.cpp
//  10week-second
//
//  Created by Hoon on 2018. 5. 11..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;

int n , m;
vector <int> vt;


int find(int number){
    if(vt[number] < 0) return number;
    int root = find(vt[number]);
    vt[number] = root;
    return vt[number];
}

bool set(int x,int y){
    int XX = find(x);
    int YY = find(y);
    if(XX==YY){
        return true;
    }
    return false;
}



int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; i++){
        vt.push_back()
    }
    
    
}
