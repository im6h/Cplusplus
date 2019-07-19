# include <iostream>
using namespace std;
/*Cho mot xau chi gom cac ki tu ‘ ‘ ‘ va co do dai chan Hay dem so luong dau ngoac can phai doi
chieu it nhat sao cho xau moi thu duoc la mot day ngoac dung*/
string chuoi;

int timMin(){
	int rt = 0, m = 0;
	int l = chuoi.length();
	for(int i = 0; i<l; i++){
		if(chuoi[i] == '('){
			m++;
		}else{
			if(m > 0) m--;
			else{
				rt++;
				m++;
			} 
		}
	}
	return rt+m/2;
}

main(){
	int sbt;
	cin >> sbt;
	while(sbt--){
		cin >> chuoi;
		cout << timMin()<< endl;
	}
}
