# include <iostream>
# include <algorithm>
using namespace std;

int n, k, a[100002];

void _Input();
void _Process();
int _Find();

main(){
	int T;
	cin >> T;
	while(T--){
		_Input();
		_Process();
	}
}

void _Input(){
	cin >> n >> k;
	for(int i  = 0; i < n; i++){
		cin >> a[i];
	}	
}

int _Find(){
	int d = 0, c = n-1, gi;
	while(d <= c){
		gi = (d+c)/2;
		if(a[gi] == k) return gi;
		else{
			if(a[gi] < k) d = gi+1;
			else c = gi-1;
		}
	}
	return -1;
}

void _Process(){
	int Pos = _Find();
	if(Pos > 0) cout << Pos + 1 << endl;
	else cout << "NO\n";
}

