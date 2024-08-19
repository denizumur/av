#ifndef BITKI_H
#define BITKI_H

#include "stdio.h"
#include "stdlib.h"
#include "canli.h"

struct BITKI{
	Canli super;
	void (*yoket)(struct BITKI*);
	char* (*gorunum)(struct CANLI*);
};
typedef struct BITKI* Bitki;

Bitki bitkiEkle(char*,int);
char* bitkiGorunum(const Canli) ;
void bitkiYoket(const Bitki);

#endif