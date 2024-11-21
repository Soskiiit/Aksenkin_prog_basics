namespace utils {
struct Config {
    char* inputPath = nullptr;
    char* keychainPath = nullptr;
    char* encodedPath = nullptr;
    char* outputPath = nullptr;
};

Config ParseAgruments(int argc, char** argv);
}  // namespace utils
