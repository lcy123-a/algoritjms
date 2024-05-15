#pragma once

//归并排序

using namespace std;

void merge(int* array, int start, int mid, int end) {
    int k = 0;
    int low = start;
    int high = mid + 1;
    int* temp = (int*)malloc(sizeof(int) * (end- start + 1));

    while (low <= mid && high <= end) {
        (array[low] < array[high]) ? temp[k++] = array[low++] : temp[k++] = array[high++];
    }
    while (high <= end) temp[k++] = array[high++];
    while (low <= mid) temp[k++] = array[low++];
    for (int i = 0; i < k; ++i) array[start + i] = temp[i];

    free(temp);
} 



void merge_sort(int* array, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);
    merge(array, start, mid, end);
}

/*int main(int argc, char *argv[])
{
    int a[] = {5, 2, 4, 6, 1, 3};
    merge_sort(a, 0, 5);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    return 0;
}*/