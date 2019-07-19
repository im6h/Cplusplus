# include <iostream>
using namespace std;
/*Cho 2 so nguyen N va K Ban hay dem so luong cac so co N chu so ma tong cac chu so cua no bang K 
Luu y chu so 0 o dau khong duoc chap nhan*/
const long long mod = 1000000007;
int n, k;
long long f[101][50001];
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
}

void _Process(){
		// f[i][j] la so nhung so co i chu so tong cac chu so = j
	for(int cs = 0; cs <= 9; cs++) f[1][cs] = 1;
	for(int cs = 10; cs <= k; cs++) f[1][cs] = 0;
	for(int dd = 2; dd <= n; dd++){
		for(int t = 0; t <= k; t++){
			f[dd][t] = 0;
			for(int i = 0; i <= 9; i ++){
				if(t > i){
					f[dd][t] = (f[dd][t] + f[dd-1][t-i])%mod;
				}
			}
		}
	}
	cout << f[n][k] << endl;
}

