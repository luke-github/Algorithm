#include <iostream>
using namespace std;

int compare(double a,double b);


double square_root_real(double x){
	double l,r;
	if(compare(x,1.0)==-1){
		l=x,r=1.0;
	}else{
		l=1.0,r=x;
	}
	while(compare(l,r)==-1){
		double m = (l+r)*0.5;
		double res = m*m;
		if(compare(res,x)==0){
			return m;
		}else if(compare(res,x)==1){
			r=m;
		}else{
			l=m;
		}
	}
	return l;
}

int compare(double a,double b){
	double diff = (a-b)/b;
	int result =  diff<-numeric_limits<double>::epsilon()? -1 : diff>numeric_limits<double>::epsilon();
	return result;
}

int main(){
	double input = 11111111232434;
	cout<<square_root_real(input);
}