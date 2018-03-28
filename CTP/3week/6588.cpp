#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m;
int result;
int input;
int Min;
int Max;
// int input;
// int sum;
bool arr[MAXX+10];
vector <int> vt;



int main(){
	freopen("input.txt", "r", stdin);

	arr[0]=true;
	arr[1]=true;
	while(cin>>input){
		if(input == 0)   break;
		for(int i = 2 ; i <= input ; i++){
			if(arr[i]==false){
				vt.push_back(i);
				for(int j = 2*i ; j <= input ; j = j + i){
					if(arr[j]) continue;
					// vt.push_back(j);
					arr[j] = true;
				}
			}
		}
		int vtSize = vt.size();
		sort(vt.begin() , vt.end());

		for(int i = 1 ; i < vtSize ; i++){
			for(int j = 0 ; j < vtSize-1 ; j++){
				result = vt[i] + vt[vtSize-1-j];
				if(result == input){
					Min = vt[i];
					Max = vt[vtSize-1-j];
					break;
				}
			}
		}

		printf("%d = %d + %d\n", input, Max, Min);
	}

}