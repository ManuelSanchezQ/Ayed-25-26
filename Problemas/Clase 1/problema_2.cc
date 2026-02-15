#include <vector>
#include <cmath>

size_t count_eq(const double *v, const size_t sz,  const double val, const double tol) {
  size_t result{0};
  for (size_t i{0}; i < sz; ++i) {
    if (fabs(v[i] - val) < tol) {
      ++result;
    }
  }
  return result;
}