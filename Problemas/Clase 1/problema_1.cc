#include <vector>

int scal_prod(const int *v1, const int *v2, const size_t sz) {
  int result{0};
  for (size_t i{0}; i < sz; ++i) {
    result += v1[i] * v2[i]; // Lo mismo que: result += *(v1 + i) * *(v2 + i);
  }
  return result;
}