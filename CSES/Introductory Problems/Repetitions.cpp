#include <iostream>
#define ll long long
#include <string>
using namespace std;
int main(){
	string str;
	cin >> str;
	int n = 1;
	int m = 1;
	for(int i = 1; i < str.length(); i++){
		if(str[i] == str[i-1]){
			n++;
		}else{
			n = 1;
		}
		if(n > m) m = n;
	}
	cout << m << endl;
}