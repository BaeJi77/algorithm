#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector <int> vt;
int input;
int sum;
int MMin;


int main(){
	freopen("input.txt", "r", stdin);
	
	for(int i = 0 ; i < 7 ; i++){
		scanf("%d" , &input);
		if(input%2 == 1){
			vt.push_back(input);
			sum += input;
		}
	}
	sort(vt.begin(), vt.end());
	if(sum == 0){
		printf("-1");
		return 0;
	}else{
		MMin = vt[0];
	}
	
	// for(int i = 0 ; i < vt.size() ; i++){
	// 	printf("%d\n" , vt[i]);
	// }
	printf("%d\n%d" , sum , MMin);

}



