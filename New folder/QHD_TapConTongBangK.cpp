# include <iostream>
using namespace std;
/*Cho day so A ] co N phan tu Nhiem vu cua ban la xac dinh xem ton tai tap con cua A sao cho tong cac phan
tu cua chung bang so K cho truoc hay khong*/
int n, k, a[101];
bool bqh[10001][10001];
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
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void _Process(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			bqh[i][j] = 0;	
		}
	}
	bqh[0][a[0]] = 1;
	for(int i = 1; i < n; i++){
		for(int t = 0; t <= k; t++){
			if(t == a[i]) bqh[i][t] = 1;
			else 
				if((t > a[i] && bqh[i-1][t-a[i]]) || bqh[i-1][t]) bqh[i][t] = 1;
		}
	}
	for(int i = 0; i < n; i++) {
		if(bqh[i][k]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

