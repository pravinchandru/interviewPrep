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

def find_closest(arr, k):
	return binary_searchh(arr, 0, len(arr), k)

def sum_pair(arr, k):
	curr_sum, start, end = 0, 0, len(arr)-1

	while(start < end):
		if(arr[start] + arr[end] < k):
			start+=1	
		elif(arr[start] + arr[end] > k):
			end-=1
		elif(arr[start]+ arr[end] == k):
			return(start, end)			
	return(-1,-1)		

def find_closest_elements(array_1, array_2, array_3):
	min_so_far = sys.maxsize
	res_i, i = 0, 0
	res_j, j = 0, 0
	res_k, k = 0, 0

	while(i < len(array_1) and j < len(array_2) and k < len(array_3)):
		min_curr = min(array_1[i], min(array_2[j], array_3[k]))
		max_curr = max(array_1[i], max(array_2[j], array_3[k]))

		diff = max_curr-min_curr

		if(diff < min_so_far):
			res_i = i
			res_j = j
			res_k = k
			min_so_far = diff

		if min_curr == array_1[i]:
			i+=1
		elif min_curr == array_2[j]:
			j+=1
		else:
			k+=1

	
	return (res_i, res_j, res_k)	


def remove_duplicates(arr):
	if not arr: 
		return None

	last = 1	
	for i in range(1, len(arr)):
		if(arr[last-1] != arr[i]):
			arr[last] = arr[i]
			last+=1

	return arr[0:last]		

def buy_stock(stock_arr):
	if not stock_arr:
		return None

	start, end, max_so_far = 0, 0, 0
	max_start = 0
	max_end = 0
	curr = 0

	for i in range(1, len(stock_arr)-1):
		if stock_arr[i] < stock_arr[i-1]:
			curr = 0
			start = i
			end = i
		else:
			curr += stock_arr[i]-stock_arr[i-1]
			end = i

			if (max_so_far <= curr):
				max_so_far = curr
				max_start = start
				max_end = i
	return (max_so_far, stock_arr[max_start], stock_arr[max_end])
				


# arr_1 = [5, 10, 15]
# arr_2 = [3, 6, 9, 12, 15]
# arr_3 = [8, 16, 24]

# i1,i2,i3 = find_closest_elements(arr_1, arr_2, arr_3)

# print(arr_1[i1])
# print(arr_2[i2])
# print(arr_3[i3])

# arr = [10, 20, 30 , 40]
# r = find_closest(arr, 32)
# print(arr[r])

# arr_2 = [3, 6, 9, 12, 16]
# print(sum_pair(arr_2, 27-))

# arr = [1,3,7,7,7,8,9,9,10]
# print(remove_duplicates(arr))

stock_arr = [310,315,275,295,260,270,290,230,255,250]

print(buy_stock(stock_arr))


