# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
/*Mot cua hang thoi trang dang thuc hien chuong trinh khuyen mai giam gia Ban dau gia cua san pham i la
a i] khi den tuan giam gia gia cua chung giam xuong con b i] Tuy nhien chu cua hang rat khon nham danh
lua khach hang moi so san pham gia tang len chu khong he giam xuong 
Nhan biet duoc quy luat nay Ti mac du can phai mua tong cong N san pham nhung cau quyet dinh mua K
san pham truoc dot khuyen mai va N K san pham trong dot khuyen mai 
Gia su rang Ti chon toi uu duoc K san pham ban dau cac ban hay tinh xem so tien it nhat Ti can bo ra de
mua du N san pham la bao nhieu*/
struct Price{
	int Index, Different;
};
vector <Price> v;
int n, k, bf[100002], at[100002];
void _Input();
void _Process();
bool ss(Price befor, Price after){
	return befor.Different < after.Different;
}

main(){
	_Input();
	_Process();
}

void _Input(){
	Price temp;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> bf[i];
	}
	for(int i = 0; i < n; i++){
		cin >> at[i];
	}
	for(int i = 0; i < n; i++){
		temp.Different = bf[i] - at[i];
		temp.Index = i;
		v.push_back(temp);
	}
}

void _Process(){
	long long kq = 0;
	sort(v.begin(), v.end(), ss);
	for(int i = 0; i < k; i++){
		kq += (long long)bf[v[i].Index];
	}
	for(int i = k; i < n; i++){
		kq += (long long)at[v[i].Index];
	}
	cout << kq;
}
