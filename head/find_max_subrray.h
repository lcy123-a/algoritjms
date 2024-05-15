#pragma once
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int find_max_crossing_subarray(int* array, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;
    for (int i = mid; i >= low; --i) {
        sum += array[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid + 1;
    for (int j = mid + 1; j <= high; ++j) {
        sum += array[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }
    return left_sum + right_sum;
}

int find_maximum_subarray(int* array, int low, int high) {
    if (high == low) {
        return array[low];
    } else {
        int mid = (low + high) / 2;
        int left_sum = find_maximum_subarray(array, low, mid);
        int right_sum = find_maximum_subarray(array, mid + 1, high);
        int cross_sum = find_max_crossing_subarray(array, low, mid, high);
        if (left_sum >= right_sum && left_sum >= cross_sum) {
            return left_sum;
        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            return right_sum;
        } else {
            return cross_sum;
        }
        
    }
}

/*int main(int argc, char *argv[])
{
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    cout << find_maximum_subarray(array, 0, 15) << endl;
    return 0;
}*/