#include "Pire.h"

Pire pireEkle(char* harf,int sayi){
	Pire this;
	this=(Pire)malloc(sizeof(struct PIRE));	
	
	this->super=bocekEkle(harf,sayi);
	this->super->super->gorunum=&pireGorunum;
	this->gorunum=&pireGorunum;
	this->yoket=&pireYoket;
	return this;
}

char* pireGorunum(const Canli this) {
	return this->harf;
}

void pireYoket(const Pire this){
	if(this==NULL) 
		return;			
    this->super->yoket(this->super); 
    free(this);	
}