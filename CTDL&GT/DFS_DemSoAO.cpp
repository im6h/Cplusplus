# include <iostream>
# include <string.h>
using namespace std;
/*Sau khi thi truot mon Cau truc du lieu va giai thuat mot so sinh vien D16 CNTT PTIT quyet
dinh bo hoc dau tu thue dat de trong rau Manh dat thue la mot hinh chu nhat N x M 1? N? 100;
1? M? 100 o dat hinh vuong Nhung chi sau do vai ngay tran lut khung khiep da dien ra lam mot
so o dat bi ngap Manh dat bong bien thanh cac cai ao Va sinh vien D16 lai du dinh chuyen sang
nuoi ca Cac ban ay muon biet manh dat duoc chia thanh bao nhieu cai ao de co the tinh toan nuoi
ca cho hop ly Hay giup cac ban ay nhe Chu y Ao la gom mot so o dat bi ngap co chung dinh De
nhan thay la mot o dat co the co toi da 8 o chung dinh*/
int n, m, NumberOfPond = 0, 
	Raw[] = {-1, -1, -1, 0, 0, 1, 1, 1}, 
 	Colum[] = {-1, 0, 1, -1, 1, -1, 0,  1};
char a[102][102];

void _Input();
void _Process();
void _Output();
void browserPond(int r, int c);


main(){
	_Input();
	_Process();
	_Output();
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
	for(int i = 0; i < 8; i++){
		bRaw = r+Raw[i];
		bColum = c+Colum[i];
		if (bRaw > 0 && bRaw <= n 
				&& bColum > 0 && bColum <= m && a[bRaw][bColum] == 'W'){
					a[bRaw][bColum] = '+';
					browserPond(bRaw, bColum);
				}
	}
}

void _Process(){
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= m; c++){
			if(a[r][c] == 'W') browserPond(r,c),NumberOfPond++;
		}
	}
}

void _Output(){
	cout << NumberOfPond;
}

