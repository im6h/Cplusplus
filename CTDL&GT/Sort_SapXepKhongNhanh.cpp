# include <iostream>
# include <stdlib.h>
using namespace std;

int n;
long long a[100002], b[100002];
void _Input();
void radixSort();
void _Output();

main(){
	_Input();
	radixSort();
	_Output();
}

void _Input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void _Output(){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

void radixSort(){
	long long maxA = a[0], mod = 1;
	int cs[12];
	for(int i = 1; i < n; i++) maxA = max(maxA, a[i]);
	while(maxA/mod){
		//cout << mod << endl;
		for(int i = 0; i < 12; i++) cs[i] = 0;
		for(int i = 0; i < n; i++){
			cs[(long long)(a[i]/mod)%10]++;
		}
		for(int i = 1; i < 12; i++) cs[i] += cs[i-1];	
		for(int i = n-1; i >= 0; i--){
			//cout <<"-" << cs[(long long)(a[i]/mod)%10] << endl;
			b[--cs[(a[i]/mod)%10]] = a[i];
		}
		for(int i = 0; i < n; i++) a[i] = b[i];
		mod *= 10;
	}
}
