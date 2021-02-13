#include <iostream>

#define NOTFOUND  (-1)

using namespace std;

/* Search key from data in binary search */
/* return : found index */
int BinarySearch(int *data, int data_size, int key)
{
    int idx_left;
    int idx_middle;
    int idx_right;

    idx_left = 0;
    idx_right = data_size;

    while (idx_left < idx_right) {
        idx_middle = (idx_left + idx_right) / 2;

        if (data[idx_middle] == key) {
            return idx_middle;
        } else if (key < data[idx_middle]){
            idx_right = idx_middle;
        } else {
            idx_left = idx_middle + 1;
        }
    }
    return NOTFOUND;
}

int main(void)
{
    int array[100000];
    int input_size;
    int search_size;
    int key;
    int found_num;

    cin >> input_size;
    for (int loop = 0; loop < input_size; loop++) {
        cin >> array[loop];
    }

    cin >> search_size;
    found_num = 0;
    for (int loop = 0; loop < search_size; loop++) {
        cin >> key;

        if (BinarySearch(array, input_size, key) != NOTFOUND) {
            found_num++;
        }
    }

    cout << found_num << endl;
    return 0;
}
