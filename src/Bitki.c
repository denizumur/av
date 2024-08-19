#include "Bitki.h"

Bitki bitkiEkle(char* harf, int sayi){
	Bitki this;
	this=(Bitki)malloc(sizeof(struct BITKI));
	this->gorunum=&bitkiGorunum;	
	this->super = canliEkle(harf,sayi);
	this->super->gorunum=&bitkiGorunum;
	this->yoket=&bitkiYoket;
	return this;
}

char* bitkiGorunum(const Canli this){
	return this->harf;
}

void bitkiYoket(const Bitki this){
	if(this==NULL) 
		return;	
    this->super->yoket(this->super); 
    free(this);	
}