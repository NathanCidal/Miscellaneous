#include <iostream>
#define ll long long
using namespace std;
int main(){
	ll int t = 0;
	int n = 0;
	cin >> t;

	ll resposta = 0;
	ll numDiagonal = 0;

	//Se o X for menor que o Y, ele vai ir pra esquerda
	//Se o X for maior, Y significa subir

	ll int x;
	ll int y;

	for(int i = 0; i < t; i++){
	cin >> y >> x;
	if(x >= y){ numDiagonal = (x*x) - (x-1); }
	if(x < y){ numDiagonal = (y*y) - (y-1);  }
	
	if(x > y){
		if(x % 2 == 0){ resposta = numDiagonal - (x - y); }
		else{	resposta = numDiagonal + (x - y); }	
	}

	if(x < y){
		if(y % 2 == 0){ resposta = numDiagonal + (y - x); }
		else{	resposta = numDiagonal - (y - x); }	
	}

	if(x == y) resposta = numDiagonal;
	

	cout << resposta << " ";
	}
	cout << endl;
	
	return 0;
}


