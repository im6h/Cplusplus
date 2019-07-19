# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
/*Tai san bay moi nguoi dang lam thu tuc de check in Co tat ca N vi khach Vi khach thu i toi lam thu tuc tai
thoi diem T i] va can D i] thoi gian de check in xong 
Cac ban hay xac dinh xem thoi diem nao tat ca cac vi khach lam xong thu tuc de len may bay*/
struct Guest{
	long long Duration, Time;
};
vector <Guest> g;
int n;
void _Input();
void _Process();
bool ss(Guest  befor, Guest after){
	return befor.Time < after.Time;
}

main(){
	_Input();
	_Process();
}

void _Input(){
	Guest temp;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp.Time >> temp.Duration;
		g.push_back(temp);
	}
}

void _Process(){
	long long kq = 0;
	sort(g.begin(), g.end(), ss);
	for(int i = 0; i < n; i++){
		if(kq < g[i].Time){
			kq = g[i].Time + g[i].Duration;
		}else{
			kq += g[i].Duration;
		}
		cout << kq << endl;
	}
	cout << kq;
}
