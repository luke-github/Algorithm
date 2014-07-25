#include <iostream>
using namespace std;

struct Rectangle{
	int x,y,width,height;
};

bool is_intersect(Rectangle R, Rectangle S){
	return R.x+R.width>=S.x && R.x <= S.x+S.width && R.y+R.height>=S.y && R.y <= S.y+S.height; 
}

Rectangle inttersect_algorithm(Rectangle& R, Rectangle& S){
	if(is_intersect(R,S)){
		return {max(R.x,S.x),max(R.y,S.y),min(R.x+R.width,S.x+S.width)-max(R.x,S.x),min(R.y+R.height,S.y+S.height)-max(R.y,S.y)};
	}else{
		return {0,0,-1,-1};
	}
}

int main(){
	Rectangle r1 = {1,1,5,5}, r2 = {2,2,5,5};
	auto res = inttersect_algorithm(r1,r2);
	cout<<res.x<<" "<<res.y<<" "<<res.width<<" "<<res.height<<endl;
}