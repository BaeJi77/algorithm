////
////  회문.cpp
////  SCPC2018
////
////  Created by Hoon on 2018. 6. 23..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//vector<int> vt;
//vector<int> ans;
//bool fin;
//int t,in,cnt;
//int temp;
//int tempin;
//bool flag;
//void make(){
//    for (int i = 1; i < 10000; i++) {
//        string TS = to_string(i);
//        reverse(TS.begin(),TS.end());
//        int temp = stoi(TS);
//        if(i == temp) vt.push_back(i);
//    }
//}
//
//void set(){
//    int find = 12345;
//    for (int i = 0; i < vt.size(); i++) {
//        if(tempin - vt[i] == 0){
//            find = vt[i];
//            fin = true;
//            break;
//        }
//
//        if (tempin - vt[i] > 0) {
//            find = vt[i];
//            break;
//        }
//    }
//    tempin = tempin - find;
//    ans.push_back(find);
//    cnt++;
//}
//
//int main(){
//    make();
//    reverse(vt.begin(), vt.end());
//    scanf("%d" , &t);
//    int test_case =0;
//    while (t--) {
//        cnt = 0;
//        in = 0;
//        ans.clear();
//        fin = false;
//        flag = false;
//        scanf("%d" , &in);
//        tempin=in;
//        //한번에 대는 경우
//        set();
//        if(fin==true){
//            cout<<"Case #"<<test_case+1<<endl;
//            cout<<cnt<<" ";
//            for (int i = 0; i < ans.size(); i++) {
//                cout<<ans[i]<<" ";
//            }
//            cout<<endl;
//            test_case++;
//            continue;
//        }
//        tempin=in;
//        cnt = 0;
//        ans.clear();
//        for (int i = 0; i < vt.size(); i++) {
//            for (int j = 0 ; j < vt.size(); j++) {
//                int total = vt[i]+vt[j];
//                if(tempin - total == 0){
//                    cout<<"Case #"<<test_case+1<<endl;
//                    cout<<2<<" "<<vt[i]<<" "<<vt[j]<<endl;
//                    test_case++;
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag == true) break;
//        }
//        if (flag == true) continue;
//
//        tempin=in;
//        for (int i = 0; i < 3; i++) {
//            set();
//            if (fin==true) break;
//        }
//        cout<<"Case #"<<test_case+1<<endl;
//        if (fin == false) {
//            cout<<0<<endl;
//        }else{
//            cout<<cnt<<" ";
//            for (int i = 0; i < ans.size(); i++) {
//                cout<<ans[i]<<" ";
//            }
//            cout<<endl;
//        }
//        test_case++;
//    }
//}
//
//
