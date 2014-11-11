#include "LResult.h"

using namespace std;

LResult::LResult(){
	mid=0;
	mid_w=0;
	final=0;
}
LResult::LResult(int i_mid, int i_mid_w, int i_final){
	mid=i_mid;
	mid_w=i_mid_w;
	final=i_final;
}
void LResult::Show(){
	cout<<mid<<":"<<mid_w<<":"<<final<<"\n";
}
void LResult::Setmid(int n_mid){
	mid=n_mid;
}
void LResult::Setmid_w(int n_mid_w){
	mid_w=n_mid_w;
}
void LResult::Setfinal(int n_final){
	final=n_final;
}
int LResult::Getmid(){
	return mid;
}
int LResult::Getmid_w(){
	return mid_w;
}
int LResult::Getfinal(){
	return final;
}


