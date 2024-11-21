#include <iostream>
#include "utils.h"

namespace {

}

int main(int argc, char** argv) {
    auto config = utils::ParseAgruments(argc, argv);
    std::cout << "Input:" << config.inputPath << std::endl;
    std::cout << "Output" << config.outputPath << std::endl;
    std::cout << "Keys:" << config.keychainPath << std::endl;
    std::cout << "Encoded" << config.encodedPath << std::endl;
    return 0;
}
