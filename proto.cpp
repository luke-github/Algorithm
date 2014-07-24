#include <iostream>
using namespace std;

int spreadsheet_algorithm(const string& s){
	int res = 0;
	for(char x : s){
		res *= 26;
		res += x-'A'+1;
	}
	return res;
}

int main(){
	string input = "AA";
	cout<<spreadsheet_algorithm(input);
}