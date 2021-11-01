// C++ program for the above approach

#include <iostream>
using namespace std;

// Function to count the minimum
// number of socks to be picked
int findMin(int arr[], int N, int k)
{
	// Stores the total count
	// of pairs of socks
	int pairs = 0;

	// Find the total count of pairs
	for (int i = 0; i < N; i++) {
		pairs += arr[i] / 2;
	}

	// If K is greater than pairs
	if (k > pairs)
		return -1;

	// Otherwise
	else
		return 2 * k + N - 1;
}

int main()
{
	int arr[3] = { 4, 5, 6 };
	int K = 3;
	cout << findMin(arr, 3, K);
	return 0;
}

// This code is contributed by RohitOberoi.
