#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
//Estructuras para uso de COLA
typedef struct info {
    int valor;
} Info;
typedef struct nodo {
    Info *elem;
    struct nodo *sgte;
} Nodo;
typedef struct cola {
    Nodo *frente;
    Nodo *fin;
    int tam; 
} Cola;

//PROTOTIPOS
Cola *crearCola();
void recorrerCola(Cola *pc);
void destruirCola(Cola *pc);
Info *crearInfo(int pval);
void encolar(Cola *pc, int pval);
int desencolar(Cola *pc);

//PROGRAMA PRINCIPAL
int main(int argc, char *argv[]){
    Cola *c = crearCola();
    Cola *cc = crearCola();
    encolar(c,1);    
    encolar(c,3);    
    encolar(c,2); 
    encolar(c,4);    
    encolar(c,5); 
    printf("\nFRENTE despues de insertar nodos:  %d  ", c->frente->elem->valor); 
    recorrerCola(c); //vaciar cola
    destruirCola(c);
    return 0;
}
//Recorre la cola (queda vac?a)
void recorrerCola(Cola *pc){ //vaciar cola
    printf("\n\n COLA RECORRIDA: ");
    while (pc->frente != NULL) {
        printf("%d  ", pc->frente->elem->valor); 
        desencolar(pc);
    }
}


//FUNCIONES BASES
Cola *crearCola(){
    Cola *c;
    if (c = (Cola *) malloc(sizeof(Cola))){
        c->frente=NULL;
        c->fin=NULL;
        c->tam=0;
    }else{
        printf("ERROR: MEMORIA LISTA NO ASIGNADA"); 
    }
    return c;
}
//Liberar Memoria
void destruirCola(Cola *pc){
    Nodo *aux;
    while (pc->frente != NULL)    {
	   aux = pc->frente;
	   pc->frente=pc->frente->sgte;
        free(aux->elem);
	   free(aux);
    }
    free(pc);
}
//Crear Info
Info *crearInfo(int pval){
    Info *newInfo;
    if (newInfo= (Info *) malloc(sizeof(Info))){
        newInfo->valor = pval;
    }else{
        printf("ERROR: MEMORIA INFO NO ASIGNADA"); 
    }
    return newInfo;
}
//crear nodo e insertar su valor
void encolar(Cola *pc, int pval){
    //Crear Info
      Info *pinfo;
      pinfo = crearInfo(pval);
    //crear Nodo
    Nodo  *newNodo;
    if (newNodo = (Nodo *) malloc(sizeof(Nodo))) {
    	newNodo->elem = pinfo;//ENGANCHO PUNTERO elem con pinfo que acabo de crear
    	newNodo->sgte = NULL;
    	if (pc->tam==0) {
    	  pc->frente=newNodo;
    	  pc->fin=newNodo;
        }else{
          pc->fin->sgte = newNodo;
    	  pc->fin=newNodo;
	    }
	    pc->tam++;
    }else{
        printf("ERROR: MEMORIA NODO NO ASIGNADA"); 
        free(newNodo);
    }
}

int desencolar(Cola *pc){
    Nodo *q = pc->frente; 
    int dato = q->elem->valor;
    pc->frente = q->sgte;  
    pc->tam--;
    free(q);
    return dato;
}
