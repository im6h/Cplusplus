#include<iostream>
using namespace std;

class xaukytu{
	protected:
		char *kytu;
		int dodai;
	public:
		xaukytu(){
			dodai=0;
			kytu = NULL;
		}
		xaukytu(char s[]){
			dodai = 0;
			for(;s[dodai]!='\0';++dodai);
			kytu = new char[dodai+1];
			for(int i=0;s[i]!='\0';++i){
				kytu[i]=s[i];
			}
			kytu[dodai] = '\0';
		}
		void xemmh(){
			cout<<kytu;
		}
		char *trichtrai(int m){
			char *p = new char[m+1];
			for(int i=0;i<m;i++){
				p[i] = kytu[i];
			}
			p[m] = '\0';
			return p;
		}
		operator int(){
			int sn=0, m=1;
			for(int i=dodai-1;i>=0;i--){
				sn = sn + m*(kytu[i]-'0');
				m = m*10;
			}
			return sn;
		}
		xaukytu(int sn){
			char s[10];
			int d=0;
			while(sn!=0){
				s[d] = sn%10+'0';
				sn = sn/10;
				++d;
			}
		
			int i=0,j=d-1;
			char x;
			while(i<j){
				x = s[i];
				s[i] = s[j];
				s [j] = x;
				i++;
				j--;
			}
			dodai = d;
			kytu = new char[d+1];
			for(int i=0;i<=d;i++){
				kytu[i] = s[i];
			}
		}
		
};
 main(){
	xaukytu c("1234");
	c.xemmh();
//	cout<<"\nTrich trai: "<<c.trichtrai(4);
	cout<<"\nInt(c): "<<int(c);
	cout<<"\nXau ky tu: "<<xaukytu(123);
}
