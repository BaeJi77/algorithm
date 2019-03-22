#include <cstdio>

using namespace std;



void view(int list[]){
    for(int i = 0 ; i < 5 ; i++)
        printf("%d ", list[i]);
    puts("");
}

void insertion_sort(int list[], int length){
    for(int i = 0 ; i < length ; i++){
        int key = list[i];
        int j = i-1;
        while(j >= 0){
            if(key >= list[j])
                break;
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
        view(list);
    }
}

int main(){
    int list[] = {5, 4, 3, 2, 1};
    insertion_sort(list, 5);
}