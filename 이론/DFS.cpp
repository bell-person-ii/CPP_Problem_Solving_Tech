#include<iostream>

using namespace std;

vector<int>adj[6];
int visited[6];

void dfs(int u){
    visited[u] = 1;
    cout << u << ": 방문 처리" << endl;
    for(int v : adj[u]){
        if(visited[v] == 0){
            dfs(v);
        }
    }
    cout << u << "에서 시작된 함수 종료" <<endl;
    return;
}

int main(void){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(2);

    dfs(1);
}
