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


//prototipos
Cola *crearCola();
void encolar(Cola *pc, int pval);
Info *crearInfo(int pval);

//funciones
int random(){
    srand(time(0));
	    int r = rand() %10;
	return r;
} 

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
Info *crearInfo(int pval){
    Info *newInfo;
    if (newInfo= (Info *) malloc(sizeof(Info))){
        newInfo->valor = pval;
    }else{
        printf("ERROR: MEMORIA INFO NO ASIGNADA"); 
    }
    return newInfo;
}
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
void recorrerCola(Cola *pc){ //vaciar cola
    printf("\n\n COLA RECORRIDA: ");
    while (pc->frente != NULL) {
        printf("%d  ", pc->frente->elem->valor); 
        desencolar(pc);    
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
// main
int main(int argc, char *argv[]){
    int r;
    Cola *c = crearCola();
    encolar(c,1);    
    encolar(c,2);    
    encolar(c,3); 
    encolar(c,4);    
    encolar(c,5);
    encolar(c,6); 
    encolar(c,7); 
    encolar(c,8); 
    encolar(c,9); 
    encolar(c,10);
    r=random();
    printf("\nEl numero al girar la ruleta es %d", r);
    printf("\nFRENTE despues de insertar nodos:  %d  ", c->frente->elem->valor); 
    recorrerCola(c);
    return 0;
}
