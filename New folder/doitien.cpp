# include<iostream>
# include<algorithm>
using namespace std;

int ds = 30, tth = 0,n, s, gt[25];

void tim(int i){
	for(int j = 0; j<2; j++){
		s -= j*gt[i];
		tth +=j;
		if(s == 0) ds = min(ds, tth);
		else	
			if(i == n-1 || s < gt[i+1] || gt[n-1] * (n-i-1) < s){
				s += j*gt[i];
				tth -=j;
			}
			else {
				tim(i+1);
				s+=j*gt[i];
				tth -=j;
			}
	}
}

main(){

	cin>>n>>s;
	for (int i = 0; i<n; i++) cin>>gt[i];
	sort(gt, gt+n);	
	tim(0);
	if(ds!=30)
	cout<<ds;
	else cout<<-1;
	
}
