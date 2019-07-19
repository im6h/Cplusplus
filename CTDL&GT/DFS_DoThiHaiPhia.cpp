# include <iostream>
# include <queue>
using namespace std;
/*Do thi hai phia la mot do thi dac biet trong do tap cac dinh co the duoc chia thanh hai tap
khong giao nhau thoa man dieu kien khong co canh noi hai dinh bat ky thuoc cung mot tap 
Cho do thi N dinh va M canh ban hay kiem tra do thi da cho co phai la mot do thi hai phia hay
khong*/
struct Canh{
	int u, v;
};
int n, m, dinh[1001];
short a[1001][1001], Not[1001];
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
	int x, y;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		Not[i] = 1;
		cin >> x >> y;
		a[x][y] = a[y][x] =  1;
	}
}

bool BFS(int bd){
	int temp, si, mau;
	queue <int> q;
	q.push(bd);
	Not[bd] = 0;
	dinh[bd] = 1;
	while(q.size()){
		si = q.size();
		mau = dinh[q.front()];
		for(int loop = 1; loop <= si; loop++){
			temp = q.front();
			q.pop();
			for(int i = 1; i <= n; i++){
				if(a[temp][i]){
					if(dinh[i] == mau) return false;
					if(dinh[i] == 0){
						if(mau == 1) dinh[i] = 2;
						else dinh[i] = 1;
						Not[i] = 0;
						q.push(i);
					}
				}
			}	
		}
	}
	return true;
}

void _Process(){
	for(int i = 1; i <= n; i++){
		if(Not[i]){
			if(BFS(i) == false){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

