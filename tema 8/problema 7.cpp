#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int n) {
    int majorityElement = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (count == 0) {
            majorityElement = arr[i];
            count = 1;
        } else if (arr[i] == majorityElement) {
            count++;
        } else {
            count--;
        }
    }

    return majorityElement;
}

bool isMajorityElement(int arr[], int n, int majorityElement) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == majorityElement) {
            count++;
        }
    }

    return count > n / 2;
}

int main() {
    int n;
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> n;

    int arr[n];
    cout << "Introduceti elementele vectorului: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int majorityElement = findMajorityElement(arr, n);

    if (isMajorityElement(arr, n, majorityElement)) {
        cout << "Elementul majoritar este: " << majorityElement << endl;
    } else {
        cout << "Nu exista un element majoritar." << endl;
    }

    return 0;
}
