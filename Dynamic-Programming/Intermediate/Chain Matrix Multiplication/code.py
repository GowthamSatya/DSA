from sys import maxsize
dp = [[-1 for i in range(100)] for j in range(100)]

def printParenthesis(arr,st, end ):
	if st == end:
		print(chr(65 + st), end = "")
		return;
	else:
		print("(", end = "")
		printParenthesis(arr, arr[st][end] - 1, end)
		printParenthesis(arr, st, arr[st][end])
		print (")", end = "" )

def matrixChainMul(list, n):
	mat = [[0 for i in range(n)]for i in range (n)]

	for i in range (2, n + 1):
		for j in range (n - i + 1):
			l = j + i - 1

			mat[j][l] =maxsize
			for k in range (j, l):
				q = (mat[j][k] + mat[k + 1][l] +(list[j] * list[k + 1] * list[l + 1]))
				if (q < mat[j][l]):
					mat[j][l] = q
					mat[l][j] = k + 1
	return mat;           

def getInput():
	x = int(input("Enter Number of Matrices to Multiply : "))
	arr = []
	print("Enter Matrix Indices : ")
	p = list(map(int, input().split(",")))
	return p

indices = getInput()
m = matrixChainMul(indices, len(indices)-1)
print("Ideal Matrix Order to Multiply : ")
printParenthesis(m, len(indices)-2, 0)
print("\nMinimum Multiplications required = ", m[0][len(indices)-2])