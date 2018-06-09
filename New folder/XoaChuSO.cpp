# include <iostream>
using namespace std;
/*
Cho mot so co N chu so Ban hay xoa di K chu so de duoc so con lai sau khi xoa la lon nhat co the
*/
int n, k;
char so[500001];

void tim(){
	int conlai = k, d = 0;
	while(conlai > 0){
		int cs = d;
		int chot = min(n-1, d +conlai);
		for(int i = d+1; i <= chot; i++){
			if(so[i] > so[cs]) {
				cs = i;
				if(so[cs] == '9') break;
			}
		}
		cout << so[cs];
		conlai = conlai-(cs - d);
		d = cs+1;
		if(conlai == (n-d)){
			break;
		}
		if(conlai == 0){
			cout << (so+cs+1);
			break;
		}
	}
}

main(){
	cin >> n >> k;
	cin >> so;
	tim ();
}
