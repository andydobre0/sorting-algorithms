#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<chrono>

void merge(std::vector<int>& arr, int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    std::vector<int> leftArray(subArrayOne),
                     rightArray(subArrayTwo);

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(std::vector<int>& arr, int const begin, int const end) {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}


std::vector<int> generateRandomNumbers(int count) {
    std::vector<int> numbers;
    for (int i = 0; i < count; ++i) {
        numbers.push_back(std::rand() % 10000);
    }
    return numbers;
}

void measureAndSort(std::vector<int>& numbers) {
    auto start = std::chrono::high_resolution_clock::now();
    
    mergeSort(numbers, 0, numbers.size() - 1);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    if (duration.count() > 100000) {
        std::cout << duration.count() / 60000 << " minutes\n";
    } else if (duration.count() > 10000) {
        std::cout << duration.count() / 1000 << " seconds\n";
    } else {
        std::cout << duration.count() << "ms\n";
    }
}




int main()
{
    std::srand(std::time(nullptr));

    std::vector<int> lista_de_1000 = generateRandomNumbers(1000);
    std::cout<<"Timpul necesar pentru 1000 de elemente: ";
    measureAndSort(lista_de_1000);

    std::vector<int> lista_de_10000 = generateRandomNumbers(10000);
    std::cout<<"Timpul necesar pentru 10 000 de elemente: ";
    measureAndSort(lista_de_10000);


    std::vector<int> lista_de_100000 = generateRandomNumbers(100000);
    std::cout<<"Timpul necesar pentru 100 000 de elemente: ";
    measureAndSort(lista_de_100000);
       
    std::vector<int> lista_de_1000000 = generateRandomNumbers(1000000);
    std::cout<<"Timpul necesar pentru 1 000 000 de elemente: ";
    measureAndSort(lista_de_1000000);


    std::vector<int> lista_de_50000000 = generateRandomNumbers(50000000);
    std::cout<<"Timpul necesar pentru 50 000 000 de elemente: ";
    measureAndSort(lista_de_50000000);
}