<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> add185c... 18.07.06
//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n, x, y;
//int jin;
//int arr[1010][1010];
//bool check;
//
//int main() {
//    scanf("%d %d %d", &n, &y, &x);
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            scanf("%d", &arr[i][j]);
//            if (i == y && j == x) jin = arr[i][j];
//        }
//    }
//    
//    for (int i = 1; i <= n; i++) {
//        if (jin < arr[y][i]) check = true;
//    }
//    
//    for (int i = 1; i <= n; i++) {
//        if (jin < arr[i][x]) check = true;
//    }
//    
//    if (check == false) { printf("HAPPY"); }
//    else { printf("ANGRY"); }
//}
////
<<<<<<< HEAD

=======
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, x, y;
int jin;
int arr[1010][1010];
bool check;

int main() {
    scanf("%d %d %d", &n, &y, &x);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            if (i == y && j == x) jin = arr[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (jin < arr[y][i]) check = true;
    }
    
    for (int i = 1; i <= n; i++) {
        if (jin < arr[i][x]) check = true;
    }
    
    if (check == false) { printf("HAPPY"); }
    else { printf("ANGRY"); }
}
>>>>>>> 69999cd... 18.05.29
=======

>>>>>>> add185c... 18.07.06
