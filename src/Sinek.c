#include "Sinek.h"

Sinek sinekEkle(char* harf, int sayi){
	Sinek this;
	this=(Sinek)malloc(sizeof(struct SINEK));
	this->super=bocekEkle(harf,sayi);
	this->super->super->gorunum=&sinekGorunum;
	this->gorunum=&sinekGorunum;
	this->yoket=&sinekYoket;
	return this;
}

char* sinekGorunum(const Canli this) {
	return this->harf;
}

void sinekYoket(const Sinek this){
	if(this==NULL) 
		return;		
	this->super->yoket(this->super); 
    free(this);	
}