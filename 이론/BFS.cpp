#include<iostream>
#include<queue>

using namespace std;

int size = 100;
int nodeList[] = {10,12,14,16,18,20,22,24}; // 출력용 배열

vector<int>adj[100];
int visited[100];

void bfs(int u){

    queue<int> q;
    visited[u] = 1;
    q.push(u); // 해당 노드 큐에 넣기
    while(q.size()){

        int u = q.front(); // 큐의 맨앞 요소 
        q.pop(); // 큐의 맨앞 요소 제거하기
            
        for(int v : adj[u]){
            if(visited[v]){
                continue;
            }
            visited[v] = visited[u] + 1; // 자신 노드 방문처리
            q.push(v); //  자식 노드 큐에 인큐
        }
    }

}

int main(void){

    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);

    for (int i : nodeList){
        cout << "노드: " << i <<" // 탐색 우선 순위: " << visited[i]<< endl; 
    }

    return 0;
}
