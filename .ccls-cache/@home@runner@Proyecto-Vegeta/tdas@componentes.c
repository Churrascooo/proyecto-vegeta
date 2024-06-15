#include "extra.h"
#include "map.h"
#include "list.h"
#include "componentes.h"

void cargarComponentes(Map *componentes, Map *carritoCompras)
{
  FILE *archivo = fopen("data/PRODUCTOS.csv", "r");
  if (archivo == NULL)
  {
    perror("Error al abrir el archivo PRODUCTOS.csv");
    return;    
  }

  char **campos;
  char componenteAct[20];
  campos = leer_linea_csv(archivo, ',');

  //Leemos cada linea del archivo para sacar los componentes
  while ((campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    strcpy(componenteAct, campos[0]);

    //Agregamos Gráficas al mapa de componentes
    if (strcmp(componenteAct, "Gráfica") == 0)
    {
      Grafica *grafica = malloc(sizeof(Grafica));
      strcpy(grafica->modelo, campos[1]);
      grafica->memoria = atoi(campos[2]);
      grafica->gddr = atoi(campos[3]);
      grafica->consumo = atoi(campos[4]);
      strcpy(grafica->gama, campos[5]);

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

    //COPIAR FORMULA PARA LOS DEMÁS COMPONENTES
    //
    //
    //
    //
    //
  }
  fclose(archivo);

  map_insert(carritoCompras, "Gráfica", NULL);
  map_insert(carritoCompras, "Procesador", NULL);
  map_insert(carritoCompras, "RAM", NULL);
  map_insert(carritoCompras, "Almacenamiento", NULL);
  map_insert(carritoCompras, "Motherboard", NULL);
  map_insert(carritoCompras, "Fuente", NULL);
}

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













