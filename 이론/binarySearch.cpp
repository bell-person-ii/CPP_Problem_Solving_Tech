#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numCount;
int targetCount;

vector<int> numList;
vector<int> targetList;

int binarySearch(int target){
    int st = 0;
    int en = numList.size() -1;

    while(st <= en){
        int mid = (st+en) / 2;

        if(numList[mid] == target){
            return 1;
        }
        else if(numList[mid] > target){
            en = mid -1;
        }
        else {
            st = mid +1;
        }
    }

    return 0;
}

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
        cout << binarySearch(t) << '\n';
    }

    return 0;
}
