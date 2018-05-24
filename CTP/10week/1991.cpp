#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,m,v,x,y;
vector <vector <int> > vt;
bool visited[10004];

queue <int> qu;
bool discover[10004];


int tree[26][2];
int N;
char a,b,c;
int aa,bb,cc;
// int A,B,C;

void preorder(int here) {
	printf("%c" , here + 'A');
	if(tree[here][0] != -1) preorder(tree[here][0]);
	if(tree[here][1] != -1) preorder(tree[here][1]);
}

void inorder(int here){
	if(tree[here][0] != -1) inorder(tree[here][0]);
	printf("%c", here + 'A');
	if(tree[here][1] != -1) inorder(tree[here][1]);
}

void postorder(int here){
	if(tree[here][0] != -1) postorder(tree[here][0]);
	if(tree[here][1] != -1) postorder(tree[here][1]);
	printf("%c", here + 'A');
}



int main(){
	freopen("input.txt" , "r" , stdin);
	// memset(tree,-1,sizeof(tree));

	scanf("%d" , &N);
	while(N--){
		scanf(" %c %c %c" , &a , &b , &c);	
		if(a == '.') aa = -1; 
		else {aa = a - 'A';}
		if(b == '.') bb = -1; else {bb = b - 'A';}
		if(c == '.') cc = -1; else {cc = c - 'A';}
		tree[aa][0] = bb;
		tree[aa][1] = cc;
	}
	
	preorder(0);
	puts("");
	inorder(0);
	puts("");
	postorder(0);

}
