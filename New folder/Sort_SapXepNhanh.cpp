# include <iostream>
using namespace std;

int n, a[100002];
void _Input();
void quickSort(int Left, int Right);
void _Output(); 

main(){
	int NumberOfTest;
	cin >> NumberOfTest;
	while(NumberOfTest--){
		_Input();
		quickSort(0, n-1);
		_Output();
	}
}

void _Input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void quickSort(int Left, int Right){
	int Chot = a[(Left+Right)/2], TempLeft = Left, TempRight = Right;
	
	while(TempLeft <= TempRight){
		
		while(TempLeft < Right && a[TempLeft] < Chot) TempLeft++;
		while(TempRight > Left && a[TempRight] > Chot) TempRight--;
		
		if(TempLeft <= TempRight){
			swap(a[TempLeft], a[TempRight]);
			TempLeft++;
			TempRight--;
		}		
	}
	if(TempLeft < Right) quickSort(TempLeft, Right);
	if(TempRight > Left) quickSort(Left, TempRight);
}

void _Output(){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
