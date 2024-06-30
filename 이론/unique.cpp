#include<iostream>
using namespace std;

int main(void){

    vector<int> arr = {1,1,2,3,3,4,5,4,3,4,6};
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());

    for(int i : arr){
        cout << i << " ";
    }
    
}
