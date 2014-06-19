#include <iostream>
#include <vector>
using namespace std;

string modifiedString(string s){
	int write_index=0;
	int a_count=0;
	for(char c : s){
		if(c!='b'){
			s[write_index++]=c;
		}
		if(c=='a')
			a_count++;
	}
	s.resize(write_index+a_count);
	int cur_itor=write_index-1;
	write_index=s.size()-1;
	while(cur_itor>=0){
		if(s[cur_itor]=='a'){
			s[write_index--]='d';
			s[write_index--]='d';
		}else{
			s[write_index--]=s[cur_itor];
		}
		cur_itor--;
	}
	return s;
}



int main(){
	cout<<modifiedString("abcabc");
}