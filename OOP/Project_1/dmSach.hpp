#include <iostream>
#include <bits/stdc++.h>
#include "Sach.hpp"
using namespace std;

class dmSach{
	private:
		int tsSach;
		Sach dm[100];
		
	public:
		void nhapbp(){
			cout << "Nhap vao tong so sach: "; cin>> tsSach;
			for	(int i=0;i<tsSach;i++){
				dm[i].nhapbp();
			}	
		};
		void xemmh(){
			for(int i=0;i<tsSach;i++){
				dm[i].xemmh();
			}
		};
};

