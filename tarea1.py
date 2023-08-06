                        #1. Split#############################################

def split(cad, sep):

    trozos = []  # Lista para almacenar los trozos resultantes
    actual = []  # Lista temporal para construir un trozo
    
    for char in cad:
        if char == sep:
            if actual:
                trozos.append(''.join(actual))
                actual = []  # Reiniciar la lista temporal
        else:
            actual.append(char)
    
    # Agregar el último trozo si queda alguno pendiente
    if actual:
        trozos.append(''.join(actual))
    
    return trozos

# Ejemplo de uso
oracion = "hola mundo bonito!"
división = "o"
resultado = split(oracion, división)
print(resultado)


                        #2. obtenerSuma################################################

def obtenerSuma(mat):

    n = len(mat)
    sums = [0] * (2*n - 1)  # Lista para almacenar las sumas de las diagonales
    
    for i in range(n):
        for j in range(n):
            suma = 0
            for k in range(n):
                for l in range(n):
                    if k + l == i + j:
                        suma += mat[k][l]
            sums[i + j] = suma  # Almacena la suma en la posición correspondiente en la lista de sumas
            
    return sums

# Ejemplo de uso
mat = [[10, 6, 5],
       [14, 30, 92],
       [12, 45, 58]]

print(obtenerSuma(mat))


                        #3. obtenerMayorPosicion#######################################

def obtenerMayorPosicion(cad1, cad2):

  # Inicializar diccionario con valores en -1
  resultado = {}
  for char in cad2: 
    resultado[char] = -1
  
  # Recorrer cad1 y actualizar posición de última ocurrencia
  for indice, char in enumerate(cad1):
    if char in cad2:
      resultado[char] = indice

  return resultado

# Ejemplo  

frase1 = "mi corazon encantado vibra por el polvo de esperanza y magia!!"
frase2 = "za!em iolpx"

posiciones = obtenerMayorPosicion(frase1, frase2)

print(posiciones)


                        #5. mostrarDivisores###########################################

def mostrarDivisores(n):
    """
    Muestra los divisores de un número dado y calcula su suma.

    Parámetros:
    n (int): El número del cual se quieren encontrar los divisores.

    """
    print("Divisores número {}:".format(n))  

    suma = 0
    for i in range(1, n):
        if n % i == 0:
            print("--> {}, ".format(i))
            suma += i

    # Agrega el propio número 'n' como divisor y suma
    if n % n == 0:
        print("--> {}".format(n))
        suma += n

    print("\nSuma de los divisores del número {}: {}".format(n, suma))

# Llamada a la función para mostrar divisores y calcular la suma en este caso para el número 100
mostrarDivisores(100)
