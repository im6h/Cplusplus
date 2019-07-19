# include <iostream>
using namespace std;
/*
Cho mot x�u s. X�u F(s) duoc x�c dinh bang c�ch gh�p x�u x�u s ban dau voi x�u s sau khi d� duoc
quay v�ng sang b�n phai 1 k� tu (k� tu cuoi c�ng cua s duoc chuyen l�n dau).
Thuc hien li�n tiep c�c buoc cong x�u nhu tr�n voi x�u moi thu duoc, ta c� duoc x�u X.2
X F s F F s ? ? k k ( ) ( ( )) ?1 v?i F s s 0( ) ? .
Nhiem vu cua ban l� h�y x�c dinh k� tu thu N trong x�u X l� k� tu n	�o?



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
