
# QUESTION
# Say there are n different ships moving in the sea. Write and implement an algorithm so
# that you can efficiently avoid collisions of the ship


# CODE : Divide and Conquer Algorithm
import math

def getDistance(p1, p2):
    y_sq = (p2[1]-p1[1])**2
    x_sq = (p2[0]-p1[0])**2
    return math.sqrt(y_sq + x_sq)

def getInput():
    points = []
    n = int(input("Enter the number of points : "))
    i=n
    while i>0:
        k,l = map(int, input("Enter Point " +str(n-i+1) + " : ").split(","))
        points.append([k,l])
        i=i-1
    
    return points

def copyArray(arr):
    arr2 = []
    for i in arr:
        arr2.append(i)
    return arr2

# function to check distance between points in a strip if they are present
def closestStrip(strip, size, d):
    min_val = d 
    for i in range(size):
        j = i + 1
        while j < size and (strip[j][1] - 
                            strip[i][1]) < min_val:
            min_val = getDistance(strip[i], strip[j])
            j += 1
  
    return min_val 

# utility function to find the distance
def closestShipUtil(points,q,n):
    if(len(points) <= 3): #use bruteforce -- base case
        return bruteForce(points,n)

    m = n//2
    midPoint = points[m]
    leftSpace = points[:m]
    rightSpace = points[m:]

    distLeft = closestShipUtil(leftSpace,q, m)
    distRight = closestShipUtil(rightSpace,q, n-m)

    minDist =  min(distLeft, distRight)

    stripP = []
    stripQ = []
    
    total = leftSpace + rightSpace

    for i in range(n):
        if(abs(total[i][0]-midPoint[0]) < minDist):
            stripP.append(total[i])
        if(abs(q[i][0] - midPoint[0]) < minDist):
            stripQ.append(q[i])

    stripP.sort(key = lambda p : p[1])
    min_a = min(minDist, closestStrip(stripP,len(stripP), minDist))
    min_b = min(minDist, closestStrip(stripQ,len(stripQ), minDist))

    return min(min_a,min_b)

# Brute Force Method Used for Base Case
def bruteForce(P, n):
    min_val = float('inf') # initialize to infinity
    for i in range(n):
        for j in range(i + 1, n):
            if getDistance(P[i], P[j]) < min_val:
                min_val = getDistance(P[i], P[j])
  
    return min_val


def closestShips(points):
    points.sort(key=lambda x: x[0]) # sort according to x-coordinates
    q = copyArray(points)
    q.sort(key=lambda x: x[1]) # sort according to y-coordinates
    n = len(points)
    return closestShipUtil(points,q,n)

points = getInput()
print("\nClosest Distance Between Two Ships is " + str(closestShips(points)))
