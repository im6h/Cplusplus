# include <iostream>
using namespace std;
/*
Cho day so gom co N phan tu Day so A duoc goi la doi xung neu nhu A i] A N i 1] voi moi gia tri
i tu 1 den N 
Ban duoc phep su dung thao tac gop so tuc loai bo di 2 so lien nhau trong day so va thay the chung
bang mot so moi co gia tri bang tong cua 2 so da chon 
Voi mot day so cho truoc hay tinh so thao tac su dung it nhat de co the bien doi day so ban dau thanh
mot day so doi xung
*/
long long n, a[1000001];

main(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	int d = 1, c = n, dem = 0;
	while(d < c){
		if(a[d] < a[c]){
			d++;
			a[d] = a[d]+a[d-1];
			dem++;
		}else{
			if(a[c] < a[d]){
				c--;
				a[c] = a[c]+a[c+1];
				dem++;
			}else{
				d++;
				c--;
			}
		}
	}
	cout << dem;
}
