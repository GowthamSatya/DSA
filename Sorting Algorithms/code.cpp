#include <bits/stdc++.h>
using namespace std;

class Sort
{
    vector<int> arr;

    void getInput()
    {
        int n;
        cout << "Enter the size of arr : ";
        cin >> n;
        arr.resize(n);
        cout << "Enter the elements of arr :\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void merge(int lo, int mid, int hi)
    {
        int leftSubArr = mid - lo + 1;
        int rightSubArr = hi - mid;

        int *leftArr = new int[leftSubArr];
        int *rightArr = new int[rightSubArr];

        for (int i = 0; i < leftSubArr; i++)
        {
            leftArr[i] = arr[lo + i];
        }

        for (int i = 0; i < rightSubArr; i++)
        {
            rightArr[i] = arr[mid + 1 + i];
        }

        int leftIdx = 0, rightIdx = 0;
        int mergedIdx = lo;

        while (leftIdx < leftSubArr && rightIdx < rightSubArr)
        {
            if (leftArr[leftIdx] <= rightArr[rightIdx])
            {
                arr[mergedIdx] = leftArr[leftIdx];
                leftIdx++;
            }
            else
            {
                arr[mergedIdx] = rightArr[rightIdx];
                rightIdx++;
            }
            mergedIdx++;
        }

        while (leftIdx < leftSubArr)
        {
            arr[mergedIdx] = leftArr[leftIdx];
            leftIdx++;
            mergedIdx++;
        }

        while (rightIdx < rightSubArr)
        {
            arr[mergedIdx] = rightArr[rightIdx];
            rightIdx++;
            mergedIdx++;
        }

        delete[] leftArr;
        delete[] rightArr;
    }

    void mergeSortUtil(int lo, int hi)
    {
        if (lo == hi)
            return;
        int mid = lo + ((hi - lo) / 2);
        mergeSortUtil(lo, mid);
        mergeSortUtil(mid + 1, hi);
        merge(lo, mid, hi);
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void printArr()
    {
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
    }

    void heapify(int n, int i)
    {
        int largest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // if leftchild is larger than root
        if (leftChild < n && arr[leftChild] > arr[largest])
            largest = leftChild;

        // if right child is larger than largest so far
        if (rightChild < n && arr[rightChild] > arr[largest])
            largest = rightChild;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(n, largest);
        }
    }

    int partition(int lo, int hi)
    {
        int pivot = arr[hi];
        int i = (lo - 1);
        for (int j = lo; j <= hi - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[hi]);
        return (i + 1);
    }

    void quickSortUtil(int lo, int hi)
    {
        if (lo < hi)
        {
            int p = partition(lo, hi);
            quickSortUtil(lo, p - 1);
            quickSortUtil(p + 1, hi);
        }
    }

    int getMax()
    {
        int max = INT_MIN;
        for (auto i : arr)
        {
            if (max < i)
                max = i;
        }
        return max;
    }

    void countSort(int n, int pos)
    {
        int a[10] = {0};
        int b[n] = {0};
        for (int i = 0; i < n; i++)
        {
            a[(arr[i] / pos) % 10]++;
        }
        for (int i = 1; i < 10; i++)
        {
            a[i] += a[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            b[a[(arr[i] / pos) % 10] - 1] = arr[i];
            a[(arr[i] / pos) % 10]--;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = b[i];
        }
    }

public:
    Sort()
    {
        getInput();
    }

    void selectionSort()
    {
        int i = 0, min, minIdx = -1;
        int n = arr.size();
        int temp;
        for (i = 0; i < n; i++)
        {
            min = INT_MAX;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < min)
                {
                    min = arr[j];
                    minIdx = j;
                }
            }
            if (arr[i] >= arr[minIdx])
                swap(&arr[i], &arr[minIdx]);
        }

        cout << "Selection Sort : ";
        printArr();
        // Time Complexity : O(n^2)
        // Space Complexity : O(1)
    }

    void bubbleSort()
    {
        int n = arr.size();
        bool flag;
        for (int i = 0; i < n - 1; i++)
        {
            flag = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    flag = true;
                }
            }

            if (flag == false)
                break;
        }

        cout << "Bubble Sort : ";
        printArr();
        // Time Complexity : O(n^2)
        // Space Complexity : O(1)
    }

    void insertionSort()
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                int k = i - 1;
                int j = i;
                while (k >= 0 && arr[j] < arr[k])
                {
                    swap(&arr[j], &arr[k]);
                    k--;
                    j--;
                }
            }
        }

        cout << "Insertion Sort : ";
        printArr();
        // Time Complexity : O(n^2)
        // Space Complexity : O(1)
    }

    void mergeSort()
    {
        int n = arr.size();
        mergeSortUtil(0, n - 1);

        cout << "Merge Sort : ";
        printArr();
        // Time Complexity : O(nlog(n))
        // Space Complexity : O(n)
    }

    void heapSort()
    {
        int n = arr.size();
        // for building heap from the array
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);

        // swapping top elements and sorting the array
        for (int i = n - 1; i > 0; i--)
        {
            swap(&arr[0], &arr[i]);
            heapify(i, 0);
        }

        cout << "Heap Sort : ";
        printArr();
        // Time Complexity : O(nlog(n))
        // Space Complexity : O(1)
    }

    void quickSort()
    {
        int n = arr.size();
        quickSortUtil(0, n - 1);

        cout << "Quick Sort : ";
        printArr();
        // Time Complexity : O(nlog(n))
        // Space Complexity : O(1)
    }

    void radixSort()
    {
        int n = arr.size();
        int max = getMax();
        for (int i = 1; (max / i) > 0; i *= 10)
            countSort(n, i);

        cout << "Radix Sort : ";
        printArr();
        // Time Complexity : O(d*(n+k))
        // d = no. of digits in max element
        // n = size of array , k = range of count arr
        // Space Complexity : O(n+k)
    }

    void shellSort()
    {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                int t = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > t; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = t;
            }
        }

        cout << "Shell Sort : ";
        printArr();
    }
};

int main()
{
    Sort *ob = new Sort();
    // ob->selectionSort();
    // ob->bubbleSort();
    // ob->insertionSort();
    // ob->mergeSort();
    // ob->heapSort();
    // ob->quickSort();
    // ob->radixSort();
    ob->shellSort();
    return 0;
}