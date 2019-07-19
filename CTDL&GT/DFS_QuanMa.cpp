# include <iostream>
# include <string.h>
# include <queue>
using namespace std;
/*Cho mot quan ma tren ban co vua tai vi tri ST Nhiem vu cua ban la hay tim so buoc di chuyen
it nhat de dua quan ma toi vi tri EN*/
struct Coordinates{
	int x, y;
};

Coordinates S, E;
short 	a[10][10], 
		h[] = {-2, -2, -1, 1, 2, 2, 1, -1},
		c[] = {-1, 1, 2, 2, 1, -1, -2, -2};

void _Input();
void _Process();
void _Output();


main(){
	int T;
	cin >> T;
	while(T--){	
		_Input();
		_Process();
	}
}

void _Input(){
	for(int i = 1; i <= 8; i++) 
		for(int j = 1; j <= 8; j++) 
			a[i][j] = 0;
	char temp;
	cin >> temp;
	S.x = (int)(temp-'a'+1);
	cin >> temp;
	S.y = (int)(temp-'0');
	cin >> temp;
	E.x = (int)(temp-'a'+1);
	cin >> temp;
	E.y = (int)(temp-'0');
}

void _Process(){
	int kq = 0, x, y, si;
	queue <Coordinates> q;
	Coordinates temp, them;
	q.push(S);
	a[S.x][S.y] = 1;
	while(q.size()){
		si = q.size();
		for(int loop = 1; loop <= si; loop++){
			temp = q.front();
			q.pop();
			if(temp.x == E.x && temp.y == E.y) {
				cout << kq << endl;
				return;
			}
			for(int i = 0; i < 8; i++){
				them.x = temp.x + h[i];
				them.y = temp.y + c[i];
				if(them.x >= 1 && them.x <= 8 
						&& them.y >= 1 && them.y <= 8 && a[them.x][them.y] == 0){
					q.push(them);
					a[them.x][them.y] == 1;
				}
			}			
		}

		kq++;
	}
}


