#include <stdio.h>
#include "tdas/map.h"
#include "tdas/list.h"

void mostrarMenuPrincipal()
{
  puts("----------------------------------------------");
  puts("=== Bienvenidos a Vegeta Makes Everything! ===");
  puts("----------------------------------------------");
  puts("\n");

  puts("1) Búsqueda de productos");
  puts("2) Carrito de compras");
  puts("3) Eliminar del carrito de compras");
  puts("4) Comprobar compatibilidad");
  puts("5) Salir del programa");
  puts("\n");
}


int main(void)
{
  char opcion;

  do
  {
    mostrarMenuPrincipal();
    printf("Ingrese la opción que desea: ");
    scanf(" %c", &opcion);

    switch(opcion)
    {
      case '1':
        //busquedaProducto();
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
    
  } while (opcion != '5');
    
  return 0;
}