# include <iostream> 
using namespace std;

int n, a[102];
void _Input();
void _Process();
void _Output(int sb);

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
	int temp, IndexInsert;
	for(int i = 0; i < n; i++){
		temp = a[i];
		IndexInsert = i;
		while(IndexInsert > 0 && a[IndexInsert-1] > temp){
			a[IndexInsert] = a[IndexInsert-1];
			IndexInsert--;
		}
		a[IndexInsert] = temp;
		_Output(i);
	}
}

void _Output(int sb){
	cout << "Buoc " << sb << ": ";
	for(int i = 0; i <= sb; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
