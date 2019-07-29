#include <bits/stdc++.h>
using namespace std;

// class canbo
class canbo{
	protected:
		char hoten[20];
		long luongcoban;
	public:
		void nhapmh(){
			cout<<"\nNhap ho ten: ";
			fflush(stdin);cin.getline(hoten,20);
			cout<<"\nNhap luong: ";
			cin>>luongcoban;
		}
		void xemmh(){
			cout<<hoten<<"- "<<"Luong co ban: "<<luongcoban<<endl;
		}
	friend class bangluong;
};
class danhsach{
	private:
		canbo a[100];
		int tscanbo;
	public:
		void nhapbp(){
			cout<<"\nNhap ts can bo: "; cin>>tscanbo;
			for(int i=0;i<tscanbo;i++){
				a[i].nhapmh();
			}
		}
		void xemmh(){
			cout<<"\nDanh sach: \n";
			for(int i=0;i<tscanbo;i++){
				a[i].xemmh();
			}
		}
	friend class bangluong;
};
class luongcb : public canbo{
	private:
		int ngaycong;
		long luong;
	public:
		void nhapNgayCong(){
			cout<<"Nhap ngay cong: "; cin>> ngaycong;
		}
		long tinhLuong(){
			return luong = luongcoban + ngaycong * 50000;
		}
		void xemLuong(){
			cout<<"Luong: "<<luong;
		}
	friend class bangluong;
};
class bangluong{
	private: 
		int thang, tongluong,tscanbo;
		luongcb b[100];
	public:
		bangluong();
		bangluong(danhsach d);
		void nhapbp(){
			cout<<"\nThang: "; cin>>thang;
			for (int i=0;i<tscanbo;i++){
				b[i].xemmh();
				b[i].nhapNgayCong();
				tongluong += b[i].tinhLuong();
			}
		}
		void xemmh2(){
			cout<<"\nBang luong thang: "<<thang<<endl;
			cout<<"Tong luong: "<<tongluong<<endl;
			for(int i=0;i<tscanbo;i++){
				cout<<"\n";
				b[i].xemmh();
				b[i].xemLuong();
				
			}
		}
		void ghitep(){
			fstream fghi("Bangluong.dat",ios::out|ios::binary);
			fghi.write(reinterpret_cast<char *>(this),sizeof(bangluong));
			cout<<"\nGhi thanh cong";
			fghi.close();
		}
	
};
bangluong::bangluong(danhsach d){
		tscanbo = d.tscanbo;
		for	(int i=0;i<tscanbo;i++){
			strcpy(b[i].hoten,d.a[i].hoten);
			b[i].luongcoban = d.a[i].luongcoban;
		}
}; 
int main(){
	danhsach c;
	c.nhapbp();
	bangluong bl(c);
	bl.nhapbp();
	bl.xemmh2();
	bl.ghitep();
		
	return 0;
}
