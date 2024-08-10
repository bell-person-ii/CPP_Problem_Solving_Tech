#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visited[10'001];

int dfs(const vector<vector<int>>& comp, int n) {
    int ret = 1;
    visited[n] = true;    // 사이클 방지해야 합니다.
    for (auto i : comp[n])
        if (!visited[i]) ret += dfs(comp, i);
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> computers(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        computers[e].push_back(s);
    }
    int max_computers = 0;
    vector<int> answers(N + 1);
    for (int i = 1; i <= N; i++) {
        answers[i] = dfs(computers, i);
        max_computers = max(max_computers, answers[i]);
        memset(visited, false, sizeof(visited));
    }
    for (int i = 1; i <= N; i++)
        if (answers[i] == max_computers) cout << i << ' ';
    return 0;
}
