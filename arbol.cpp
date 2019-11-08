#include <bits/stdc++.h>
using namespace std;

struct nodo{
	int dato;
	nodo* izquierda, *derecha;
};
nodo* crearnodo(int n){
	nodo* nuevo=new nodo();

	nuevo -> dato = n;
	nuevo ->izquierda = NULL;
	nuevo -> derecha = NULL;

	return nuevo;
}

void insertar(nodo *&arbol, int n){
	if(arbol == NULL){
		nodo *nuevo = crearnodo(n);
		arbol = nuevo;
	}else{
		int raiz = arbol->dato;
		if (n < raiz){
			insertar(arbol -> izquierda,n);
		}else{
			insertar(arbol -> derecha,n);
		}
	}
}
void orden(nodo *raiz){
    if(raiz==NULL) return;
    orden(raiz->izquierda);
    cout<<raiz->dato<<endl;
    orden(raiz->derecha);
}

nodo *arbol = NULL;

int main(){
    int opcion;
    int dato;
	do{
		cout<<"..MENU.."<<endl;
		cout<<"1.- Ingresar un dato"<<endl;
		cout<<"2.- Mostrar"<<endl;
		cout<<"3.- Salir"<<endl;
		cin>>opcion;
		switch (opcion){
			case 1:
				cout<<"Ingresa un valor"<<endl;
				cin>>dato;
				insertar(arbol,dato);
				break;
			case 2:
				cout<<"El arbol es:"<<endl;
				orden(arbol);
				break;
            case 3:
            cout<<"Salir"<<endl;
            break;
		}
    }while(opcion!=3);

	return 0;
}

