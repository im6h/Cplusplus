# include <iostream>
using namespace std;
/*Cho mot bang so N hang M cot chi gom 0 va 1 Ban hay tim hinh vuong co kich thuoc lon nhat sao cho cac
so trong hinh vuong toan la so 1*/
int N, M, a[1001][1001];
int f[1001][1001];
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
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> a[i][j];
		}
	}
}

void _Process(){
	int kq = 0;
	for(int i = 0; i < N; i++){
		f[i][0] = a[i][0];
		kq = max(kq, f[i][0]);
	}
	for(int i = 0; i < M; i++){
		f[0][i] = a[0][i];
		kq = max(kq, f[0][i]);
	}
	int temp = 0;
	for(int r = 1; r < N; r++){
		for(int c = 1; c < M; c++){
			if(a[r][c]){
				temp = min(f[r-1][c-1], f[r-1][c]);
				f[r][c] = min(f[r][c-1], temp) + 1;
				kq = max(kq, f[r][c]);
			}else{
				f[r][c] = 0;
			}
		}
	}
	cout << kq << endl;
}

