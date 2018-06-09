# include <iostream>
using namespace std;
/*
Cho bang so A gom n hang va n cot Cac hang duoc danh so tu 1 den n tu tren xuong duoi cac cot cua
luoi duoc danh so tu 1 den n tu trai sang phai O giao cua hang i va cot j goi la o i j va duoc dien mot
so nguyen aij co gia tri tuyet doi khong vuot qua 109 
Xet tro choi doi khang giua hai nguoi tren bang nhu sau Tro choi dien ra trong n luot di moi luot nguoi
thu nhat chon mot hang nguoi thu hai chon mot cot Gia su tai mot luot di neu nguoi choi thu nhat
chon hang i nguoi choi thu hai chon cot j khi do nguoi thu nhat duoc cong aij diem nguoi thu hai duoc
cong aij diem Sau luot di do bang bi xoa hang va cot ma hai nguoi choi vua chon Nguoi co diem cang
cao cang the hien su thong minh cua minh 
Yeu cau Cho bang so A va biet ca hai nguoi deu choi toi uu hay tinh diem lon nhat ma nguoi thu nhat
co the dat duoc

*/
int n, a[10][10],ha[10], co[10];
long long kq;

void _Input(){
	cin >> n;
	for(int h = 1; h <= n; h++){
		for(int c = 1; c <= n; c++)
			cin >> a[h][c];
	}
	kq = 0;
	for(int i = 1; i<=n; i++) {
		ha[i] = 0;
		co[i] = 0;
	}
}

int chooseRow(){
	int m = -1000000001, cs, ma = 1000000001;
	for(int h = 1; h<=n; h++){
		if(ha[h] == 0){
			//cout << h << endl;
			int amin = 1000000001, amax = -1000000001;
			for(int c = 1; c <= n; c++){
				if(co[c] == 0)  {
					amin = min(amin, a[h][c]);
					amax = max(amax, a[h][c]);
				}
			}
			//cout << amin<< endl;
			if(amin > m ){
				//cout << cs << endl;
				ma = amax;
				cs = h;
				m = amin;
			}else{
				if(amin == m){
					if(amax < ma) {
						ma = amax;
						cs = h;
					}
				}
			}
		}
	}
	
	return cs;
}

int chooseColum(int h){
	int mi = 1000000001, cs;
	for(int c = 1; c <= n; c++){
		if(co[c] == 0) {
			if(a[h][c] < mi){
				mi = a[h][c];
				cs = c;
			}
		}
	}
	return cs;
}

void _Play(){
	int h, c;
	for(int i = 1; i<=n; i++){
		h = chooseRow();
		ha[h] = 1;
	//	cout <<"hang: "<< h << endl;
		c = chooseColum(h);
		co[c] = 1;
		kq += (long long)a[h][c];
	//	cout << c << endl;
	}
}

void _Output(){
	cout << kq << endl;
}

main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		_Input();
		_Play();
		_Output();
	}
}
