#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>


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
}
#endif