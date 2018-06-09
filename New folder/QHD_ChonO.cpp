# include <iostream>
using namespace std;
/*Cho mot bang kich thuoc 4 x N gom N cot Moi o i j co diem bang A i] j] Ban can chon mot tap hop
cac o sao cho diem dat duoc la lon nhat va trong cac o duoc chon khong co 2 o nao co chung canh 
Vi du voi bang co N 3 nhu hinh ve tren Cach chon tap toi uu la 3 1 1 2 4 2 va 3 3*/
const long long amin = -1000000000000;
long long n, a[6][10002], f[10002][16];
int cs[] = {0, 1, 2, 4, 5, 8, 9, 10};
bool am;
void _Input();
void _Process();
void khongTrung();
long long tinh(int i, int j);

main(){
	int T;
	cin >> T;
	while(T--){
		_Input();
		_Process();
	}
}

void _Input(){
	am = true;
	cin >> n;
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] >= 0) am = false;
		}
	}
}

bool khongTrung(int x, int y){
	while(x && y){
		if((x&1)&&(y&1)) return false;
		x>>=1;
		y>>=1;
	}
	return true;
}

long long tinh(int i, int j){
	long long rt = 0;
	for(int tt = 1; tt <= 4; tt++){
		if(j%2){
			rt += a[tt][i];
		//	cout << tt << " "  << a[tt][i]<< "___";
		}
		j/=2;
	}//cout << endl;
	return rt;
}

void _Process(){
	long long kq = amin, fmax;
	if(am){
		for(int i = 1; i <= 4; i++){
			for(int j = 1; j <= n; j++){
				kq = max(kq, a[i][j]);
			}
		}
		cout << kq << endl;
		return;
	}
	
	for(int i = 0; i <= 7; i++) {
		f[1][i] = tinh(1, cs[i]);
		kq = max(kq, f[1][i]);
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= 7; j++){
			fmax = amin;
			for(int x = 0; x <= 7; x++){
				if(khongTrung(cs[j], cs[x])){
					fmax = max(fmax, f[i-1][x]);
				}
			}
			f[i][j] = fmax+tinh(i,cs[j]);
			kq = max(kq, f[i][j]);
		}
	}
	cout << kq;
}
