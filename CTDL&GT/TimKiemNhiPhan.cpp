#include<bits/stdc++.h>
using namespace std;
/*
Cho day so A ] gom co N phan tu da duoc sap xep tang dan va so K 
Nhiem vu cua ban la kiem tra xem so K co xuat hien trong day so hay khong Neu co hay in ra vi tri
trong day A ] neu khong in ra “NO”*/
int a[10000004],k,n;
int Tim(){
    int d=0, c=n-1,mid;
    while(d<=c){
        if(a[d]==k) return d;
        if(a[c]==k) return c;
        mid = (d+c)/2;
        if(a[mid]==k) return mid;
        if(a[mid]<k){
            d   = mid+1;
            c--;
        }
        else {
            d++;
            c   = mid-1;
        }
    }
    return -1;
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int cs = Tim();
        if(cs>=0) cout<<cs+1<<endl;
        else cout<<"No"<<endl;
    }
}
