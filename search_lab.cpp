
#include <iostream>
#include <vector>

using namespace std;

/*
    Linear Search
    Goes through the array from left to right.
    Stops when the key is found or when the array ends.
*/
int linearSearch(const vector<int>& numbers, int key, long long& steps) {
    steps = 0;

    for (size_t i = 0; i < numbers.size(); i++) {
        steps++;  // we compare numbers[i] with key

        if (numbers[i] == key) {
            return i;  // found it
        }
    }

    return -1;  // not found
}


/*
    Binary Search
    Works only on sorted arrays.
    Repeatedly cuts the search space in half.
*/
int binarySearch(const vector<int>& numbers, int key, long long& steps) {
    steps = 0;

    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right) {

        int middle = left + (right - left) / 2;

        steps++;  // compare numbers[middle] with key
        if (numbers[middle] == key) {
            return middle;  // found it
        }

        steps++;  // compare numbers[middle] < key
        if (numbers[middle] < key) {
            left = middle + 1;  // search right half
        } else {
            right = middle - 1; // search left half
        }
    }

    return -1;  // not found
}


int main() {

    const int SIZE = 100000;

    // Create a sorted dataset: 0, 1, 2, ..., 99999
    vector<int> dataset(SIZE);
    for (int i = 0; i < SIZE; i++) {
        dataset[i] = i;
    }

    int key;
    cout << "Enter a number between 0 and 99999 to search: ";
    cin >> key;

    long long linearSteps = 0;
    long long binarySteps = 0;

    int linearResult = linearSearch(dataset, key, linearSteps);
    int binaryResult = binarySearch(dataset, key, binarySteps);

    cout << "\n===== Search Results =====\n";

    cout << "Linear Search:\n";
    cout << "  Index found: " << linearResult << "\n";
    cout << "  Comparisons: " << linearSteps << "\n\n";

    cout << "Binary Search:\n";
    cout << "  Index found: " << binaryResult << "\n";
    cout << "  Comparisons: " << binarySteps << "\n";

    return 0;
}
