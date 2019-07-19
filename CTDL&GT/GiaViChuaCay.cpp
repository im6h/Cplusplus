# include <iostream>
# include <cmath>
using namespace std;
/*
Mot nha hang rat noi tieng voi cac mon an chua va cay Hien tai dang co
tat ca N loai gia vi Moi loai co do chua S i va do cay B i dac chung Khi tron K loai gia vi vao mon an 
do chua cua mon an se bang tich do chua cua K loai gia vi trong khi do do cay se bang tong do cay cua
K loai gia vi De cho mon an duoc hap dan va hai hoa dau bep se chon cac loai gia vi sao cho su chenh
lech giua do chua va do cay cua mon an la nho nhat Di nhien can phai chon it nhat mot loai gia vi cho
mon an Cac ban hay giup dau bep thuc hien cong viec nay*/
int n, kq = 1000000000, ch[12], ca[12];
short x[12];

bool sinh(){
	int cs = n;
	while(cs >= 1 && x[cs] == 1) x[cs--] = 0;
	if(cs < 1) return false;
	x[cs] = 1;
	return true;
}

int tinh(){
	int chua = 1, cay = 0;
	for(int i = 1; i<=n; i++){
		if(x[i]){
			chua *= ch[i];
			cay  += ca[i];
		}
	}
	return abs(chua-cay);
}

void capnhat(){
	int chl = tinh();
	if(chl < kq) kq = chl;
}

main(){
	
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> ch[i] >> ca[i];
	}
	while(sinh()){
		capnhat();
	}
	cout << kq;
	
}
