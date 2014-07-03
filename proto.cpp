#include <iostream>
#include <vector>
using namespace std;

void count_occurance(string s){
	sort(s.begin(),s.end());
	int counter=1;
	for(int i=1;i<s.size();i++){
		if(s[i-1]==s[i]){
			counter++;
		}else{
			cout<<s[i-1]<<" "<<counter<<endl;
			counter=1;
		}
	}
}

int main(){
	string input = "asdfkjaklsnmvxzc";
	count_occurance(input);
}