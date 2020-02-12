#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	string str="";
	cin>>str;
	int arr[26] = {0,};
	for(int i=0;i<str.length();i++){
		if(str[i].compare("a")==0){
				arr[0]++;
		}else if(str[i].compare("b")==0){
				arr[1]++;
		}else if(str[i].compare("c")==0){
				arr[2]++;
		}else if(str[i].compare("d")==0){
				arr[3]++;
		}else if(str[i].compare("e")==0){
				arr[4]++;
		}else if(str[i].compare("f")==0){
				arr[5]++;
		}else if(str[i].compare("g")==0){
				arr[6]++;
		}else if(str[i].compare("h")==0){
				arr[7]++;
		}else if(str[i].compare("i")==0){
				arr[8]++;
		}else if(str[i].compare("j")==0){
				arr[9]++;
		}else if(str[i].compare("k")==0){
				arr[10]++;
		}else if(str[i].compare("l")==0){
				arr[11]++;
		}else if(str[i].compare("m")==0){
				arr[12]++;
		}else if(str[i].compare("n")==0){
				arr[13]++;
		}else if(str[i].compare("o")==0){
				arr[14]++;
		}else if(str[i].compare("p")==0){
				arr[15]++;
		}else if(str[i].compare("q")==0){
				arr[16]++;
		}else if(str[i].compare("r")==0){
				arr[17]++;
		}else if(str[i].compare("s")==0){
				arr[18]++;
		}else if(str[i].compare("t")==0){
				arr[19]++;
		}else if(str[i].compare("u")==0){
				arr[20]++;
		}else if(str[i].compare("v")==0){
				arr[21]++;
		}else if(str[i].compare("w")==0){
				arr[22]++;
		}else if(str[i].compare("x")==0){
				arr[23]++;
		}else if(str[i].compare("y")==0){
				arr[24]++;
		}else(str[i].compare("z")==0){
				arr[25]++;
	}}
	for(int i=0;i<26;i++){
		c{out<<arr[i]<<" ";
}	}
}