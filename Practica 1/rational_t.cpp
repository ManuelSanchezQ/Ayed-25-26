// AUTOR: Manuel Sánchez Quijada
// FECHA: 11/02/26
// EMAIL: alu0101806815@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo: comentarios multilínea usando solo "*/ ... */

#include "rational_t.hpp"
#include <cmath>

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo : 1 línea de separación entre métodos

// pauta de estilo : tipo retornado en línea del método

int rational_t::get_num() const //Getter del atrubuto num_
{
  return num_;
}



int rational_t::get_den() const //Getter del atrubuto den_
{
  return den_;
}


  
void rational_t::set_num(const int n) //Setter del atrubuto num_
{
  num_ = n;
}


  
void rational_t::set_den(const int d) //Setter del atrubuto den_
{
  assert(d != 0);
  den_ = d;
}


/* value
  * @brief Devuelve en valor en numero decimal del racional correspondiente
  * @param: void 
  * @return Devuelve en valor en 
  */ 
double rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// comparaciones

bool rational_t::is_equal(const rational_t& r, const double precision) const {
  if (fabs(value() - r.value()) < precision) {
    return true;
  }
  return false;
}



bool rational_t::is_greater(const rational_t& r, const double precision) const {
  if (value() - r.value() > precision) {
    return true;
  }
  return false;
}



bool rational_t::is_less(const rational_t& r, const double precision) const {
  if (r.value() - value() > precision) {
    return true;
  }
  return false;
}


// operaciones

rational_t rational_t::add(const rational_t& r) const {
  rational_t result{(get_num() * r.get_den() + r.get_num() * get_den()), (get_den() * r.get_den())};
  return result;
}



rational_t rational_t::substract(const rational_t& r) const { 
  rational_t result{(get_num() * r.get_den() - r.get_num() * get_den()), (get_den() * r.get_den())};
  return result;
}



rational_t rational_t::multiply(const rational_t& r) const {
  rational_t result{(get_num() * r.get_num()), (get_den() * r.get_den())};
  return result;
}



rational_t rational_t::divide(const rational_t& r) const { 
  rational_t result{get_num() * r.get_den(), get_den() * r.get_num()};
  return result;
}



// E/S

/* write
  * @brief Escribe un numero de tipo racional, con su forma en fraccion y en decimal
  * @param cout 
  * @return void
  */ 
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


/* read
  * @brief Lee un numero de tipo racional, pididendo su numerador y denominador 
  * @param cin
  * @return void
  */ 
void  rational_t::read(istream& is) {
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
