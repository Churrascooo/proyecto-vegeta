#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "map.h"

typedef struct {
  char modelo[50];
  int memoria; // en GB
  int gddr;    //GDDR3-4-5-6
  int consumo; // en Watts
  char gama[10]; //Alta-Media-Baja
} Grafica;

typedef struct {
  char modelo[50];
  char marca[10];
  int nucleos;
  int hilos;
  int frecuenciaMin; //En MHz
  char gama[10];
} Procesador;

typedef struct {
  char modelo[50];
  char marcaProce[10];
  char socket[20];
  int nvme;
  char ddrCom[10];
} TarjetaMadre;

typedef struct {
  char modelo[50];
  int memoria;
  int ddr;
  int frecuencia; //En MHz
} MemoriaRAM;

typedef struct {
  char modelo[50];
  int lectura;
  int escritura;
  int espacio;
  char tipo[10]; //Sata o Nvme
} Almacenamiento;

typedef struct {
  char modelo[50];
  int energia; //En Watts
  char calidad; //80 PLUS
} FuentePoder;

void cargarComponentes(Map *componentes, Map *carritoCompras);

void mostrarGraf(List *lista);

void mostrarProce(List *lista);

void mostrarTarjetaMadre(List *lista);



