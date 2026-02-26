#include "vector.h" 
#include <cassert>
#include <cmath>

namespace Ayed {
  class matrix : private vector {
    private:
      size_t m_; //Filas
      size_t n_; //Columnas
      size_t pos_(const size_t i, const size_t j) const {
        return (i - 1) * n_ + j - 1;
      }
    public:
      matrix (const size_t m, const size_t n) : vector(m*n), m_{m}, n_{n} {}
      ~matrix (){}
      double& at(const size_t i, const size_t j) {
        const size_t k{pos_(i,j)};
        return vector::at(k);
      }
      double at(const size_t i, const size_t j) const {
        const size_t k{pos_(i,j)};
        return vector::at(k);
      }
      double& operator() (const size_t i, const size_t j) {
        return at(i,j);
      } 
       double operator() (const size_t i, const size_t j) const {
        return at(i,j);
      } 
      double suma_por_filas() const {
        double suma{0};
        for (size_t i{1}; i <= m_; ++i) {
          for (size_t j{1}; j <= n_; ++j) {
            suma += at(i, j);
          }
        }
        return suma;
      }
      size_t count_zero_diagonal(const double tol) const {
        assert(m_ == n_);
        int contador{0};
        for(size_t i{1}; i <= m_; ++i) {
          if (fabs(at(i, i)) < tol) {
            ++contador; 
          }
        }
        return contador;
      }
      size_t count_nz_ds(const double tol) const {
        assert(m_ == n_);
        int contador{0};
        for(size_t i{1}; i <= m_; ++i) {
          if (fabs(at(i, n_ - i + 1)) > tol) {
            ++contador; 
          }
        }
        return contador;
      }
    };
}