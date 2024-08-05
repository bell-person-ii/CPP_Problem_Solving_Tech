#include<iostream>
#include<vector>

using namespace std;

int arr[1000004]= {0};
int temp[1000004]= {0};
int rep;


void mergeSort(int start, int end){

    if((end-start) < 1){ //범위가 한칸인 경우는 바로 리턴
        return ;
    }

    int mid = (start + end) / 2;

    mergeSort(start,mid); //  앞쪽 재귀 호출
    mergeSort(mid+1,end); //  뒤쪽 재귀 호출

    for(int i = start; i <= end; i++){ // temp는 해당 구간의 arr 배열이 변경되기 시작하기 전의 모습을 임시 저장함
        temp[i] = arr[i];
    }

    int k = start;
    int index1 = start;
    int index2 = mid+1;

    while(index1 <= mid && index2 <=end){ // 앞쪽 또는 뒤쪽 그룹의 숫자가 모두 정렬될때 까지 돌아감

        if(temp[index1] < temp[index2]){ //  앞쪽 그룹의 숫자가 작은 경우
            arr[k] = temp[index1];
            k++;
            index1++;
        }
        else{ //  뒷쪽 그룹의 숫자가 작은 경우
            arr[k] = temp[index2];
            k++;
            index2++;
        }
    }

    while(index1 <= mid){ // 앞쪽 그룹에 숫자가 남은 경우
        arr[k] = temp[index1];
        k++;
        index1++;
    }

    while(index2 <=end){ // 뒷쪽 그룹에 숫자가 남은 경우
        arr[k] = temp[index2];
        k++;
        index2++;
    }
}

int main(void){

    cin >> rep;
    for(int i=0 ; i <rep; i++){
        cin >> arr[i];
    }

    mergeSort(0,rep-1);

    for(int i=0 ; i<rep; i++){
        cout << arr[i] << '\n';
    }


    return 0;
}
