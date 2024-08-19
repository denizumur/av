#include "Canli.h"

Canli canliEkle(char* harf,int sayi){
	Canli this;
	this=(Canli)malloc(sizeof(struct CANLI));	
	
	this->sayi=sayi;	
	this->harf=harf;	
	this->yoket= &canliYoket;
	return this;
}

void canliYoket(const Canli this){
	if(this==NULL) 
		return;
	free(this);		
}