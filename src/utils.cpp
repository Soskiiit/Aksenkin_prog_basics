#include "utils.h"

#include <cstring>

namespace {
bool StartsWith(const char* str, const char* prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}
}  // namespace

namespace utils {
Config ParseAgruments(int argc, char** argv) {
    Config config;
    for (int i = 1; i < argc; i++) {
        if (StartsWith(argv[i], "--source=")) {
            config.inputPath = &argv[i][strlen("--source=")];
        } else if (StartsWith(argv[i], "--keychain=")) {
            config.keychainPath = &argv[i][strlen("--keychain=")];
        } else if (StartsWith(argv[i], "--output=")) {
            config.outputPath = &argv[i][strlen("--output=")];
        } else if (StartsWith(argv[i], "--encoded=")) {
            config.encodedPath = &argv[i][strlen("--encoded=")];
        }
    }
    return config;
}
}  // namespace utils
