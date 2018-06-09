# include <iostream>
# include <algorithm>
using namespace std;
/*Ti rat thich uong ca phe da mot thu ma rat nhieu lap trinh vien khac cung yeu thich Co N cua hang ban ca
phe o gan cho lam viec cua Ti gia ban cho moi coc ca phe tai day lan luot la X i] 
Moi ngay Ti co the su dung so tien bang Y i] de mua ca phe Cac ban hay xac dinh xem Ti co the lua chon
bao nhieu cua hang de mua duoc ca phe cho minh*/
int n, tien, a[100002];

void _Input();
void _Process();
int _Find();

main(){
	
	_Input();
	_Process();

}

void _Input(){
	cin >> n ;
	for(int i  = 0; i < n; i++){
		cin >> a[i];
	}	
}

int _Find(){
	int d = 0, c = n-1, gi;
	while(d <= c){
		gi = (d+c)/2;
		if(a[gi] <= tien){
			d = gi+1;
		}
		else{
			c = gi-1;
		}
	}
	if(d == n) return n-1;
	for(int i = d; i < n; i++){
		if(a[i] > tien) return i-1;
	}
}

void _Process(){
	int sl;
	sort(a, a+n);
	cin >> sl;
	while(sl--){
		cin >> tien;
		cout << _Find() + 1<< endl;
	}
}

