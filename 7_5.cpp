#include <iostream>
#include <array>
using namespace std;

void sequence_generator_handler(string &num, int index, string& ans);

void sequence_generator(string num){
	string ans(num.size(),0);
	sequence_generator_handler(num,0,ans);
}

array<string,10> M={"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void sequence_generator_handler(string &num, int index, string& ans){
	if(index==num.size()){
		cout<<ans<<":";
	}else{
		for(char c : M[num[index]-'0']){
			ans[index]=c;
			sequence_generator_handler(num,index+1,ans);
		}
	}
}

int main(){
	string input = "234";
	sequence_generator(input);

}