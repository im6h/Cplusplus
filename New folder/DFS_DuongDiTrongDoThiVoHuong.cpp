# include <iostream>
# include <queue>
using namespace std;
/*Cho do thi co N dinh va M canh Co Q truy van moi truy van yeu cau tra loi cau hoi giua 2
dinh x va y co ton tai duong di toi nhau hay khong*/
int n, m; 
short a[1001][1001];

void _Input_vs_Process();
bool BFS(int bd, int kt);

main(){
	int T;
	cin >> T;
	while(T--){
		_Input_vs_Process();
	}
}

void _Input_vs_Process(){
	int x, y;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	int q;
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		if(BFS(x, y)) cout << "YES\n";
		else cout << "NO\n";
	}
}

bool BFS(int bd, int kt){
	int temp, Not[n+1];
	for(int i = 1; i <= n; i++) Not[i] = 1;
	queue <int> q;
	q.push(bd);
	Not[bd] = 0;
	while(q.size()){
		temp = q.front();
		if(temp == kt) return true;
		q.pop();
		for(int i = 1; i <= n; i++){
			if(a[temp][i] && Not[i]){
				q.push(i);
				Not[i] = 0;
			}
		}
	}
	return false;
}
