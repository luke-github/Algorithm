#include <iostream>
#include <vector>
using namespace std;

void count_occurance(string s){
	sort(s.begin(),s.end());
	int count=1;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			count++;
		}else{
			cout<<s[i-1]<<" "<<count<<endl;
			count=1;
		}
	}
}

int main(){
	string input = "aasdfasdfasdfasdfasdfl;jlk;qweroipuczv";
	count_occurance(input);
}