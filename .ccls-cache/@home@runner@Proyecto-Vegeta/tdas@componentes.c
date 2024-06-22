#include "extra.h"
#include "map.h"
#include "list.h"
#include "componentes.h"
#include <stdbool.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void cargarComponentes(Map *componentes, Map *carritoCompras)
{
  FILE *archivo; //Para recorrer los archivos
  char **campos; //Para recorrer los diversos campos de una linea

  //Agregamos Gráficas al mapa de componentes
  //------------------------------------------------------------------------------
  archivo = fopen("data/GRAFICAS.csv", "r");
  if (archivo == NULL)
  {
    perror("Error al abrir el archivo GRAFICAS.csv");
    return;    
  }
  campos = leer_linea_csv(archivo, ',');


  while ((campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    
    Grafica *grafica = malloc(sizeof(Grafica));
    strcpy(grafica->modelo, campos[0]);
    grafica->memoria = atoi(campos[1]);
    grafica->gddr = atoi(campos[2]);
    grafica->consumo = atoi(campos[3]);
    strcpy(grafica->gama, campos[4]);

    MapPair *pair = map_search(componentes, "Gráfica");
    if (pair == NULL || pair->value == NULL || pair->key == NULL)
    {
      List *listaGraficas = list_create();
      list_pushBack(listaGraficas, grafica); 
      map_insert(componentes, "Gráfica", listaGraficas);
    }
    else
    { 
      List *listaGraficas = (List *)pair->value;
      list_pushBack(listaGraficas, grafica); 
    }
  } 
  fclose(archivo);
  //------------------------------------------------------------------------------

  //Agregamos Procesadores al mapa de componentes
  //------------------------------------------------------------------------------
  archivo = fopen("data/PROCESADORES.csv", "r");
  if (archivo == NULL)
  {
    perror("Error al abrir el archivo PROCESADORES.csv");
    return;    
  }
  campos = leer_linea_csv(archivo, ',');

  while ((campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    Procesador *procesador = malloc(sizeof(Procesador));
    strcpy(procesador->modelo, campos[0]);
    strcpy(procesador->marca, campos[1]);
    procesador->nucleos = atoi(campos[2]);
    procesador->hilos = atoi(campos[3]);
    procesador->frecuenciaMin = atoi(campos[4]);
    strcpy(procesador->gama, campos[5]);

    MapPair *pair = map_search(componentes, "Procesador");
    if (pair == NULL || pair->value == NULL || pair->key == NULL)
    {
      List *listaProcesadores = list_create();
      list_pushBack(listaProcesadores, procesador);
      map_insert(componentes, "Procesador", listaProcesadores);
    }
    else
    {
      List *listaProcesadores = (List *)pair->value;
      list_pushBack(listaProcesadores, procesador);
    }
  }
  fclose(archivo);
  //------------------------------------------------------------------------------

  //Agregamos Tarjetas madres al mapa de componentes
  //------------------------------------------------------------------------------
  archivo = fopen("data/TARJETAMADRE.csv", "r");
  if (archivo == NULL)
  {
    perror("Error al abrir el archivo TARJETAMADRE.csv");
    return;    
  }
  campos = leer_linea_csv(archivo, ',');

  while ((campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    TarjetaMadre *tarjetaMadre = malloc(sizeof(TarjetaMadre));
    strcpy(tarjetaMadre->modelo, campos[0]);
    strcpy(tarjetaMadre->socket, campos[1]);
    strcpy(tarjetaMadre->marcaProce, campos[2]);
    tarjetaMadre->nvme = atoi(campos[3]);
    strcpy(tarjetaMadre->ddrCom, campos[4]);
    
    
    MapPair *pair = map_search(componentes, "Tarjeta Madre");
    if (pair == NULL || pair->value == NULL || pair->key == NULL)
    {
      List *listaTarjetasMadres = list_create();
      list_pushBack(listaTarjetasMadres, tarjetaMadre);
      map_insert(componentes, "Tarjeta Madre", listaTarjetasMadres);
    }
    else
    {
      List *lista = (List *)pair->value;
      list_pushBack(lista, tarjetaMadre);
    }
  }
  fclose(archivo);
  //------------------------------------------------------------------------------

  //Agregamos Memorias Ram al mapa de componentes
  //------------------------------------------------------------------------------
  archivo = fopen("data/RAM.csv", "r");
  if (archivo == NULL)
  {
    perror("Error al abrir el archivo RAM.csv");
    return;    
  }
  campos = leer_linea_csv(archivo, ',');
    
  while ((campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    MemoriaRAM *memoriaRam = malloc(sizeof(MemoriaRAM));
    strcpy(memoriaRam->modelo, campos[0]);
    memoriaRam->memoria = atoi(campos[1]);
    strcpy(memoriaRam->ddr, campos[2]);
    memoriaRam->frecuencia = atoi(campos[3]);

    MapPair *pair = map_search(componentes, "RAM");
    if (pair == NULL || pair->value == NULL || pair->key == NULL)
    {
      List *listaMemoriasRam = list_create();
      list_pushBack(listaMemoriasRam, memoriaRam);
      map_insert(componentes, "RAM", listaMemoriasRam);
    }
    else
    {
      List *listaMemoriasRam = (List *)pair->value;
      list_pushBack(listaMemoriasRam, memoriaRam);
    }
  }
  fclose(archivo);
  //------------------------------------------------------------------------------

  //Agregamos Almacenamientos al mapa de componentes
  //------------------------------------------------------------------------------
  archivo = fopen("data/ALMACENAMIENTO.csv", "r");
  if (archivo == NULL)
  {
    perror("Error al abrir el archivo ALMACENAMIENTO.csv");
    return;    
  }
  campos = leer_linea_csv(archivo, ',');
  
  while ((campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    Almacenamiento *almacenamiento = malloc(sizeof(Almacenamiento));
    strcpy(almacenamiento->modelo, campos[0]);
    almacenamiento->lectura = atoi(campos[1]);
    almacenamiento->escritura = atoi(campos[2]);
    almacenamiento->espacio = atoi(campos[3]);
    strcpy(almacenamiento->tipo, campos[4]);

    MapPair *pair = map_search(componentes, "Almacenamiento");
    if (pair == NULL || pair->value == NULL || pair->key == NULL)
    {
      List *listaAlmacenamiento = list_create();
      list_pushBack(listaAlmacenamiento, almacenamiento);
      map_insert(componentes, "Almacenamiento", listaAlmacenamiento);
    }
    else
    {
      List *listaAlmacenamiento = (List *)pair->value;
      list_pushBack(listaAlmacenamiento, almacenamiento);
    }
  }
  fclose(archivo);
  //------------------------------------------------------------------------------

  //Agregamos Fuentes De Poder al mapa de componentes
  //------------------------------------------------------------------------------
  archivo = fopen("data/FUENTEPODER.csv", "r");
  if (archivo == NULL)
  {
    perror("Error al abrir el archivo FUENTEPODER.csv");
    return;    
  }
  campos = leer_linea_csv(archivo, ',');

  while ((campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    FuentePoder *fuentePoder = malloc(sizeof(FuentePoder));
    strcpy(fuentePoder->modelo, campos[0]);
    fuentePoder->energia = atoi(campos[1]);
    strcpy(fuentePoder->calidad, campos[2]);

    MapPair *pair = map_search(componentes, "Fuente de Poder");
    if (pair == NULL || pair->value == NULL || pair->key == NULL)
    {
      List *listaFuenteDePoder = list_create();
      list_pushBack(listaFuenteDePoder, fuentePoder);
      map_insert(componentes, "Fuente de Poder", listaFuenteDePoder);
    }
    else
    {
      List *listaFuenteDePoder = (List *)pair->value;
      list_pushBack(listaFuenteDePoder, fuentePoder);
    }
  }
  fclose(archivo);
  //------------------------------------------------------------------------------
  
  //Inserciones para que el carrito del usuario inicie en NULL
  map_insert(carritoCompras, "Gráfica", NULL);
  map_insert(carritoCompras, "Procesador", NULL);
  map_insert(carritoCompras, "RAM", NULL);
  map_insert(carritoCompras, "Almacenamiento", NULL);
  map_insert(carritoCompras, "Tarjeta Madre", NULL);
  map_insert(carritoCompras, "Fuente de Poder", NULL);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void mostrarGraf(List *lista)
{
  Grafica *grafica = (Grafica *)list_first(lista);
  int contador = 1;
  puts("");
  puts("Lista Tarjetas Gráficas \n");
  printf("--------------------------------------------\n");
  while (grafica != NULL)
  {
    printf("%i.-\n", contador);
    printf("Modelo: %s\n", grafica->modelo);
    printf("Memoria: %d GB\n", grafica->memoria);
    printf("Tipo de Memoria: GDDR%d\n", grafica->gddr);
    printf("Consumo: %dW\n", grafica->consumo);
    printf("Gama: %s\n", grafica->gama);
    printf("--------------------------------------------\n");
    grafica = (Grafica *)list_next(lista);
    contador++;
  }
  printf("%i.- Cancelar Operación\n", contador);
  printf("--------------------------------------------\n\n");
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void mostrarProce(List *lista)
{
  Procesador *procesador = (Procesador *)list_first(lista);
  int contador = 1;
  puts("");
  puts("Lista Procesadores \n");
  printf("--------------------------------------------\n");
  while (procesador != NULL)
  {
    printf("%i.-\n", contador);
    printf("Modelo: %s\n", procesador->modelo);
    printf("Marca: %s\n", procesador->marca);
    printf("Núcleos: GDDR%d\n", procesador->nucleos);
    printf("Hilos: %dW\n", procesador->hilos);
    printf("Frecuencia Mínima: %d\n", procesador->frecuenciaMin);
    printf("Gama: %s\n", procesador->gama);
    printf("--------------------------------------------\n");
    procesador = (Procesador *)list_next(lista);
    contador++;
  }
  printf("%i.- Cancelar Operación\n", contador);
  printf("--------------------------------------------\n\n");
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void mostrarTarjetaMadre(List *lista)
{
  TarjetaMadre *tarjetaMadre = (TarjetaMadre *)list_first(lista);
  int contador = 1;
  puts("");
  puts("Lista de Tarjetas Madres \n");
  printf("--------------------------------------------\n");
  while (tarjetaMadre != NULL)
  {
    printf("%i.-\n", contador);
    printf("Modelo: %s\n", tarjetaMadre->modelo);
    printf("Compatible con: %s\n", tarjetaMadre->marcaProce);
    printf("%s\n", tarjetaMadre->socket);
    printf("Puertos NVMe: %i\n", tarjetaMadre->nvme);  
    printf("Memoria: %s\n", tarjetaMadre->ddrCom);
    printf("--------------------------------------------\n");
    tarjetaMadre = (TarjetaMadre *)list_next(lista);
    contador++;
  }
  printf("%i.- Cancelar Operación\n", contador);
  printf("--------------------------------------------\n\n");
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void mostrarRam(List *lista)
{
  MemoriaRAM *memoriaRam = (MemoriaRAM *)list_first(lista);
  int contador = 1;
  puts("");
  puts("Lista de memorias Ram \n");
  printf("--------------------------------------------\n");
  while (memoriaRam != NULL)
  {
    printf("%i.-\n", contador);
    printf("Modelo: %s\n", memoriaRam->modelo);
    printf("Cantidad de memoria: %i gb\n", memoriaRam->memoria);
    printf("Tipo de memoria: %s\n", memoriaRam->ddr);
    printf("Frecuencia: %i mhz\n", memoriaRam->frecuencia);  
    printf("--------------------------------------------\n");
    memoriaRam = (MemoriaRAM *)list_next(lista);
    contador++;
  }
  printf("%i.- Cancelar Operación\n", contador);
  printf("--------------------------------------------\n\n");
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void mostrarAlmacenamiento(List *lista)
{
  Almacenamiento *unidadAlmacenamiento = (Almacenamiento *)list_first(lista);
  int contador = 1;
  puts("");
  puts("Lista de unidades de almacenamiento \n");
  printf("--------------------------------------------\n");
  while (unidadAlmacenamiento != NULL)
  {
    printf("%i.-\n", contador);
    printf("Modelo: %s\n", unidadAlmacenamiento->modelo);
    printf("Velocidad de lectura: %i mb/s\n", unidadAlmacenamiento->lectura);
    printf("Velocidad de escritura: %i mb/s\n", unidadAlmacenamiento->escritura);
    printf("Espacio de almacenamiento: %i gb\n", unidadAlmacenamiento->espacio);  
    printf("Tipo de SSD M2: %s\n", unidadAlmacenamiento->tipo);
    printf("--------------------------------------------\n");
    unidadAlmacenamiento = (Almacenamiento *)list_next(lista);
    contador++;
  }
  printf("%i.- Cancelar Operación\n", contador);
  printf("--------------------------------------------\n\n");
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void mostrarFuentePoder(List *lista)
{
  FuentePoder *fuentePoder = (FuentePoder *)list_first(lista);
  int contador = 1;
  puts("");
  puts("Lista de fuentes de poder \n");
  printf("--------------------------------------------\n");
  while (fuentePoder != NULL)
  {
    printf("%i.-\n", contador);
    printf("Modelo: %s\n", fuentePoder->modelo);
    printf("Consumo de energía: %i watts\n", fuentePoder->energia);
    printf("Certificación: %s\n", fuentePoder->calidad);
    printf("--------------------------------------------\n");
    fuentePoder = (FuentePoder *)list_next(lista);
    contador++;
  }
  printf("%i.- Cancelar Operación\n", contador);
  printf("--------------------------------------------\n\n");
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool carritoVacio(Map *carritoCompras)
{
  MapPair *pair;
  pair = map_search(carritoCompras, "Gráfica");
  if (pair->value != NULL) return false;
  pair = map_search(carritoCompras, "Procesador");
  if (pair->value != NULL) return false;
  pair = map_search(carritoCompras, "RAM");
  if (pair->value != NULL) return false;
  pair = map_search(carritoCompras, "Almacenamiento");
  if (pair->value != NULL) return false;
  pair = map_search(carritoCompras, "Tarjeta Madre");
  if (pair->value != NULL) return false;
  pair = map_search(carritoCompras, "Fuente de Poder");
  if (pair->value != NULL) return false;
  
  return true; //El carrito está completamente vacío
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------