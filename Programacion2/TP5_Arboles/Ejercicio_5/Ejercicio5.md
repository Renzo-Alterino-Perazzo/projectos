## Ejercicio 5

## a. Mostrar el resultado de insertar 5, 3, 8, 15, 9, 13, 6, 11, 10 y 12 en un árbol AVL inicialmente vacío (indicando las rotaciones realizadas)



Inserto 5:
```text
  5
```
Inserto 3:
```text
  5
 /
3
```
Inserto 8:
```text
  5
 / \
3   8
```
Inserto 15:
```text
  5
 / \
3   8
     \
     15
```
Inserto 9:
```text
  5
 / \
3   8
     \
     15
     /
    9
```
Hay desbalanceo por derecha en el nodo 8 y en la raíz.
Realizo una rotación doble izquierda-derecha:
```text
  5
 / \
3   9
   / \
  8  15
```
Inserto 13:
```text
  5
 / \
3   9
   / \
  8  15
     /
    13
```
Hay desbalanceo por derecha en la raíz.
Realizo una rotación doble izquierda-derecha:
```text
    8
   / \
  5   9
 /     \
3      15
       /
      13
```
Hay desbalanceo por derecha en el nodo 9.
Realizo una rotación doble izquierda-derecha:
```text
     8
    / \
   /   \
  5    13
 /     / \
3     9  15
```
Inserto 6:
```text
      8
     / \
    /   \
   /     \
  5      13
 / \     / \
3   6   9  15
```
Inserto 11:
```text
      8
     / \
    /   \
   /     \
  5      13
 / \     / \
3   6   9  15
         \
         11
```
Inserto 10:
```text
      8
     / \
    /   \
   /     \
  5      13
 / \     / \
3   6   9  15
         \
         11
         /
        10
```
Hay desbalanceo por derecha tanto en la raíz como en el nodo 9,
y desbalanceo por izquierda en el nodo 13.
Realizo una rotación doble izquierda-derecha en el nodo 9:
```text
      8
     / \
    /   \
   /     \
  5      13
 / \     / \
3   6   /   \
       10   15
      / \
     9  11
```
Inserto 12:
```text
      8
     / \
    /   \
   /     \
  5      13
 / \     / \
3   6   /   \
       10   15
      / \
     9  11
          \
          12
```
Hay desbalanceo por derecha en la raíz y desbalanceo por izquierda en el nodo 13.
Realizo una rotación doble derecha-izquierda en el nodo 13:
```text
      8
     / \
    /   \
   /     \
  5      11
 / \     / \
3   6   /   \
       10   13
      /     / \
     9     /   \
          12   15
```
## b. Dibujar el árbol AVL que resulta de realizar las siguientes inserciones: 1, 11, 10, 12, 2, 8, 4, 1, 3. A continuación, eliminar los elementos: 18, 14, 17

Inserto 1:
```text
  1
```
Inserto 11:
```text
  1
   \
   11
```
Inserto 10:
```text
  1
   \
   11
   /
  10
```
Hay desbalanceo por derecha en la raíz.
Realizo una rotación doble izquierda-derecha:
```text
 10
 / \
1  11
```
Inserto 12:
```text
 10
 / \
1  11
     \
     12
```
Inserto 2:
```text
  10
  / \
 /   \
1    11
 \     \
  2    12
```
Inserto 8:
```text
  10
  / \
 /   \
1    11
 \     \
  2    12
   \
    8
```
Hay desbalanceo por derecha en el nodo 1.
Realizo una rotación simple izquierda:
```text
    10
    / \
   /   \
  2    11
 / \     \
1   8    12
```
Inserto 4:
```text
    10
    / \
   /   \
  2    11
 / \     \
1   8    12
   /
  4
```
Inserto 1:
No se puede porque el 1 ya se encuentra en el árbol

Inserto 3:
```text
    10
    / \
   /   \
  2    11
 / \     \
1   8    12
   /
  4
 /
3
```
Hay desbalanceo por izquierda tanto en el nodo 8 como en la raíz.
Realizo una rotación simple derecha en el nodo 8:
```text
    10
    / \
   /   \
  2    11
 / \     \
1   4    12
   / \
  3   8
```
Ahora ya no hay desbalanceo por izquierda en la raíz.

Elimino los elementos 18, 14 y 17:
No se puede ya que no se encuentran en el árbol.


## c. Realizar las operaciones que se detallan, marcando para cada nodo su factor de equilibrio en cada momento. En caso de producirse desequilibrio, indicar la causa y explicar con detalle qué operación se ha utilizado para resolverlo. Inserciones: 5, 11, 2, 19, 9, 10, 14, 6 y 15. Eliminaciones: 14, 9 y 10.

Inserto 5:
```text
  5                 FE(5) = 0
```
Inserto 11:
```text
  5                 FE(5) = 1
   \
   11               FE(11) = 0
```
Inserto 2:
```text
  5                 FE(5) = 0
 / \
2  11               FE(2) = 0; FE(11) = 0
```
Inserto 19:
```text
  5                 FE(5) = 1
 / \
2  11               FE(2) = 0; FE(11) = 1
     \
     19             FE(19) = 0
```
Inserto 9:
```text
  5                 FE(5) = 1
 / \
2  11               FE(2) = 0; FE(11) = 0
   / \
  9  19             FE(9) = 0; FE(19) = 0
```
Inserto 10:
```text
  5                 FE(5) = 2
 / \
2  11               FE(2) = 0; FE(11) = -1
   / \
  9  19             FE(9) = 1; FE(19) = 0
   \
   10               FE(10) = 0
```
Hay desbalanceo por derecha en la raíz.
Realizo una rotación doble izquierda-derecha:
```text
     9              FE(9) = 0
    / \
   /   \
  5    11           FE(5) = -1; FE(11) = 0
 /     / \
2     /   \         FE(2) = 0
     10   19        FE(10) = 0; FE(19) = 0
```
Inserto 14:
```text
     9              FE(9) = 1
    / \
   /   \
  5    11           FE(5) = -1; FE(11) = 1
 /     / \
2     /   \         FE(2) = 0
     10   19        FE(10) = 0; FE(19) = -1
          /
         14         FE(14) = 0;
```
Inserto 6:
```text
      9             FE(9) = 1
     / \
    /   \
   /     \
  5      11         FE(5) = 0; FE(11) = 1
 / \     / \
2   6   /   \       FE(2) = 0; FE(6) = 0
       10   19      FE(10) = 0; FE(19) = -1
            /
           14       FE(14) = 0
```
Inserto 15:
```text
      9             FE(9) = 2
     / \
    /   \
   /     \
  5      11         FE(5) = 0; FE(11) = 2
 / \     / \
2   6   /   \       FE(2) = 0; FE(6) = 0
       10   19      FE(10) = 0; FE(19) = -2
            /
           14       FE(14) = 1
            \
            15      FE(15) = 0
```
Hay desbalanceo por derecha tanto en la raíz como en el nodo 11,
y desbalanceo por izquierda en el nodo 19.
La manera más simple de solucionar los desbalanceos es balancear el subárbol del nodo 19.
Realizo una rotación doble derecha-izquierda en el nodo 19:
```text
      9             FE(9) = 1
     / \
    /   \
   /     \
  5      11         FE(5) = 0; FE(11) = 1
 / \     / \
2   6   /   \       FE(2) = 0; FE(6) = 0
       10   15      FE(10) = 0; FE(15) = 0
            / \
           /   \
          14   19   FE(14) = 0; FE(19) = 0
```
Elimino 14:
```text
      9             FE(9) = 1
     / \   
    /   \
   /     \
  5      11         FE(5) = 0; FE(11) = 1
 / \     / \
2   6   /   \       FE(2) = 0; FE(6) = 0
       10   15      FE(10) = 0; FE(15) = 1
              \
              19    FE(19) = 0
```
Como el 14 era un nodo hoja, puedo eliminarlo fácilmente, 
y su eliminación no produce ningún desequilibrio.

Elimino 9:
Como la raíz tiene dos hijos, no puedo eliminarlo tan fácil, entonces tengo que reemplazarlo
por el nodo con la clave más chica de su subárbol derecho, en este caso sería el 10.
```text
    10              FE(10) = 1
    / \
   /   \
  5    11           FE(5) = 0; FE(11) = 2
 / \     \
2   6    15         FE(2) = 0; FE(6) = 0; FE(15) = 1
           \
           19       FE(19) = 0
```
Hay desbalanceo por derecha en el nodo 11.
Realizo una rotación simple izquierda:
```text
     10             FE(10) = 0
     / \
    /   \
   /     \
  5      15         FE(5) = 0; FE(15) = 0
 / \     / \
2   6   /   \       FE(2) = 0; FE(6) = 0
       11   19      FE(11) = 0; FE(19) = 0
```
Elimino 10:
Se produce el mismo caso que en la eliminación anterior. Busco el menor del subárbol
de la raíz para reemplazarlo, en este caso sería 11.
```text
    11              FE(11) = 0
    / \
   /   \
  5    15           FE(5) = 0; FE(15) = 1
 / \     \
2   6    19         FE(2) = 0; FE(6) = 0; FE(19) = 0
```
