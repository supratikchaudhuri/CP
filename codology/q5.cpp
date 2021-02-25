// C++ implementation to minimize the
// number of the box by putting small
// box inside the bigger one

#include <bits/stdc++.h>
using namespace std;

// Function to minimize the count
void minBox(int arr[], int n)
{
    // Initial number of box
    int box = n;

    // Sort array of box size
    // in increasing order
    sort(arr, arr + n);

    int curr_box = 0, next_box = 1;
    while (curr_box < n && next_box < n) {

        // check is current box size
        // is smaller than next box size
        if (arr[curr_box] < arr[next_box]) {

            box--;
            curr_box++;
            next_box++;
        }

        // Check if both box
        // have same size
        else if (arr[curr_box] == arr[next_box])
            next_box++;
    }

    // Print the result
    cout << box << endl;
}

// Driver code
int main()
{
    int n; cin>>n;
  int arr[n];
  for(int i=0;i<n;++i)  cin>>arr[i];
    minBox(arr, n);
    return 0;
}
