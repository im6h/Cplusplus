# include <iostream>
using namespace std;
/*Cho mot xau chi gom cac ki tu ‘ ‘ va ‘ ’ Mot day ngoac dung duoc dinh nghia nhu sau
 Xau rong la 1 day ngoac dung 
 Neu A la 1 day ngoac dung thi A la 1 day ngoac dung 
 Neu A va B la 2 day ngoac dung thi AB la 1 day ngoac dung 
Cho mot xau S Nhiem vu cua ban la hay tim day ngoac dung dai nhat xuat hien trong xau da cho*/
struct md{
	int Mo, Dong, trth;
	int dodai;
};
string chuoi;
md  tim[1000009];
int d;
bool kiemTra(){
	if(tim[d-1].trth == 1){
		if(tim[d-1].Mo + 1 == tim[d].Mo && tim[d-1].Dong - 1 == tim[d].Dong){
			return true;
		}
		if(tim[d-1].Dong + 1 == tim[d].Mo){
			tim[d-1].Dong = tim[d].Dong;
			return true;
		}
	}
	return false;
}


int timMax(){
	d = 0;
	int l = chuoi.length();
	for(int i = 0; i<l; i++){
		if(chuoi[i] == '('){
			tim[++d].Mo = i;
			tim[d].trth = 0;
		}else{
			if(d > 0){
				int cs = d;
				while(cs >= 1 && tim[cs].trth == 1) cs--;
				tim[cs].Dong = i;
				tim[cs].dodai = 2;
				tim[cs].trth = 1;
				while(d > 1 && kiemTra()){
					tim[d-1].dodai+=tim[d].dodai;
					d--;
				}
			}
		}
	}
	int kq = 0;
	for(int i = 1; i<=d; i++){
		if(tim[i].trth){
			kq = max(kq, tim[i].dodai);
		}
	}
	return kq;
}

main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> chuoi;
		cout << timMax()<< endl;
	}
}
