#include <iostream>
#include <string>
using namespace std;
int main(){
long long int n;
int mod = 1e9 + 7;
cin >> n;
long long int resposta = 1;
for(int i = 0; i < n; i++){
	resposta *= 2;
	resposta %= mod;
}
cout << resposta << endl;
return 0;
}