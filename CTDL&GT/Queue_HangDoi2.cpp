# include <iostream>
using namespace std;
/*Yeu cau ban xay dung mot queue voi cac truy van sau day
“PUSH x” Them phan tu x vao cuoi cua queue 0 x 1000 
“PRINTFRONT” In ra phan tu dau tien cua queue Neu queue rong in ra “NONE” 
“POP” Xoa phan tu o dau cua queue Neu queue rong khong lam gi ca*/
int q[100000], d = 1, c;

main(){
	int scv;
	string lenh;
	cin >> scv;
	while(scv--){
		cin >> lenh;
		if(lenh == "PUSH"){
			cin >> q[++c];
		}else{
			if(lenh == "POP"){
				if(d <= c) d++;
			}else{
				if(d > c) cout << "NONE\n";
				else cout << q[d]<< endl;
			}
		}
	}
}
