///Juan Camilo vasquez Jaramillo
///codigo: 8976396
#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
//La función comparador() es O(n) donde n es la longitud máxima de las strings a comparar, debido a recorrer caracter por caracter.
//El algoritmo de ordenamiento sort() utilizando comparador() es O(n log n) donde n es el número de palabras, ya que utiliza quicksort o mergesort internamente.
//Los loops externos son O(t) donde t es el número de casos de prueba.
//Los loops internos para leer palabras son O(n) donde n es el número de palabras por caso.
//Imprimir palabras es O(n) también.
//Entonces la complejidad total es O(t * (n + n log n + n)) = O(t * n log n)

using namespace std;

// Variable global que contiene el alfabeto 
string alfabeto;

// Función de comparación para ordenar palabras
// Compara dos strings a y b basado en el orden del alfabeto global
// Devuelve true si a debe ir antes que b en el ordenamiento
bool comparador(const string& a, const string& b) {

  // Índice para iterar sobre los caracteres
  int i = 0;

  // Compara caracter por caracter mientras sean iguales
  while (i < a.length() && i < b.length() && 
         alfabeto.find(a[i]) == alfabeto.find(b[i])) {
    i++;
  }

  // Compara los caracteres distintos
  if (i < a.length() && i < b.length()) {
    return alfabeto.find(a[i]) < alfabeto.find(b[i]);

  // Si una cadena es prefijo de la otra, la más corta va primero
  } else {
    return a.length() < b.length();
  }
}

// Función main
int main() {

  // Lee número de casos de prueba
  int t;
  cin >> t;

  // Procesa cada caso  
  for (int i = 0; i < t; ++i) {

    // Lee el alfabeto 
    cin >> alfabeto;
  
    // Lee cantidad de palabras
    int n;
    cin >> n;

    // Vector de palabras 
    vector<string> palabras(n);

    // Lee las palabras
    for (int j = 0; j < n; ++j) {
      cin >> palabras[j];
    }

    // Ordena con la función de comparación
    sort(palabras.begin(), palabras.end(), comparador);

    // Imprime ordenadas
    for (size_t k = 0; k < palabras.size(); ++k) {
      cout << palabras[k] << endl;
    }

  }

  return 0;

}