# Trie, Data Structure

*Implementación, resultados y artículo científico de estructura de datos "Trie" (Prefix Tree).*

![Screenshot 2024-10-07 at 11 36 10 AM](https://github.com/user-attachments/assets/b4b599f7-c661-4f0b-a323-cab8579b401f)

El desarrollo de esta estructura es en **C++**.

La forma en que trabaja esta estructura es guardando palabras (*strings*),cada caracter de esta palabra será considerado un ***nodo***, generando así un camino desde la raíz (***root***) hasta el último caracter de la palabra guardada, marcando al último nodo como termino de esta palabra.

***Representación Visual***

![Screenshot 2024-10-07 at 11 42 51 AM](https://github.com/user-attachments/assets/78dff416-38dc-4002-a752-f27af7c8d514)

**Características**, El "*Trie*" es una estructura de tipo arbol, eficiente para el guardado de cadenas de caracteres. Esta estructura trabaja con un ***alfabeto finito***, esto quiere decir que cada nodo del arbol tendrá como mucho un numero de hijos igual al numero de llaves dentro de este alfabeto, debido a esto, la estructura **NO** es eficiente en termino de memoria.

![Screenshot 2024-10-07 at 11 51 03 AM](https://github.com/user-attachments/assets/4323c741-3bfe-47d7-a9de-7722cbdda47f)

***Operaciones clave de la estructura***

***Inserción*** *O(K)* *(K siendo el largo de la cadena)*.

***Búsqueda***  *O(K)* *(K siendo el largo de la cadena)*.

***Eliminación*** *O(K)* *(K siendo el largo de la cadena)*.
