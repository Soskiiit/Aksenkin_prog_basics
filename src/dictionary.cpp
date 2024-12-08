#include "dictionary.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "utils.h"


namespace dict {
    const int kInitialDictionarySize = 10;
    const int kMaxWordLength = 1024;

    bool AddWord(Dictionary** dict, int* dictLength, int* dictCapacity, char* englishWord, char* russianWord) {
        int low = 0;
        int high = *dictLength - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (strcmp((*dict)[mid].engl, englishWord) == 0) {
                return false; // word was in dictionary
            }

            if (strcmp((*dict)[mid].engl, englishWord) < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        utils::Insert(dict, dictLength, dictCapacity, low, Dictionary{.engl = englishWord, .rus = russianWord});
        return true;
    }

    void ReadAndAddWord(Dictionary** dict, int* dictLength, int* dictCapacity) {
        char* newEnglishWord = new char[kMaxWordLength];
        std::cout << "Введите английское слово: ";
        std::cin >> newEnglishWord;

        char* newRussianWord = new char[kMaxWordLength];
        std::cout << "Введите русское слово: ";
        std::cin >> newRussianWord;

        if (AddWord(dict, dictLength, dictCapacity, newEnglishWord, newRussianWord)) {
            std::cout << "Слово добавлено" << std::endl;
        } else {
            std::cout << "Слово уже было в словаре" << std::endl;
        }
    }

    bool DeleteWord(Dictionary* dict, int* dictLength, char* word) {
        for (int i = 0; i < *dictLength; i++) {
            if (strcmp(word, dict[i].engl) == 0) {
                delete[] dict[i].engl;
                delete[] dict[i].rus;
                utils::DeleteByIndex(dict, dictLength, i);
                return true;
            }
            if (strcmp(word, dict[i].rus) == 0) {
                delete[] dict[i].engl;
                delete[] dict[i].rus;
                utils::DeleteByIndex(dict, dictLength, i);
                return true;
            }
        }
        return false;
    }

    void ReadAndDeleteWord(Dictionary* dict, int* dictLength) {
        char* word = new char[kMaxWordLength];
        std::cout << "Введите слово для удаления: ";
        std::cin >> word;
        if (DeleteWord(dict, dictLength, word)) {
            std::cout << "Слово успешно удалено" << std::endl;
        } else {
            std::cout << "Слово не было найдено" << std::endl;
        }
    }

    char* TranslateEngToRus(Dictionary* dict, int dictLength, char* englishWord) {
        int low = 0;
        int high = dictLength - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (strcmp(dict[mid].engl, englishWord) == 0) {
                return dict[mid].rus; // word was in dictionary
            }

            if (strcmp(dict[mid].engl, englishWord) < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nullptr;
    }

    void ReadAndTranslateEngToRus(Dictionary* dict, int dictLength) {
        if (dictLength == 0)
            std::cout << "Словарь пуст!";
        else {
            char* englishWord = new char[kMaxWordLength];
            std::cout << "Введите слово по-английски: ";
            std::cin >> englishWord;
            char* russianWord = TranslateEngToRus(dict, dictLength, englishWord);
            if (russianWord != nullptr)
                std::cout << "По-русски это будет " << russianWord << std::endl;
            else
                std::cout << "Такого слова нет в словаре" << std::endl;
        }
    }

    char* TranslateRusToEng(Dictionary* dict, int dictLength, char* russianWord) {
        for (int i = 0; i < dictLength; i++) {
            if (strcmp(russianWord, dict[i].rus) == 0) {
                return dict[i].engl;
            }
        }
        return nullptr;
    }

    void ReadAndTranslateRusToEng(Dictionary* dict, int dictLength) {
        if (dictLength == 0)
            std::cout << "Словарь пуст!";
        else {
            char* russianWord = new char[kMaxWordLength];
            std::cout << "Введите слово по-русски: ";
            std::cin >> russianWord;
            char* englishWord = TranslateRusToEng(dict, dictLength, russianWord);
            if (englishWord != nullptr)
                std::cout << "По-английски это будет " << englishWord << std::endl;
            else
                std::cout << "Такого слова нет в словаре" << std::endl;
        }
    }

    void PrintDictionary(Dictionary* dict, int dictLength) {
        std::cout << std::endl << "Словарь:" << std::endl;
        for (int i = 0; i < dictLength; i++) {
            std::cout << "\t" << dict[i].engl << ": " << dict[i].rus << std::endl;
        }
    }

    void DumpDictionary(Dictionary* dict, int dictLength, char* filename) {
        std::ofstream file;
        file.open(filename);
        for (int i = 0; i < dictLength; i++) {
            file << dict[i].engl << " - " << dict[i].rus << "\n";
        }
        file.close();
    }

    int Demo() {
        auto* dict = new Dictionary[kInitialDictionarySize];
        int dictLength = 0;
        int dictCapacity = kInitialDictionarySize;

        char* wordPairs[][2] = {
            {new char[] {"meow"}, new char[] {"мяу"}},
            {new char[] {"MSTU"}, new char[] {"МГТУ"}},
            {new char[] {"C++"}, new char[] {"C++"}},
            {new char[] {"Hashmap"}, new char[] {"is_better"}},
            {new char[] {"хочу"}, new char[] {"персик"}},
            {new char[] {"O_o"}, new char[] {"🤨"}}
        };

        std::cout << "Демо\n\n";
        for (int i = 0; i < std::size(wordPairs); i++) {
            std::cout << "Добавляем в словарь пару " << wordPairs[i][0] <<":" << wordPairs[i][1] << "\n";
            AddWord(&dict, &dictLength, &dictCapacity, wordPairs[i][0], wordPairs[i][1]);
        }

        std::cout << "Попробуем ещё раз добавить пару meow:мяу" << std::endl;
        AddWord(&dict, &dictLength, &dictCapacity, "meow", "мяу");

        std::cout << "\nПолучаем:";
        PrintDictionary(dict, dictLength);
        std::cout << "\nУвидим, что словарь отсортирован и не имеет повторений\n";

        std::cout << "\nУдаляем пару с персиком\n";
        DeleteWord(dict, &dictLength, "персик");

        std::cout << "\nПолучаем:";
        PrintDictionary(dict, dictLength);
        return 0;
    }

    Action Menu() {
        int choice;
        std::cout << "\nВыберите действие:\n"
                     "\t1. Добавление слов в словарь\n"
                     "\t2. Удаление слов из словаря\n"
                     "\t3. Перевод слов с английского на русский\n"
                     "\t4. Перевод слов с русского на английский\n"
                     "\t5. Просмотр словаря (вывод на экран словаря из ОП)\n"
                     "\t6. Вывод словаря в файл\n"
                     "\t7. Выход\n";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        return static_cast<Action>(choice);
    }

    int Interactive() {
        auto* dict = new Dictionary[kInitialDictionarySize];
        int dictLength = 0;
        int dictCapacity = kInitialDictionarySize;
        std::cout << "Интерактивный режим!\n";
        for (;;) {
            switch (Menu()){
                case Action::AddWord:
                    ReadAndAddWord(&dict, &dictLength, &dictCapacity);
                    break;
                case Action::DeleteWord:
                    ReadAndDeleteWord(dict, &dictLength);
                    break;
                case Action::TranslateEngToRus:
                    ReadAndTranslateEngToRus(dict, dictLength);
                    break;
                case Action::TranslateRusToEng:
                    ReadAndTranslateRusToEng(dict, dictLength);
                    break;
                case Action::PrintDictionary:
                    PrintDictionary(dict, dictLength);
                    break;
                case Action::DumpDictionary:
                    DumpDictionary(dict, dictLength, "../dict.txt");
                    break;
                case Action::Exit:
                    return 0;
                default:
                    std::cout << "Некорректный ввод\n";
            }
        }
    }
}
    