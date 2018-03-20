#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int kim;
int im;
int check=0;


int main(){
	freopen("input.txt", "r", stdin);
	cin>>n>>kim>>im;
	/*
		swap을 통해 한쪽만을 크게 만들어서 나머지 경우를 삭제시킨다.
		*/
	while(1){
		check++;
		if((kim%2==1)&&((kim+1)==im))
			break;
		if((im%2==1)&&((im+1)==kim))
			break;
		

		if(kim%2==0){
			kim = kim/2;
		}else{
			kim = kim/2+1;
		}

		if(im%2==0){
			im = im/2;
		}else{
			im = im/2+1;
		}
	}

	printf("%d",check);

}