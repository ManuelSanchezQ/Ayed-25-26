#include <vector>
#include <cassert>

namespace Ayed {
  class vector { 

   public: 
    vector(const size_t sz);
    ~vector();
    void resize(const size_t new_sz);
    double at(const size_t n) const;
    double& at(const size_t n);
   private:
    size_t sz_;
    double *base_;
    void build(const size_t sz);
    void destroy();
  };

  void vector::build(const size_t sz) {
    base_ = new double[sz];
  }
  void vector::destroy() {
    if (base_ != NULL) {
      delete []base_;
      base_ = NULL;
    }
  }

  vector::vector(const size_t sz) : sz_{sz}, base_{NULL} {
    build(sz);
  }

  vector::~vector() {
    destroy();
  }

  void vector::resize(const size_t new_sz) {
    if (new_sz > sz_) {
      double *aux{base_};
      build(new_sz);
      for (size_t i{0}; i < sz_; ++i) {
        base_[i] = aux[i];
      }
      delete []aux;
      aux = NULL;
      sz_ = new_sz;
    }
  }

  double vector::at(const size_t n) const {
    assert(n >= sz_);
    return base_[n];
  }

  double& vector::at(const size_t n) {
    assert(n >= sz_);
    return base_[n];
  }
}