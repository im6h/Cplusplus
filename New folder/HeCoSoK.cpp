# include <iostream>
using namespace std;
/*Cho hai so A B o he co so K Hay tinh tong hai so do o he co so K*/
string a, b;
int k;

string cong(){
	string kq = "";
	while(a.length() < b.length()) a = "0"+a;
	while(b.length() < a.length()) b = "0"+b;
	int d = a.length()-1, nho = 0, t = 0, c;
	for(int i = d; i>=0; i--){
		t = (a[i]+b[i]-48*2+nho);
		c = t%k;
		kq = (char)(c+48) + kq;
		nho = t/k;
	}
	if(nho) kq = (char)(nho+48)+kq;
	while(kq[0] == '0') kq.erase(kq.begin());
	return kq;
}

main(){
	cin >> k >> a >> b;
	cout << cong();
}
