#pragma once


namespace dict {
    struct Dictionary {
        char *engl;    // слово по-английски
        char *rus;     // слово по-русски
    };
    int demo();
    int interactive();
}