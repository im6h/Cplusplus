# include <iostream>
# include <cmath>
using namespace std;
//Cho so nguy�n N. Nhiem vu cua ban can t�m so nguy�n X nho nhat l� boi cua N, v� X chi chua hai chu
so 0 v� 9
long long n;
long long so[1000000];

long long tim(){
	so[0] = 9;
	int d = 0, c = 0, mu = 1, cs = 0;
	while(so[cs] % n != 0){
		if(d == c){
			so[++cs] = 9*pow(10,mu++);
			c = 0; d = cs;
		}else{
			so[++cs] = so[d] + so[c++];
		}
	}
	return so[cs];
}


main(){
	
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> n;
		cout << tim() << endl;
	}
}
