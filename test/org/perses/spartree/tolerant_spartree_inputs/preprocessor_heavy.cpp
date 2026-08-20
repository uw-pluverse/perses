#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>

#define MAX_SIZE 1024
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define STRINGIFY(x) #x

#if defined(__linux__) && !defined(EMBEDDED)
#define PLATFORM 1
#elif defined(_WIN32)
#define PLATFORM 2
#else
#define PLATFORM 0
#endif

namespace app {

template <typename T>
class Buffer {
public:
  Buffer() : size_(MAX_SIZE) {
#ifdef ENABLE_LOGGING
    trace("Buffer created");
#endif
  }

  int compute(int x) {
#if defined(FAST_PATH)
    return x << 2;
#else
    int result = 0;
    for (int i = 0; i < MIN(x, size_); ++i) {
#ifndef NDEBUG
      result += (i * PLATFORM);
#else
      result += i;
#endif
    }
    return result;
#endif
  }

private:
  int size_;
  std::vector<T> data_;
};

}
#endif
