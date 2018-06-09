# include <iostream>
using namespace std;
/*Xet cac so X co cac chu so duoc sap xep tang dan tuc a 1] = a 2] = … = a N] trong do a 1] a 2] … a N]
lan luot la cac chu so cua X Chang han 223 8999 …Nhiem vu cua ban la dem xem co bao nhieu so nhu vay voi moi N cho truoc*/
const long long mod = 1000000007;
int n, k;
long long f[11][101];
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
}

void _Process(){
		// f[i][j] KET THUC == I VAF COS J CHWX SOOS
	for(int cs = 0; cs <= 9; cs++) f[cs][1] = 1;
	for(int dd = 2; dd <= n; dd++){
		f[0][dd] = 1;
		for(int cs = 1; cs <= 9; cs++){
			//f[cs][dd] = 0;
			//for(int csn = 1; csn <= cs; csn++){
				f[cs][dd] = (f[cs-1][dd] + f[cs][dd-1])%mod;
			//}
		}
	}
	long long kq = 0;
	for(int i = 0; i <= 9; i++) {
		kq = (kq+f[i][n])%mod;
		//cout << f[i][n] << " ";
	}
	cout << kq << endl;
}

