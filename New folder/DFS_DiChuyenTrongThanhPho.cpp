# include <iostream>
using namespace std;
/*Mister la tong thong cua dat nuoc ma Luka dang sinh song Mot ngay no Mister den tham
thanh pho noi Luka sinh song va de dam bao an ninh mot so van de giao thong bi xao tron 
lam anh huong toi doi song cua nguoi dan va cong viec cho hang cua Luka cung gap chut
van de 5
Khi Mister dang di tren mot con duong nao do canh sat se chan o 2 dau duong va khong cho
phep bat cu ai di vao con duong tuy nhien nhung ai da di vao con duong truoc khi Mister
vao van co the tiep tuc di chuyen va roi khoi con duong nay 
Luka van co gang thuc hien cong viec cho hang cua minh Anh biet truoc duoc lich trinh cua
Mister va tinh toan ke hoach cho minh 
Thanh pho duoc mo phong bang cac nut giao thong va cac con duong 2 chieu 
Hay viet chuong trinh tinh toan thoi gian toi thieu de Luka hoan thanh cong viec cua minh 
Biet rang Luka xuat phat cham hon Mister k phut 
Vi du Mister di vao 1 con duong vao luc 10 phut va can 5 phut de di het con duong thi con
duong nay se bi cam trong cac phut 10 11 12 13 14 Luka khong the di vao duoc tuy
nhien anh co the di vao o phut thu 9 hoac som hon o phut 15 hoac muon hon*/
struct Time{
	int truoc, sau;
};
long long tMin = 1000000000000000000, LukaTime;
int n, m, k, s, e, g;
int a[1001][1001], RouteOfMister[1001], Not[1001];
Time d[1001][100];
void _Input_vs_Init();
void _Find(int ht);

main(){
	_Input_vs_Init();
	_Find(s);
	cout << tMin - k;
}

void _Input_vs_Init(){
	cin >> n >> m;
	cin >> s >> e >> k >> g;
	for(int i = 1; i <= g; i++){
		cin >> RouteOfMister[i];
	}
	int x, y, SumTime = 0;
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		cin >> a[x][y];
		a[y][x] = a[x][y];
	}
	for(int i = 1; i < g; i++){
		d[RouteOfMister[i]][RouteOfMister[i+1]].truoc = SumTime;
		d[RouteOfMister[i+1]][RouteOfMister[i]].truoc = SumTime;
		SumTime += a[RouteOfMister[i]][RouteOfMister[i+1]];
		d[RouteOfMister[i]][RouteOfMister[i+1]].sau = SumTime;
		d[RouteOfMister[i+1]][RouteOfMister[i]].sau = SumTime;
	}
	LukaTime = k;
	Not[s] = 1;
}
void _Find(int ht){
	for(int i = 1; i <= n; i++){
		if(a[ht][i] && Not[i] == 0){
			if(LukaTime  < d[ht][i].truoc || LukaTime >= d[ht][i].sau ){
				if(LukaTime + a[ht][i] < tMin){
					Not[i] = 1;
					LukaTime += (long long)a[ht][i];
					if(i == e) tMin = min(tMin, LukaTime);
					else _Find(i);
					LukaTime -= a[ht][i];
					Not[i] = 0;
				}
			}else{
				if((long long)(a[ht][i] + d[ht][i].sau) < tMin){
					Not[i] = 1;
					long long timeht = LukaTime;
					LukaTime = (long long)(d[ht][i].sau + a[ht][i]);
					if(i == e) tMin = min(tMin, LukaTime);
					else _Find(i);
					LukaTime = timeht;
					Not[i] = 0;
				}
			}
		}
	}
}
