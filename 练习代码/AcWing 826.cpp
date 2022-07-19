#include <iostream>
using namespace std;

const int N = 100010;

int val[N], head, ne[N], idx;

void addToHead(int x) {
    val[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void deleteAfterK(int k) {
    if (!k) {
        head = ne[head];
        return;
    }
    ne[k - 1] = ne[ne[k - 1]];
}

void insertAfterK(int k, int x) {
    val[idx] = x;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx++;
}

int main() {
    head = -1;
    idx = 0;
    int n;
    scanf("%d", &n);
    while (n --) {
        int k, x;
        char c;
        cin>>c;
        if (c == 'H') {
            cin>>x;
            addToHead(x);
        }else if (c == 'D') {
            cin>>k;
            deleteAfterK(k);
        }else if (c == 'I') {
            cin>>k>>x;
            insertAfterK(k, x);
        }
    }
    for (int i = head; i != -1; i = ne[i] ) cout<<val[i]<<' ';
    cout<<endl;
    return 0;
}