#pragma once

namespace utils {
    template<typename T>
    void DeleteByIndex(T* list, int* size, int pos) {
        *size = *size - 1;
        for (int i = pos; i < *size; i++) {
            list[i] = list[i + 1];
        }
    }

    template<typename T>
    void Insert(T** list, int* size, int* capacity, int pos, T value) {
        // If we haven't enough capacity to add new element
        if (*size == *capacity) {
            *capacity *= 2;
            auto newDict = new T[*capacity];
            for (int i = 0; i < *size; i++) {
                newDict[i] = (*list)[i];
            }
            delete [] *list;
            *list = newDict;
        }
        // moving elements to get free place at pos
        for (int i = *size; i > pos; i--) {
            (*list)[i] = (*list)[i - 1];
        }
        // insert new element
        (*list)[pos] = value;
        (*size)++;
    }
}
