#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<double> vt;

int main(){
    freopen("input.txt","r",stdin);
    double a,b;
    scanf("%lf %lf", &a,&b);
    vt.push_back(a/b);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        double a,b;
        scanf("%lf %lf", &a,&b);
        vt.push_back(a/b);
    }

    sort(vt.begin(), vt.end());
    printf("%.02f", vt[0]*1000);
}