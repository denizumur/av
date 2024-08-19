#ifndef PIRE_H
#define PIRE_H

#include "stdio.h"
#include "stdlib.h"
#include "bocek.h"

struct PIRE{
	Bocek super;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire pireEkle(char*,int);
char* pireGorunum(const Canli) ;
void pireYoket(const Pire);

#endif