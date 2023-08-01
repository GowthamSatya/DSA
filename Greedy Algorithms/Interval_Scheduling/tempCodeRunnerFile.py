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
