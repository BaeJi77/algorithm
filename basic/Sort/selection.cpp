#include <cstdio>

void view(int list[]){
    for(int i = 0; i < 5 ; i++){
        printf("%d " , list[i]);
    }
    puts("");
}

void selection_sort(int list[], int length){
    for(int i = 0 ; i < length ; i++){
        int key = list[i];
        int midx = i;
        for(int j = i+1; j < length ; j++){
            if(key > list[j]){
                key = list[j];
                midx = j;
            }
        }

        int temp = list[i];
        list[i] = key;
        list[midx] = temp;
        view(list);
    }
}

int main(){
    int list[] = {5,4,3,2,1};
    selection_sort(list, 5);
}