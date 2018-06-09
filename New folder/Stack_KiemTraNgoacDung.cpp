# include <iostream>
using namespace std;
/*Cho mot xau chi gom cac ki tu ‘ ‘ ‘ ’ ‘ ‘ ‘]’ ‘{‘ ‘}’ Mot day ngoac dung duoc dinh nghia nhu sau
 Xau rong la 1 day ngoac dung 
 Neu A la 1 day ngoac dung thi A A] {A} la 1 day ngoac dung 
 Neu A va B la 2 day ngoac dung thi AB la 1 day ngoac dung 
Cho mot xau S Nhiem vu cua ban la xac dinh xau S co la day ngoac dung hay khong*/
int ngoac[100007],d;
string chuoi;

bool kiemTra(){
	if(chuoi.length() % 2) return false;
	d = 0;
	for(int i = 0; i<chuoi.length(); i++){
		if(chuoi[i] == '(' || chuoi[i] == '{' || chuoi[i] == '[') ngoac[++d] = (int)chuoi[i];
		else{
			if(d < 1) return false;
			else{
				if(ngoac[d] == 40 ) {
					if((int)chuoi[i] != 41)
					return false;
				}
				else if(ngoac[d] + 2 != (int)chuoi[i]) return false;
				d--;
			}
		}
	}
	if(d != 0) return false;
	return true;
}

main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> chuoi;
		if(kiemTra()) cout << "YES\n";
		else cout << "NO\n";
	}	
}
