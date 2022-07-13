https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/


//// https://www.youtube.com/watch?v=5MeI5Kk8KTQ


// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int wrongIndex, int cur)
{
	char tmp = arr[cur];
	for (int i = cur; i > wrongIndex; i--)
		arr[i] = arr[i - 1];
	arr[wrongIndex] = tmp;
}

void rearrange(int arr[], int n)
{
	int wrongIndex = -1;

	for (int i = 0; i < n; i++)
	{
		if (wrongIndex != -1)
		{
			// find the item which must be moved into the
			// out-of-place entry if out-of-place entry is
			// positive and current entry is negative OR if
			// out-of-place entry is negative and current
			// entry is negative then right rotate
			//
			// [...-3, -4, -5, 6...] --> [...6, -3, -4,
			// -5...]
			//	 ^						 ^
			//	 |						 |
			//	 outofplace	 -->	 outofplace
			// FINDING the thing to place at wroongindex
			if (((arr[i] >= 0) && (arr[wrongIndex] < 0))
				|| ((arr[i] < 0)
					&& (arr[wrongIndex] >= 0)))
			{
				rightrotate(arr, n, wrongIndex, i);

				// the new out-of-place entry is now 2 steps
				// ahead
				if (i - wrongIndex >= 2)
					wrongIndex = wrongIndex + 2;
				else
					wrongIndex = -1;
			}
		}

		// if no entry has been flagged out-of-place
		else {
			// check if current entry is out-of-place
			if (((arr[i] >= 0) && (!(i%2==0)))
				|| ((arr[i] < 0) && (i%2==1))) {
				wrongIndex = i;  // wrong index mil gya
			}
		}
	}
}
