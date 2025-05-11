#include <iostream>
using namespace std;

bool binarySearch(int X[], int n, int item) {
    int first = 0;
    int last = n - 1;
    bool found = false;
    int mid;

    while (!found && first <= last) {
        mid = (first + last) / 2;
        cout << X[mid] << " ";
        if (item < X[mid]) {
            last = mid - 1;
        }
        else if (item > X[mid]) {
            first = mid + 1;
        }
        else {
            found = true;
            break;
        }
    }

    return found;
}

bool recursiveBinarySearch(int X[], int first, int last, int item) {
    if (first > last) {
        return false;
    }
    else {
        int mid = (first + last) / 2;
        cout << X[mid] << " ";
        if (item < X[mid]) {
            return recursiveBinarySearch(X, first, mid - 1, item);
        }
        else if (item > X[mid]) {
            return recursiveBinarySearch(X, mid + 1, last, item);
        }
        else {
            return true;
        }
    }
}

int main() {
    int a[100];
    for (int i = 0; i <= 99; i++) {
        a[i] = i + 1;
    }

    for (int i = 1; i <= 100; i++) {
        cout << "Searching for " << i << ": " << endl;
        binarySearch(a, 100, i);
        cout << endl;
        recursiveBinarySearch(a, 0, 99, i);
        cout << endl;
    }



    return 0;
}
