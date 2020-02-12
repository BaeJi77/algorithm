////
////  10448.cpp
////  11week
////
////  Created by Hoon on 2018. 5. 20..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//int T;
//int input;
//int n;
//int size;
//int minus; bool check;
//vector <int> vt;
//
//void set(){
//    int maxx;
//    do{
//        n++;
//        maxx = n*(n+1)/2;
//        vt.push_back(maxx);
//    }while(maxx<1000);
//}
//
//int main(){
//    scanf("%d" , &T);
//    set();
//    size = vt.size();
//    while (T--) {
//        scanf("%d" ,&input);
//        for(int i = 0 ; i < size ; i++){
//            for(int j = 0 ; j < size ; j++){
//                for(int k = 0 ; k < size ; k++){
//                    int temp = vt[i]+vt[j]+vt[k];
//                    if(input-temp == 0) {
//                        check = true;
//                        break;
//                    }
//                }
//                if(check) break;
//            }
//            if (check) break;
//        }
//        if(check == false) printf("0\n");
//        else printf("1\n");
//        check = false;
//    }
//}

