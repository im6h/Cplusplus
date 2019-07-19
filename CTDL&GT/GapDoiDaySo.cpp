# include <iostream>
using namespace std;
/*
Mot day so tu nhien bat dau boi con so 1 va duoc thuc hien N 1 phep bien doi “gap doi” day so nhu sau
Voi day so A hien tai day so moi co dang A x A trong do x la so tu nhien be nhat chua xuat hien trong
A 
Vi du voi 2 buoc bien doi ta co 1] ? 1 2 1] ? 1 2 1 3 1 2 1] 
Cac ban hay xac dinh so thu K trong day so cuoi cung la bao nhieu
*/
long long n, k;

long long tim(){
	if(k == 1) return 1;
	long long dem = 1, x = 1;
	while(dem < k){
		dem = dem*2+1;
		x++;
	}
	if(dem == k) return 1;
	dem/=2;
	dem++;
	if(dem == k) return x;
	while(k > 1){
		k -= (dem);		
		while(k < dem){
			dem /=2;
			x--;
		}
		if(k == dem) return x;
	}return 1;
}

main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> n >> k;
		cout << tim()<< endl;
	}
	
}
