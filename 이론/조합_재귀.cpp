#include<iostream>
using namespace std;

int n = 5;
int k = 3;

// 5C3 인 경우 인델스 출력

int a[5] = {1,2,3,4,5};

void print(vector<int> b){
    for(int i : b){
        cout << i << " ";
    }
    cout<< "\n";
}

void combi(int start, vector<int> b){
    if(b.size() == k){
        print(b);
        return;
    }

    for(int i = start+1; i<n; i++){
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }
    return;
}

int main(void){
    vector<int> b;
    combi(-1,b);
    return 0;
}
