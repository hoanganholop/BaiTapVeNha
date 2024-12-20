#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void displayMenu();

int main(){
	int choice;
	int position;
	int size =5;
	struct Dish{
		int id;
		char name[50];
		float price;
	};
	struct Dish menu[100]={
		 {1, "Long xao dua", 50},
		 {2, "Suon xao chua ngot", 50},
		 {3, "Com tam suon bi cha", 55},
		 {4, "My tran 3 trung", 35},
		 {5, "Pho bo", 40},
	};
	do{
 	displayMenu();
    scanf("%d", &choice);
    switch(choice){
    	case 1:{ 
		//In cac mon trong menu
    		int i;
    		printf("\n-----MENU-----\n");
    		for( i=0;i<size;i++){
    			printf("%d. %s: %.2f\n",menu[i].id, menu[i].name, menu[i].price);
			}
			break;
		}
		case 2:{
		// Them 1 mon vao menu	
			int i;
			struct Dish monmoi;
			printf("Nhap id: ");
			scanf("%d", &monmoi.id);
			fflush(stdin);
			printf("Nhap ten mon: ");
			fgets(monmoi.name,sizeof(monmoi.name),stdin);
			monmoi.name[strcspn(monmoi.name,"\n")]='\0';
			printf("Nhap gia mon: ");
			scanf("%f",&monmoi.price);
			printf("Nhap vi tri can them mon: ");
			scanf("%d", &position);
			if(position<0||position>size||position>=100){
				printf("Vi tri them mon khong hop le!\n");
				return 1;
			}
			for(i=size;i>position;i--){
				menu[i]=menu[i-1];
			}
			menu[position]=monmoi;
			size++;
			break;
		}
		case 3:{
		// Chinh sua mon menu
			int i;
			struct Dish suamon;
			printf("Nhap id thay doi: ");
			scanf("%d", &suamon.id);
			fflush(stdin);
			printf("Nhap ten mon thay doi: ");
			fgets(suamon.name,sizeof(suamon.name),stdin);
			suamon.name[strcspn(suamon.name,"\n")]='\0';
			printf("Nhap gia mon thay doi: ");
			scanf("%f",&suamon.price);
			printf("Nhap vi tri can thay doi mon: ");
			scanf("%d", &position);
			if(position<0||position>=size){
				printf("Vi tri thay doi mon khong hop le!\n");
				return 1;
			}
			menu[position]=suamon;	
			break;
		}
		case 4:{
		// Xoa 1 mon trong menu
			int i;
			printf("Nhap vi tri mon can xoa: ");
			scanf("%d",&position);
			if(position<0||position>=size){
				printf("Vi tri xoa mon khong hop le!\n");
				return 1;
			}	
			for(i=position;i<size-1;i++){
				menu[i]=menu[i+1];
			}
			size--;
			break;
		}
		case 5:{
		// Sap xep menu theo thu tu tang dan cua gia
			int i,j;
			for(i=0;i<size;i++){
				for(j=0;j<size-i-1;j++){
					if(menu[j].price>menu[j+1].price){
						struct Dish temp;
						temp.price=menu[j].price;
						menu[j].price=menu[j+1].price;
						menu[j+1].price=temp.price;
					}
				}
			}
			printf("\n-----MENU-----\n");
    		for( i=0;i<size;i++){
    			printf("%d. %s: %.2f\n",menu[i].id, menu[i].name, menu[i].price);
			}	
			break;
		}
		case 6:{
		// 	Tim kiem mon an trong menu
			char *findName;
			int i;
			fflush(stdin);
			printf("Nhap ten mon can tim: ");
			fgets(findName,sizeof(findName),stdin);
			findName[strcspn(findName,"\n")]='\0';
			for(i=0;i<size;i++){
				if(strcmp(menu[i].name, findName)==0){
					printf("Mon can tim o vi tri %d\n",i+1);
					printf("%d. %s: %.2f\n",menu[i].id, menu[i].name, menu[i].price);
				}
			}
			break;
		}
		case 7:{
			printf("Thoat khoi menu\n");
			break;
		}
		default:{
			printf("Lua chon khong hop le!\n");
			break;
		}
	}
    }while(choice!=7);
    return 0;
}
void displayMenu (){
	printf("\n--------------MENU--------------\n");
    printf("1. In cac mon trong menu\n");
    printf("2. Them mot mon vao menu\n");
    printf("3. Sua mot mon trong menu\n");
	printf("4. Xoa mot mon trong menu\n");
    printf("5. Sap xep mon theo gia tang dan\n");
    printf("6. Tim kiem mon trong menu\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

