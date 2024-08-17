#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numCount;
int targetCount;

vector<int> numList;
vector<int> targetList;

int lower_idx(int target, int len) {
    int st = 0;
    int en = len;
    while(st < en) {
        int mid = (st + en) / 2;
        if(numList[mid] >= target) 
            en = mid;
        else 
            st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len) {
    int st = 0;
    int en = len;
    while(st < en) {
        int mid = (st + en) / 2;
        if(numList[mid] > target)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
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
        cout << upper_idx(t,numCount) - lower_idx(t,numCount) << " ";
    }

    return 0;
}
