#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

ll N, K; // N은 1억, K는 10억
ll kNumber[20];
ll digitNumber[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    freopen("/Users/baejihoon/Desktop/알고리즘/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    
    if(N >= K && N < 10 && K < 10) {
        printf("%d", K);
        return 0;
    } else if (N < 10 && K < 10 && N < K){
        printf("-1");
        return 0;
    }

    // ll i = 1;
    // ll digit = 0;
    // while(1) {
    //     if(digit >= 190) break;
    //     if(i < 10) digit++;
    //     if(10 <= i && i < 100) digit += 2;
    //     if(100 <= i && i < 1000) digit += 3;
    //     printf("%d", i);
    //     i++;
    // }
    // printf("\n%d %d\n", i, digit);
        
    ll cumulativeSum = 0;
    ll maxDigit = 1;
    ll product = 1;
    while(1) {
        if(K < cumulativeSum + product * 9 * digitNumber[maxDigit]) {
            break;
        }
        cumulativeSum += product * 9 * digitNumber[maxDigit];
        
        maxDigit++;
        product *= 10;
    }

    ll temProduct = product;
    ll moveDigit = maxDigit;
    while(1) {
        if(moveDigit == 0)
            break;
        
        int division = (K - cumulativeSum) / (product * digitNumber[maxDigit]);

        cumulativeSum += division * product * digitNumber[maxDigit];

        if(maxDigit == moveDigit) division++;
        if(division != 0 && moveDigit == 1) division--;
        kNumber[moveDigit] = division;
        
        moveDigit--;
        product /= 10;
    }

    int realKNumber = 0;
    for(ll i = maxDigit ; i >= 1 ; i--) {
        realKNumber += kNumber[i];
        if(i != 1) realKNumber *= 10;
    }
    // if(realKNumber / temProduct == 1 && realKNumber % temProduct == 0) cumulativeSum += digitNumber[maxDigit];
    printf("%d", realKNumber);
    puts("");
    printf("%d %d %d %d\n", K, cumulativeSum, realKNumber, K - cumulativeSum + 1);

    if(K == cumulativeSum) {
        printf("%d", kNumber[1]);
        return 0;
    }

    // if(K > cumulativeSum) {
    //     realKNumber++;
    //     cumulativeSum += digitNumber[maxDigit];
    // }
    printf("%d %d\n",N , realKNumber);
    if(N < realKNumber) printf("-1");
    else {
        int ansDigit = cumulativeSum - K + 1;
        string kString = to_string(realKNumber);
        cout<<kString<<endl;
        printf("%d\n", ansDigit);
        int ans = 0;
        while(1) {
            if(ansDigit == 0)
                break;
            ans = realKNumber % 10;
            realKNumber /= 10;
            ansDigit--;
        }
        printf("%d\n", ans);
    }
}