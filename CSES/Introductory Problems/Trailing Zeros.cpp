#include <iostream>
#define ll long long
using namespace std;
int main(){
	ll int contador = 0;
	ll int n = 0;
	cin >> n;
	int num = 5;
	while(num <= n){
		contador += n / num;
		num *= 5;
	}

	 cout << contador << endl;
	
	return 0;
}

