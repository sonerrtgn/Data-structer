#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int anahtar;
    struct dugum *sol_link, *sag_link;
};

struct dugum* yer_ayir_agac(struct dugum *kok,int anahtar){
	
	kok = (struct dugum *)malloc(sizeof(struct dugum));

	kok->anahtar= anahtar;
	kok->sol_link=NULL;
	kok->sag_link=NULL;
	return kok;
}
struct dugum* agac_ekle(struct dugum *kok, int anahtar){
	if(kok==NULL){
		kok = (struct dugum *)malloc(sizeof(struct dugum));
		kok->anahtar= anahtar;
		kok->sag_link=NULL;
		kok->sol_link=NULL;
		return kok;
	}
	if(kok->anahtar < anahtar){
		kok->sag_link = agac_ekle(kok->sag_link,anahtar);
	}else{
		kok->sol_link= agac_ekle(kok->sol_link,anahtar);
	}
}
void agac_yazdir(struct dugum *ana){
	if(ana == NULL){
		return ;
	}
	agac_yazdir(ana->sol_link);
	printf("%d\n",ana->anahtar);
	agac_yazdir(ana->sag_link);
	
}

int tek_cocuklu_dugum_sayisi(struct dugum *kok){
	if(kok==NULL){
		return 0;
	}
	if(kok->sag_link==NULL && kok->sol_link == NULL){
		return 0;
	}
	if(kok->sag_link==NULL && kok->sol_link!=NULL){
		return 1+tek_cocuklu_dugum_sayisi(kok->sol_link)+tek_cocuklu_dugum_sayisi(kok->sag_link);
	}
	if(kok->sag_link!=NULL && kok->sol_link==NULL){
		return 1+tek_cocuklu_dugum_sayisi(kok->sol_link)+tek_cocuklu_dugum_sayisi(kok->sag_link);
	}
	return tek_cocuklu_dugum_sayisi(kok->sol_link)+tek_cocuklu_dugum_sayisi(kok->sag_link);
}

int main(){
	struct dugum *kok;
	kok= yer_ayir_agac(kok,10);
	agac_ekle(kok,5);
	agac_ekle(kok,1);
	agac_ekle(kok,20);
	agac_ekle(kok,14);
	agac_ekle(kok,35);
	agac_ekle(kok,56);
	agac_ekle(kok,45);
	agac_yazdir(kok);
	printf("\n tek cocuklu dugum sayısı :%d",tek_cocuklu_dugum_sayisi(kok));
	//printf("%d",kok->sag_link->anahtar);
}
