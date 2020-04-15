#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cassert>


using namespace std;

// const int numbers[] = {(1<<7) - 1 - 64, 10, (1<<7) - 1 - 32 - 2, 79, 106, 1 + 32 + 64 + 2 + 4 + 16, (1<<7) - 1 - 8 - 16, 32 + 1 + 8 + 2, (1<<7) - 1, (1<<7) - 1 - 16 - 4};
const int numbers[] = {(1<<7) - 1 - 64, 10, (1<<7) - 1 - 32 - 2, 79, 106, (1<<7) - 1 - 8 - 16, (1<<7) - 1 - 8, 1 + 2 + 8, (1<<7) - 1, (1<<7) - 1 - 16 - 4};
//(1<<7) - 1

int convertThreeDigitStringToInt(string str) {
    int number = stoi(str);
    for(int i = 0 ; i < 10 ; ++i) {
        if(number == numbers[i]) {
            return i;
        }
    }
}

int stringToInt(string str) {
    int ret = 0;
    for(int i = 0 ; i < str.size(); i += 3) {
        ret *= 10;
        ret += convertThreeDigitStringToInt(str.substr(i, 3));
    }
    return ret;
}

string convertToSevenBit(int number) {
    string ret = "";
    if(number >= 1000) {
        int a1 = numbers[number / 1000];
        if(a1 < 100) ret += "0";
        ret += to_string(a1);
    }
    if(number >= 100) {
        // cout<<(number % 1000) / 100<<endl;
        assert(number / 100 < 10);
        // assert((number % 1000) / 100 < 10); // false이면 에러
        int a1 = numbers[(number) / 100];
        if(a1 < 100) ret += "0";
        ret += to_string(a1);
    } 
    if(number >= 10) {
        assert((number % 100) / 10 < 10);
        int a1 = numbers[(number % 100) / 10];
        if(a1 < 100) ret += "0";
        ret += to_string(a1);
    }
    int a1 = numbers[number % 10];
    if(a1 < 100) ret += "0";
    ret += to_string(a1);

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    // for(int i = 0 ; i < 10 ; ++i)
    //     cout<<i<<" "<<numbers[i]<<"\n";
    while(1) {
        string input;
        cin>>input;
        if(input == "BYE") break;

        int plusIdx = 0;
        for(int i = 0 ; i < input.size() ; ++i) {
            if(input[i] == '+') {
                plusIdx = i;
                break;
            }
        }

        int first = stringToInt(input.substr(0, plusIdx));
        int second = stringToInt(input.substr(plusIdx + 1, input.size() - plusIdx - 2));

        // cout<<first<<" "<<second<<endl;
        string printNumber = convertToSevenBit(first + second);
        cout<<input<<printNumber<<"\n";
    }
}