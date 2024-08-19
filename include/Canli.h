#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

struct CANLI{
	char* harf;
	int sayi;
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct CANLI*);
	char* (*turget)(struct CANLI*);	
};
typedef struct CANLI* Canli;

Canli canliEkle(char*,int);
void canliYoket(const Canli);

#endif





