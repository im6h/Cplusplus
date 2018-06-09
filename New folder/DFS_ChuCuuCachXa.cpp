# include <iostream>
# include <string.h>
using namespace std;
/*Tren canh dong kich thuoc N x N co K chu cuu Nguoi nong dan so cac chu cuu di lac nen da
lam mot so rao chan giua cac khu vuc Cac chu cuu chi co the di chuyen len tren xuong duoi 
sang trai sang phai khu vuc ben canh va khong the vuot qua duoc hang rao 
Hai chu cuu A va B duoc goi la ‘xa cach’ neu nhu chung khong the di chuyen toi vi tri cua
nhau Cac ban hay xac dinh xem so cap chu cuu xa cach bang nhau nhieu*/
struct Cell{
	int cuu;
	bool tren, duoi, trai, phai;
};

int n, m, k, Result = 0, count;
Cell a[102][102];

void _Input();
void _Process();
void updateWall(int u, int v, int x, int y);
void _Output();
void browser(int r, int c);


main(){
	_Input();
	_Process();
	_Output();
}

void _Input(){
	int u, v, x, y;
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j].cuu = 0;
			a[i][j].duoi = a[i][j].phai = a[i][j].trai = a[i][j].tren = false;
		}
	}
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> x >> y;
		updateWall(u, v, x, y);
	}
	for(int i = 1; i <= k; i++){
		cin >> x >> y;
		a[x][y].cuu = 1;
	}
}

void updateWall(int u, int v, int x, int y){
	if(u != x){
		if(u > x) swap(u,x);
		a[u][v].duoi = 1;
		a[x][y].tren = 1;
	}else{
		if(v > y) swap(v, y);
		a[u][v].phai = 1;
		a[x][y].trai = 1;
	}
}

void browser(int r, int c){
	int queue[5][2];
	int head = 0;
	if(r > 1 && a[r][c].tren == false && a[r-1][c].cuu != 2){
		count += a[r-1][c].cuu;
		a[r-1][c].cuu = 2;
		queue[head][0] = r-1;
		queue[head++][1] = c;
	}
	if(r < n && a[r][c].duoi == false && a[r+1][c].cuu != 2){
		count += a[r+1][c].cuu;
		a[r+1][c].cuu = 2;
		queue[head][0] = r+1;
		queue[head++][1] = c;
	}
	if(c > 1 && a[r][c].trai == false && a[r][c-1].cuu != 2){
		count += a[r][c-1].cuu;
		a[r][c-1].cuu = 2;
		queue[head][0] = r;
		queue[head++][1] = c-1;
	}
	if(c < n && a[r][c].phai == false && a[r][c+1].cuu != 2){
		count += a[r][c+1].cuu;
		a[r][c+1].cuu = 2;
		queue[head][0] = r;
		queue[head++][1] = c+1;
	}
	for(int i = 0; i < head; i++){
		browser(queue[i][0], queue[i][1]);
	}
}

void _Process(){
	int khu[100], cs = 0;
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= n; c++){
			if(a[r][c].cuu == 1) {
				a[r][c].cuu = 2;
				count = 1;
				browser(r,c);
				khu[cs++] = count;
			}
		}
	}
	for(int i = 0; i < cs; i++){
		for(int j = i+1; j < cs; j++){
			Result += khu[i]*khu[j];
		}
	}
}

void _Output(){
	cout << Result;
}

