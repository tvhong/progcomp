#!/usr/bin/python
MOD = 10**16
MAX = 250250
def fastpow(a, b, mod):
   if b == 0:
      return 1
   tmp = fastpow(a, b/2, mod)
   ans = (tmp * tmp ) % mod;
   if (b % 2 == 1):
      ans = (ans * a) % mod;
   return ans

dp = [0] * 251;
tmp = [0] * 251;
for k in range(1, MAX+1):
   n = fastpow(k, k, 250)
   for i in range(0, 250):
       tmp[i] = dp[i]
   for i in range(0, 250):
       dp[i] = (dp[i] + tmp[(i-n+250)%250]) % MOD
   dp[n] = (dp[n] + 1) % MOD

print dp[0]
