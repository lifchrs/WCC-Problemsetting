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
ll distCovid[int(2e5+5)];
ll dist[int(2e5+5)];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /* ifstream cin("input_014"); */
  ll n,m,x;
  cin >> n >> m >> x;
  vpl adjList[int(1e5)+5];
  for(ll& a : dist) a = (ll)(1e18);
  for(ll& a : distCovid) a = (ll)(1e18);
  dist[1] = 0;
  distCovid[0] = 0;
  F0R(i,m){
    ll a,b,c;
    cin >> a >> b >> c;
    adjList[a].pb(mp(b,c));
    adjList[b].pb(mp(a,c));
  }

  vl hasCovid;
  F0R(i,x){
    ll a;
    cin >> a;
    hasCovid.pb(a);
    adjList[0].pb(mp(a,0));
  }


  priority_queue<pl> pq; // dist, node

  /* cout << "1" nn; */


  pq.push(mp(0,0));
  while(!pq.empty()){
    pl curr = pq.top(); pq.pop();
    if(distCovid[curr.second] != -curr.first) continue;
    for(pl next : adjList[curr.second]){
      if(distCovid[curr.second] + next.second < distCovid[next.first]){
        distCovid[next.first] = distCovid[curr.second] + next.second;
        pq.push(mp(-distCovid[next.first],next.first));
      }
    }
  }
/* cout << 2; */

  pq.push(mp(0,1));
  while(!pq.empty()){
    pl curr = pq.top(); pq.pop();
    if(dist[curr.second] != -curr.first) continue;
    for(pl next : adjList[curr.second]){
      if(dist[curr.second] + next.second < dist[next.first]){
        dist[next.first] = dist[curr.second] + next.second;
        pq.push(mp(-dist[next.first],next.first));
      }
    }
  }

  /* cout << 3; */

  bool can = 0;

  /* F0R(i,n+1){ */
  /*   if(adjList[i].size() == 1){ */
  /*     cout << i <<  "a" << endl; */
  /*     cout << dist[i] << "  " << distCovid[i] nn; */
  /*   } */
  /*   if(dist[i] < distCovid[i]){ */
  /*     cout << i <<  "b" << endl; */
  /*   } */
  /*   cout << endl; */
  /* } */

  /* cout << adjList[4].size() nn << dist[4] nn << distCovid[4] nn; */
  /* cout nn; */

  F0R(i,n+1){
    /* cout << i nn; */
    if(adjList[i].size() == 1 && dist[i] < distCovid[i]){
      cout << "YES";
      can = 1;
      break;
    }
  }

  if(!can){
    cout << "NO";
  }

}


/*
6 7 2
1 2 5
1 3 2
2 3 4
3 5 2
5 4 1
2 5 4
6 1 3
6
2

6 7 1
1 2 5
1 3 2
2 3 4
3 5 2
5 4 1
2 5 4
6 1 3
6
*/
