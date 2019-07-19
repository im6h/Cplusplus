# include <iostream>
# include <algorithm>
using namespace std;
/*Ca tuan lien ngoi doc Harry Potter lam dau oc cua Ti ngay nao cung nghi ve phep thuat Dem qua cau da co
giac mo tro thanh nhan vat chinh cua cau chuyen 
Ti thay minh dang chien dau voi ke thu va bi truy duoi rao riet Nhiem vu cua Ti hien tai la di tim nhung
chiec gay ma thuat de mang lai suc manh cho nhung dong doi dang bi co lap cua minh Theo loi chi dan cuamot nha tien tri Ti da den duoc khu vuon phep mau Sau khi su dung mot vai than chu Ti da tim duoc N
chiec gay co suc manh lon nhat moi chiec co do dai bang A i] Tuy nhien nhung chiec gay nay can phai
duoc bao ve trong nhung chiec hop phep thuat neu khong chung se bi suy giam ma thuat Ti cung da tim
duoc N chiec hop phep thuat Mot chiec gay co the dat duoc trong mot chiec hop phep thuat neu nhu chieu
dai X cua no khong vuot qua kich thuoc Y cua chiec hop X = Y 
Thoi gian het suc gap rut Cac ban hay tinh giup Ti xem lieu co the mang di duoc tat ca N chiec gay ma thuat
hay khong Neu co the day se la nguon suc manh than bi vo gia de Ti cung cac dong doi chien thang duoc
ke thu*/
int n, k, Wand[100002], Box[100002];
void _Input();
void _Process();

main(){
	_Input();
	_Process();
}

void _Input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> Wand[i];
	}
	for(int i = 0; i < n; i++){
		cin >> Box[i];
	}
	
}

void _Process(){
	bool kq = 1;
	sort(Wand, Wand + n);
	sort(Box, Box + n);
	for(int i = 0; i < n; i++){
		if(Wand[i] > Box[i]){
			kq = 0;
			break;
		}
	}
	if(kq) cout << "YES";
	else cout << "NO";
}
