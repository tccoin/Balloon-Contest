#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int j=0;j<n;j++){
		string a;
		bool good = false;
		cin >> a;
		if(a.length()==1){
			cout << "-1" <<'\n';
			continue;
		}
		for (int i=0;i<a.length()/2;i++){
			if(a[i]!=a[a.length()-1-i]){
				good = true;
				break;
			}
		}
		if(good){
			cout << a << '\n';
			continue;
		}
		
		bool canbegood = false;
		int itobegood;
		for (int i=1;i<a.length()/2+1;i++){
			if(a[0]!=a[i]){
				canbegood = true;
				itobegood = i;
				break;
			}
		}
		if(!canbegood){
			cout << "-1" << '\n';
		}else{
			char temp = a[0];
			a[0] = a[itobegood];
			a[itobegood] = temp;
			cout << a << '\n';
		}
	}
	return 0;
}
