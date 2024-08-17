#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numCount;
int targetCount;

vector<int> numList;
vector<int> targetList;


int main(void){

    cin >> numCount;

    for(int i=0;i<numCount;i++){
        int num;
        cin >> num;
        numList.push_back(num);
    }

    cin >> targetCount;

    for(int i=0;i<targetCount;i++){
        int num;
        cin >> num;
        targetList.push_back(num);
    }

    sort(numList.begin(),numList.end());

    for(int t: targetList){
        cout << binary_search(numList.begin(),numList.end(),t) << '\n';
    }

    return 0;
}
