#include <bits/stdc++.h>

using namespace std;

void morezero(string * a, int length){
    *a = string(string::size_type(length-a->length()),'0') + *a;
}

string lesszero(string a){
    int s = 0;
    for(int i=0;i<a.length()-1;i++){
        if(a[i] != '0') break;
        s++;
    }
    return string(a,s,a.length()-s);
}

int getSign(string* a){
    if((*a)[0]=='-'){
        *a = string(*a,1,a->length()-1);
        return -1;
    }else{
        return 1;
    }
}

string padd(string a, string b){
    if(a.length() < b.length()){
        string temp = a;
        a = b;
        b = temp;
    }
    morezero(&b, a.length());

    string o = string(string::size_type(a.length()),'0');
    int c = 0;
    for(int i=a.length()-1;i>=0;i--){
        char n = a[i]+b[i]-'0'+c;
        c = n > '9';
        if(c) n -= 10;
        o[i] = n;
    }
    if(c) o = "1"+o;
    return o;
}

string psub(string a, string b){
    bool aLarger = true;
    if(a.length()==b.length()){
        for(int i=0;i<a.length();i++){
            if(a[i]<b[i]){
                aLarger = false;
                break;
            }
        }
    }else{
        aLarger = a.length() > b.length();
    }
    if(!aLarger){
        string temp = a;
        a = b;
        b = temp;
    }
    for(int i=0;i<b.length();i++){
        b[i] = '9' - b[i] + '0';
    }
    string o = padd(a,padd(b,"1"));
    if(o.length()>a.length()) o = string(o,1,o.length()-1);
    return (aLarger?"":"-") + o;
}

string add(string a, string b){
    string o;
    int signA, signB;
    signA = getSign(&a);
    signB = getSign(&b);
    if(signA>0&&signB>0) o = padd(a,b);
    else if(signA<0&&signB<0) o = "-"+ padd(a,b);
    else{
        o = psub(a,b);
        if(getSign(&o) * signA == -1) o = "-" + o;
    }
    return lesszero(o);
}

int main(void){
	string a, b;
	cin >> a >> b;
	cout << add(a, b);
}
