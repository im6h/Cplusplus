# include <iostream>
# include <queue>
using namespace std;
/*Mot do thi N dinh la mot cay neu nhu no co dung N 1 canh va giua 2 dinh bat ki chi ton tai
duy nhat 1 duong di giua chung 
Cho mot do thi N dinh va N 1 canh hay kiem tra do thi da cho co phai la mot cay hay khong*/
int n; 
short a[1001][1001];

void _Input(){
	int x, y;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = 0;
		}
	}
	for(int i = 1; i < n; i++){
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
}

bool BFS(int bd){
	int count = 1, temp, Not[n+1];
	for(int i = 1; i <= n; i++) Not[i] = 1;
	queue <int> q;
	q.push(bd);
	Not[bd] = 0;
	while(q.size()){
		temp = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(a[temp][i] && Not[i]){
				q.push(i);
				Not[i] = 0;
				count++;
			}
		}
	}
	return count == n;
}

main(){
	int T;
	cin >> T;
	while(T--){
		_Input();
		if(BFS(1)) cout << "YES\n";
		else cout << "NO\n";
	}
}
