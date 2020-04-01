#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1e5;

int N;
vector<int> primes;

void findPrime () {
    int primeCheckArray[MAX+1];
    for(int i = 2 ; i <= MAX ; i++)
        primeCheckArray[i] = i;

    for(int i = 2 ; i <= sqrt(MAX) ; i++) {
        if(primeCheckArray[i] == 0)
            continue;

        for(int j = i+i ; j <= MAX ; j+=i) {
            primeCheckArray[j] = 0;
        }
    }

    for(int i = 2 ; i <= MAX ; i++) 
        if(primeCheckArray[i] != 0)
            primes.push_back(i);

    printf("%d\n", primes.size());
    for(int i = 0 ; i <= primes.size() ; i++) 
        printf("%d ", primes[i]);
}

int cal (int a, int b) {
    int ret;


    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    findPrime();
    while(N--) {

    }
}