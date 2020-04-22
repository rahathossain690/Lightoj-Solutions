#include <stdio.h>
  int main() {
    long long int n, b, cases, a[10005], i;
    scanf("%lld", &cases);
    for (b = 1; b<=cases; b++){
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &n);
        for (i = 6; i<=n; i++){
            a[i] = (a[i-1] + a[i-2] + a[i-3] + a[i-4] + a[i-5] + a[i-6])%10000007;
        }
        printf("Case %lld: %lld\n", b, a[n]%10000007);
    }
    return 0;
}