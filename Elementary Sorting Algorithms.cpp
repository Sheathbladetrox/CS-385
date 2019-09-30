static void swap(int array[], const int a, const int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
/**
 * Best case: Array is already sorted. Θ(n)
 * Average case: Θ(n^2) with a lower constant.
 * Worst case: Array is sorted in reverse. Θ(n^2)
 * Overall: O(n^2): Pick worst running time along with O if the g(n)'s are different for worst and best cases.
 */
void bubble_sort(int array[], const int length) {
    int len = length;
    while (len > 0) {
        int n = 0;
        for (int i = 1; i < len; ++i) {
            if (array[i - 1] > array[i]) {
                swap(array, i - 1, i);
                n = i;
            }
        }
        len = n;
    }
}

/**
 * Selection sort always makes n(n-1)/2 comparisons and at most n-1 swaps.
 * Best case: Θ(n^2)
 * Worst case: Θ(n^2)
 * Average case: Θ(n^2)
 * Overall: Θ(n^2)
 */
void selection_sort(int array[], const int length) {
    for (int i = 0, i_bound = length - 1; i < i_bound; ++i) {
        int min_index = i, min = array[i];
        for (int j = i + 1; j < length; ++j) {
            if (array[j] < min) {
                min_index = j;
                min = array[j];
            }
        }
        if (min_index != i) {
            swap(array, i, min_index);
        }
    }
}

/**
 * Best case: Θ(n)
 * Worst case: Θ(n^2)
 * Average case: Θ(n^2)
 * Overall: O(n^2)
 */
void insertion_sort(int array[], const int length) {
    for (int i = 1; i < length; ++i) {
        int k, current = array[i];
        for (k = i - 1; k >= 0 && array[k] > current; --k) {
            array[k + 1] = array[k];
        }
        array[k + 1] = current;
    }
}