#ifndef SORTING_H
#define SORTING_H

#include <algorithm>
#include <vector>

namespace sorting {
    // swap
    template <typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    template <typename T>
    bool Greater(T a, T b) {
        return a > b;
    }

    namespace n_square {
        template <typename T>
        void bubbleSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (cmp(arr[j], arr[j + 1])) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        template <typename T>
        void selectionSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            for (int i = 0; i < n - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < n; j++) {
                    if (cmp(arr[j], arr[minIndex])) {
                        minIndex = j;
                    }
                }
                swap(arr[i], arr[minIndex]);
            }
        }

        template <typename T>
        void insertionSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            for (int i = 1; i < n; i++) {
                T key = arr[i];
                int j = i - 1;
                while (j >= 0 && cmp(arr[j], key)) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }
    }

    namespace n_onehalf {
        template <typename T>
        void shellSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            for (int gap = n / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; i++) {
                    T temp = arr[i];
                    int j;
                    for (j = i; j >= gap && cmp(arr[j - gap], temp); j -= gap) {
                        arr[j] = arr[j - gap];
                    }
                    arr[j] = temp;
                }
            }
        }
    }

    namespace n_logn {
        template <typename T>
        void merge(T arr[], int l, int m, int r, bool (*cmp)(T, T) = &Greater) {
            int n1 = m - l + 1;
            int n2 = r - m;

            T L[n1], R[n2];
            for (int i = 0; i < n1; i++) {
                L[i] = arr[l + i];
            }
            for (int i = 0; i < n2; i++) {
                R[i] = arr[m + 1 + i];
            }

            int i = 0, j = 0, k = l;
            while (i < n1 && j < n2) {
                if (cmp(L[i], R[j])) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        template <typename T>
        void mergeSort(T arr[], int l, int r, bool (*cmp)(T, T) = &Greater) {
            if (l >= r) {
                return;
            }
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m, cmp);
            mergeSort(arr, m + 1, r, cmp);
            merge(arr, l, m, r, cmp);
        }

        template <typename T>
        int partition(T arr[], int low, int high, bool (*cmp)(T, T) = &Greater) {
            T pivot = arr[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (cmp(arr[j], pivot)) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            return i + 1;
        }

        template <typename T>
        void quickSort(T arr[], bool (*cmp)(T, T) = &Greater, int low = 0, int high = -100) {
            if (high == -100) {
                high = sizeof(arr) / sizeof(arr[0]) - 1;
            }
            if (low < high) {
                int pi = partition(arr, low, high, cmp);
                quickSort(arr, cmp, low, pi - 1);
                quickSort(arr, cmp, pi + 1, high);
            }
        }

        template <typename T>
        void timSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            const int RUN = 32;
            for (int i = 0; i < n; i += RUN) {
                insertionSort(arr, i, std::min((i + 31), (n - 1)), cmp);
            }
            for (int size = RUN; size < n; size = 2 * size) {
                for (int left = 0; left < n; left += 2 * size) {
                    int mid = left + size - 1;
                    int right = std::min((left + 2 * size - 1), (n - 1));
                    merge(arr, left, mid, right, cmp);
                }
            }
        }

        template <typename T>
        void heapify(T arr[], int n, int i, bool (*cmp)(T, T) = &Greater) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < n && cmp(arr[l], arr[largest])) {
                largest = l;
            }
            if (r < n && cmp(arr[r], arr[largest])) {
                largest = r;
            }
            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(arr, n, largest, cmp);
            }
        }

        template <typename T>
        void heapSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(arr, n, i, cmp);
            }
            for (int i = n - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                heapify(arr, i, 0, cmp);
            }
        }
    }

    namespace n {
        // Counting Sort
        template <typename T>
        void countingSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            T output[n];
            T max = arr[0];
            for (int i = 1; i < n; i++) {
                if (cmp(arr[i], max)) {
                    max = arr[i];
                }
            }
            T count[max + 1];
            for (int i = 0; i <= max; i++) {
                count[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                count[arr[i]]++;
            }
            for (int i = 1; i <= max; i++) {
                count[i] += count[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                output[count[arr[i]] - 1] = arr[i];
                count[arr[i]]--;
            }
            for (int i = 0; i < n; i++) {
                arr[i] = output[i];
            }
        }

        template <typename T>
        void cSort(T arr[], int n, int exp, bool (*cmp)(T, T) = &Greater) {
            T output[n];
            T count[10] = {0};
            for (int i = 0; i < n; i++) {
                count[(arr[i] / exp) % 10]++;
            }
            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
            }
            for (int i = 0; i < n; i++) {
                arr[i] = output[i];
            }
        }

        // Radix Sort
        template <typename T>
        void radixSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            T max = arr[0];
            for (int i = 1; i < n; i++) {
                if (cmp(arr[i], max)) {
                    max = arr[i];
                }
            }
            for (int exp = 1; max / exp > 0; exp *= 10) {
                cSort(arr, n, exp, cmp);
            }
        }
        // Bucket Sort
        template <typename T>
        void bucketSort(T arr[], int n, bool (*cmp)(T, T) = &Greater) {
            T max = arr[0];
            for (int i = 1; i < n; i++) {
                if (cmp(arr[i], max)) {
                    max = arr[i];
                }
            }
            max++;
            std::vector<T> b[max];
            for (int i = 0; i < n; i++) {
                int bi = n * arr[i] / max;
                b[bi].push_back(arr[i]);
            }
            for (int i = 0; i < max; i++) {
                n_logn::quickSort(b[i].data(), cmp, 0, b[i].size() - 1);
            }
            int index = 0;
            for (int i = 0; i < max; i++) {
                for (int j = 0; j < b[i].size(); j++) {
                    arr[index++] = b[i][j];
                }
            }
        }
    }
}



#endif