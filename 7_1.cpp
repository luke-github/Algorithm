#include <iostream>
using namespace std;

string intToString(int x){
	bool is_negative=false;
	if(x<0){
		x=-x;
		is_negative=true;
	}
	string s;
	while(x){
		s.push_back('0'+x%10);
		x/=10;
	}
	if(s.empty()){
		return {"0"};
	}
	if(is_negative){
		s.push_back('-');
	}
	reverse(s.begin(),s.end());
	return s;
}

int stringToInt(string x){
	if(x=="-"){
		throw invalid_argument("illegal input");
	}
	bool is_negative = x[0]=='-';
	int result=0;
	for(int i=is_negative;i<x.size();i++){
		if(isdigit(x[i])){
			result=result*10+(x[i]-'0');
		}else{
			throw invalid_argument("illegal input");
		}
	}
	if(is_negative)
		result=-result;
	return result;
}

int main(){
	int input=-5236;
	string inputstr="-12a34";
	cout<<intToString(input)<<endl<<stringToInt(inputstr)<<endl;

}