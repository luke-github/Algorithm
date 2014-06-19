#include <iostream>
using namespace std;

void reverse_words(string & str){
	reverse(str.begin(),str.end());
	int start=0;
	int end;
	while((end=str.find(" ",start))!=string::npos){
		reverse(str.begin()+start,str.begin()+end);
		start=end+1;
	}
	reverse(str.begin()+start,str.end());
}
int main(){
	string input="123 234 345";
	reverse_words(input);
	cout<<input;
}