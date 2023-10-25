#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ofstream arq;
	arq.open("Default.cpp", ios::out);
	if(!arq.is_open()) return 1;
	
	arq << "#include <iostream>" << endl;
	arq << "#include <string>" << endl << endl;
	arq << "using namespace std;" << endl << endl;
	arq << "int main(){" << endl << endl;
	arq << "	return 0;" << endl << "}" << endl;
	arq.close();

	return 0;
}