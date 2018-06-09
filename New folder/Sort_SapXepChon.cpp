# include <iostream>
using namespace std;

int n, a[102];
void _Input();
void _Process();
void _Output(int i);

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

void _Output(int sb){
	cout << "Buoc " << sb << ": ";
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void _Process(){
	int IndexMin;
	for(int i = 0; i < n-1; i++){
		IndexMin = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[IndexMin]) IndexMin = j;
		}
		swap(a[i], a[IndexMin]);
		_Output(i+1);
	}
}
