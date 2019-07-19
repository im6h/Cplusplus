# include <iostream>
using namespace std;
/*
Mot day xau ky tu G chi bao gom cac chu cai A va B duoc goi la day xau Fibonacci neu thoa man tinh
chat G 1 A; G 2 B; G n G n 2 G n 1 Voi phep cong la phep noi hai xau voi nhau 
Bai toan dat ra la tim ky tu o vi tri thu i tinh tu 1 cua xau Fibonacci thu n*/
long long fibo[93], n, k;

void xuLy(){
	if(n == 1){
		cout << "A\n";
		return;
	}else{
		if( n == 2){
			cout << "B\n";
			return;
		}else{
			while(n > 2){
				if(k > fibo[n-2]){
					k -= fibo[n-2];
					n--;
				}else{
					n-=2;+9-
				}
			}
			if(n == 1) cout << "A\n";
			else cout << "B\n";
		}
	}

}

main(){
	fibo[1] = 1;
	fibo[2] = 1;
	for(int i = 3; i<93; i++){
		fibo[i] = fibo[i-1]+fibo[i-2];
	}
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> n >> k;
		xuLy();
	}
	
}
