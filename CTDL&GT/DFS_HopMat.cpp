# include <iostream>
# include <queue>
using namespace std;
/*Co K nguoi 1 ? K ? 100 dung tai vi tri nao do trong N dia diem cho truoc 1 ? N ? 1 000 
duoc danh so tu 1 N Cac diem duoc noi voi nhau boi M doan duong mot chieu 1 ? M ?
10 000 khong co doan duong nao noi mot diem voi chinh no 
Moi nguoi muon cung tu hop tai mot dia diem nao do Tuy nhien voi cac duong di cho
truoc chi co mot so dia diem nao do co the duoc chon la diem hop mat Cho truoc K N M7
va vi tri ban dau cua K nguoi cung voi M duong di mot chieu hay xac dinh xem co bao nhieu
diem co the duoc chon lam diem hop mat*/
int n, k, m, vt[1001], d[1001]; 
short a[1001][1001];

void _Input(){
	int x, y;
	cin >> k >> n >> m;
	for(int i = 1; i <= k; i++){
		cin >> vt[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		a[x][y] = 1;
	}
}

bool BFS(int bd){
	int temp, Not[n+1];
	for(int i = 1; i <= n; i++) Not[i] = 1;
	queue <int> q;
	q.push(bd);
	d[bd]++;
	Not[bd] = 0;
	while(q.size()){
		temp = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(a[temp][i] && Not[i]){
				q.push(i);
				Not[i] = 0;
				d[i]++;
			}
		}
	}
	
}

void _Process(){
	for(int i = 1; i <= k; i++){
		BFS(vt[i]);
	}
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(d[i] == k) count++;
	}
	cout << count;
}

main(){
	_Input();
	_Process();
}
