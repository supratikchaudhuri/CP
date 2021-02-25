#include<bits/stdc++.h>
using namespace std;

int main() {
 // your code goes here
 int t;
 cin>>t;
 while(t--)
 {
  int n,i,j;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
  cin>>a[i];
  if(n==1)
  cout<<a[0]<<endl;
  else if(n==2)
  cout<<max(a[0],a[1])<<endl;
  else if(n==3)
  {
   sort(a,a+n);
   cout<<max(a[0]+a[1],a[2])<<endl;
  }
  else   //n==4
  {
   sort(a,a+n);
   i=max(a[0]+a[3],a[2]+a[1]);
   j=max(a[0]+a[1]+a[2],a[3]);
   cout<<min(i,j)<<endl;
  }
  
 }
 return 0;
}


// Chef Ada is preparing N dishes (numbered 1 through N). For each valid i, it takes Ci minutes to prepare the i-th dish. The dishes can be prepared in any order.

// Ada has a kitchen with two identical burners. For each valid i, to prepare the i-th dish, she puts it on one of the burners and after Ci minutes, removes it from this burner; the dish may not be removed from the burner before those Ci minutes pass, because otherwise it cools down and gets spoiled. Any two dishes may be prepared simultaneously, however, no two dishes may be on the same burner at the same time. Ada may remove a dish from a burner and put another dish on the same burner at the same time.

// What is the minimum time needed to prepare all dishes, i.e. reach the state where all dishes are prepared?

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line contains N space-separated integers C1,C2,…,CN.
// Output
// For each test case, print a single line containing one integer ― the minimum number of minutes needed to prepare all dishes.

// Constraints
// 1≤T≤1,000
// 1≤N≤4
// 1≤Ci≤5 for each valid i
// Subtasks
// Subtask #1 (1 points): C1=C2=…=CN
// Subtask #2 (99 points): original constraints