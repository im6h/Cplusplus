#include <bits/stdc++.h>
using namespace std;

class sinhvien{
	protected:
		int maso;
		char hoten[20];
	public:
		nhapbp(){
			cout<<"\nNhap ma so: ";cin>>maso;
			cout<<"\nNhap ho ten: ";
			fflush(stdin);
			cin.getline(hoten,20);
		}
		xemmh(){
			cout<<"\nMa: "<<maso<<"\nHo ten: "<<hoten;
		}
	friend class bangdiem;
	friend class lop;
};
// class lop
class lop{
	private:
		sinhvien a[100];
		int tssinhvien;
	public:
		nhapbp(){
			cout<<"\nNhap tong so sinh vien: ";cin>>tssinhvien;
			for(int i=0;i<tssinhvien;i++){
				a[i].nhapbp();
			}
		}
		xemmh(){
			cout<<"\nDanh sach sinh vien: ";
			for(int i=0;i<tssinhvien;i++){
				a[i].xemmh();
			}
		}
		sapxep(){
			for(int i=0;i<tssinhvien;i++){
				for (int j=i+1;j<=tssinhvien;j++){
					if	(a[i].maso > a[j].maso){
						swap(a[i],a[j]);
					}
				}
			}
		
			for(int u=0;u<tssinhvien;u++){
				a[u].xemmh();
			}
		}
	friend class bangdiem;
};
// class diem sinh vien
class diemsinhvien: public sinhvien{
	private:
		int diemthi,ketqua;
	public:
		int kiemtra(){
			cout<<"\nNhap vao diem thi: ";
			cin>>diemthi;
			if(diemthi >=5){
				cout<<"Qua";
				return 1;
			}else{
				cout<<"Thi lai";
				return 0;
			}
					
		}
	friend class bangdiem;		
};

class bangdiem{
	private:
		char monhoc[20];
		int tsqua,tsthilai,tssinhvien;
		diemsinhvien b[100];
		
	public:
		bangdiem();
		bangdiem(lop c);
		nhapbp(){
			cout<<"\nNhap vao mon hoc: ";
			fflush(stdin);cin.getline(monhoc,20);
			for (int i=0;i<tssinhvien;i++){
				b[i].sinhvien::xemmh();
				if(b[i].kiemtra() == 1){
					tsqua ++;
				}else{
					tsthilai++;
				}
			} 
		}
		xemmh(){
			cout<<"\n\nTong so sinh vien:"<<tssinhvien;
			cout<<"\nTong so qua: "<<tsqua;
			cout<<"\nTong so thi lai: "<<tsthilai;
			for(int i=0;i<tssinhvien;i++){
				b[i].sinhvien::xemmh();
				cout<<"\nDiem thi: "<<b[i].diemthi;
			}
		}
		ghitep(){
			fstream fghi("sinhvien.dat",ios::out|ios::binary);
			fghi.write(reinterpret_cast<char *>(this),sizeof(bangdiem));
			fghi.close();
			cout<<"\nGhi thanh cong";
		}
		doctep(const char *file){
			fstream fdoc(file,ios::in|ios::binary);
			fdoc.read(reinterpret_cast<char *>(this),sizeof(bangdiem));
			fdoc.close();
			xemmh();
		}
};
bangdiem::bangdiem(){
	
}
bangdiem::bangdiem(lop c){
	tssinhvien = c.tssinhvien;
	tsqua = 0;
	tsthilai = 0;
	for(int i=0;i<tssinhvien;i++){
		b[i].maso = c.a[i].maso;
		strcpy(b[i].hoten,c.a[i].hoten);
	}
	
} 
main(){
//	lop l;
//	l.nhapbp();
//	cout<<"\nBang diem: ";
//	bangdiem b;
//	b.doctep("sinhvien.dat");
//	b.nhapbp();
//	b.xemmh();
//	b.ghitep();
}
