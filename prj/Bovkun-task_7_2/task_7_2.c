#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>

int main() {
    // Встановлюємо локаль на українську UTF-8
    setlocale(LC_ALL, "uk_UA.UTF-8");
    // Налаштовуємо вивід для підтримки широких символів
    _setmode(_fileno(stdout), _O_U16TEXT);

    int arr[20];
    int even = 0, odd = 0;
    int count = 0;

    wprintf(L"Введіть 20 натуральних чисел:\n");
    for (int i = 0; i < 20; i++) {
        if (wscanf(L"%d", &arr[i]) != 1) {
            break;
        }
        if (arr[i] <= 0) {
            wprintf(L"Помилка: числа мають бути натуральними (≥1).\n");
            return 1;
        }
        count++;
        if (arr[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    // Перевірка на кількість введених чисел
    if (count != 20) {
        wprintf(L"Ви ввели %d чисел замість 20.\n", count);
        wprintf(L"\n"); // Додаємо новий рядок перед виведенням результатів
    }

    if (even > odd) {
        wprintf(L"Більше парних\n");
    } else if (odd > even) {
        wprintf(L"Більше непарних\n");
    } else {
        wprintf(L"Однакова кількість\n");
    }

    return 0;
}
