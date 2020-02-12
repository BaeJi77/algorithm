#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#define MAXX 10000010

using namespace std;


int n,m,temp,age;
string name;
int arr[MAXX];

class Person{
	public : 
	int age;
	string name;

	Person(string name , int age){
		this->name = name;
		this->age = age;
	}
};

bool operator <(const Person &a, const Person &b){
    return a.age < b.age;
}

int main(){
	freopen("input.txt", "r", stdin);

	vector<Person> vt;
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; i++){
		cin>>age>>name;
		vt.push_back(Person(name,age));
	}
	sort(vt.begin() , vt.end());
	for(int i = 0 ; i < n ; i ++){
		cout<<vt[i].age<<" "<<vt[i].name<<endl;
	}
}


