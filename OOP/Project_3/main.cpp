#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Sach{
	private:
		int ma;
		char tenSach[20];
	public:
		void nhapbp(){
			cout<<"\nNhap ma: ";cin>>ma;
			cout<<"\nNhap ten sach: ";
			fflush(stdin);
			cin.getline(tenSach,20);
			fflush(stdin);
	}
		void xemmh(){
			cout<<"\n"<<ma<<":"<<tenSach;
		}
	friend class dmSach;	
};
class dmSach{
	private:
		Sach dm[100];
		int tsSach;
	public:
		void nhapbp(){
			cout<<"\nNhap ts sach: "; cin>>tsSach;
			for(int i=0;i<tsSach;++i){
				dm[i].nhapbp();
			}
		}
		void xemmh(){
			cout<<"\nDanh muc sach: ";
			for(int i=0;i<tsSach;++i){
				dm[i].xemmh();
			}
		}
		void ghitep(){
			fstream fghi("sach.dat",ios::out|ios::binary);
			fghi.write(reinterpret_cast<char *>(this),sizeof(dmSach));
			cout<<"\nGhi thanh cong";
			fghi.close();
		}
		dmSach();
		dmSach(const char tep[20]);
		char *xemten(int ma){
			char *ts = new char[20];
			for (int i=0;i<tsSach;++i){
				if(dm[i].ma == ma){
					strcpy(ts,dm[i].tenSach);
				}
			}
			return ts;
		}
};
dmSach::dmSach(const char tep[20]){
	fstream fdoc(tep,ios::in|ios::binary);
	fdoc.read(reinterpret_cast<char *>(this),sizeof(dmSach));
	fdoc.close();
	xemmh();
}
int main(){
	dmSach s("sach.dat");
	cout<<"\nSach co ma 3: "<<s.xemten(3);
	return 0;
}
