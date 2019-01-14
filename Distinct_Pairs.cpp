#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct output
{
    ll x; ll y;
}arr[400002];
struct seq
{
    ll val; ll idx;
}a[200001],b[200001];
bool compare(seq e,seq f){ return e.val < f.val; }
set<ll> s;
int main()
{
    ll n,m,i,j,k,temp,maxa,mina,minb,maxb,count;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> a[i].val; a[i].idx = i;
    }
    for(j = 0; j < m; j++)
    {
        cin >> b[j].val; b[j].idx = j;
    }
    sort(a,a+n,compare); sort(b,b+m,compare);
    mina = a[0].val; maxa = a[n - 1].val;
    minb = b[0].val; maxb = b[m - 1].val;
    count = m + n - 1;
    k = 0;
    for(j = 0; j < m; j++)
    {
        temp = mina + b[j].val;
        count--;
        arr[k].x = a[0].idx; arr[k].y = b[j].idx; k++;
        s.insert(temp);
    }
    for(j = 0; j < m; j++)
    {
        temp = maxa + b[j].val;
        if(count > 0 and s.find(temp) == s.end())
        {
            count--;
            arr[k].x = a[n - 1].idx; arr[k].y = b[j].idx; k++;
            s.insert(temp);
        }
    }
    if(count > 0)
    {
        for(i = 0; i < n; i++)
        {
            temp = a[i].val + minb;
            if(count > 0 and s.find(temp) == s.end())
            {
                count--;
                arr[k].x = a[i].idx; arr[k].y = b[0].idx; k++;
                s.insert(temp);
            }
        }
    }
    if(count > 0)
    {
        for(i = 0; i < n; i++)
        {
            temp = a[i].val + maxb;
            if(count > 0 and s.find(temp) == s.end())
            {
                count--;
                arr[k].x = a[i].idx; arr[k].y = b[m - 1].idx; k++; 
                s.insert(temp);
            }
        }
    }
    for(i = 0; i < k; i++)
        cout << arr[i].x << ' ' << arr[i].y << endl;
}
