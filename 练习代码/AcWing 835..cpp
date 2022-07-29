#include <iostream>
using namespace std;

const int N = 100010;

char str[N];

int son[N][26];
int cnt[N];
int idx;

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    ++cnt[p];
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    while (n--) {
        char a;
        cin>>a;
        cin>>str;
        if (a == 'I') {
            insert(str);
        }
        if (a == 'Q') {
            cout<<query(str)<<'\n';
        }
    }
    return 0;
}