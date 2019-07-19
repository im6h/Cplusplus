# include <iostream>
# include <string.h>
using namespace std;
/*Cho mot ban do kich thuoc N x M duoc mo ta bang ma tran A ] ] A i] j] 1 co nghia vi tri i 
j la noi tren bien 2 vi tri i j va x y duoc coi la lien nhau neu nhu no co chung dinh hoac11
chung canh Mot hon dao la mot tap hop cac diem i j ma A i] j] 1 va co the di chuyen giua
hai diem bat ki trong do 
Nhiem vu cua ban la hay dem so luong dao xuat hien tren ban do*/
int n, m, NumberOfIsland = 0, 
	Raw[] = { -1, 1, 0, 0}, 
 	Colum[] = {0, 0, 1, -1};
short a[1001][1001];

void _Input();
void _Process();
void _Output();
void browserPond(int r, int c);


main(){
	int T;
	cin >> T;
	while(T--){
		NumberOfIsland = 0;
		_Input();
		_Process();
		_Output();		
	}

}

void _Input(){
	cin >> n >> m;
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= m; c++){
			cin >> a[r][c];
		}
	}
}

void browserPond(int r, int c){
	int bRaw, bColum;
	for(int i = 0; i < 4; i++){
		bRaw = r+Raw[i];
		bColum = c+Colum[i];
		if (bRaw > 0 && bRaw <= n 
				&& bColum > 0 && bColum <= m && a[bRaw][bColum] == 1){
					a[bRaw][bColum] = 0;
					browserPond(bRaw, bColum);
				}
	}
}

void _Process(){
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= m; c++){
			if(a[r][c] == 1) browserPond(r,c),NumberOfIsland++;
		}
	}
}

void _Output(){
	cout << NumberOfIsland << endl;
}

