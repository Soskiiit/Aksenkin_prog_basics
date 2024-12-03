#include <cstring>

#include "dictionary.h"


int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "i") == 0) {
        return dict::interactive();
    }
    return dict::demo();
}

