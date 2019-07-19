# include <iostream>
using namespace std;
/*
Cho truoc mot day so duong co N phan tu Ban biet truoc tong cua bat ki 2 phan tu nao trong day so 
hay tim day so ban dau
*/
int n, a[1001][1001], day[10001];

int tim(int cs ){
	for(int h = 1; h <= n; h++){
		for(int c = 1; c <= n; c++){
			if(cs != h && cs != c && a[cs][h] && a[cs][c] && a[h][c]){
				return (a[cs][h] + a[cs][c]-a[h][c])/2;
			}
		}
	}
	return 0;
}

main(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> a[i][j];
		}
	}	
	if(n == 2){
		cout << "1 1";
	}else{
		for(int i = 1; i <=n; i++){
			day[i] = tim(i);
		}
		for(int i = 1; i <= n; i++){
			if(day[i] == 0){
				for(int j = 1; j <= n;  j++){
					if(a[i][j] == 0 && day[j]) day[i] = day[j];
				}
			}
		}
		for(int i = 1; i<=n; i++) cout << day[i] << " ";
	}
}
