# include <iostream>
using namespace std;
/*Ban dau cho mot queue rong Ban can thuc hien cac truy van sau
1 Tra ve kich thuoc cua queue
2 Kiem tra xem queue co rong khong neu co in ra “YES” neu khong in ra “NO” 
3 Cho mot so nguyen va day so nguyen nay vao cuoi queue 
4 Loai bo phan tu o dau queue neu queue khong rong neu rong khong can thuc hien 
5 Tra ve phan tu o dau queue neu queue rong in ra 1 
6 Tra ve phan tu o cuoi queue neu queue rong in ra 1*/
int q[10000], d, c;

main(){
	int sbt,n, lenh, k;
	cin >> sbt;
	while(sbt--){
		cin >> n;
		d = 1; c = 0;
		for(int i = 1; i<=n; i++){
			cin >> lenh;
			switch(lenh){
				case 1: cout << c-d+1<<endl; 
						break;
						
				case 2: if(c < d) cout << "YES\n";
						else cout << "NO\n";
						break;
						
				case 3: cin >> q[++c]; 
						break;
						
				case 4: if(c >= d) d++;
						break;
						
				case 5: if(c < d) cout << "-1\n";
						else cout << q[d]<< endl;
						break;
						
				case 6: if(c < d) cout << "-1\n";
						else cout << q[c]<< endl;
						break;
			}
		}
	}
}
