#include <cstdio>
#include <vector>

using namespace std;

int n,m;
int good;
int temp;
int result;
int input1,input2;
int sum;
vector <int> vt;


int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d %d" , &n,&m);
	for(int i=0 ; i<n ; i++){
		scanf("%d" , &good);
		temp += good;
		vt.push_back(temp);
		// printf("%d\n", temp);
	}

	for(int i = 0 ; i < m ; i++){
		scanf("%d%d" , &input1, &input2);
		if(input1 == 1){
			result = vt[input2-1];
		}else {
			result = vt[input2-1] - vt[input1-2];
		}

		
		printf("%d\n", result);
	}
}