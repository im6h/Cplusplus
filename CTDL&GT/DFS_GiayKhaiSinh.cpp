# include <iostream>
# include <map>
# include <queue>
# include <algorithm>
using namespace std;
/*Mot buoi hop mat dai gia dinh nhan dip cu gia Ted tron 100 tuoi nguoi ta muon sap xep con
chau cua cu theo thu tu tu tuoi cao xuong thap Gia su ta co thong tin ve giay khai sinh cua
tung nguoi do Moi giay khai sinh chi viet ba thong tin don gian gom Ten nguoi cha Ten
nguoi con Tuoi cua nguoi cha luc sinh con 
Hay giup dai gia dinh tren tinh ra tuoi cua tung nguoi con chau cu Ted va viet ra danh sach
theo thu tu tu tuoi cao xuong thap 
*/
struct Nguoi{
	string ten;
	int tuoi;
};

Nguoi  o[103];
map <string, int> t;
int a[1033][103], n, tuoi[103], sbt = 1;

void _Input();
void _Process();
void _Output();
bool ss(Nguoi tr, Nguoi s);

main(){
	int T;
	cin >> T;
	while(T--){
		_Input();
		_Process();
		_Output();
	}
}

void _Input(){
	t.clear();
	cin >> n; 
	for(int i = 1; i <= n+1; i++) 
		for(int j = 1; j <= n+1; j++) 
			a[i][j] = 0;
	string temp1, temp2;
	int cs = 0;
	for(int i = 1; i <= n; i++){
		cin >> temp1;
		if(t[temp1] == 0)
			t[temp1] = ++cs;
		cin >> temp2;
		if(t[temp2] == 0)
			t[temp2] = ++cs;
		cin >> a[t[temp1]][t[temp2]];
	}
}

void _Process(){
	int temp, Not[101];
	for(int i = 1; i <= n+1; i++) Not[i] = 1;
	queue <int> q;
	q.push(t["Ted"]);
	tuoi[t["Ted"]] = 100;
	while(q.size()){
		temp = q.front();
		q.pop();
		for(int i = 1; i <= n+1; i++){
			if(a[temp][i] && Not[i]){
				tuoi[i] = tuoi[temp] - a[temp][i];
				Not[i] = 0;
				q.push(i);
			}
		}
	}
	map <string, int>::iterator d = t.begin();
	for(int i = 0; i <= n; i++){
		o[i].ten = d->first;
		o[i].tuoi = tuoi[d->second];
		d++;
	}
}


bool ss(Nguoi tr, Nguoi s){
	if(tr.tuoi != s.tuoi) return tr.tuoi > s.tuoi;
	return tr.ten < s.ten;
}

void _Output(){
	sort(o, o+n+1, ss);
	cout << "DATASET " << sbt++ << endl;
	for(int i = 0; i <= n; i++){
		if(o[i].tuoi == 100) continue;
		cout << o[i].ten << " " << o[i].tuoi << endl;
	}
}

