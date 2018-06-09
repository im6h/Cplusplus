# include <iostream>
# include <stack>
using namespace std;
/*Hay su dung ngan xep de thuc hien viec chuyen cac bieu thuc trung to sang hau to*/
string chuoi;

bool kiemTra(char a, char b){
	if(a != '+' && a!= '-' && a != '*' && a!= '/') return false;
	if((a == '+' || a == '-') && (b == '*' || b == '/') ) return false;
	return true;
}

void xuLy(){
	int l = chuoi.length();
	stack <char> st;
	for(int i = 0; i<l; i++){
		if(chuoi[i] >= 'a' && chuoi[i]<='z') cout << chuoi[i];
		else{
			if(chuoi[i] == '(') st.push(chuoi[i]);
			else {
				if(chuoi[i] == ')') {
					while(st.top() != '(') {
						cout << st.top();
						st.pop();
					}st.pop();
				}else{
					if(st.empty() || !kiemTra(st.top(), chuoi[i])){
						st.push(chuoi[i]);
					}else{
						cout << st.top();
						st.pop();
						st.push(chuoi[i]);
					}
				}
			}
		}
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}cout << endl;
}


main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> chuoi;
		xuLy();
	}
}
