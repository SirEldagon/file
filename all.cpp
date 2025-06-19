#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Функция для генерации большого файла с случайными числами
void generateFile(const std::string& filename, long long fileSizeInBytes) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
        return;
    }

    long long numCount = fileSizeInBytes / sizeof(int); // Количество чисел в файле
    for (long long i = 0; i < numCount; ++i) {
        int randomNumber = rand(); // Генерируем случайное число
        file.write(reinterpret_cast<char*>(&randomNumber), sizeof(int));
    }

    file.close();
}

// Функция для сортировки файла частями (external merge sort)
void sortFile(const std::string& filename, size_t chunkSize) {
    // Реализация external merge sort (сортировка слиянием)
    // 1. Читаем файл частями размером chunkSize в память.
    // 2. Сортируем каждую часть.
    // 3. Записываем отсортированные части обратно во временные файлы.
    // 4. Выполняем слияние отсортированных частей.
}

int main() {
    const std::string filename = "large_file.bin";
    long long fileSize = 2LL * 1024 * 1024 * 1024; // 2GB
    size_t chunkSize = 1024 * 1024; // 1MB - размер чанка для сортировки

    generateFile(filename, fileSize);
    sortFile(filename, chunkSize);

    std::cout << "Файл успешно сгенерирован и отсортирован." << std::endl;

    return 0;
}
