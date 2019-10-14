import sys

def binary_searchh(arr, start, end, k):
	
	middle = (end + start)//2
	if (start < end):
		
		if (arr[middle] == k):
			return middle
		elif (arr[middle] <= k):
			return binary_searchh(arr, middle+1, end, k)
		else:
			return binary_searchh(arr, start, middle, k)
	else:
		res = middle
		diff = k - arr[middle]
		if (middle-1 >= 0 and (k-arr[middle-1]) < diff):
			res = middle-1
			diff = k-arr[middle-1]
		if (middle + 1 <= len(arr)-1 and (k-arr[middle+1]) < diff):
			res = middle+1
			diff = k-arr[middle+1]
			
		return res

