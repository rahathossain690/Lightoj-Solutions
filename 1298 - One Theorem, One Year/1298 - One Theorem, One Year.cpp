#include <bits/stdc++.h>
using namespace std;
  typedef long long       ll;
typedef pair<int, int>  pii;
#define pb              push_back
#define endl            "\n"
#define mp              make_pair"%d", &tc); t < tc; t++){
    scanf("%lld %lld", &K, &P);
    ans = (go(P - 1, K - P) * pn[P - 1]) % mod;
    printf("Case %d: %lld\n", t + 1, ans);
  }
    return 0;
}