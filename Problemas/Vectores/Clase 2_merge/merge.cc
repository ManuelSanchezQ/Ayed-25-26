#include <iostream>
void merge_1(const int *a, const size_t sz_a, const int *b, const size_t sz_b, int *c, size_t& sz_c) {
  /* Metodo del profesor 
  sz_c = 0;
  for (size_t i{0}; i < sz_a; ++i) {
    c[sz_c] = a[i];
    ++sz_c;
  }
  for (size_t i{0}; i < sz_b; ++i) {
    c[sz_c] = b[i];
    ++sz_c;
  }*/
  // Como lo haria yo
  sz_c = sz_a + sz_b;
  for (size_t i{0}; i < sz_a; ++i) {
    c[i] = a[i];
  }
  for (size_t i{0}; i < sz_b; ++i) {
    c[sz_c + i] = b[i];
  }
}

void merge_2(const int *a, const size_t sz_a, const int *b, const size_t sz_b, int *c, size_t& sz_c) {
  size_t i{0}, j{0};
  sz_c = 0;
  while(i < sz_a && j < sz_b) {
    if (a[i] <= b[j]) {
      c[sz_c] = a[i];
      ++i;
    } else {
      c[sz_c] = b[j];
      ++j;
    }
    ++sz_c;
  }
  while (j < sz_b) {
  c[sz_c] = b[j];
  ++j;
  ++sz_c;
  }
  while (i < sz_a) {
  c[sz_c] = a[i];
  ++i;
  ++sz_c;
  }
}
  