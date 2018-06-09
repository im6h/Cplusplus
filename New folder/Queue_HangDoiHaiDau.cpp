# include <iostream>
# include <vector>
using namespace std;
/*Yeu cau ban xay dung mot hang doi hai dau voi cac truy van sau day
“PUSHFRONT x” Them phan tu x vao dau cua dequeue 0 x 1000 
“PRINTFRONT” In ra phan tu dau tien cua dequeue Neu dequeue rong in ra “NONE” 
“POPFRONT” Xoa phan tu dau cua dequeue Neu dequeue rong khong lam gi ca 
“PUSHBACK x” Them phan tu x vao cuoi cua dequeue 0 x 1000 11
“PRINTBACK” In ra phan tu cuoi cua dequeue Neu dequeue rong in ra “NONE” 
“POPBACK” Xoa phan tu cuoi cua dequeue Neu dequeue rong khong lam gi ca 
Input*/
vector <int> q;

main(){
	string lenh;
	int scv, k;
	cin >> scv;
	while(scv--){
		cin >> lenh;
		if(lenh == "PUSHFRONT"){
			cin >> k;
			if(q.size())  q.insert(q.begin(),k);
			else q.push_back(k);
		}else{
			if(lenh == "PRINTFRONT"){
				if(q.size()) cout << q[0]<< endl;
				else cout << "NONE\n";
			}else{
				if(lenh == "POPFRONT"){
					if(q.size()) q.erase(q.begin());
				}
			}
		}
		if(lenh == "PUSHBACK"){
			cin >> k;
			q.push_back(k);
		}else{
			if(lenh == "PRINTBACK"){
				if(q.size()) cout << q[q.size()-1]<< endl;
				else cout << "NONE\n";
			}else{
				if(lenh == "POPBACK"){
					if(q.size()) q.erase(q.begin()+q.size()-1);
				}
			}
		}
	}
}
