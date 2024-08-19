#include "stdio.h"
#include "Habitat.h"
void satir_sutun_bul(const char *dosya_adi, int *satir, int *sutun) {
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        printf("Dosya açılamadı: %s\n", dosya_adi);
        return;
    }

    *satir = 0;
    *sutun = 0;
    int sayi;
    while (fscanf(dosya, "%d", &sayi) == 1) {
        (*sutun)++;
        char karakter;
        while (fscanf(dosya, "%c", &karakter) == 1 && karakter != '\n') {
            // Satırın sonuna kadar boşluk karakterlerini atla
        }
        (*satir)++;
    }

    (*sutun)++;
    fclose(dosya);
}


int main(){	
		int satir;
		int sutun;
		satir_sutun_bul("Veri.txt", &satir, &sutun);
		printf("Dosya %d satır ve %d sütundan oluşuyor.\n", satir, sutun);
		
		Habitat habitat = habitatEkle(satir, sutun);		
		habitat->doldur(habitat, "Veri.txt");

		
        
		habitat->yazdir(habitat);
		printf("Sayi matrisinin ilk hali,devam etmek icin entera basiniz\n");
		getchar();
		
       
		habitat->yeme(habitat);
		
		habitat->yazdir(habitat);
		printf("Sayi matrisinin son hali,entera bainiz\n");
		getchar();
		
		
		habitat->kazanan(habitat);
		
		habitat->yoket(habitat);
		
        
		
		return 0;
}
