#include <bits/stdc++.h>
using namespace std;

class hang{
	protected:
		char tenhang[20];
		long donggia;
	public:
		void nhapbp(){
			cout<<"\nNhap ten hang: ";
			fflush(stdin);cin.getline(tenhang,20);
			cout<<"Dong gia: ";cin>>donggia;
		}
		void xemmh(){
			cout<<tenhang<<": "<<donggia<<endl;
		}
	friend class banggia;
};
class banggia{
	private:
		hang a[100];
		int tshang;
	public:
		void nhapbp(){
			cout<<"\nNhap ts hang: ";cin>>tshang;
			for(int i=0;i<tshang;i++){
				a[i].nhapbp();
			}
		}
		void xemmh(){
			cout<<"\nTong so hang: "<<tshang<<endl;
			for(int i=0;i<tshang;i++){
				a[i].xemmh();
			}
		}
		long xemgia(char *s){
			for(int i=0;i<tshang;i++){ 
				if(strcmp(a[i].tenhang,s)==0){
					return a[i].donggia;
				}
			}
			return 0;
		}
	friend class phieuxuat;
};

class hangxuat : public hang{
	private:
		long soluongxuat;
		long thanhtien;
	public:
		void nhapsoluongxuat(){
			cout<<"\nNhap so luong xuat: "; cin>> soluongxuat;
		}
		long tinhtien(long donggia){
			return thanhtien = soluongxuat * donggia;	
		}
	friend class phieuxuat;
};
class phieuxuat{
	private:
		int sophieu;
		long tongtien;
		int tshangxuat;
		hangxuat b[100];
		char s[20];
	public:
		void nhapbp(banggia d){
			cout<<"\nNhap sophieu: ";cin>>sophieu;
			cout<<"\nNhap tshangxuat: ";cin>>tshangxuat;
				for	(int i=0;i<tshangxuat;i++){
					cout<<"\nTen hang xuat: ";fflush(stdin);
					cin.getline(s,20);
					cout<<"Gia hang: "<< d.xemgia(s);
					b[i].nhapsoluongxuat();
					cout<<"\nThanh tien: "<<b[i].tinhtien(d.xemgia(s));
					tongtien += b[i].tinhtien(d.xemgia(s));
				}
			}
		void xemmh(){
			cout<<"\nSo phieu: "<<sophieu;
			cout<<"\nTong so hang xuat: "<<tshangxuat;
			cout<<"\nTong tien: "<<tongtien;
		}
		void ghitep(){
			fstream fghi("phieuxuat.dat",ios::out|ios::binary);
			fghi.write(reinterpret_cast<char *> (this),sizeof(phieuxuat));
			cout<<"\nGhi thanh cong";	
			fghi.close();
		}
		void doctep(){
			fstream fdoc("phieuxuat.dat",ios::in|ios::binary);
			fdoc.read(reinterpret_cast<char *> (this),sizeof(phieuxuat));
			fdoc.close();
			xemmh();
		}
};

int main(){
	banggia c;
	c.nhapbp();
	c.xemmh();
	phieuxuat px;
	px.nhapbp(c);
	px.xemmh();
	px.ghitep();
//	px.doctep();
	return 0;
}
