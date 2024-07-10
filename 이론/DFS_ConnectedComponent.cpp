#include<iostream>

using namespace std;

int a[101][101];
int visited[101][101];

int n,m;

// 상하좌우
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

void dfs(int y, int x){
    visited[y][x] = 1; // 방문처리
    for(int i=0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx <0 || ny >= n || nx >= m ){ // 범위를 벗어난 경우
            continue;
        }
        if(visited[ny][nx] == 0 && a[ny][nx] == 1){// 방문한적이 없고, 방문이 가능한 노드인 경우 방문
            dfs(ny,nx);
        }
    }
    return; // 더이상 방문 가능한 인접 노드가 없는 경우
}

int main(void){

    cin >> n >> m ;
    int ret=0;

    for(int i = 0; i < n; i++){ //  좌표 입력
        for(int j = 0; j < m ; j++){
            int input;
            cin >> input;
            a[i][j] = input;
        }
    }

    for(int i=0 ; i < n; i++){
        for(int j=0 ; j < m; j++){
            if(visited[i][j] == 0 && a[i][j] == 1){ //  맵에서 방문 가능한 위치 탐색하기
                ret ++; 
                dfs(i,j); // 해당 위치에서 방문 가능한 노드를 dfs로 방문 처리함
            }
        }
    }

    cout << "정답: " << ret << endl;
    return 0;
}
