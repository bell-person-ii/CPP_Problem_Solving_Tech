#include<iostream>
using namespace std;

int main(void){

    vector<int> arr = {1,2,3};

    sort(arr.begin(),arr.end());

    do{
        for(int i : arr){
            cout << i << " ";
        }
        cout << "\n";
    }while(next_permutation(arr.begin(),arr.end()));
    return 0;
}
