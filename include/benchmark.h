#pragma once

namespace benchmark {
enum class ArrayType {
    Static = 1,
    Dynamic = 2,
};

void RunBenchmark();
void ExecuteApplication();
}  // namespace benchmark
