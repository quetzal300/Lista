/**
	Nombres(s): Altamirnao Leal Jose ALfonso
	Descripcion:metodos de la clase nodo que permite mober e interactuar con ellos 
	
*/
#include <iostream>

class Nodo
{
private:
	int Dato;
	Nodo* Sig;
public:
	Nodo(int Dato, Nodo* Sig);
	Nodo(int Dato);
	void setDato(int Dato);
	void setSig(Nodo* Sig);
	int getDato();
	Nodo* getSig();
	//~Nodo();
};