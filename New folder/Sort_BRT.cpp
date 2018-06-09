# include <iostream>
# include <algorithm>
using namespace std;
/*Thanh pho X co N thi tran tren truc duong chinh Toa do cua cac thi tran lan luot la a 1] a 2] … a N] cac
toa do nay la phan biet khong co 2 toa do nao trung nhau 
Chinh quyen thanh pho muon xay dung mot tuyen buyt nhanh BRT de ket noi 2 thi tran gan nhau nhat voi
nhau 
Ban hay tinh thu xem chieu dai cua tuyen buyt nay bang bao nhieu Va co bao nhieu cap thi tran co tiem
nang giong nhau de xay dung tuyen BRT nay*/
int n, a[100002];

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
	cin >> n;
	for(int i  = 0; i < n; i++){
		cin >> a[i];
	}	
}



void _Process(){
	sort(a, a+n);
	int count = 1;
	long long mi = a[1]-a[0];
	for(int i = 1; i < n-1; i++){
		if(a[i+1]-a[i] < mi){
			mi = a[i+1]-a[i];
			count = 1;
		}else{
			if(a[i+1]-a[i] == mi) count ++;
		}
	}
	cout << mi << " " << count << endl;
}

