#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // Підтримка українських символів

    wchar_t sentence[1000];
    int count_ukr = 0; // Лічильник для 'є', 'Є', 'е', 'Е'
    int count_eng = 0; // Лічильник для 'e', 'E'

    wprintf(L"Введіть речення, яке закінчується '.' або '!':\n");
    fgetws(sentence, sizeof(sentence) / sizeof(wchar_t), stdin);

    int length = wcslen(sentence);

    // Видалення символу нового рядка
    if (length > 0 && sentence[length - 1] == L'\n') {
        sentence[length - 1] = L'\0';
        length--;
    }

    // Перевірка на коректне завершення
    if (length == 0 || (sentence[length - 1] != L'.' && sentence[length - 1] != L'!')) {
        wprintf(L"Помилка: речення має закінчуватися '.' або '!'\n");
        return 1;
    }

    // Підрахунок символів 'є', 'Є', 'е', 'Е', 'e', 'E'
    for (int i = 0; i < length; i++) {
        if (sentence[i] == L'є' || sentence[i] == L'Є' || sentence[i] == L'е' || sentence[i] == L'Е') {
            count_ukr++;
        } else if (sentence[i] == L'e' || sentence[i] == L'E') {
            count_eng++;
        }
    }

    int total = count_ukr + count_eng;

    if (total > 0) {
        wprintf(L"Знайдено:\n");
        if (count_ukr > 0) {
            wprintf(L"- Українських 'є'/'Є'/'е'/'Е': %d\n", count_ukr);
        }
        if (count_eng > 0) {
            wprintf(L"- Англійських 'e'/'E': %d\n", count_eng);
        }
        wprintf(L"Загальна кількість: %d\n", total);
    } else {
        wprintf(L"Символ 'є', 'е' або 'e' відсутні у введеному реченні.\n");
    }

    return 0;
}
