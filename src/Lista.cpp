#include "Lista.h"
/**
creamos una lista vacia.
@params void
@result void
*/
Lista::Lista()
{
	this->H=NULL;
	this->T=NULL;
}
/**
Constructor:resibe un dato con el cual crea un nodo y los apunta a T y H 
@params Dato
@reult void
*/
Lista::Lista(int Dato)
{
	Nodo * aux= new Nodo(Dato);
	this->H=aux;
	this->T=aux;
}
/**
verifica si la lista esta vacia 
@params void
@reult bool
*/
bool Lista::ListaVacia()
{
	if (this->H == NULL && this->T == NULL)
		return true;
	return false;
}
/**
agrega a un elemento al inicio de la lista  
@params Dato
@reult void
*/
void Lista::AddInicio(int Dato)
{
	Nodo* aux = new Nodo(Dato,this->H);
	if (ListaVacia())
	{
		this->T= aux;
	}
	this->H= aux;
}
/**
agrega a un elemento al final de la lista  
@params Dato
@reult void
*/
void Lista::AddFinal(int Dato){
	Nodo* aux = new Nodo(Dato);
	if (ListaVacia()){
		this->H= aux;
	} 
	this->T->setSig(aux);
	this->T= aux;
}
/**
remueve al primer elemento de la lista y guarda el elemento borrado de la lista  
@params void
@reult int
*/
int Lista::RemoveInicio(){
	if(ListaVacia()){
		std::cout<<"La lista esta vacia"<<std::endl;
		return 0;
	}
	if(Longitud()==1){
		this->H=NULL;
		this->T=NULL;
		return 0;
	}
	int a = this->H->getDato();
	this->H=this->H->getSig();
	return a;
}
/**
remueve al ultimo elemento de la lista y guarda el elemento borrado de la lista   
@params void
@reult int
*/
int Lista::RemoveFinal(){
	if(ListaVacia()){
		std::cout<<"La lista esta vacia"<<std::endl;
		return 0;
	}
	int i=Longitud();
	int a = this->T->getDato();
	Nodo* aux = this->H;
	if(i==2){
		this->T=aux;
		return a;
	}if(i==1){
		this->H=NULL;
		this->T=NULL;
		return a;
	}
	i=i-2;
	while(i){
		aux=aux->getSig();
		i--;
	}
	this->T=aux;
	return a;
}
/**
calcula el numero de elementos en la lista    
@params void
@reult int
*/
int Lista ::Longitud(){
	int a=0;
	Nodo* aux = this->H;
	if(ListaVacia()){
		return a;
	}
	a=1;
	while(aux!=this->T){
		aux=aux->getSig();
		a++;
	}	
	return a;
}
/**
vacia la lista    
@params void
@reult void
*/
void Lista::VaciarLista(){
	while(!ListaVacia()){
		RemoveInicio();
	}

}
/**
imprime los elementos de la lista  
@params void
@reult void
*/
void Lista::ShowH(){
	if(ListaVacia()){
		std::cout<<"La lista esta vacia"<<std::endl;
		return;
	}
	Nodo* aux = this->H;
	while(aux!=this->T)
	{
		std::cout<<aux->getDato()<<std::endl;
		aux=aux->getSig();
	}
	std::cout<<aux->getDato()<<std::endl;
}
/**
busca el nodo en los elementos de la lista comparandolos con una referencia 
@params Ref
@reult Nodo*
*/
Nodo* Lista::BuscarElemento(int Ref){
	Nodo* aux = this->H;
	while(aux!=this->T)
	{
		if(aux->getDato()==Ref){
			return aux;
		}
		aux=aux->getSig();
	}
	if(aux->getDato()==Ref){
		return aux;
	}
	std::cout<<"la referencia no existe"<<std::endl;
	return NULL;
	
}
/**
imprime el elemonto buscado por el metodo buscar elemento e imprime su direcion de memoria  
@params Dato
@reult void
*/
void Lista::DireccionElementoBusacado(int Dato){
	std::cout<<"esta es la direccion del nodo " 
	<<BuscarElemento(Dato)<<std::endl;
	std::cout<<"este es el nodo"<<BuscarElemento(Dato)->getDato()<<std::endl;
}
/**
agrega un elemento a la lista en frente de la referencia dada y 
esta referencia apuntara a la que la refenrencia apuntaba antes de este 
@params Dato,Ref
@reult vois
*/
void Lista::AddRef(int Dato, int Ref){
	Nodo* aux =new Nodo(Dato);
	if (BuscarElemento(Ref)==NULL){
		return;
	}
	if(BuscarElemento(Ref)==this->T){
		AddFinal(Dato);
		return;
	}
	aux->setSig(BuscarElemento(Ref)->getSig());
	BuscarElemento(Ref)->setSig(aux);
}
/**
remueve un dato con la referencia dada apoyandose en de buscar por referencia   
@params Ref
@reult int
*/
int Lista::RemoveRef(int Ref){
	if(BuscarElemento(Ref)==this->H){
		return RemoveInicio();
	}
	if(BuscarElemento(Ref)==this->T){
		return RemoveFinal();
	}
	int i=0;
	Nodo* aux = this->H;
	while(aux!=BuscarElemento(Ref)){
		aux=aux->getSig();
		i++;
	}
	Nodo* aux2 = this->H;
	i--;
	while(i){
		aux2=aux2->getSig();
		i--;
	}
	int a = BuscarElemento(Ref)->getDato();
	aux2->setSig(BuscarElemento(Ref)->getSig());
	return a;
}