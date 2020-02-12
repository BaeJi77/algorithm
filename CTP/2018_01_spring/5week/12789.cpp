#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>


using namespace std;

int n;
int inp;

stack<int> first;
stack<int> temp;
vector<int> vt;
priority_queue<int> pq;


int arr[1010];



int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d",&n);
	int tmp;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]);
		pq.push(-arr[i]);
	}	

	for(int i = 0 ; i < n ; i++){
		arr[i] = -pq.top();
		pq.pop();
	}
	sort(vt.begin(),vt.end());

}
