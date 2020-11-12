#include <iostream>

using namespace std;

//Sort Function for Heap
void max_heap(int* a, int m, int n) {
    int j, t;
    t = a[m];
    j = 2 * m;
    while (j <= n) {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (t > a[j])
            break;
        else if (t <= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = t;
    return;
}

//Build Function
void build_maxheap(int* a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        max_heap(a, k, n);
    }
}

int main() {
    //initialise data
    int n, i;
    cout << "enter no of elements of array\n";

    //Assign data to variable from user input - for testing
    cin >> n;

    //Define temporary array for testing - will use a vector later
    int a[30];

    //Loop through and assign required input numbers
    for (i = 1; i <= n; i++) {
        cout << "enter elements" << " " << (i) << endl;
        cin >> a[i];
    }

    //Create the heap and display
    build_maxheap(a, n);
    cout << "Max Heap\n";
    for (i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
}