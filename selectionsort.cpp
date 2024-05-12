#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<chrono>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[minIndex], arr[i]);
    }
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
    
    selectionSort(numbers);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    
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
    std::cout<<"Timpul necesar pentru 10000 de elemente: ";
    measureAndSort(lista_de_10000);


    std::vector<int> lista_de_100000 = generateRandomNumbers(100000);
    std::cout<<"Timpul necesar pentru 100000 de elemente: ";
    // measureAndSort(lista_de_100000);

}