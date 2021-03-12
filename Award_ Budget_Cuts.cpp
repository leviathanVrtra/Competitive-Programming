/*
Given an array grantsArray of the original grants and the reduced budget newBudget, 
write a function findGrantsCap that finds in the most efficient manner a cap such 
that the least number of recipients is impacted and that the new budget constraint 
is met (i.e. sum of the N reallocated grants equals to newBudget)
*/

#include <bits/stdc++.h>

using namespace std;

double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  sort(grantsArray.begin(), grantsArray.end());
  int n = grantsArray.size();
  int tot = 0;
  
  for (int i = 0; i < n; i++) {
    int curr = grantsArray[i];
    int leftItem = n - i;
    
    if ((curr * leftItem) > (newBudget - tot)) {
        return (1.0 *(newBudget - tot) / (1.0 * leftItem)); 
    }
    
    tot += curr;
  }
  double ans = grantsArray[n-1];
  return (ans);
}

int main() {
  return 0;
}

/*
Ex : 
    grantsArray = [2, 100, 50, 120, 1000], newBudget = 190
    Ans = 47

*/