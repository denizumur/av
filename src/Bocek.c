#include "Bocek.h"

Bocek bocekEkle(char* harf,int sayi){
	Bocek this;
	this=(Bocek)malloc(sizeof(struct BOCEK));
	
	this->super = canliEkle(harf,sayi);
	this->super->gorunum=&bocekGorunum;
	this->gorunum=&bocekGorunum;
	this->yoket=&bocekYoket;
	return this;
}

char* bocekGorunum(const Canli this) {
    return this->harf;
}

void bocekYoket(const Bocek this) {
	if(this==NULL)
		return;	
    this->super->yoket(this->super); 
    free(this);	
}