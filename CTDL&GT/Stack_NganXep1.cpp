# include <iostream>
using namespace std;
/*Cho mot ngan xep cac so nguyen Cac thao tac duoc mo ta trong file van ban gom 3 lenh push pop
va show Trong do thao tac push kem theo mot gia tri can them Hay viet chuong trinh ghi ra ket qua
cua cac lenh show*/
int stack[1000000], d = 0;

main(){
	string lenh;
	while(cin >> lenh){
		if(lenh == "push"){
			d++;
			cin >> stack[d];
		}else{
			if(lenh == "pop"){
				if(d > 0) d--;
			}else{
				if(d == 0) cout << "empty\n";
				else{
					for(int i = 1; i<=d; i++) cout << stack[i]<<" ";
					cout << endl;
				}
			}
		}
	}
}
