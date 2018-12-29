//https://www.acmicpc.net/problem/2608

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// string a,b;

/*
I	V	X	L	C	D	M
1	5	10	50	100	500	1000

IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 90
*/

int getRoma(string a){
    int sum = 0;
    for(int i = 0 ; i < a.length() ; i++){
        char ch = a[i];
        int ret = 0;
        if(ch == 'M'){
            sum += 1000;
        }else if(ch == 'C' && a[i+1] == 'M'){
            sum += 900;
            i++;
        }else if(ch == 'D'){
            sum += 500;
        }else if(ch == 'C' && a[i+1] == 'D'){
            sum += 400;
            i++;
        }else if(ch == 'C'){
            sum += 100;
        }else if(ch == 'X' && a[i+1] == 'C'){
            sum += 90;
            i++;
        }else if(ch == 'L'){
            sum += 50;
        }else if(ch == 'X' && a[i+1] == 'L'){
            sum += 40;
            i++;
        }else if(ch == 'X'){
            sum += 10;
        }else if(ch == 'I' && a[i+1] == 'X'){
            sum += 9;
            i++;
        }else if(ch == 'V'){
            sum += 5;
        }else if(ch == 'I' && a[i+1] == 'V'){
            sum += 4;
            i++;
        }else if(ch == 'I'){
            sum += 1;
        }
    }
    return sum;
}

int main(){
    string a,b;
    freopen("input.txt","r",stdin); 
    getline(cin,a);
    getline(cin,b);
    int sum = 0;
    sum += getRoma(a);
    sum += getRoma(b);
    //IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900
    printf("%d\n" , sum);
    while(sum != 0){
        if(sum >= 1000){
            printf("M");
            sum -= 1000;
        }else if(1000 > sum && sum >= 900){
            printf("CM");
            sum -= 900;
        }else if(900 > sum && sum >= 500){
            printf("D");
            sum -= 500;
        }else if(500 > sum && sum >= 400){
            printf("CD");
            sum -= 400;
        }else if(400 > sum && sum >= 100){
            printf("C");
            sum -= 100;
        }else if(100 > sum && sum >= 90){
            printf("XC");
            sum -= 90;
        }else if(90 > sum && sum >= 50){
            printf("L");
            sum -= 50;
        }else if(50 > sum && sum >= 40){
            printf("XL");
            sum -= 40;
        }else if(40 > sum && sum >= 10){
            printf("X");
            sum -= 10;
        }else if(10 > sum && sum >= 9){
            printf("IX");
            sum -= 9;
        }else if(9 > sum && sum >= 5){
            printf("V");
            sum -= 5;
        }else if(5 > sum && sum >= 4){
            printf("IV");
            sum -= 4;
        }else if(4 > sum && sum >= 1){
            printf("I");
            sum -= 1;
        }
    }
}
