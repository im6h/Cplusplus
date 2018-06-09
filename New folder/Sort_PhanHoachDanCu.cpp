# include <iostream>
# include <algorithm>
# include <iomanip>
# define  ll long long
using namespace std;
/*Thanh pho X moi xay dung xong 2 khu do thi moi va bat dau ke hoach di chuyen dan cu Co tong cong N
nguoi dang ki chuyen den khu do thi moi trong khi suc chua cua khu do thi 1 va 2 chi la lan luot C va D 
Chi so A i] the hien muc do giau co cua nguoi thu i Ban quan ly du an muon su giau co o 2 khu do thi nay
la lon nhat co the Chi so danh gia duoc tinh bang tong trung binh chi so giau co cua cu dan o 2 khu do thi
moi trung binh cua khu do thi 1 trung binh khu do thi 2 
Cac ban hay tinh xem khi sap xep toi uu chi so danh gia nay co gia tri lon nhat bang bao nhieu*/
ll n, c, d, a[100002];

void _Input();
void _Process();

main(){
	int T;
	cin >> T;
	while(T--){
		_Input();
		_Process();
	}
}

void _Input(){
	cin >> n >> c >> d;
	for(int i  = 0; i < n; i++){
		cin >> a[i];
	}	
}

void _Process(){
	sort(a, a+n);
	if(c > d) swap(c, d);
	ll t1 = 0, t2 = 0, cuoi = n;
	for(ll i = 1; i <= c; i++){
		t1 += a[--cuoi];
	}
	for(ll i = 1; i <= d; i++){
		t2 += a[--cuoi];
	}
	double kq = (double)(t1*d+t2*c)/(d*c);
	printf("%f\n", kq);
}

