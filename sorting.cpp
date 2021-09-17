#include <iostream>

using namespace std;

void print_array(int[], int);
void bubble_sort(int[], int);
void selection_sort(int[], int);
void insertion_sort(int[], int);

int main()
{
    int n = 4;
    int arr[n] = {7,4,5,2};
    
    print_array(arr, n);
    
    //bubble_sort(arr, n);
    selection_sort(arr, n);
    
    print_array(arr, n);
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
}

void print_array(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    cout << endl;
}

