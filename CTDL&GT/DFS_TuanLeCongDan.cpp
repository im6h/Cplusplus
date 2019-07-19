# include <iostream>
# include <string.h>
using namespace std;
/*Sau khi di nhap hoc Teo rat phan khoi va bat dau ngay viec hoc o truong dai hoc Tuan hoc
dau tien la tuan le cong dan Muc tieu chinh cua Teo cung nhu cac tan sinh vien khac la ket
ban 
Hoi truong gom co R C vi tri cho ngoi R hang va C cot Moi ban sinh vien se co gang lam
quen va bat tay voi tat ca nhung nguoi ban xung quanh minh Nhu vay moi ban se lam quen
duoc toi da la 8 nguoi ban moi 3
Buoi hoc da bat dau nhung khong may Teo lai den muon la nguoi muon nhat Teo se chon
mot vi tri trong sao cho co the lam quen voi nhieu ban moi nhat co the Neu khong co ghe
trong nao Teo quyet dinh bung hoc D
Hay tinh toan so luong cai bat tay se duoc thuc hien trong buoi hoc dau tien nay*/
int n, m, Result = 0, 
	Raw[] = {-1, -1, -1, 0, 0, 1, 1, 1}, 
 	Colum[] = {-1, 0, 1, -1, 1, -1, 0,  1};
char a[102][102];

void _Input();
void _Process();
void _Output();
void findSeatingForTeo();
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
	int bRaw, bColum, queue[9][2], head = 0;
	for(int i = 0; i < 8; i++){
		bRaw = r+Raw[i];
		bColum = c+Colum[i];
		if (bRaw > 0 && bRaw <= n 
				&& bColum > 0 && bColum <= m && a[bRaw][bColum] == 'o'){
					queue[head][0] = bRaw;
					queue[head][1] = bColum;
					head++;
					Result++;
				}
	}
	a[r][c] = '-';
	for(int i = 0; i < head; i++){
		browserPond(queue[i][0], queue[i][1]);
	}
}

void findSeatingForTeo(){
	int hang, cot, tmax = -1, temp, bRaw, bColum;
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= m; c++){
			if(a[r][c] == '.'){
				temp = 0;
				for(int i = 0; i < 8; i++){
					bRaw = r+Raw[i];
					bColum = c+Colum[i];
					if (bRaw > 0 && bRaw <= n 
						&& bColum > 0 && bColum <= m && a[bRaw][bColum] == 'o'){
						temp++;
					}
				}
				if(temp > tmax) hang = r, cot = c, tmax = temp;	
			}
		}
	}
	if(tmax != -1) a[hang][cot] = 'o';
}

void _Process(){
	findSeatingForTeo();
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= m; c++){
			if(a[r][c] == 'o') browserPond(r,c);
		}
	}
}

void _Output(){
	cout << Result;
}

