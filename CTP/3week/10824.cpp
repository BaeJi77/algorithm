#include <cstdio>
#include <cstring>
// #include <string>
#include <stdlib.h>
#define MAXX 1000000
#include <iostream>

using namespace std;

int n;
int input;
string ab,cd;
string str;
int a,b,c,d;
long long int out1,out2;


int main(){
	freopen("input.txt", "r", stdin);

	cin>>a>>b>>c>>d;
	to_string(a);
	to_string(b);
	to_string(c);
	to_string(d);

	ab = to_string(a) + to_string(b);
	cd = to_string(c) + to_string(d);

	out1 = atoll(ab.c_str());
	out2 = atoll(cd.c_str());

	// cout<<ab;
	cout<<out1+out2;
}