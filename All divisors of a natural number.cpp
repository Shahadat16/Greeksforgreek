#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
     int n;
     cin>>n;
     for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<" ";
     }
     cout<<endl;
    }
	return 0;
}

