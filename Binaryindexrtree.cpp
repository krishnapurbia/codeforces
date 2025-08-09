inline int lastbit(int x) {
  return x & (-x);
}
template <ll... ArgsT> struct BIT {
  ll val = 0;
  void update(ll val) {
    this->val += val;
  }
  ll query() {
    return val;
  }
};
template <ll N, ll... Ns>
struct BIT<N, Ns...> {
  BIT<Ns...> bit[N + 1];
  template<typename... Args>
  void update(ll pos, Args... args) {
    for (; pos <= N; bit[pos].update(args...), pos += lastbit(pos));
  }
  template<typename... Args>
  ll query(ll l, ll r, Args... args) {
    ll ans = 0;
    for (; r >= 1; ans += bit[r].query(args...), r -= lastbit(r));
    for (--l; l >= 1; ans -= bit[l].query(args...), l -= lastbit(l));
    return ans;
  }
};
