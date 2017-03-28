#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;
typedef pair<string, int> psi;

unordered_map<string, string> p;//并查集中每个item的祖先，开始时指向自己
unordered_map<string, bool> visited;//是否访问过的标记
unordered_map<string, vector<string>> children;//每个点的孩子
unordered_map<string, set<psi>> query;//所有查询
vector<string> res;//存放结果

//并查集的root函数
string getRoot(string& name) {
    if (name != p[name]) {
        p[name] = getRoot(p[name]);
    }
    return p[name];
}

void dfs(string root) {
    visited[root] = true;//已访问
    p[root] = root;
    if (query.find(root) != query.end()) {
        for (auto it = begin(query[root]); it != end(query[root]); ++it) {
            psi bar = *it;
            if (visited[bar.first]) res[bar.second] = getRoot(bar.first);
        }
    }

    for (string child : children[root]) {
        dfs(child);
        p[child] = root;//将子树所在集合的祖先指向自己
    }
}

int main() {
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; ++i) {
        string fa, ch;
        cin >> fa >> ch;
        if (i == 0) tmp = fa;
        children[fa].push_back(ch);
        visited[ch] = false;
    }

    int m;
    cin >> m;
    res.resize(m);
    for (int j = 0; j < m; ++j) {
        string name1, name2;
        cin >> name1 >> name2;
        if (name1 == name2) {
            res[j] = name1;
        } else {
            query[name1].insert(psi(name2, j));
            query[name2].insert(psi(name1, j));
        }
    }
    dfs(tmp);

    for (int j = 0; j < m; ++j) cout << res[j] << endl;

    return 0;
}