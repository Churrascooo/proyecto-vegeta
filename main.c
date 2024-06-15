#include "tdas/extra.h"
#include "tdas/list.h"
#include "tdas/map.h"
#include "tdas/componentes.h" //Carpeta con estructuras y funciones para mostrar componentes
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------- Función para el menú principal -----------------------
void mostrarMenuPrincipal()
{
  puts("----------------------------------------------");
  puts("===  Bienvenido a Vegeta Makes Everything  ===");
  puts("----------------------------------------------");
  puts("\n");

  puts("1) Búsqueda de productos");
  puts("2) Carrito de compras");
  puts("3) Eliminar del carrito de compras");
  puts("4) Comprobar compatibilidad");
  puts("5) Salir del programa");
  puts("\n");
}

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int isEqualStr(void *clave1, void *clave2) {
  return strcmp((char *)clave1, (char *)clave2) == 0;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void elegirGrafica(Map *componentes, Map *carritoCompras)
{
  //Comprobamos que no haya una tarjeta en el carrito
  MapPair *pairCar = map_search(carritoCompras, "Gráfica");
  if (pairCar->value != NULL)
  {
    puts("Ya tienes una tarjeta grafica en tu carrito!");
    return;
  }

  //Busca la lista de gráficas disponibles en 'componentes'
  int opcionGraf;
  MapPair *pairGraf = map_search(componentes, "Gráfica");
  if (pairGraf == NULL || pairGraf->value == NULL) {
    puts("No hay tarjetas graficas disponibles");
    return;
  }

  List *listaGraficas = (List *)pairGraf->value;
  mostrarGraf(listaGraficas);
  printf("Escoge una gráfica: ");
  scanf("%i", &opcionGraf);

  //Busca la gráfica elegida por el usuario y la agrega a su carrito
  Grafica *grafica = (Grafica *)list_first(listaGraficas);
  for (int i = 1; i < opcionGraf; i++)
  {
    grafica = (Grafica *)list_next(listaGraficas); 
    if (grafica == NULL) {
      puts("Opción inválida");
      return;
    }
  }

  pairCar->value = (void *)grafica;
  printf("\n%s ha sido agregada correctamente a tu carrito!\n\n", grafica->modelo);
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void escogerComponente(Map *componentes, Map *carrito)
{
  char opcionComponente;
  puts("Escoge el componente que deseas agregar al carrito:");
  puts("1. Gráfica");
  puts("2. Salir");
  do
  {
    printf("Ingrese su opción: ");
    scanf(" %c", &opcionComponente);

    switch(opcionComponente)
    {
      case '1':
        limpiarPantalla();
        elegirGrafica(componentes, carrito);
        return;
      case '2':
        puts("Saliendo al Menú Principal");
        return;
      //AGREGAR EL RESTO DE COMPONENTES COMO OPCIONES
    } 
    limpiarPantalla();
  } while (opcionComponente != '2');

}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void)
{
  Map *componentes = map_create(isEqualStr); //Contiene todos los productos
  Map *carritoCompras = map_create(isEqualStr); //Contiene por cada clave un producto
  cargarComponentes(componentes, carritoCompras);
  
  char opcion;
  do
  {
    mostrarMenuPrincipal();
    printf("Ingrese la opción que desea: ");
    scanf(" %c", &opcion);

    switch(opcion)
    {
      case '1':
        limpiarPantalla();
        escogerComponente(componentes, carritoCompras);
        break;
      case '2':
        //carritoDeCompras();
        break;
      case '3':
        //eliminarProducto();
        break;
      case '4':
        //comprobacionCompatibilidad();
        break;
      case '5':
        puts("Saliendo del programa...");
        puts("Gracias por usar Vegeta Makes Everything :]");
        break;
      default:
        puts("Opcióno inválida, por favor ingrese una correcta.");
        break;
    }
    presioneTeclaParaContinuar();
    limpiarPantalla();
    
  } while (opcion != '5');
    
  return 0;
}