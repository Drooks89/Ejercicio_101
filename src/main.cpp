#include <Arduino.h>

struct Nodo {
  int dato;
  Nodo* siguiente;
};

Nodo* frente = NULL;
Nodo* fin = NULL;

bool cola_vacia() {
  return (frente == NULL);
}

void insertarCola(int n) {
  Nodo* nuevo_nodo = new Nodo();
  nuevo_nodo->dato = n;
  nuevo_nodo->siguiente = NULL;

  if (cola_vacia()) {
    frente = nuevo_nodo;
  } else {
    fin->siguiente = nuevo_nodo;
  }

  fin = nuevo_nodo;

  Serial.print("\tElemento ");
  Serial.print(n);
  Serial.println(" insertado a la cola correctamente");
}

void suprimirCola(int& n) {
  n = frente->dato;
  Nodo* aux = frente;

  if (frente == fin) {
    frente = NULL;
    fin = NULL;
  } else {
    frente = frente->siguiente;
  }

  delete aux;
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }

  int dato;

  Serial.print("Digite un número: ");
  while (!Serial.available()) {
  
  }
  dato = Serial.parseInt();
  insertarCola(dato);

  Serial.print("Digite un número: ");
  while (!Serial.available()) {
  }
  dato = Serial.parseInt();
  insertarCola(dato);

  Serial.print("Digite un número: ");
  while (!Serial.available()) {
  
  }
  dato = Serial.parseInt();
  insertarCola(dato);

  Serial.println("\nQuitando los nodos de la cola: ");
  while (frente != NULL) {
    suprimirCola(dato);

    if (frente != NULL) {
      Serial.print(dato);
      Serial.print(" , ");
    } else {
      Serial.print(dato);
      Serial.println(".");
    }
  }
}

void loop() {
  
}