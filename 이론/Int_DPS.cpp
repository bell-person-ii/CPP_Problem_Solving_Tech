#include<iostream>
#include<vector>
#include<algorithm>

using namespace  std;

int m,n,cnt,rep,lx,ly,rx,ry,ret,ny,nx;

vector<int> res;

int a[101][101];
int visited[101][101];

int dy[] = {1,-1,0,0};
int dx[] = {0,0,-1,1};

int dfs(int y, int x){
    visited[y][x]=1;
    int ret = 1;
    for(int i=0; i <4; i++){
        
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || nx <0 || ny >= m || nx >= n || visited[ny][nx]){
            continue;
        }
        if(a[ny][nx] == 1){
            continue;
        }
        ret += dfs(ny,nx);
    
    }
    return ret;
}


int main(void){

    cin >> m >> n >> rep; // m : 열, n : 행

    for(int i = 0 ; i < rep; i++){
        cin >> lx >> ly >> rx >> ry;

        for(int i = ly; i < ry; i++){
            for(int j = lx; j < rx; j++){
                a[i][j] = 1; // 직사각형 부분 방문처리
            }
        }
    }

    for(int i = 0; i < m ; i++ ){
        for(int j = 0 ; j <n; j++){
            if(a[i][j] != 1 && visited[i][j] == 0){
                res.push_back(dfs(i,j));
            }
        }
    }

    sort(res.begin(),res.end());

    cout << res.size() << endl;

    for(int i : res){
        cout << i << endl;
    }
    return 0;
}
