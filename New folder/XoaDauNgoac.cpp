# include <iostream>
# include <algorithm>
using namespace std;
/*
Cho bieu thuc toan hoc dung ban can tim tat ca cac bieu thuc dung co the bang cach xoa bo cac cap dau
ngoac tuong ung voi nhau tu bieu thuc ban dau 
Vi du Cho bieu thuc 2 2 2 2 
Cac bieu thuc tim duoc
 2 2 2 2 
2 2 2 2
2 2 2 2
Cac bieu thuc 2 2 2 2 va 2 2 2 2 khong duoc chap nhan vi khong xoa di cac cap dau ngoac tuong
ung voi nhau
*/
string bt, inra, ht[99999];
int ng[13][2], n, x[13], Mo = 0;

void tim_ngoac(){
	int cs = 0, d = 1;
	for(int i = 0; i < bt.length(); i++){
		if(bt[i] == '('){
			ng[++cs][0] = i;
			d = cs;
		}else{
			if(bt[i] == ')'){
				ng[d][1] = i;
				while(d > 0 && ng[d][1] != 0) d--;
			}
		}
	}
	n = cs;
}

bool sinh(){
	int cs = n;
	while(cs >= 1 && x[cs] == 1) x[cs--] = 0;
	if(cs < 1) return false;
	x[cs] = 1;
	return true;
}

void in(){
	int xoa[26], cs = 0;
	for(int i = 1; i<=n; i++){
		if(x[i] == 1){
			xoa[cs++] = ng[i][0];
			xoa[cs++] = ng[i][1];
		}
	}
	sort(xoa, xoa +cs);
	inra = bt;
	for(int i = cs-1; i>=0; i--) inra.erase(inra.begin()+xoa[i]);
	for(int i = 0; i<Mo; i++){
		if(ht[i] == inra ) return;
	}
	ht[Mo++] = inra;
}

main(){
	cin >> bt;
	for(int i = 1; i<=10; i++) ng[i][1] = 0;
	tim_ngoac();
	while(sinh()){
		in();
	}
	sort(ht, ht+Mo);
	for(int i = 0; i<Mo; i++) cout << ht[i]<< endl;
}
