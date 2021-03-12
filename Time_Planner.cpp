
/*
Implement a function meetingPlanner that given the availability, slotsA and slotsB, of two people 
and a meeting duration dur, returns the earliest time slot that works for both of them and 
is of duration dur. If there is no common time slot that satisfies the duration requirement, 
return an empty array.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{
  int n = slotsA.size();
  int m = slotsB.size();
  
  int i = 0, j = 0;
  vector<int>res;
  while (i < n && j < m) {
    int st, ed;
    st = max(slotsA[i][0], slotsB[j][0]);
    ed = min(slotsA[i][1], slotsB[j][1]);
    
    if ((ed - st) >= dur) {
      res.push_back(st);
      res.push_back(st + dur);
      return res;
    }
    
    if (slotsA[i][1] < slotsB[j][1]) {
      i++;  
    } else {
      j++;
    }
  }
  return res;
}

int main() {
  return 0;
}
  
/*
input:  slotsA = [[10, 50], [60, 120], [140, 210]]
        slotsB = [[0, 15], [60, 70]]
        dur = 8
output: [60, 68]

input:  slotsA = [[10, 50], [60, 120], [140, 210]]
        slotsB = [[0, 15], [60, 70]]
        dur = 12
output: []
  
*/