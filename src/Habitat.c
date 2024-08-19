#include "Habitat.h"

Habitat habitatEkle(int satir,int sutun){	
	Habitat this;
	this=(Habitat)malloc(sizeof(struct HABITAT));
	
	this->satir= satir;
    this->sutun = sutun;
	this->boyut = satir*sutun;
	
	this->doldur =&matrisOlusum;
	this->yazdir=&habitatYaz;
	this->yeme=&habitatYeme;
	this->kazanan = &kazananBul;
	this->yoket= &habitatYoket;

	this->matris = (Canli **)malloc(satir * sizeof(Canli *));
    if (this->matris == NULL) {
        printf("Hafiza ayirma basarisiz.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < satir; i++) {
        this->matris[i] = (Canli *)malloc(sutun* sizeof(Canli));
        if (this->matris[i] == NULL) {
            printf("Hafiza ayirma basarisiz.\n");
            exit(EXIT_FAILURE);
        }
    }
    return this;	
}

void matrisOlusum(const Habitat this, const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(EXIT_FAILURE);
    }
    int sayi;
    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            fscanf(dosya, "%d", &sayi);
            
            if (sayi >= 1 && sayi <= 9) {
                Bitki bitki = bitkiEkle("B", sayi);
                this->matris[i][j] = bitki->super;
            } 
			else if (sayi >= 10 && sayi <= 20) {
                Bocek bocek = bocekEkle("C", sayi);
                this->matris[i][j] = bocek->super;
            } 
			else if (sayi >= 21 && sayi <= 50) {
                Sinek sinek = sinekEkle("S", sayi);
                this->matris[i][j] = sinek->super->super;
				
            } 
			else if (sayi >= 51 && sayi <= 99) {
                Pire pire = pireEkle("P", sayi);
                this->matris[i][j] = pire->super->super;
				
            } 
			else {
                this->matris[i][j] = NULL;
            }
        }
    }
	 
    
    fclose(dosya);
}

void habitatYaz(const Habitat this) {
	printf("\n");
	
	system("cls");
    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            if (this->matris[i][j] != NULL && (this->matris[i][j]->harf == "C"||this->matris[i][j]->harf == "B"||this->matris[i][j]->harf == "P"||this->matris[i][j]->harf == "S")) {
                printf("%s ", this->matris[i][j]->gorunum(this->matris[i][j]));
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}
void habitatYeme(const Habitat this) {
    int satir = this->satir;
    int sutun = this->sutun;
    int toplam = satir * sutun;

    while (this->boyut > 1) {
        for (int i = 0; i < toplam; i++) {
            int i_satir = i / sutun;
            int i_sutun = i % sutun;

            if (this->matris[i_satir][i_sutun] != NULL && 
                (this->matris[i_satir][i_sutun]->harf == "C" ||
                 this->matris[i_satir][i_sutun]->harf == "B" ||
                 this->matris[i_satir][i_sutun]->harf == "P" ||
                 this->matris[i_satir][i_sutun]->harf == "S")) {
                Canli yiyici = this->matris[i_satir][i_sutun];

                for (int j = 0; j < toplam; j++) {
                    if (i == j) continue;

                    int j_satir = j / sutun;
                    int j_sutun = j % sutun;

                    if (this->matris[j_satir][j_sutun] != NULL && 
                        (this->matris[j_satir][j_sutun]->harf == "C" ||
                         this->matris[j_satir][j_sutun]->harf == "B" ||
                         this->matris[j_satir][j_sutun]->harf == "P" ||
                         this->matris[j_satir][j_sutun]->harf == "S")) {
                        Canli yem = this->matris[j_satir][j_sutun];

                        int yiyici_harfi = yiyici->harf;
                        int yem_harfi = yem->harf;

                        // Yiyici ve yem arasındaki etkileşimi kontrol et
                        if ((yiyici_harfi == "C" && (yem_harfi == "B" || yem_harfi == "P")) ||
                            (yiyici_harfi == "B" && (yem_harfi == "P" || yem_harfi == "S")) ||
                            (yiyici_harfi == "S" && (yem_harfi == "C" || yem_harfi == "P")) ||
                            (yiyici_harfi == "P" && yem_harfi == "S")) {
                            yem->harf = "x";
                            (this->boyut)--;
                            habitatYaz(this);
                        } else if ((yiyici_harfi == "C" && yem_harfi == "S") ||
                                   (yiyici_harfi == "B" && yem_harfi == "C") ||
                                   (yiyici_harfi == "P" && yem_harfi == "B") ||
                                   (yiyici_harfi == "S" && yem_harfi == "B")) {
                            yiyici->harf = "x";
                            (this->boyut)--;
                            habitatYaz(this);
                        } else if (yiyici_harfi == yem_harfi) {
                            if (yiyici->sayi > yem->sayi) {
                                yem->harf = "x";
                            } else {
                                yiyici->harf = "x";
                            }
                            (this->boyut)--;
                            habitatYaz(this);
                        }
                    }
                }
            }
        }
    }
}


void kazananBul(const Habitat this){
	
	int satir = this->satir;
    int sutun = this->sutun;
	
	for (int i = 0; i < satir; i++) {			
		for (int j = 0; j < sutun; j++) {
				
			if(this->matris[i][j] != NULL && (this->matris[i][j]->harf== "C"||this->matris[i][j]->harf== "B"||this->matris[i][j]->harf == "P"||this->matris[i][j]->harf== "S")){
					
				printf("\n");
				system("cls");
				printf("Kazanan: %s : (%d,%d)", this->matris[i][j]->gorunum(this->matris[i][j]),i,j );	
			}
		}										
	}
}

void habitatYoket(const Habitat this){
	
	if (this != NULL) {	
				
         if (this->matris != NULL) {
            for (int i = 0; i < this->satir; i++) {
                free(this->matris[i]);
            }
            free(this->matris);
        }
        free(this);				
    }
}
