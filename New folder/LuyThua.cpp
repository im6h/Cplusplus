# include <iostream>
using namespace std;
//Cho so nguyên duong N và K. Hãy tính N^K modulo 10^9+7.
long long n,k;

long long timdu(long long a, long long b){
	if(b==0) return 1;
	long long t = timdu(a,b/2);
	long long t2 = (t*t) % 1000000007;
	if(b%2) return (t2*a)%1000000007;
	return (t2)%1000000007;
}

main(){
	int sbt;
	cin>>sbt;
	while(sbt--){
		cin >> n >> k;
		cout << timdu(n, k) << endl;
	}
}
