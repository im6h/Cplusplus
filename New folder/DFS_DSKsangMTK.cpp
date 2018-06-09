# include <iostream>
# include <string.h>
using namespace std;
/*Cho don do thi vo huong co n dinh duoi dang danh sach ke 
Hay bieu dien do thi bang ma tran ke*/
int n;
short a[1002][1002];

void _Input();
void _Process(int r, string temp);
void _Output();


main(){
	_Input();
	_Output();
}

void _Input(){
	string temp;
	cin >> n;
	getline(cin, temp);
	for(int r = 1; r <= n; r++){
		getline(cin, temp);
		_Process(r, temp);
	}
}

void _Process(int r, string temp){
	int l = temp.length(), cs;
	for(int i = 0; i < l; i++){
		if(temp[i] == ' ') continue;
		else{
			cs = temp[i]-48;
			while(i < l-1 && temp[i+1] != ' '){
				i++;
				cs = cs*10+temp[i]-48;
			}
			a[r][cs] = 1;
		}
	}
}

void _Output(){
	for(int r = 1; r <= n; r++){
		for(int c = 1; c <= n; c++){
			cout << a[r][c] << " ";
		}
		cout << endl;
	}
}

