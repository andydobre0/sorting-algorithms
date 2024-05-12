#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<chrono>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];    
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;    
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    
    quickSort(numbers, 0, numbers.size() - 1);
    
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


    std::vector<int> lista_de_10000000 = generateRandomNumbers(10000000);
    std::cout<<"Timpul necesar pentru 10 000 000 de elemente: ";
    measureAndSort(lista_de_10000000);

    std::vector<int> vector_sortat;
    for(int i = 0; i < 100000; i++)
        vector_sortat.push_back(i);
    std::cout<<"Timpul necesar pentru 100 000 de elemente deja sortate: ";
    measureAndSort(vector_sortat);

    // std::vector<int> vector_sortat2;
    // for(int i = 0; i < 1000000; i++)
    //     vector_sortat2.push_back(i);
    // std::cout<<"Timpul necesar pentru 1 000 000 de elemente deja sortate: ";
    // measureAndSort(vector_sortat2);

}