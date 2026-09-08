#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n[8];
    cout<<"Enter the numbers\n";
    for(int i=0;i<8;i++){
        cin>>n[i];
    }
    int a=INT_MIN;
    int p;
    for(int j=0;j<8;j++){
        if(a<n[j]){
            a=n[j];
            p=j;
        }
    }
    cout<<"The Largest number is "<<a<<" at "<<p<<endl;;
    int b=INT_MAX;
    int q;
    for(int k=0;k<8;k++){
        if(b>n[k]){
            b=n[k];
        }
    }
    cout<<"The smallest number is "<<b<<" at "<<q<<endl;

    for(int l = 0; l < 8; l++){

        bool alreadyPrinted = false;


        for(int p = 0; p < l; p++){
            if(n[l] == n[p]){
                alreadyPrinted = true;
                break;
            }
        }

        if(alreadyPrinted)
            continue;


        for(int j = l + 1; j < 8; j++){
            if(n[l] == n[j]){
                cout << "The repeated number is " << n[l] << endl;
                break;
            }
        }
    }
}