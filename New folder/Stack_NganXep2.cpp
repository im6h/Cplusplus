# include <iostream>
using namespace std;
/*Yeu cau ban xay dung mot stack voi cac truy van sau day
“PUSH x” Them phan tu x vao stack 0 x 1000 
“PRINT” In ra phan tu dau tien cua stack Neu stack rong in ra “NONE” 
“POP” Xoa phan tu dau tien cua stack Neu stack rong khong lam gi ca*/
int n,k, stack[100006],d;

main(){
	cin >> n;
	string lenh;
	while(n--){
		cin >> lenh;
		if(lenh == "PUSH"){
			cin >> stack[++d];
		}else{
			if(lenh == "POP"){
				if(d > 0) d--;
			}else{
				if(d > 0) cout << stack[d]<< endl;
				else cout << "NONE\n";
			}
		}
	}
}
