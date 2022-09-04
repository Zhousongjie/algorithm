#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int x;
    cin>>x;
    for(int i=0;i<n;i++){
        if(x==num[i]){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}