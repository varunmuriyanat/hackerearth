#include <iostream>

using namespace std;

void print_array(int [], int);
void bubble_sort(int [], int);
void selection_sort(int [], int);
void insertion_sort(int [], int);
void merge_sort(int [], int, int);
void merge(int [], int, int, int);
void quick_sort(int [], int, int);
int partition(int [], int, int);

int main()
{
    int n = 4;
    int arr[n] = {7,4,5,2};
    
    //print_array(arr, n);
    
    //bubble_sort(arr, n);
    //selection_sort(arr, n);
    //insertion_sort(arr, n);
    
    //cout << "merge sort: " << endl;
    //merge_sort(arr, 0, 3); 

    cout << "quick sort" << endl;
    quick_sort(arr, 0, 3);
    
    print_array(arr, n);

    cout << "sorted";
    return 0;
}


void bubble_sort(int a[], int n) {
    int temp;
    
    for(int k = 0; k < n-1; k++) {
        for(int i = 0; i < n-k-1; i++) {
            if(a[i] > a[i+1]) {
                //swap values
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
    
    cout << "bubble sort: ";
    print_array(a, n);
}

void selection_sort(int a[], int n) {
    int minimum;
    int temp;
    
    for(int i = 0; i < n-1; i++) {
        minimum = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minimum]) {
                minimum = j;
            }
        }

        //swap values
        temp = a[minimum];
        a[minimum] = a[i];
        a[i] = temp;
    }
    
    cout << "selection sort: ";
    print_array(a, n);
}

void insertion_sort(int a[], int n) {
    for(int i = 0; i < n; i++)
    {
       int temp = a[i];
       int j = i;

       while(temp < a[j-1] && j > 0)
       {
           a[j] = a[j-1];
           j = j - 1;
       }
       a[j] = temp;
    }

    cout << "insertion sort: ";
    print_array(a, n);
}

void merge(int a[], int start, int mid, int end) {
    int p = start, q = mid + 1;
    int arr[end-start+1], k = 0;

    for(int i = start; i <= end; i++){
        if(p > mid)
            arr[k++] = a[q++];
        else if(q > end)
            arr[k++] = a[p++];
        else if(a[p] < a[q])
            arr[k++] = a[p++];
        else
            arr[k++] = a[q++];
    }

    for(int p = 0; p < k; p++) {
        a[start++] = arr[p];
    }

    cout << "Merge Completed" << endl;
}

void merge_sort(int a[], int start, int end) {
    cout << "Inside merge_sort" << endl;
    int mid;
    if(start < end) {
        mid = (start + end) / 2;
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);

        merge(a, start, mid, end);
    }
}

int partition(int a[], int start, int end) {
    int i = start + 1;
    int piv = a[start];

    for(int j = start + 1; j <= end; j++) {
        if(a[j] < piv) {
            swap(a[i], a[j]);
            i += 1;
        }
    }

    swap(a[start], a[i-1]);
    return i-1;
}

int rand_partition(int a[], int start, int end) {
    int random = start + rand() % (end-start+1);
    swap(a[random], a[start]);
    return partition(a, start, end);
}

void quick_sort(int a[], int start, int end) {
    if(start < end) {
        int piv_pos = partition(a, start, end);
        quick_sort(a, start, piv_pos-1);
        quick_sort(a, piv_pos+1, end);
    }
}

void print_array(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    cout << endl;
}

