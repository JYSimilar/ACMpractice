#include <iostream>
using namespace std;

void merge_sort(int q[], int tmp[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, tmp, l, mid);
    merge_sort(q, tmp, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] < q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; ++i, ++j) q[i] = tmp[j];
}

int main() {
    int n;
    scanf("%d", &n);
    int q[n], tmp[n];
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    merge_sort(q, tmp, 0, n - 1);

    for (int i = 0; i < n; ++i) printf("%d ", q[i]);
    return 0;
}