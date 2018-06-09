# include <iostream>
using namespace std;
/*
Cho mot xâu s. Xâu F(s) duoc xác dinh bang cách ghép xâu xâu s ban dau voi xâu s sau khi dã duoc
quay vòng sang bên phai 1 kí tu (kí tu cuoi cùng cua s duoc chuyen lên dau).
Thuc hien liên tiep các buoc cong xâu nhu trên voi xâu moi thu duoc, ta có duoc xâu X.2
X F s F F s ? ? k k ( ) ( ( )) ?1 v?i F s s 0( ) ? .
Nhiem vu cua ban là hãy xác dinh kí tu thu N trong xâu X là kí tu n	ào?



*/ 
int n, a[20][20], h[20], c[20];
long long tam, kq;

int choncot(int i){
	int trave = 1000000001, cs;
	for(int cot = 1; cot <= n; cot++){
		if(c[cot] == 0){
			if(a[i][cot] < trave){
				cs = cot;
				trave = a[i][cot];
			}
		}
	}
	return cs;
}

void thu(int ha){
	for(int i = 1; i<=n; i++){
		if(h[i] == 0){
			h[i] = 1;
			int cot = choncot(i);
			c[cot] = 1;
			tam += (long long)a[i][cot];
			if(ha == n){
				if(tam > kq) kq = tam;
				//	cout << i << "  "<<cot << " "<<tam<< endl;
			}else{
				thu(i+1);
			}
			h[i] = 0;
			c[cot] = 0;
			tam -= (long long)a[i][cot];
		}
	}
}

main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		kq = -1000000001;
		cin >> n;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				cin >> a[i][j];
			}
		}
		thu(1);
		cout << kq << endl;
	}
}
