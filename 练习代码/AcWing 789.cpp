#include <iostream>
using namespace std;

int st,ed;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int q[n];
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    while (m--) {
        int target;
        scanf("%d", &target);
        int l = 0, r = n - 1;
        int mid;
        while (l < r) {
            mid = l + r >> 1;
            if (q[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (q[l] != target) printf("-1 -1\n");
        else{
            printf("%d ", l);
            l = 0, r = n - 1;
            while (l < r) {
                mid = l + r + 1 >> 1;
                if (q[mid] <= target) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}