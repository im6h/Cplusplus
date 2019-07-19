#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Sach{
	private:
		int ma;
		string ten;
	public:
		void nhapbp(){
			cout<<"Nhap vao ma sach: ";cin>> ma;
		cout<<"Nhap vao ten sach: ";cin>>ten;
		};
		void xemmh(){
			cout << "Ma sach: "<<ma<<endl;
			cout << "Ten sach: "<<ten<<endl;
		};
	friend class dmSach;
};


