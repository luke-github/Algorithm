#include <iostream>
#include <vector>
using namespace std;
int square_root_integer(int x){
	int l=0,r=x;
	while(l+1<r){
		int m = (l+r)/2;
		int square = m*m;
		if(square==x){
			return m;
		}else if(square>x){
			r=m-1;
		}else{
			l=m;
		}
	}
	if(r*r>x)
		return l;
	else
		return r;
}
int main(){
	cout<<square_root_integer(26);
}