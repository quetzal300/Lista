#include "Lista.h"



int main()
{
	Lista l = Lista(2);
	l.AddInicio(1);
	l.AddFinal(3);
	l.AddFinal(4);
	l.AddFinal(6);
	l.AddFinal(7 );
	std::cout<<"buscando nodo con referencia 2"<<std::endl;
	l.DireccionElementoBusacado(2);
	std::cout<<"lista empesando con H"<<std::endl;
	l.ShowH();
	l.RemoveInicio();
	std::cout<<"lista con primer elemento borrado "<<std::endl;
	l.ShowH();
	l.RemoveFinal();
	std::cout<<"lista con ultimo elemento borrado "<<std::endl;
	l.ShowH();
	std::cout<<"la longitud es  "<<l.Longitud()<<std::endl;
	l.AddRef(7,6);
	std::cout<<"lista con referencia agregada "<<std::endl;
	l.ShowH();
	l.RemoveRef(3);
	std::cout<<"lista con referencia eliminada "<<std::endl;
	l.ShowH();
	l.VaciarLista();
	l.ShowH();
	std::cout<<"la longitud es  "<<l.Longitud()<<std::endl;
	return 0;
}