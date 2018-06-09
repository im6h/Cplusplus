# include <iostream>
using namespace std;
/*Cho xau S gom N ki tu Ban can phan hoach S thanh cac xau con voi dieu kien moi xau con co ki tu ‘a’ se
co do dai khong qua X 1] neu co ki tu ‘b’ do dai se khong vuot qua X 2] … neu co ki tu ‘z’ do dai se
khong vuot qua X 26] 
2 phan hoach duoc coi la khac nhau neu nhu ton tai it nhat 1 vi tri cat o moi xau la khac nhau Vi du xau
“aaa” 2 phan hoach a aa va aa a la khac nhau vi vi tri cat o xau thu nhat la 1 con o xau thu hai la 2 
Nhiem vu cua ban la can tim 3 so A B C trong do
A la so cach phan hoach thoa man yeu cau In ra dap an theo modulo 10 9 7 
B la xau con co do dai lon nhat trong cac xau con co the co cua mot phan hoach 
C la so xau con nho nhat trong mot phan hoach co the co*/
const long long mod = 1000000007;
int n, a[30];
string  str;
long long btt[1002];

void _Input();
void _Process();

main(){
	int T;
	cin >> T;
	while(T--){
		_Input();
		_Process();
	}
}

void _Input(){
	cin >> n;
	cin >> str;	
	for(int i = 0; i < 26; i++) cin >> a[i];
}

void _Process(){
	// BTT[I] = SO PHAN HOACH CUA XAU KET THUC TAI STR[I]
	int lMin, B = 1, c[1001];
	btt[0] = 1;
	c[0] = 1;
	for(int i = 1; i < n; i++){
		c[i] = c[i-1]+1;
		btt[i] = btt[i-1];
		lMin = a[str[i]-'a'];
		for(int j = i-1;  j > 0; j--){
			lMin = min(lMin, a[str[j]-'a']);
			if(lMin >= (i-j+1)){			
				btt[i] = (btt[i] + btt[j-1])%mod;
				B = max(B, i-j+1);
				c[i] = min(c[i], c[j-1]+1);
			}else break;
		}
		lMin = min(lMin, a[str[0]-'a']);
		if(lMin >= (i+1)){			
			btt[i] = (btt[i] + 1)%mod;
			B = i+1;
			c[i] = 1;
		}
	}
	cout << btt[n-1] << " " << B << " " << c[n-1] << endl;
}

