def get_max(arr):
    max=-1
    for i in arr:
        if max < i:
            max = i
    return max

def getInput(arr):
    k = int(input("Enter the size of array : "))
    for i in range(0,k):
        arr.append(int(input("Enter the value of " + str(i+1) + " : ")))
    return arr

# count sort function
def countSort(arr):
    n = len(arr)
    k = get_max(arr)
    count_arr = [0 for i in range(k+1)] #initialize count_arr with size max(arr)

    # fill count_arr with occurence of each value in array
    for i in arr:
        count_arr[i] = count_arr[i]+1
    
    # add cumilative values to count_arr
    for i in range(1,k+1):
        count_arr[i] = count_arr[i] + count_arr[i-1]
    
    sorted_arr = [0 for i in range(n)] # initialize sorted_arr
    # place elements in original arr in their correct positions in sorted_arr
    for i in reversed(range(n)):
        pos = count_arr[arr[i]]-1
        count_arr[arr[i]] = count_arr[arr[i]]-1
        sorted_arr[pos] = arr[i]
    
    return sorted_arr

arr = []
arr= getInput(arr)
sorted = countSort(arr)
print("Sorted Array : \n" ,sorted)