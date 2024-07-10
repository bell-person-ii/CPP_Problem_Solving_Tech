#include<iostream>
#include<queue>
using namespace std;

int n,m,sy,sx,ey,ex,ny,nx,y,x;

int a[101][101];
int visited[101][101];
pair<int,int> sPos;
pair<int,int> ePos;

int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};

int main(void){

    cin >> n >> m;
    cin >> sy >> sx; // 승환 좌표
    cin >> ey >> ex; // 끝 좌표

    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j]; // 맵 초기화
        }
    }

    queue<pair<int,int>> q;

    visited[sy][sx] = 1;
    q.push({sy,sx});
    while(q.size()){

        tie(y,x) = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny <0 || nx <0 || ny >= n || nx >= m || a[ny][nx] == 0){
                continue;
            }
            if(visited[ny][nx]){
                continue;
            }

            visited[ny][nx] = visited[y][x] + 1; //  최단 거리 반영
            q.push({ny,nx});
        }

    }
    cout << visited[ey][ex]<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	cout << visited[i][j] << ' '; 
        }
        cout << '\n';
    } 

}
