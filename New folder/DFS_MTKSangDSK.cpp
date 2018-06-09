# include <iostream>
using namespace std;
/*Ma tran ke A cua mot do thi vo huong la mot ma tran chi co cac so 0 hoac 1 trong do A i] j] 1
co y nghia la dinh i ke voi dinh j chi so tinh tu 1 
Danh sach ke thi liet ke cac dinh ke voi dinh do theo thu tu tang dan 
Hay chuyen bieu dien do thi tu dang ma tran ke sang dang danh sach ke*/
int n;
short a[1000][1000];

void _Input(){
	cin >> n;
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= n; c++){
			cin >> a[r][c];
		}
	}
}

void _Process(){
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= n; c++){
			if(a[r][c]) cout<< c <<" ";
		}cout << endl;
	}
}

main(){
	_Input();
	_Process();
}
