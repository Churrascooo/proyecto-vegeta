# Aplicación Vegeta Makes Everything

Vegeta Makes Everything es una aplicación que se dedica a la venta de componentes de pc. Existe una variedad de 6 componentes, los cuáles son: Tarjeta gráfica, procesador, tarjeta madre, memoria ram, almacenamiento y fuente de poder.
A continuación enseñaremos más a detalle sobre el programa.

## Como compilar y ejecutar el programa
Para ejecutar el programa lo que deberá hacer es lo siguiente:

- Primero, visite Repl.it
- Crea una cuenta en caso de que no tengas, en caso contrario, inicia sesión.
- Pega el siguiente link https://replit.com/join/rwxinojdml-arielcarrascos
- Y luego ejecutar:

- Presione el botón "Run" verde que sale arriba, para compilar y ejecutar la aplicación.
  
## Funcionalidades
### Funcionando correctamente:
- La función **Búsqueda de productos**. Se encarga a la búsqueda entre los 6 productos que dispone la aplicación. El usuario se encargará en elegir el producto que desee, para así agregarlo a su carrito.
- La función **Carrito de compras**. Se dedica a mostrar los productos que el usuario ha agregado a su carrito de compras. Este mostrará el producto con sus respectivos datos.
- La función **Eliminar del carrito de compras**. Como dice su nombre, sirve para eliminar el producto que desee el usuario de su carrito de compras. Al seleccionar esta opción, el usuario deberá elegir un tipo de producto; en caso que tenga, se borarrá. En caso contrario, la aplicación le dirá que no ha agregado ningún producto al carrito.
- La función **Comprobar compatibilidad**. Lo que hace esta función es comprobar si existen compatibilidades entre los productos que ha seleccionado el usuario. Esto abrirá dos opciones: en caso que tenga compatibilidad, podrá confirmar la compra. En caso opuesto, el programa le dirá que no son compatibles, por lo que el usuario tendrá que seleccionar otro producto.

### Errores comúnes
- HAY QUE BUSCAR
- No es un error como tal, pero en "escoger un componente", poner un carácter (letra, etc) no hace nada.

### Cosas a mejorar:
- Mejorar la interfaz para que sea más agradable a la vista del usuario.

### Ejemplo de uso

Al correr el programa, se verá así:
````
----------------------------------------------
===  Bienvenido a Vegeta Makes Everything  ===
----------------------------------------------

1) Búsqueda de productos
2) Carrito de compras
3) Eliminar del carrito de compras
4) Comprobar compatibilidad
5) Salir del programa

Ingrese la opción que desea:
````
El primer paso es seleccionar la opción 1:
### Paso 1:
````
----------------------------------------------
===  Bienvenido a Vegeta Makes Everything  ===
----------------------------------------------

1) Búsqueda de productos
2) Carrito de compras
3) Eliminar del carrito de compras
4) Comprobar compatibilidad
5) Salir del programa

Ingrese la opción que desea: 1
````
Al seleccionar este paso, el programa pedirá que el usuario escoja un componente para agregar al carrito.
````
Escoge el componente que deseas agregar al carrito:

1. Gráfica
2. Procesador
3. Tarjeta Madre
4. Memoria RAM
5. Almacenamiento
6. Fuente de Poder
7. Cancelar Operación

Ingrese su opción: 1
````
Si el usuario, por ejemplo, elige la opción 1 (Gráfica), mostrará una lista con 4 opciones de dicho componente.
Asi se vería:
````
Lista Tarjetas Gráficas 

--------------------------------------------
1.-
Modelo: GTX 1060
Memoria: 3 GB
Tipo de Memoria: GDDR5
Consumo: 120W
Gama: Media
--------------------------------------------
2.-
Modelo: RTX 2060
Memoria: 6 GB
Tipo de Memoria: GDDR6
Consumo: 160W
Gama: Alta
--------------------------------------------
3.-
Modelo: GTX 1660
Memoria: 6 GB
Tipo de Memoria: GDDR6
Consumo: 125W
Gama: Media
--------------------------------------------
4.-
Modelo: GTX 1050
Memoria: 4 GB
Tipo de Memoria: GDDR5
Consumo: 80W
Gama: Baja
--------------------------------------------
5.- Cancelar Operación
--------------------------------------------

Escoge una Tarjeta Gráfica: 1
````
Al elegir una opción, la aplicación le dirá que se ha agregado a su carrito correctamente.
````
Escoge una Tarjeta Gráfica: 1

GTX 1060 ha sido agregada correctamente a tu carrito!

Presione una tecla para continuar...
````
### NOTA: El usuario puede elegir 1 producto de cada tipo. Para elegirlo, debe hacer lo mismo que se explicó en el paso anterior.

Supongamos que el usuario también eligió un procesador, como ejemplo, el procesador de la primera opción.
````
Escoge un Procesador: 1

i5-10600K ha sido agregada correctamente a tu carrito!

Presione una tecla para continuar...
````
### Paso 2:
El paso siguiente es usar la opción 2.
````
----------------------------------------------
===  Bienvenido a Vegeta Makes Everything  ===
----------------------------------------------

1) Búsqueda de productos
2) Carrito de compras
3) Eliminar del carrito de compras
4) Comprobar compatibilidad
5) Salir del programa

Ingrese la opción que desea: 2
````
El usuario podrá ver su carrito de compras con todos los productos que agregó desde la función 1. En base al ejemplo anterior, quedaría así:
````
Tu carrito de compras:
--------------------------------------------
Tarjeta Gráfica:

Modelo: GTX 1060
Memoria: 3 GB
Tipo de Memoria: GDDR5
Consumo: 120W
Gama: Media
--------------------------------------------
Procesador:

Modelo: i5-10600K
Marca: Intel
Nucleos: 6
Hilos: 12
Frecuencia: 2666MHz
Gama: Media
--------------------------------------------
Presione una tecla para continuar...
````
### Paso 3:
La función 3 (eliminar del carrito de compras) es opcional, puesto a que dependerá de si el usuario quiera eliminar un producto que seleccionó anteriormente.
Siguiendo con el ejemplo anterior, quedaría así:
````
----------------------------------------------
===  Bienvenido a Vegeta Makes Everything  ===
----------------------------------------------

1) Búsqueda de productos
2) Carrito de compras
3) Eliminar del carrito de compras
4) Comprobar compatibilidad
5) Salir del programa

Ingrese la opción que desea: 3
````
El usuario deberá escoger un componente que quiera eliminar. Supongamos que quiere eliminar el procesador.
````
Escoge el componente que deseas eliminar del carrito:

1. Gráfica
2. Procesador
3. Tarjeta Madre
4. Memoria RAM
5. Almacenamiento
6. Fuente de Poder
7. Salir
Ingrese su opción: 2
````
Luego de esto, saldrá el siguiente mensaje (en caso de que el usuario haya tenido un producto en su carrito)
````
El Procesador ha sido eliminado correctamente del carrito.

Presione una tecla para continuar...
````
### Paso 4:
El último paso es ver la compatibilidad de los productos seleccionados. La aplicación te mostrará si son compatibles o no.
En este ejemplo, volvimos a poner el procesador anterior, solo para mostrar como se vería un ejemplo de compatibilidad.
````
Comprobando compatibilidad...
--------------------------------------------
Tarjeta Gráfica:
La Tarjeta Gráfica no tiene incompatibilidades.
--------------------------------------------
Procesador:
El Procesador no tiene incompatibilidades.
--------------------------------------------

¡Tu carrito está completo y compatible!

Deseas confirmar la compra?
1) Confirmar Compra.
2) Seguir Comprando...
Ingrese su opción: 
````
Acá hay dos opciones. En caso de confirmar la compra, mostrará lo siguiente:
````
Compra confirmada.
El equipo de Vegeta Makes Everything está preparando tu pedido!
Gracias por comprar con nosotros <3
⢀⣀⡀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢿⣷⠀⠀⢀⣿⠇⠀⠀⣀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⣀⠀⠀⠀⣶⡆⠀⠀⠀⣀⡀⠀⠀
⠀⠈⣿⡆⠀⣼⡟⠀⣾⡿⠛⢻⣦⠀⣾⠟⠛⢿⣿⠀⣾⡟⠛⢻⣆⠛⣿⡟⠃⠼⠿⠛⢻⣷⠀
⠀⠀⠘⣷⣸⣿⠃⠀⣿⡿⠿⠿⠿⠇⣿⠀⠀⢸⣿⠰⣿⠿⠿⠿⠿⠀⣿⡇⠀⣴⣾⠿⢻⣿⠀
⠀⠀⠀⢹⣿⠇⠀⠀⠻⣷⣤⣴⠷⠀⢿⣧⣤⣿⣿⠀⠻⣧⣤⣴⠶⠀⢿⣧⡄⢿⣷⣤⣾⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣤⣤⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀
Presione una tecla para continuar...
````
En caso de seleccionar la opción 2 (seguir comprando) el programa te devolverá principal para que sigas usándolo.

Eso es todo, esperando que se haya entendido, te deseo mucha suerte utilizando el programa! :]