# include <iostream>
# include <algorithm>
using namespace std;
/*Mot may ATM hien co n n ? 30 to tien co gia tri t 1] t 2] … t n] Hay tim cach tra it to nhat voi so
tien dung bang S*/
int n,s, t[35], dem, kq = 30;

void thu(int i){
	if(i < 0) return;
	if(t[i] <= s){
		s -= t[i];
		dem++;
		if(s == 0) {
			kq = min(kq, dem);
			if(kq == 1) return;
		}else	thu(i-1);
		dem--;
		s += t[i];
	}
	thu(i-1);
}

main(){
	cin >> n >> s;
	for(int i = 0; i<n; i++) cin >> t[i];
	sort(t, t+n);
	thu(n-1);
	cout << kq;
}
