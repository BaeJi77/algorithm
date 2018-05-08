
#include <iostream>
using namespace std;

int T;
int K;
int M,N;
int arr[52][52];
int visited[52][52];
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};


void DFS(int a, int b)
{
	int A1=0;
	int B1=0;
	for(int i=0; i<4; i++)
	{
		A1 = a + X[i];
		B1 = b + Y[i];

		if(A1>=0 && B1>=0 && A1<N && B1<M && arr[A1][B1] ==1 && visited[A1][B1] ==0)
		{
			DFS(A1,B1);
		}
	}
	return;


}

int main()
{
	freopen("input.txt" , "r" , stdin);
	cin>>T;
	while(T--)
	{
		cin>>M>>N>>K;
		while(K--)
		{
			int a =0;
			int b =0;
			cin>>a>>b;
			arr[a][b] =1;
		}
		int cnt =0;

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				if(visited[i][j] ==0 && arr[i][j] ==1)
				{
					DFS(i,j);
					cnt++;
				}	
			}
		}
		cout<<cnt<<endl;

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				visited[i][j]=0;
			}
		}

	}

	return 0;
}