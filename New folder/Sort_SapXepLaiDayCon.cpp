# include <iostream>
using namespace std;
/*Cho day so A ] gom co N phan tu Nhiem vu cua ban la hay tim mot day con lien tiep dai nhat sao cho sau
khi sap xep lai day con nay day so A ] se la mot day so duoc sap xep tang dan*/
int n, a[100002], Left, Right, aMax, aMin, Begin, End;

void _Input();
void _Process();
int findLeft();
int findRight();
void timMaxMin();
void timcs();

main(){
	int T;
	cin >> T;
	while(T--){
		_Input();
		_Process();
	}
}

void _Input(){
	cin >> n;
	for(int i  = 0; i < n; i++){
		cin >> a[i];
	}	
}

void timMaxMin(){
	aMax = a[Left];
	aMin = a[Left];
	for(int i = Left+1; i <= Right; i++){
		aMax = max(aMax, a[i]);
		aMin = min(aMin, a[i]);
	}
}

void timcs(){
	Begin = Left;
	End = Right;
	while(Begin > 0 && a[Begin-1] > aMin) Begin--;
	while(End < n-1 && a[End+1] < aMax) End++;
}

void _Process(){
	Left = findLeft();
	if(Left >= 0)  {
		Right = findRight();
		timMaxMin();
		timcs();
		cout << End - Begin + 1 << endl;
	}
	else cout << "YES\n";
}

int findLeft(){
	for(int i = 0; i < n-1; i++){
		if(a[i] > a[i+1]) return i;
	}
	return -1;
}

int findRight(){
	for(int i = n-1; i > 0; i--){
		if(a[i] < a[i-1]) return i;
	}
	return -1;
}

