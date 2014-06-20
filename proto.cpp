#include <iostream>
#include <array>
using namespace std;

array<string,10> M={"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void phone_num_parser_handler(string &num,int index,string &ans);
void phone_num_parser(string& num){
	string ans(num.size(),0);
	phone_num_parser_handler(num,0,ans);
}

void phone_num_parser_handler(string &num,int index,string &ans){
	if(index==num.size()){
		cout<<ans<<":";
	}else{
		for(char c : M[num[index]-'0']){
			ans[index]=c;
			phone_num_parser_handler(num,index+1,ans);
		}
	}
}

int main(){
	string input="234";
	phone_num_parser(input);

}