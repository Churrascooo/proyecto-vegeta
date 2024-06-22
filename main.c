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
//-----------------------------------------------------------------------
void mostrarMenuPrincipal()
{
  puts("----------------------------------------------");
  puts("===  Bienvenido a Vegeta Makes Everything  ===");
  puts("----------------------------------------------\n");

  puts("1) Búsqueda de productos");
  puts("2) Carrito de compras");
  puts("3) Eliminar del carrito de compras");
  puts("4) Comprobar compatibilidad");
  puts("5) Salir del programa\n");
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
int isEqualStr(void *clave1, void *clave2) {
  return strcmp((char *)clave1, (char *)clave2) == 0;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void elegirGrafica(Map *componentes, Map *carritoCompras, ContadoresComp *contadores)
{
  //Comprobamos que no haya una tarjeta en el carrito
  MapPair *pairCar = map_search(carritoCompras, "Gráfica");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes una Tarjeta Gráfica en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();
  //Busca la lista de gráficas disponibles en 'componentes'
  int opcionGraf;
  MapPair *pairGraf = map_search(componentes, "Gráfica");
  if (pairGraf == NULL || pairGraf->value == NULL) {
    puts("No hay Tarjetas Gráficas disponibles");
    return;
  }

  List *listaGraficas = (List *)pairGraf->value;
  mostrarGraf(listaGraficas);
  printf("Escoge una Tarjeta Gráfica: ");
  scanf("%i", &opcionGraf);

  if (opcionGraf == 5) {
    puts("\nVolviendo al Menú Principal.");
    return;
  }

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
  contadores->contGraf++;
  contadores->contadorTotal++;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void elegirProce(Map *componentes, Map *carritoCompras, ContadoresComp *contadores)
{
  //Comprobamos que no haya una tarjeta en el carrito
  MapPair *pairCar = map_search(carritoCompras, "Procesador");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes un Procesador en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();
  //Busca la lista de procesadores disponibles en 'componentes'
  int opcionProce;
  MapPair *pairProce = map_search(componentes, "Procesador");
  if (pairProce == NULL || pairProce->value == NULL) {
    puts("No hay Procesadores disponibles");
    return;
  }

  List *listaProcesadores = (List *)pairProce->value;
  mostrarProce(listaProcesadores);
  printf("Escoge un Procesador: ");
  scanf("%i", &opcionProce);

  if (opcionProce == 5) {
    puts("\nVolviendo al Menú Principal.");
    return;
  }

  //Busca la gráfica elegida por el usuario y la agrega a su carrito
  Procesador *procesador = (Procesador *)list_first(listaProcesadores);
  for (int i = 1; i < opcionProce; i++)
  {
    procesador = (Procesador *)list_next(listaProcesadores); 
    if (procesador == NULL) {
      puts("Opción inválida");
      return;
    }
  }

  pairCar->value = (void *)procesador;
  printf("\n%s ha sido agregada correctamente a tu carrito!\n\n", procesador->modelo);
  contadores->contProce++;
  contadores->contadorTotal++;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void elegirTarjetaMadre(Map *componentes, Map *carritoCompras, ContadoresComp *contadores)
{
  //Comprobamos que no haya una tarjeta en el carrito
  
  MapPair *pairCar = map_search(carritoCompras, "Tarjeta Madre");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes una Tarjeta Madre en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }
  
  limpiarPantalla();
  
  int opcionTarjetaMadre;
  MapPair *pairTarjetaMadre = map_search(componentes, "Tarjeta Madre");
  if (pairTarjetaMadre == NULL || pairTarjetaMadre->value == NULL) {
    puts("No hay Tarjetas Maadres disponibles");
    return;
  }

  List *listaTarjetasMadre = (List *)pairTarjetaMadre->value;
  mostrarTarjetaMadre(listaTarjetasMadre);
  printf("Escoge una Tarjeta Madre: ");
  scanf("%i", &opcionTarjetaMadre);

  if (opcionTarjetaMadre == 5) {
    puts("\nVolviendo al Menú Principal.");
    return;
  }
  
  //Busca la gráfica elegida por el usuario y la agrega a su carrito
  TarjetaMadre *tarjetaMadre = (TarjetaMadre *)list_first(listaTarjetasMadre);
  for (int i = 1; i < opcionTarjetaMadre; i++)
  {
    tarjetaMadre = (TarjetaMadre *)list_next(listaTarjetasMadre); 
    if (tarjetaMadre == NULL) {
      puts("Opción inválida");
      return;
    }
  }

  pairCar->value = (void *)tarjetaMadre;
  printf("\n%s ha sido agregada correctamente a tu carrito!\n\n", tarjetaMadre->modelo);
  contadores->contTarj++;
  contadores->contadorTotal++;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void elegirMemoriaRAM(Map *componentes, Map *carritoCompras, ContadoresComp *contadores)
{
  //Comprobamos que no haya una memoria Ram en el carrito

  MapPair *pairCar = map_search(carritoCompras, "RAM");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes una Memoria RAM en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();

  int opcionRam;
  MapPair *pairRam = map_search(componentes, "RAM");
  if (pairRam == NULL || pairRam->value == NULL) {
    puts("No hay Memorias RAM disponibles");
    return;
  }

  List *listaMemoriasRam = (List *)pairRam->value;
  mostrarRam(listaMemoriasRam);
  printf("Escoge una Memoria RAM: ");
  scanf("%i", &opcionRam);

  if (opcionRam == 5) {
    puts("\nVolviendo al Menú Principal.");
    return;
  }

  //Busca la memoria Ram elegida por el usuario y la agrega a su carrito
  MemoriaRAM *memoriaRam = (MemoriaRAM  *)list_first(listaMemoriasRam);
  for (int i = 1; i < opcionRam; i++)
  {
    memoriaRam = (MemoriaRAM *)list_next(listaMemoriasRam); 
    if (memoriaRam == NULL) {
      puts("Opción inválida");
      return;
    }
  }

  pairCar->value = (void *)memoriaRam;
  printf("\n%s ha sido agregada correctamente a tu carrito!\n\n", memoriaRam->modelo);
  contadores->contRAM++;
  contadores->contadorTotal++;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void elegirAlmacenamiento(Map *componentes, Map *carritoCompras, ContadoresComp *contadores)
{
  //Comprobamos que no haya una unidad de almacenamiento en el carrito

  MapPair *pairCar = map_search(carritoCompras, "Almacenamiento");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes una Unidad de Almacenamiento en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();

  int opcionAlmacenamiento;
  MapPair *pairAlmacenamiento = map_search(componentes, "Almacenamiento");
  if (pairAlmacenamiento == NULL || pairAlmacenamiento->value == NULL) {
    puts("No hay Unidades de Almacenamiento disponibles");
    return;
  }

  List *listaUnidadesAlmacenamiento = (List *)pairAlmacenamiento->value;
  mostrarAlmacenamiento(listaUnidadesAlmacenamiento);
  printf("Escoge una Unidad de Almacenamiento: ");
  scanf("%i", &opcionAlmacenamiento);

  if (opcionAlmacenamiento == 5) {
    puts("\nVolviendo al Menú Principal.");
    return;
  }

  //Busca la unidad de almacenamiento elegida por el usuario y la agrega a su carrito
  Almacenamiento *unidadAlmacenamiento = (Almacenamiento  *)list_first(listaUnidadesAlmacenamiento);
  for (int i = 1; i < opcionAlmacenamiento; i++)
  {
    unidadAlmacenamiento = (Almacenamiento *)list_next(listaUnidadesAlmacenamiento); 
    if (unidadAlmacenamiento == NULL) {
      puts("Opción inválida");
      return;
    }
  }

  pairCar->value = (void *)unidadAlmacenamiento;
  printf("\n%s ha sido agregada correctamente a tu carrito!\n\n", unidadAlmacenamiento->modelo);
  contadores->contAlmacenamiento++;
  contadores->contadorTotal++;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void elegirFuentePoder(Map *componentes, Map *carritoCompras, ContadoresComp *contadores)
{
  //Comprobamos que no haya una fuente de poder en el carrito

  MapPair *pairCar = map_search(carritoCompras, "Fuente de Poder");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes una Fuente de Poder en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();

  int opcionFuentePoder;
  MapPair *pairFuentePoder = map_search(componentes, "Fuente de Poder");
  if (pairFuentePoder == NULL || pairFuentePoder->value == NULL) {
    puts("No hay Fuentes de Poder disponibles");
    return;
  }

  List *listaFuentesPoder = (List *)pairFuentePoder->value;
  mostrarFuentePoder(listaFuentesPoder);
  printf("Escoge una Fuente de Poder: ");
  scanf("%i", &opcionFuentePoder);

  if (opcionFuentePoder == 5) {
    puts("\nVolviendo al Menú Principal.");
    return;
  }

  //Busca la fuente de poder elegida por el usuario y la agrega a su carrito
  FuentePoder *fuentePoder = (FuentePoder  *)list_first(listaFuentesPoder);
  for (int i = 1; i < opcionFuentePoder; i++)
  {
    fuentePoder = (FuentePoder *)list_next(listaFuentesPoder); 
    if (fuentePoder == NULL) {
      puts("Opción inválida");
      return;
    }
  }

  pairCar->value = (void *)fuentePoder;
  printf("\n%s ha sido agregada correctamente a tu carrito!\n\n", fuentePoder->modelo);
  contadores->contFuente++;
  contadores->contadorTotal++;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void escogerComponente(Map *componentes, Map *carrito, ContadoresComp *contadores)
{
  char opcionComponente;
  puts("Escoge el componente que deseas agregar al carrito:\n");
  puts("1. Gráfica");
  puts("2. Procesador");
  puts("3. Tarjeta Madre");
  puts("4. Memoria RAM");
  puts("5. Almacenamiento");
  puts("6. Fuente de Poder");
  puts("7. Cancelar Operación\n");
  do
  {
    printf("Ingrese su opción: ");
    scanf(" %c", &opcionComponente);

    switch(opcionComponente)
    {
      case '1':
        elegirGrafica(componentes, carrito, contadores);
        return;
      case '2':
        elegirProce(componentes, carrito, contadores);
        return;
      case '3':
        elegirTarjetaMadre(componentes, carrito, contadores);
        return;
      case '4':
        elegirMemoriaRAM(componentes, carrito, contadores);
        return;
      case '5':  
        elegirAlmacenamiento(componentes, carrito, contadores);
        return;
      case '6':
        elegirFuentePoder(componentes, carrito, contadores);
        return;  
      case '7':
        puts("\nVolviendo al Menú Principal.");
        return;
    } 
    limpiarPantalla();
  } while (opcionComponente != '7');
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void mostrarCarro(Map *carritoCompras, ContadoresComp *contadores)
{
  puts("Tu carrito de compras:");
  puts("--------------------------------------------");
  
  MapPair *pairCar = map_search(carritoCompras, "Gráfica");
  if (pairCar->value != NULL)
  {
    Grafica *grafica = (Grafica *)pairCar->value;
    puts("Tarjeta Gráfica:\n");
    printf("Modelo: %s\n", grafica->modelo);
    printf("Memoria: %d GB\n", grafica->memoria);
    printf("Tipo de Memoria: GDDR%d\n", grafica->gddr);
    printf("Consumo: %dW\n", grafica->consumo);
    printf("Gama: %s\n", grafica->gama);
    puts("--------------------------------------------");
  }
  
  pairCar = map_search(carritoCompras, "Procesador");
  if (pairCar->value != NULL)
  {
    Procesador *procesador = (Procesador *)pairCar->value;
    puts("Procesador:\n");
    printf("Modelo: %s\n", procesador->modelo);
    printf("Marca: %s\n", procesador->marca);
    printf("Nucleos: %d\n", procesador->nucleos);
    printf("Hilos: %d\n", procesador->hilos);
    printf("Frecuencia: %dMHz\n", procesador->frecuenciaMin);
    printf("Gama: %s\n", procesador->gama);
    puts("--------------------------------------------");
  }

  pairCar = map_search(carritoCompras, "Tarjeta Madre");
  if (pairCar->value != NULL)
  {
    TarjetaMadre *tarjetaMadre = (TarjetaMadre *)pairCar->value;
    puts("Tarjeta Madre:\n");
    printf("Modelo: %s\n", tarjetaMadre->modelo);
    printf("Marca Compatible: %s\n", tarjetaMadre->marcaProce);
    printf("%s\n", tarjetaMadre->socket);
    printf("Puertos NVMe: %d\n", tarjetaMadre->nvme);
    printf("Compatible con %s\n", tarjetaMadre->ddrCom);
    puts("--------------------------------------------");
  }

  pairCar = map_search(carritoCompras, "RAM");
  if (pairCar->value != NULL)
  {
    MemoriaRAM *memoriaRam = (MemoriaRAM *)pairCar->value;
    puts("Memoria Ram:\n");
    printf("Modelo: %s\n", memoriaRam->modelo);
    printf("Cantidad de memoria: %i gb\n", memoriaRam->memoria);
    printf("Tipo de memoria: %s\n", memoriaRam->ddr);
    printf("Frecuencia: %i mhz\n", memoriaRam->frecuencia); 
    puts("--------------------------------------------");
  }

  pairCar = map_search(carritoCompras, "Almacenamiento");
  if (pairCar->value != NULL)
  {
    Almacenamiento *unidadAlmacenamiento = (Almacenamiento *)pairCar->value;
    puts("Unidad de Almacenamiento:\n");
    printf("Modelo: %s\n", unidadAlmacenamiento->modelo);
    printf("Velocidad de lectura: %i mb/s\n", unidadAlmacenamiento->lectura);
    printf("Velocidad de escritura: %i mb/s\n", unidadAlmacenamiento->escritura);
    printf("Espacio de almacenamiento: %i gb\n", unidadAlmacenamiento->espacio);  
    printf("Tipo de SSD M2: %s\n", unidadAlmacenamiento->tipo); 
    puts("--------------------------------------------");
  }

  pairCar = map_search(carritoCompras, "Fuente de Poder");
  if (pairCar->value != NULL)
  {
    FuentePoder *fuentePoder = (FuentePoder *)pairCar->value;
    puts("Fuente de Poder:\n");
    printf("Modelo: %s\n", fuentePoder->modelo);
    printf("Consumo de energía: %i watts\n", fuentePoder->energia);
    printf("Certificación: %s\n", fuentePoder->calidad);
    puts("--------------------------------------------");
  }

  if (contadores->contadorTotal == 0)
  {
    puts("No hay nada en tu carrito!");
    puts("--------------------------------------------");
    return;
  }
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void eliminarProducto(Map *carritoCompras, ContadoresComp *contadores)
{
  int opcionBorrar;

  if(contadores->contadorTotal == 0){
    puts("--------------------------------");
    puts("No hay nada en tu carrito!");
    puts("--------------------------------");
    return;
  }
  
  do
  {
    puts("Escoge el componente que deseas eliminar del carrito:\n");
    puts("1. Gráfica");
    puts("2. Procesador");
    puts("3. Tarjeta Madre");
    puts("4. Memoria RAM");
    puts("5. Almacenamiento");
    puts("6. Fuente de Poder");
    puts("7. Salir");
    printf("\n");
    printf("Ingrese su opción: ");
    scanf(" %d", &opcionBorrar);

    MapPair *pairCar;
    switch(opcionBorrar)
    {
      case 1:
        limpiarPantalla();
        pairCar = map_search(carritoCompras, "Gráfica");
        if (pairCar->value == NULL)
        {
          puts("No hay Tarjeta Gráfica en el carrito.\n");
        }
        else
        {
          pairCar->value = NULL;
          puts("La Tarjeta Gráfica ha sido eliminada correctamente del carrito.\n");
          contadores->contGraf--;
          contadores->contadorTotal--;
          return;
        }
        break;
      
      case 2:
        limpiarPantalla();
        pairCar = map_search(carritoCompras, "Procesador");
        if (pairCar == NULL || pairCar->value == NULL)
        {
          puts("No hay Procesador en el carrito.\n");
        }
        else
        {
          pairCar->value = NULL;
          puts("El Procesador ha sido eliminado correctamente del carrito.\n");
          contadores->contProce--;
          contadores->contadorTotal--;
          return;
        }
        break;
      
      case 3:
        limpiarPantalla();
        pairCar = map_search(carritoCompras, "Tarjeta Madre");
        if (pairCar == NULL || pairCar->value == NULL)
        {
          puts("No hay Tarjeta Madre en el carrito.\n");
        }
        else
        {
          pairCar->value = NULL;;
          puts("La Tarjeta Madre ha sido eliminada del carrito.\n");
          contadores->contTarj--;
          contadores->contadorTotal--;
          return;
        }
        break;
      
      case 4:
        limpiarPantalla();
        pairCar = map_search(carritoCompras, "RAM");
        if (pairCar == NULL || pairCar->value == NULL)
        {
          puts("No hay RAM en el carrito.\n");
        }
        else
        {
          pairCar->value = NULL;
          puts("La RAM ha sido eliminada del carrito.\n");
          contadores->contRAM--;
          contadores->contadorTotal--;
          return;
        }
        break;
      
      case 5:
        limpiarPantalla();
        pairCar = map_search(carritoCompras, "Almacenamiento");
        if (pairCar == NULL || pairCar->value == NULL)
        {
          puts("No hay Almacenamiento en el carrito.\n");
        }
        else
        {
          pairCar->value = NULL;
          puts("El Almacenamiento ha sido eliminado del carrito.\n");
          contadores->contAlmacenamiento--;
          contadores->contadorTotal--;
          return;
        }
        break;
      
      case 6:
        limpiarPantalla();
        pairCar = map_search(carritoCompras, "Fuente de Poder");
        if (pairCar == NULL || pairCar->value == NULL)
        {
          puts("No hay Fuente de Poder en el carrito.\n");
        }
        else
        {
          pairCar->value = NULL;
          puts("La Fuente de Poder ha sido eliminada del carrito.\n");
          contadores->contFuente--;
          contadores->contadorTotal--;
          return;
        }
        break;
      
      case 7:
        puts("Volviendo al menú principal...");
        break;
      
      default:
        puts("Opción inválida");
        break;
    }
  presioneTeclaParaContinuar();
  limpiarPantalla();
  } while (opcionBorrar != 7);

  return;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*
void comprobacionCompatibilidad(Map *carritoCompras, ContadoresComp *contadores){
  limpiarPantalla();
  puts("Comprobando compatibilidad...");
  puts("--------------------------------------------");
  if(contadores->contadorTotal == 0){
    puts("No hay nada en tu carrito!");
    puts("--------------------------------------------");
    return;
  }
  else{
    
  }

  return;
}
*/
//----------------------------------------------------------------------
int main(void)
{
  Map *componentes = map_create(isEqualStr); //Contiene todos los productos
  Map *carritoCompras = map_create(isEqualStr); //Contiene por cada clave un producto
  ContadoresComp *contadores = (ContadoresComp *)malloc(sizeof(ContadoresComp));
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
        escogerComponente(componentes, carritoCompras, contadores);
        break;
      case '2':
        limpiarPantalla();
        mostrarCarro(carritoCompras, contadores);
        break;
      case '3':
        limpiarPantalla();
        eliminarProducto(carritoCompras, contadores);
        break;
      case '4':
        //comprobacionCompatibilidad(carritoCompras, contadores);
        break;
      case '5':
        puts("\nSaliendo del programa...");
        puts("Gracias por usar Vegeta Makes Everything :]");
        break;
      default:
        puts("Opción inválida, por favor ingrese una correcta.");
        break;
    }
    presioneTeclaParaContinuar();
    limpiarPantalla();
    
  } while (opcion != '5');
    
  return 0;
}