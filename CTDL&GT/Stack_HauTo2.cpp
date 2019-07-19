# include <iostream>
# include <stack>
using namespace std;
/*Cho mot day bieu thuc dang trung to co the chua dung khuon dang voi cac phep toan cong tru nhan
chia luy thua 
Nhiem vu cua ban la hay chuyen bieu thuc da cho ve dang hau to 
Chu y xem vi du de hieu su khac biet voi bai truoc*/
string chuoi;

bool kiemTra(char a, char b){
	if(a != '+' && a!= '-' && a != '*' && a!= '/' && a!='^') return false;
	if((a == '+' || a == '-') && (b == '*' || b == '/' || b == '^')) return false;
	if((b == '^') && (a == '*' || a == '/')) return false;
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
						while(kiemTra(st.top(), chuoi[i])){
							cout << st.top();
							st.pop();
						}						
						//cout << chuoi[i];
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
