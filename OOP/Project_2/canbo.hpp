#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class canbo{
	private:
		string hoTen;
		int luong;
	public:
		void nhapbp(){
			cout <<"Ho ten: "<<endl;
			getline(cin,hoTen);
//			cout<<"Luong: ";cin >> luong;
		}
		void xemmh(){
			cout<<"Ho ten: " <<hoTen<<endl;
//			cout<<"Luong: "<<luong<<endl;
		}
		
	friend class danhsachcanbo;
};
