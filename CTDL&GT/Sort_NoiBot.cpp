# include <iostream>
using namespace std;

short n, a[102];
void _Input();
void _Process();
void _Output(short NumberOfStep); 

main(){
	_Input();
	_Process();
}

void _Input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void _Process(){
	short NumberOfStep = 1;
	bool Done = false;
	for(int i = n-1; i > 0; i--){
		Done = true;
		for(int j = 0; j < i; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				Done = false;
			}
		}
		if(Done) break;
		else _Output(NumberOfStep++);
	}
}

void _Output(short NumberOfStep){
	cout << "Buoc " << NumberOfStep << ": ";
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
