#include <bits/stdc++.h>
using namespace std;

int sz;
map<int, int>mp;
list<int>dq;

void init(int cap) {
    sz = cap;
    mp.clear();
    dq.clear();
}

int get(int key) {
    if (mp.find(key) == mp.end()) {
        return -1;
    }
    dq.remove(key);
    dq.push_back(key);

    return mp[key];
}

void set(int key, int val) {
    if (sz == 0) {
        return ;
    }
    if (mp.find(key) != mp.end()) {
        dq.remove(key);
        dq.push_back(key);
        mp[key] = val;
        return;
    }
    if (dq.size() < sz) {
        dq.push_back(key);
        mp[key] = val;
        return;
    }
    map<int, int>::iterator it = mp.find(dq.front());
    mp.erase(it);
    dq.pop_front();
    dq.push_back(key);
    mp[key] = val;
}

int main()
{
    return 0;
}
