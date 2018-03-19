#include <iostream>
#include <string>
#include <vector>



using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	int a,b,c;
	// int aAarr[5];
	vector<int> aArr;
	vector<int> bArr;
	vector<int> cArr;
	vector<int> dArr;
	vector<int> result;

	cin>>n;
	if(n==2){
		cin>>a>>b;
		for(int i=1;i<a+1;i++){
			if(a%i==0){
				aArr.push_back(i);
			}
		}
		for(int i=1;i<b+1;i++){
			if(b%i==0){
				bArr.push_back(i);
			}
		}
		for(int i=0;i<aArr.size();i++){
			for(int j=0;j<bArr.size();j++){
				if(aArr[i]==bArr[j]){
					result.push_back(aArr[i]);
				}

			}
		}
	}

	if(n==3){
		cin>>a>>b>>c;
		for(int i=1;i<a+1;i++){
			if(a%i==0){
				aArr.push_back(i);
			}
		}
		for(int i=1;i<b+1;i++){
			if(b%i==0){
				bArr.push_back(i);
			}
		}
		for(int i=1;i<c+1;i++){
			if(c%i==0){
				cArr.push_back(i);
			}
		}
		for(int i=0;i<aArr.size();i++){
			for(int j=0;j<bArr.size();j++){
				if(aArr[i]==bArr[j]){
					dArr.push_back(aArr[i]);
				}

			}
		}
		for(int i=0;i<cArr.size();i++){
			for(int j=0;j<dArr.size();j++){
				if(cArr[i]==dArr[j]){
					result.push_back(cArr[i]);
				}

			}
		}
	}

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<"\n";
	}
}