# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
using namespace std;
/*Cho truoc mot danh sach M tu goi la tu dien moi tu la mot chuoi khong qua 25 chu cai thuong 
khong co khoang trong Sau do lan luot cho cac luoi kich thuoc N N cac chu cai viet thuong 
voi 2 N 8 
Hay xac dinh xem tu mot luoi nhu vay co the ghep thanh cac tu nao trong tu dien M tu ban
dau Quy tac ghep chu tu luoi la chi duoc ghep theo chieu ngang chieu doc hoac duong cheo
va moi vi tri tren luoi chi duoc dung mot lan 
Ngoai ra co mot ngoai le bo sung la voi o tren luoi co chu cai q thi duoc xu ly nhu mot cap
chu cai qu khi ghep tu*/
int m, n, cs, 
	hang[] = {-1, -1, -1, 0, 0, 1, 1, 1},
	cot[] = {-1, 0, 1, -1, 1, -1, 0, 1},
	Not[10][10];
	
string Tu[202], ds[202];
char a[10][10];


void _Input();
void _Process();
bool _Find(int i);
bool DFS(int i, int j, int vt, int cs);
void _Output();

main(){
	_Input();
	_Process();	
}

void _Input(){
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> Tu[i];
	}
}

void _Process(){
	cin >> n;
	while(n){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		cs = 0;
		for(int i = 1; i <= m; i++){
			if(_Find(i)) ds[cs++] = Tu[i];
		}
		_Output();
		cin >> n;
	}
}

bool _Find(int vt){
	int tiep = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(Tu[vt][0] == a[i][j]){
				if(a[i][j] == 'q') 
					if(Tu[vt].length() < 2 || Tu[vt][1] != 'u'){
						continue;
					}else{
						tiep = 2;
					}
				Not[i][j] = 1;
				if(DFS(i, j, vt, tiep)) {
					Not[i][j] = 0;
					return true;
				}
				Not[i][j] = 0;
			}
		}
	}
	return false;
}

bool  DFS(int r, int c, int vt, int cs){
	if(cs == Tu[vt].length()) {
		return true;
	}
	int x, y, tiep = cs+1;
	for(int i = 0; i < 8; i++){
		x = r+hang[i];
		y = c+cot[i];
		if(x > 0 && x <= n && y > 0 && y <= n 
				&& a[x][y] == Tu[vt][cs] && Not[x][y] == 0){
			if(Tu[vt][cs] == 'q'){
				if(Tu[vt].length() < cs+1 || Tu[vt][cs+1] != 'u'){
					continue;
				}else{
					tiep = cs + 2;	
				}	
			}
			Not[x][y] = 1;
			if(DFS(x, y, vt, tiep)){
				Not[x][y] = 0;
				return true;; 
			}
			Not[x][y] = 0;
		}
	}
	return false;
}

void _Output(){
	sort(ds, ds+cs);
	for(int i = 0; i < cs; i++){
		cout << ds[i] << endl;
	}
	cout << "-\n";
}
