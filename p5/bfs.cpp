#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double; // or double, if TL is tight
using str = string; // yay python!

using pl = pair<ll,ll>;
using pd = pair<ld,ld>;

using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<str>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

#define sz(x) (ll)((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(ll i=0;i<a;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)

#define nn << "\n"

ll dist[int(1e5+5)];

ll covDist[int(1e5+5)];

bool visited[int(1e5)+5];

bool cVisited[int(1e5)+5];

int main(){
  /* ifstream cin("in/input.004"); */
  ll n,m,x;
  cin >> n >> m >> x;
  F0R(i,n) dist[i] = covDist[i] = (ll)(1e18);
  dist[1] = 0;
  vl adjList[int(1e5+5)];
  F0R(i,m){
    ll a,b,c;
    cin >> a >> b >> c;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  ll covid;
  cin >> covid;
  covDist[covid] = 0;
  queue<ll> q;
  q.push(1);
  while(!q.empty()){
    ll curr = q.front();
    q.pop();
    visited[curr] = 1;
    for(ll neighbour : adjList[curr]){
      if(!visited[neighbour]){
        visited[neighbour] = 1;
        q.push(neighbour);
        dist[neighbour] = dist[curr]+1;
      }
    }
  }
  q.push(covid);
  while(!q.empty()){
    ll curr = q.front();
    q.pop();
    cVisited[curr] = 1;
    for(ll neighbour : adjList[curr]){
      if(!cVisited[neighbour]){
        cVisited[neighbour] = 1;
        q.push(neighbour);
        covDist[neighbour] = covDist[curr]+1;
      }
    }
  }
  bool can = 0;
  for(int i = 1; i <= n; i++){
    if(adjList[i].size() == 1 && dist[i] < covDist[i]){
      cout << "YES" nn;
      /* cout << i nn; */
      /* cout << dist[i] << " " << covDist[i] nn; */
      can = 1;
      break;
    }
  }
  if(!can){
    cout << "NO" nn;
  }
}
