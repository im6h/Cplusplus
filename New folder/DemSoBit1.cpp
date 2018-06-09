# include <iostream>
using namespace std;
/*
Cho so nguyen duong N Moi buoc ban se bien doi N thanh N 2] N mod 2 N 2] Sau khi thuc hien
mot cach triet de ta thu duoc mot day so chi toan so 0 va 1 
Nhiem vu cua ban la hay dem cac so bang 1 trong doan L R] cua day so cuoi cung*/
long long  n, l, r, kq;
long long tim(){
	short x[60];
	long long ntam = n, cs = 1;
	while(ntam > 1){
		x[cs++] = ntam%2;
		ntam/=2;
	}
	for(int d = 1, c = cs-1; d < c; d++, c--) swap(x[d], x[c]);
	long long khoang = 2, tr_r, tr_l;
	for(int i = 1; i<cs; i++){
		khoang*=2;
		if(x[i]){
			if(r < khoang/2){
				continue;
			}
			tr_r = (long long)(r-khoang/2)/khoang + 1;		
			if(l < khoang/2) {
				tr_l = 0;
			}else{
				tr_l = (long long)(l-khoang/2)/khoang;
				if((l-khoang/2)%khoang != 0) tr_l++;
			}			
			kq+=(tr_r-tr_l);
		//	cout << tr_r<< " "<<tr_l << " "<< khoang<< endl;
		}
	}
	//cout << kq << endl;
	if(l%2 == 0) l++;
	if(r%2 == 0) r--;
	if(r >= l){
		kq += ((r-l)/2+1);
	//	cout << (r-l)/2+1<< endl;
	}
}

main(){
	int sbt;
	cin>>sbt;
	while(sbt--){
		kq = 0;
		cin >> n >> l >> r;
		tim();
		cout << kq << endl;
	}
}
