#ifndef HABITAT_H
#define HABITAT_H

#include "stdio.h"
#include "stdlib.h"
#include "canli.h"
#include "bocek.h"
#include "pire.h"
#include "sinek.h"
#include "bitki.h"

struct HABITAT{
	Canli **matris;	
	int satir;
    int sutun;
	int boyut;	
	void (*doldur)(struct HABITAT*,const char*);
	void (*yazdir)(struct HABITAT*);
	void (*yoket)(struct HABITAT*);
	void (*yeme)(struct HABITAT*);
	void (*kazanan)(struct HABITAT*);
	
};
typedef struct HABITAT* Habitat;

Habitat habitatEkle(int,int);
void matrisOlusum(const Habitat, const char*);
void habitatYaz(const Habitat) ;
void habitatYeme(const Habitat);
void kazananBul(const Habitat);
void habitatYoket(const Habitat);


#endif