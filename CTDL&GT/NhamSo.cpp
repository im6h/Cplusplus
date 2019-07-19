# include <iostream>
using namespace std;
/*
Trong mot buoi hoc toan giao vien viet 2 so nguyen A va B va yeu cau Teo thuc hien phep cong Teo
hong bao gio tinh toan sai nhung thinh thoang cau ta khong chep cac con so mot cach chinh xac Loi
duy nhat cua la ghi nham 5 thanh 6 hoac nguoc lai Cho hai so A va B tinh tong nho nhat va lon nhat
ma Teo co the nhan duoc*/
string a, b;

int nho(){
	string aa = a;
	int so = 0;
	for(int i = 0; i<aa.length(); i++){
		if(aa[i] == '6') {
			so = so*10+5;
		}else{
			so = so*10+aa[i]-48;
		}
	}
	string bb = b;
	int s = 0;
	for(int i = 0; i<bb.length(); i++){
		if(bb[i] == '6') {
			s = s*10+5;
		}else{
			s = s*10+bb[i]-48;
		}
	}
	return so + s;
}

int lon(){
	string aa = a;
	int so = 0;
	for(int i = 0; i<aa.length(); i++){
		if(aa[i] == '5') {
			so = so*10+6;
		}else{
			so = so*10+aa[i]-48;
		}
	}
	string bb = b;
	int s = 0;
	for(int i = 0; i<bb.length(); i++){
		if(bb[i] == '5') {
			s = s*10+6;
		}else{
			s = s*10+bb[i]-48;
		}
	}
	return so +s;
}


main(){
	cin >> a >> b;
	cout << nho() << lon();
}
