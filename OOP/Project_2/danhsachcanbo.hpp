#include <iostream>
#include <bits/stdc++.h>
#include "canbo.hpp"

using namespace std;

class danhsachcanbo{
	private:
		int tsCanbo;
		canbo dsCanbo[100];
	public:
		void nhapbp(){
			cout<<"Nhap ts can bo:";cin>>tsCanbo;
			for (int i=0;i<tsCanbo;i++){
				dsCanbo[i].nhapbp();
			}
		}
		void xemmh(){
			cout<<"Danh sach can bo:"<<endl;
			for(int i=0;i<tsCanbo;i++){
				dsCanbo[i].xemmh();
			}
		}
		void ghitep(){
			
		}
		void danhsach(){
			
		}
		void sapxep(){
			
		}
};
