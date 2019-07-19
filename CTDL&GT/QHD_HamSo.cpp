# include <iostream>
# include <cmath>
using namespace std;

int n, a[100001];
long long neg[100001], pos[100001];
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
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void _Process(){
	long long ht, kq;
	neg[0] = 0;
	pos[0] = 0;
	pos[1] = (long long) abs(a[0]-a[1]);
	kq = pos[1];
	neg[1] = 0;
	for(int i = 2; i < n; i++){
		ht = (long long)abs(a[i-1]-a[i]);
		neg[i] = pos[i-1]-ht;
		pos[i] = max(ht, neg[i-1]+ht);
		kq = max(kq, max(neg[i], pos[i]));
	}
	cout << kq << endl;
}

