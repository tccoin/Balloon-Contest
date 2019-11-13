#include <bits/stdc++.h>

using namespace std;

int main(){
	string os, nos;
	cin >> os;
	int s = 1,skip=0;
	int len = os.length();
	while(s){
		s = 0;
		nos = "";
		for(int i=0;i<os.length();i++){
			if(skip){
				skip=0;
				continue;
			}
			if(i==len-1){
				nos += os[i];
				continue;
			}
			if(os[i]=='O'&&os[i+1]=='O'){
				s = 1;
				skip=1;
			}else if(os[i]=='o'&&os[i+1]=='o'){
				nos += "O";
				s = 1;
				skip=1;
			}else{
				nos += os[i];
			}
		}
		os = nos;
		if(!s){
			if(nos.length()!=0){
				cout << nos;
			}else{
				cout << 0;
			}
		}
	}
	return 0;
}

