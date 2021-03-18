#include <stdio.h>
#include <stdlib.h>

int** array_initilaze(int len1,int len2){
	int **array;
	array = (int **)malloc(sizeof(int *)*len1);
	while(-1<len1){
		*(array+len1-1) = (int *)malloc(sizeof(int)*len2);
		len1--;
	}
	return array;
}
void array_pos_insert(int **array,int pos1,int pos2,int key){
	*(*(array+pos1)+pos2) = key;
}
void array_insert(int **array,int pos1,int pos2,int sira,int key){
	int sutun = (int) sira/pos2;
	int satir = sira%pos2 - 1;
	*(*(array+sutun)+satir) = key;
}
void print_array(int **array,int len1,int len2){
	int count = 0;
	while(count < len1){
		int count2 = 0;
		while(count2 < len2){
			printf("%d.Sutun %d.satir elemani =  %d  \n",count,count2,*(*(array+count)+count2));
			count2++;
		}
		count++;
	}
}
void print_array_matris(int **array, int len1,int len2){
	int count = 0;
	while(count < len1){
		int count2 = 0;
		while(count2 < len2){
			printf(" [%d] ",*(*(array+count)+count2));
			count2++;
		}
		printf("\n");
		count++;
	}
}
void array_eleman_sifir_yap(int **array, int len1,int len2){
	int count = 0;
	while(count < len1){
		int count2 = 0;
		while(count2 < len2){
			*(*(array+count)+count2) = 0;
			count2++;
		}
		count++;
	}
}
int main(){
	int **array;
	//printf("%d", *(*(array+1)+1) );
	int sutun_sayisi;
	int satir_sayisi;
	int sira  = 1;
	printf("Sutun sayisini giriniz: \n");
	scanf("%d",&sutun_sayisi);
	printf("Satir sayisini giriniz: \n");
	scanf("%d",&satir_sayisi);
	array = array_initilaze(sutun_sayisi,satir_sayisi);
	array_eleman_sifir_yap(array,sutun_sayisi,satir_sayisi);
	int islem = 0;
	while(islem != 1 ){
		int islem=0;
		printf("Eleman eklemek için 1\'e basip entere týklayýnýz. \n");
		printf("Herhangi bir pozisyona eleman eklemek icin 2\'ye basiniz ve entere tiklayiniz \n");
		printf("Herhangi bir elemani pozisyonu ile yazdýrmak için 3\'e basiniz ve entere tiklayiniz. \n");
		printf("Butun elemanlari yazdirmak icin 4\'e basiniz ve entere tiklayiniz. \n");
		scanf("%d",&islem);
		if(islem == 1){
			printf("Eklemek istediðiniz elemani giriniz: \n");
			int key;
			scanf("%d",&key);
			array_insert(array,sutun_sayisi,satir_sayisi,sira,key);
			sira++;
		}else if(islem == 2){
			int ekleme_satir;
			int ekleme_sutun;
			int key;
			printf("Eklemek istediðiniz sutunu giriniz: \n");
			scanf("%d",&ekleme_sutun);
			printf("eklemek istediðiniz satiri giriniz: \n");
			scanf("%d",&ekleme_satir);
			printf("Eklemek istediðiniz sayiyi giriniz: \n");
			scanf("%d",&key);
			array_pos_insert(array,ekleme_sutun,ekleme_satir,key);

		}else if(islem == 3){
			int ekleme_satir;
			int ekleme_sutun; 
			printf("Yazdirmak istediðiniz satiri giriniz: \n");
			scanf("%d",&ekleme_satir);
			printf("Yazdirmak istediðiniz sutunu giriniz: \n");
			scanf("%d",&ekleme_sutun);
			printf("%d satir %d sutun elemani = %d",ekleme_satir,ekleme_sutun,*(*(array+ekleme_satir)+ekleme_sutun));
		}else if(islem == 4){
			int yazdirma_sekli;
			printf("Satir ve sutun sayilari ile yazdirmak için 1\'e basiniz \n");
			printf("Matris seklinde yazdirmak için 2\'ye basiniz \n");
			scanf("%d",&yazdirma_sekli);
			if(yazdirma_sekli == 1){
				print_array(array,sutun_sayisi,satir_sayisi);
			}else{
				print_array_matris(array,sutun_sayisi,satir_sayisi);
			}
		}
	}
}






