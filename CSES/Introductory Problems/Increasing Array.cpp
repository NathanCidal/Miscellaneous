#include <iostream>
#include <string>

using namespace std;

int main(){
	long long int n = 0;
	cin >> n;
	int v[n];
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	long long int soma = 0;
	for(int i = 1; i < n; i++){
		if(v[i] < v[i-1]){
			soma += v[i-1] - v[i];
			v[i] = v[i-1];
		}
	}	
	cout << soma << endl;

	return 0;
}