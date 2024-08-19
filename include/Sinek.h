#ifndef SINEK_H
#define SINEK_H

#include "stdio.h"
#include "stdlib.h"
#include "bocek.h"

struct SINEK{
	Bocek super;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek sinekEkle(char*,int);
char* sinekGorunum(const Canli) ;
void sinekYoket(const Sinek);

#endif