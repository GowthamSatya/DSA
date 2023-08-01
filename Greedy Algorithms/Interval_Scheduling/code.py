# Input will be of the form start time, end time
def getInput(size):
    lst= []
    print("Enter Each Interval in form startTime, endTime:")
    for m in range(0,size):
        k = list(map(int,input().split(',')))
        lst.append((k[0], k[1]))
    return lst

def getScheduledIntervals(st, end):
    possibleJobs =[]
    finish = 0
    for i in range(0,len(st)):
        if finish <= st[i]:
            possibleJobs.append((i+1,st[i],end[i]))
            finish = end[i]

    return possibleJobs

# we use merge sort to sort end times present in 2d array
def sortEndTimes(list, key= lambda x:x):
    if len(list) == 1:
        return list
    m = len(list)//2
    leftArr = list[:m]
    rightArr = list[m:]

    sortEndTimes(leftArr)
    sortEndTimes(rightArr)

    a=b=c=0
    while a < len(leftArr) and b<len(rightArr):
        if key(leftArr[a]) < key(rightArr[b]):
            list[c] = leftArr[a]
            a+=1
        else:
            list[c] = rightArr[b]
            b+=1
        c+=1

    while a<len(leftArr):
        list[c] = leftArr[a]
        a+=1
        c+=1
    while b<len(rightArr):
        list[c] = rightArr[b]
        b+=1
        c+=1
    return list

k = int(input("Enter Number of Intervals : "))
allIntervals = getInput(k)

list = sortEndTimes(allIntervals,key=lambda x:x[1])

st = [i[0] for i in list]
end = [i[1] for i in list]

possibleJobs = getScheduledIntervals(st,end)

# output will be of the form [(job_number, start_time, end_time)]
print(possibleJobs)


