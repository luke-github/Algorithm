#include <iostream>
#include <vector>
using namespace std;

int stringToInt(string x){
	if(x=="-"){
		throw invalid_argument("illegal input");
	}
	bool is_negative = x[0]=='-';
	int result=0;
	for(int i=is_negative;i<x.size();i++){
		if(isdigit(x[i])){
			result=result*10+x[i]-'0';
		}else{
			throw invalid_argument("illegal input");
		}
	}
	if(is_negative)
		result=-result;
	return result;
}

string inToString(int x){
	bool is_negative=false;
	if(x<0){
		x=-x;
		is_negative=true;
	}
	string result;
	while(x){
		result.push_back('0'+x%10);
		x/=10;
	}
	if(result.empty()){
		return "0";
	}
	if(is_negative)
		result.push_back('-');
	reverse(result.begin(),result.end());
	return result;
}

int main(){
	int inputint=-123;
	string inputstr="-1a23";
	cout<<inToString(inputint)<<" "<<stringToInt(inputstr)<<endl;
}