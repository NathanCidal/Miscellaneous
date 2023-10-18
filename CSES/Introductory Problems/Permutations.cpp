#include <iostream>
#include <string>
using namespace std;
int main(){
	long long int n = 0;
	cin >> n;
	if(n == 1){ cout << 1 << endl; }
	else{
	
	if(n == 3 || n == 2){ cout << "NO SOLUTION" << endl; }else{
	for(int i = 0; i < n; i++){
		if(i % 2 == 1) cout << n - i << " ";
	}

	for(int i = 0; i < n; i++){
		if(i % 2 == 0) cout << n - i << " ";
	}

	}
	}
	return 0;
}