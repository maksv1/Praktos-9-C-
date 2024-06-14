#include <iostream>
#include <vector>
#include <thread>
#include <locale> 

class MergeSort {
public:
    void Sort(std::vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
        std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());

        Sort(left);
        Sort(right);

        Merge(arr, left, right);
    }

private:
    void Merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            arr[k++] = left[i++];
        }
        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }
};

int main() {
    std::vector<int> arr(10);
    std::cout << "Vvedite 10 celic chisel:\n";
    for (int& num : arr) {
        std::cin >> num;
    }

    MergeSort mergeSort;

    auto sortFunction = [&mergeSort](std::vector<int>& array) {
        mergeSort.Sort(array);
        };

    std::thread mergeSortThread(sortFunction, std::ref(arr));

    mergeSortThread.join();

    std::cout << "Otsortirovan massiv:";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
