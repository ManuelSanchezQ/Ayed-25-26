// AUTOR: Manuel Sánchez Quijada
// FECHA: 11/02/26
// EMAIL: alu0101806815@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo: comentarios multilínea usando  "*/ ... */

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>


# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pauta de estilo: Primero "public" y después "private"
 public:
  rational_t(const int = 0, const int = 1); /// Constructor de la clase racional_t, recibe dos enteros, con valores por defecto 0 y 1
  ~rational_t() {} /// Destructor de la clase racional_t
  
  // pauta de estilo: Indentación a 2 espacios
  // getters
  int get_num() const; /// Getter del atrubuto num_
  int get_den() const; /// Getter del atrubuto den_
  
  // setters
  void set_num(const int); /// Setter del atrubuto num_
  void set_den(const int); /// Setter del atrubuto num_

  /* value
  * @brief Devuelve en valor en numero decimal del racional correspondiente
  * @param void 
  * @return Devuelve en valor en 
  */ 
  double value(void) const;

  // FASE II
  /* is_equal
  * @brief Compara dos racionales para ver si son iguales
  * @param r: Racional a comparar con el que hace la llamada
  * @param precision: Presicion para determinar si sus valores en punto flotante son iguales
  * @return True si son iguales o false si no
  */
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  /* is_greater
  * @brief Compara dos racionales para ver si el que hace la llamada es mayor que el segundo
  * @param r: Racional a comparar con el que hace la llamada
  * @param precision: Presicion para determinar si su valor en punto flotante es mayor que el otro 
  * @return True si es mayor o false si no
  */
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  /* is_less
  * @brief Compara dos racionales para ver si el que hace la llamada es menor que el segundo
  * @param r: Racional a comparar con el que hace la llamada
  * @param precision: Presicion para determinar si su valor en punto flotante es menor que el otro 
  * @return True si es menor o false si no
  */
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  /* add
  * @brief Suma dos racionales
  * @param r: Racional a sumar con el que hace la llamada
  * @return Racional que representa la suma de ambos
  */
  rational_t add(const rational_t&) const;

   /* substract
  * @brief Resta dos racionales
  * @param r: Racional a restar con el que hace la llamada
  * @return Racional que representa la resta de ambos
  */
  rational_t substract(const rational_t&) const;

   /* multiply
  * @brief Multiplica dos racionales
  * @param r: Racional a multiplicar con el que hace la llamada
  * @return Racional que representa la multiplicacion de ambos
  */
  rational_t multiply(const rational_t&) const;

   /* divide
  * @brief Divide dos racionales
  * @param r: Racional que divide al que hace la llamada
  * @return Racional que representa la division de ambos
  */
  rational_t divide(const rational_t&) const;
  
  /* write
  * @brief Escribe un numero de tipo racional, con su forma en fraccion y en decimal
  * @param cout 
  * @return void
  */ 
  void write(ostream& = cout) const;
  

  /* read
  * @brief Lee un numero de tipo racional, pididendo su numerador y denominador 
  * @param cin
  * @return void
  */ 
  void read(istream& = cin);
  
 private:
  // pauta de estilo: Nombre de los atributos seguido de "_"
  int num_, den_;
};
