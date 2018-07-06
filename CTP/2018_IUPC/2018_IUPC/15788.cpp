#include <cstdio>

using namespace std;

int n;
long long int arr[510][510];
long long int x;
long long int y;
long long int sum;
long long int temp;
long long int k;
bool check;
bool incheck;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            
            scanf("%lld", &k);
            arr[i][j] = k;
            if (k == 0) {
                x = i;
                y = j;
                incheck = true;
            }
        }
    }
    
    if(incheck == false) {
        printf("-1");
        return 0;
    }
    
    
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        break;
    }
    long long sol=0;
    for(int i=0;i<n;i++){
        sol+=arr[x][i];
    }
    sol=sum-sol;
    
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        for (int j = 0; j < n; j++) {
            temp += arr[i][j];
        }
        if (sum != temp) {
            printf("-1");
            return 0;
        }
        temp = 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == y) continue;
        for (int j = 0; j < n; j++) {
            temp += arr[j][i];
        }
        if (sum != temp) {
            printf("-1");
            return 0;
        }
        temp = 0;
    }
    
    
    for (int i = 0; i < n; i++) {
        temp += arr[i][i];
        if (arr[i][i] == 0) {
            temp+=sol;
            continue;
        }
    }
    if (sum != temp) {
        printf("-1");
        return 0;
    }
    check = false;
    temp = 0;
    
    for (int i = 0; i < n ; i++) {
        temp += arr[i][n-i-1];
        if (arr[i][n-i-1] == 0) {
            temp+=sol;
            continue;
        }
    }
    if (sum != temp) {
        printf("-1");
        return 0;
    }
    
    printf("%lld", sol);
}
