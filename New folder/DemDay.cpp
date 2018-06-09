# include <iostream>
using namespace std;
/*
Cho so nguyen duong n Hay cho biet co bao nhieu day so nguyen duong co tong cac phan tu trong day
bang n*/
long long n;

long long tinh(long long b){
	if(b == 0) return (long long)1;
	long long tem = tinh(b/2);
	long long k = (tem*tem)%123456789;
	if(b%2){		
		return (long long)(k*2)%123456789;
	}
	return k;
}

main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> n;
		cout << tinh(n-1)<< endl;
	}
}
