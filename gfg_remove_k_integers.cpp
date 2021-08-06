#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum
// different in the subarrays of size K in the array
int findKMin(int arr[], int n, int k)
{
	std::deque<int> Qi(k);

	int i;
	for (i = 0; i < k; ++i) {
		// For every element,
		// the previous smaller elements
		// are useless so remove them from Qi
		while ((!Qi.empty()) &&
			arr[i] >= arr[Qi.back()])
			Qi.pop_back(); // Remove from rear

		// Add new element at rear of queue
		Qi.push_back(i);
	}
	
	int minDiff = INT_MAX;
	
	// Process rest of the elements,
	// i.e., from arr[k] to arr[n-1]
	for (; i < n; ++i) {
		// The element at the front
		// of the queue is the largest
		// element of previous window
		minDiff = min(minDiff, arr[Qi.front()]);

		// Remove the elements
		// which are out of this window
		while ((!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();

		// Remove all elements smaller
		// than the currently being
		// added element (remove useless elements)
		while ((!Qi.empty()) &&
				arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		// Add current element
		// at the rear of Qi
		Qi.push_back(i);
	}

	// compare the maximum
	// element of last window
	minDiff = min(minDiff, arr[Qi.front()]);
	return minDiff;
}

// Function to find the minimum
// of the maximum difference of the
// adjacent elements after removing
// K elements from the array
int minimumAdjacentDifference(int a[],
						int n, int k)
{

	// Create the difference array
	int diff[n - 1];
	for (int i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
	}

	// find minimum of all maximum
	// of subarray sizes n - k - 1
	int answer = findKMin(diff,
				n - 1, n - k - 1);
	return answer;
}

// Driver Code
int main()
{
	int n = 5;
	int k = 2;

	int a[n] = { 3, 7, 8, 10, 14 };

	cout << minimumAdjacentDifference(a, n, k);
	return 0;
}
