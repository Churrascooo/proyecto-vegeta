#include "tdas/extra.h" //Agregamos la carpeta de tdas extras
#include "tdas/list.h" //Agregamos la carpeta de tdas list
#include "tdas/map.h" //Agregamos la carpeta de tdas map
#include "tdas/componentes.h" //Carpeta con estructuras y funciones para mostrar componentes
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------- Función para el menú principal -----------------------
//-----------------------------------------------------------------------
/*Esta función es la del menú principal. El usuario tendrá la opción de elegir la operación que desee.*/
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
/*La función isEqualStr sirve para determinar si los carácteres son iguales.*/
int isEqualStr(void *clave1, void *clave2) {
  return strcmp((char *)clave1, (char *)clave2) == 0;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*La Función elegir gráfica se encarga en buscar en el mapa el valor "Gráfica". En caso que no hayan, printeará el mensaje correspondiente. En caso contrario, le dará la opción al usuario de escoger la gráfica que desea.*/
void elegirGrafica(Map *componentes, Map *carritoCompras)
{
  //Comprobamos que no haya una tarjeta en el carrito
  MapPair *pairCar = map_search(carritoCompras, "Gráfica");
  if (pairCar->value != NULL) //Si ya hay una gráfica en el carrito:
  {
    puts("\nYa tienes una Tarjeta Gráfica en tu carrito!\n"); //Printea el mensaje.
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();
  //Busca la lista de gráficas disponibles en 'componentes'
  int opcionGraf;
  MapPair *pairGraf = map_search(componentes, "Gráfica"); //Se hace la búsqueda del valor "Gráfica" en el mapa 'componentes'.
  if (pairGraf == NULL || pairGraf->value == NULL) { //En caso que no hayan gráficas disponibles:
    puts("No hay Tarjetas Gráficas disponibles"); //Printea este mensaje.
    return;
  }

  List *listaGraficas = (List *)pairGraf->value; //Se guarda la lista de gráficas en 'listaGraficas'.
  mostrarGraf(listaGraficas); //Se muestra la listas con las gráficas disponibles.
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
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*Se hace el mismo proceso que las gráficas, pero en este caso con los procesadores.*/
void elegirProce(Map *componentes, Map *carritoCompras)
{
  //Comprobamos que no haya una tarjeta en el carrito.
  MapPair *pairCar = map_search(carritoCompras, "Procesador");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes un Procesador en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();
  //Busca la lista de procesadores disponibles en 'componentes'.
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

  //Busca la gráfica elegida por el usuario y la agrega a su carrito.
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
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*Se repite el proceso pero con la tarjeta madre.*/
void elegirTarjetaMadre(Map *componentes, Map *carritoCompras)
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
  //Busca la lista de tarjetas madres disponibles en 'componentes'.
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
  
  //Busca la gráfica elegida por el usuario y la agrega a su carrito.
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
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*Mismo proceso pero con las memoria RAM.*/
void elegirMemoriaRAM(Map *componentes, Map *carritoCompras)
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
  //Busca la lista de memoria RAM disponibles en 'componentes'.
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

  //Busca la memoria Ram elegida por el usuario y la agrega a su carrito.
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
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*Mismo proceso pero con el almacenamiento.*/
void elegirAlmacenamiento(Map *componentes, Map *carritoCompras)
{
  //Comprobamos que no haya una unidad de almacenamiento en el carrito.

  MapPair *pairCar = map_search(carritoCompras, "Almacenamiento");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes una Unidad de Almacenamiento en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();
  //Busca la lista de unidades de almacenamiento disponibles en 'componentes'.
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

  //Busca la unidad de almacenamiento elegida por el usuario y la agrega a su carrito.
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
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*Mismo proceso pero con la fuente de poder.*/
void elegirFuentePoder(Map *componentes, Map *carritoCompras)
{
  //Comprobamos que no haya una fuente de poder en el carrito.
  MapPair *pairCar = map_search(carritoCompras, "Fuente de Poder");
  if (pairCar->value != NULL)
  {
    puts("\nYa tienes una Fuente de Poder en tu carrito!\n");
    puts("Volviendo al Menú Principal.");
    return;
  }

  limpiarPantalla();
  //Busca la lista de fuentes de poder disponibles en 'componentes'.
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

  //Busca la fuente de poder elegida por el usuario y la agrega a su carrito.
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
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*Esta función se encarga en escoger el componente que desee el usuario. Dependiendo del producto que escogió, se llama la función de elegir (producto seleccionado).*/
void escogerComponente(Map *componentes, Map *carrito)
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
        elegirGrafica(componentes, carrito);
        return;
      case '2':
        elegirProce(componentes, carrito);
        return;
      case '3':
        elegirTarjetaMadre(componentes, carrito);
        return;
      case '4':
        elegirMemoriaRAM(componentes, carrito);
        return;
      case '5':  
        elegirAlmacenamiento(componentes, carrito);
        return;
      case '6':
        elegirFuentePoder(componentes, carrito);
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
/*Esta función muestra los productos que escogió el usuario, con sus respectivas especificaciones.*/
void mostrarCarro(Map *carritoCompras)
{
  puts("Tu carrito de compras:");
  puts("--------------------------------------------");
  
  MapPair *pairCar = map_search(carritoCompras, "Gráfica"); //Busca gráfica en el mapa.
  if (pairCar->value != NULL) //Si existe:
  {
    /*Muestra los datos y especificaciones de gráfica.*/
    Grafica *grafica = (Grafica *)pairCar->value;
    puts("Tarjeta Gráfica:\n");
    printf("Modelo: %s\n", grafica->modelo);
    printf("Memoria: %d GB\n", grafica->memoria);
    printf("Tipo de Memoria: GDDR%d\n", grafica->gddr);
    printf("Consumo: %dW\n", grafica->consumo);
    printf("Gama: %s\n", grafica->gama);
    puts("--------------------------------------------");
  }

  /*Se repite el proceso con 'procesador'.*/
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

  /*Lo mismo con 'tarjeta madre'.*/
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

  /*Lo mismo con 'ram'.*/
  pairCar = map_search(carritoCompras, "RAM");
  if (pairCar->value != NULL)
  {
    MemoriaRAM *memoriaRam = (MemoriaRAM *)pairCar->value;
    puts("Memoria RAM:\n");
    printf("Modelo: %s\n", memoriaRam->modelo);
    printf("Cantidad de memoria: %i gb\n", memoriaRam->memoria);
    printf("Tipo de memoria: %s\n", memoriaRam->ddr);
    printf("Frecuencia: %i mhz\n", memoriaRam->frecuencia); 
    puts("--------------------------------------------");
  }

  /*Mismo proceso con 'almacenamiento'.*/
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

  /*Por último la 'fuente de poder'.*/
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

  //En caso de que el carrito de compras esté vacio, se printeará ese mensaje.
  if (carritoVacio(carritoCompras))
  {
    puts("No hay nada en tu carrito!");
    puts("--------------------------------------------");
    return;
  }
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*Esta función se encarga en eliminar los productos que el usuario escogió.*/
void eliminarProducto(Map *carritoCompras)
{
  int opcionBorrar;

  if(carritoVacio(carritoCompras)) //En caso de que esté vacio el carrito de compras, printeará que no hay nada.
  {
    puts("--------------------------------");
    puts("No hay nada en tu carrito!");
    puts("--------------------------------");
    return;
  }
  
  do
  {
    /*El usuario debe escoger el componente que quiera eliminar de su carrito.*/
    puts("Escoge el componente que deseas eliminar del carrito:\n");
    puts("1. Gráfica");
    puts("2. Procesador");
    puts("3. Tarjeta Madre");
    puts("4. Memoria RAM");
    puts("5. Almacenamiento");
    puts("6. Fuente de Poder");
    puts("7. Salir");
    printf("Ingrese su opción: ");
    scanf(" %d", &opcionBorrar);

    MapPair *pairCar;
    switch(opcionBorrar)
    {
      case 1:
        //Para borrar la gráfica.
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
          return;
        }
        break;
      
      case 2:
        //Para borrar el procesador.
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
          return;
        }
        break;
      
      case 3:
        //Para borrar la tarjeta madre.
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
          return;
        }
        break;
      
      case 4:
        //Para borrar la ram.
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
          return;
        }
        break;
      
      case 5:
        //Para borrar el almacenamiento.
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
          return;
        }
        break;
      
      case 6:
        //Para borrar la fuente de poder.
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
/*Se encargará de comprobar la compatibilidad de los productos seleccionados por el usuario, esto mediante una comparación de las especificaciones de los productos escogidos.
El proceso será el mismo para cada comparación de compatibilidad entre los productos.*/
void comprobarCompatibilidad(Map *carritoCompras)
{
  limpiarPantalla();
  puts("Comprobando compatibilidad...");
  puts("--------------------------------------------");

  if(carritoVacio(carritoCompras))
  {
    puts("No hay nada en tu carrito!");
    puts("--------------------------------------------");
  }
    
  else
  { //Si hay algún elemento en el carrito
    MapPair *pairCar; //Componente principal que se va a comprobar
    MapPair *pairAux; //Auxiliar para comparar
    int contadorInco = 0; //Cuenta las incompatibilidades por componente
    
    //Comparación Tarjeta Gráfica
    pairCar = map_search(carritoCompras, "Gráfica");
    if (pairCar->value != NULL) //Se comprueba que haya gráfica
    {
      int contadorError = 0; //Contador de errores local
      puts("Tarjeta Gráfica:");
      Grafica *grafica = (Grafica *)pairCar->value; //Asignamos variable para comparación

      pairAux = map_search(carritoCompras, "Procesador");
      if (pairAux->value != NULL) //Si hay un procesador...
      {
        Procesador *procesador = (Procesador *)pairAux->value;
        if (strcmp(grafica->gama, procesador->gama) != 0) //Comparamos la gama entre gráfica y procesador.
        {
        puts("La gráfica y el procesador provocarán cuello de botella.");
        puts("No recomendamos esta combinación debido a que puede afectar el rendimiento.");
        contadorError++; //Sumamos uno al contador de errores.
        }
      }

      //Verificación de incompatibilidades
      if (contadorError == 0)
        puts("La Tarjeta Gráfica no tiene incompatibilidades.");
      else  
        contadorInco++;
      
      puts("--------------------------------------------");
    }

    //Comparación Procesador
    pairCar = map_search(carritoCompras, "Procesador");
    if (pairCar->value != NULL) //Se comprueba que haya procesador
    {
      int contadorError = 0; //Contador de errores local
      puts("Procesador:");
      Procesador *procesador = (Procesador *)pairCar->value;

      pairAux = map_search(carritoCompras, "Tarjeta Madre");
      if (pairAux->value != NULL) //Si hay una tarjeta madre...
      {
        //Haremos las comparaciones necesarias con la tarjeta Madre.
        TarjetaMadre *tarjetaMadre = (TarjetaMadre *)pairAux->value;
        if (strcmp(procesador->marca, tarjetaMadre->marcaProce) != 0)
        {
          printf("La Tarjeta Madre no es compatible con el Procesador de marca %s.\n", procesador->marca);
          contadorError++;
        }
        
      }

      //Verificación de incompatibilidades
      if (contadorError == 0)
        puts("El Procesador no tiene incompatibilidades.");
      else
        contadorInco++;
      
      puts("--------------------------------------------");
    }
    
    //Comparación Tarjeta Madre
    pairCar = map_search(carritoCompras, "Tarjeta Madre");
    if(pairCar->value != NULL) 
    { 
      int contadorError = 0; //Contador de errores local
      puts("Tarjeta Madre:");
      TarjetaMadre *tarjetaMadre = (TarjetaMadre *)pairCar->value; //Asignamos variable para comparación
      
      pairAux = map_search(carritoCompras, "RAM");
      if(pairAux->value != NULL) //Si hay una RAM...
      {
        //Haremos las comparaciones necesarias con la RAM
        MemoriaRAM *memoriaRam = (MemoriaRAM *)pairAux->value;
        if(strcmp(memoriaRam->ddr, tarjetaMadre->ddrCom) != 0)
        {
          printf("La Tarjeta Madre requiere memoria %s, tienes una RAM %s.\n", tarjetaMadre->ddrCom, memoriaRam->ddr);
          contadorError++;
        }
      }

      //Verificación de incompatibilidades
      if (contadorError == 0)
        puts("La Tarjeta Madre no tiene incompatibilidades.");
      else
        contadorInco++;
      
      puts("--------------------------------------------");
    }

    //Comparación Almacenamiento
    pairCar = map_search(carritoCompras, "Almacenamiento");
    if(pairCar->value != NULL)
    {
      int contadorError = 0; //Contador de errores local
      puts("Almacenamiento:");
      Almacenamiento *almacenamiento = (Almacenamiento *)pairCar->value;
      
      //Haremos las comparaciones necesarias con el almacenamiento
      pairAux = map_search(carritoCompras, "Tarjeta Madre");
      if (pairAux->value != NULL) //Si hay Tarjeta Madre...
      {
        TarjetaMadre *tarjetaMadre = (TarjetaMadre *)pairAux->value;
        if(strcmp(almacenamiento->tipo, "NVMe") == 0 &&  tarjetaMadre->nvme == 0)
        {
          puts("La Tarjeta Madre no tiene puertos NVMe para la unidad de almacenamiento.");
          puts("Recomendamos usar un almacenamiento de tipo SATA");
          contadorError++;
        }
      }

      //Verificación de incompatibilidades
      if(contadorError == 0)
        puts("La unidad de Almacenamiento no tiene incompatibilidades.");
      else  
        contadorInco++;

      puts("--------------------------------------------");
    }

    //comparacion RAM
    pairCar = map_search(carritoCompras, "RAM");
    if(pairCar->value != NULL)
    {
      int contadorError = 0; //Contador de errores local
      puts("Memoria RAM:");
      MemoriaRAM *memoriaRam = (MemoriaRAM *)pairCar->value;
      
      //Haremos las comparaciones necesarias con el procesador
      pairAux = map_search(carritoCompras, "Procesador");
      if (pairAux->value != NULL) //Si hay un procesador...
      {
        Procesador *procesador = (Procesador *)pairAux->value;
        if(memoriaRam->frecuencia < procesador->frecuenciaMin)
        {
          puts("La frecuencia de la RAM no es compatible con la del Procesador.");
          puts("Busca una RAM con mayor frecuencia.");
          contadorError++;
        }
      }

      //Verificación de incompatibilidades
      if (contadorError == 0)
        puts("La Memoria RAM no tiene incompatibilidades.");
      else
        contadorInco++;
      
      puts("--------------------------------------------");
    }

    //Comparación Fuente de Poder
    pairCar = map_search(carritoCompras, "Fuente de Poder");
    if (pairCar->value != NULL) 
    {
      int contadorError = 0;
      puts("Fuente de Poder:");
      FuentePoder *fuentePoder = (FuentePoder *)pairCar->value;
      pairAux = map_search(carritoCompras, "Gráfica");
      if (pairAux->value != NULL)
      {
        //Haremos las comparaciones necesarias con la gráfica
        Grafica *grafica = (Grafica *)pairAux->value;
        if(fuentePoder->energia < grafica->consumo)
        {
          puts("El *CONSUMO* de la Fuente de Poder y la Gráfica no son compatibles.");
          contadorError++;
        }      
      }

      //Verificación de incompatibilidades
      if (contadorError == 0)
        puts("La Fuente de Poder no tiene incompatibilidades.");
      else
        contadorInco++;

      puts("--------------------------------------------");
    }

    if (contadorInco == 0)
    {
      
      int opcion;
      puts("\n¡Tu carrito está completo y compatible!\n");
      puts("Deseas confirmar la compra?");
      puts("1) Confirmar Compra.");
      puts("2) Seguir Comprando...");
      printf("Ingrese su opción: ");
      scanf(" %d" , &opcion);

      switch(opcion)
      {
        case 1:
          limpiarPantalla();
          puts("Compra confirmada.");
          puts("El equipo de Vegeta Makes Everything está preparando tu pedido!");
          puts("Gracias por comprar con nosotros <3");

          puts("⢀⣀⡀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
          puts("⠀⢿⣷⠀⠀⢀⣿⠇⠀⠀⣀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⣀⠀⠀⠀⣶⡆⠀⠀⠀⣀⡀⠀⠀");
          puts("⠀⠈⣿⡆⠀⣼⡟⠀⣾⡿⠛⢻⣦⠀⣾⠟⠛⢿⣿⠀⣾⡟⠛⢻⣆⠛⣿⡟⠃⠼⠿⠛⢻⣷⠀");
          puts("⠀⠀⠘⣷⣸⣿⠃⠀⣿⡿⠿⠿⠿⠇⣿⠀⠀⢸⣿⠰⣿⠿⠿⠿⠿⠀⣿⡇⠀⣴⣾⠿⢻⣿⠀");
          puts("⠀⠀⠀⢹⣿⠇⠀⠀⠻⣷⣤⣴⠷⠀⢿⣧⣤⣿⣿⠀⠻⣧⣤⣴⠶⠀⢿⣧⡄⢿⣷⣤⣾⣿");
          puts("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣤⣤⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
          puts("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀");
          break;
        
        case 2:
          limpiarPantalla();
          puts("Volviendo al menú principal.\n");
          break;
      }    
    }
  }
  return;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/*La función main es para crear los mapas que usamos, y que el usuario use la opción que quiera.*/
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
        limpiarPantalla();
        mostrarCarro(carritoCompras);
        break;
      case '3':
        limpiarPantalla();
        eliminarProducto(carritoCompras);
        break;
      case '4':
        limpiarPantalla();
        comprobarCompatibilidad(carritoCompras);
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