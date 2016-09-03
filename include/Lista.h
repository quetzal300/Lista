/**
	Nombres(s): Altamirnao Leal Jose ALfonso
	Descripcion:Lista con una solo direccion capar de resivir enteros eliminarlos gragregar etc.
	
*/
#include "Nodo.h"

class Lista
{
public:
	Nodo* H;
	Nodo* T;	
	Lista();
	Lista(int Dato);
	bool ListaVacia();
	void AddInicio(int Dato);
	void AddFinal(int Dato);
	void AddRef(int Dato, int Ref);
	int RemoveInicio();
	int RemoveFinal();
	int Longitud();
	int RemoveRef(int Ref);
	void VaciarLista();
	Nodo* BuscarElemento(int Ref);
	void ShowH();
	void DireccionElementoBusacado(int Dato);//solo para hacer una prueva
};