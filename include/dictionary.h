#pragma once


namespace dict {
    struct Dictionary {
        char *engl; // слово по-английски
        char *rus; // слово по-русски
    };

    enum class Action {
        AddWord = 1,
        DeleteWord = 2,
        TranslateEngToRus = 3,
        TranslateRusToEng = 4,
        PrintDictionary = 5,
        DumpDictionary = 6,
        Exit = 7,
    };

    int Demo();

    int Interactive();
}
