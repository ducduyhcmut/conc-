#include<stdio.h>
// ham cau a
int SoNgayCuaThang(int thang,int nam){
	switch(thang){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:	
		return 30;		
	case 2:
		if((nam%400==0)||(nam%4==0&&nam%100!=0)){
			return 29;
		}else{
			return 28;
		}
	default: return -1;		
	}
	}	
// ham cau b
int NgayTrongNam(int ngay,int thang, int nam){
	int tongngay=0;
	for(int i = 1 ;i<thang;i++){
		tongngay= tongngay + SoNgayCuaThang(i,nam);		
	}	
	return tongngay+ngay;	
}
// ham cau c
void NgayTruocDo(int ngay,int thang, int nam){
	if(ngay==1){
		if(thang==1){
			nam--;
			printf("\nNgay truoc do la 31-12-%d",nam);	
		}else{
			thang--;
			ngay = SoNgayCuaThang(thang,nam);
			printf("\nNgay truoc do la %d-%d-%d",ngay,thang,nam);			
		}	
	}else{
		ngay--;
		printf("\nNgay truoc do la %d-%d-%d",ngay,thang,nam);
	}	
	}
// ham cau d
void NgayKeTiep(int ngay, int thang, int nam){
	if(ngay==SoNgayCuaThang(thang,nam)){
		if(thang==12){
		nam++;
		printf("\nNgay ke tiep la 1-1-%d",nam);
	}else{
		thang++;
		printf("\nNgay ke tiep la 1-%d-%d",thang,nam);
	}		
	}else{
		ngay++;
		printf("\nNgay ke tiep la %d-%d-%d",ngay,thang,nam);
	}
} 
int main(){
	int ngay,thang,nam;
	do{
		printf("Nhap ngay thang nam : ");
		scanf("%d %d %d",&ngay,&thang,&nam);
	}while(ngay<1||thang<1||thang>12||ngay>31||nam<1);

// cau a: tim so ngay cua thang
	printf("\nThang %d nam %d co %d ngay",thang,nam,SoNgayCuaThang(thang,nam));
	
// cau b: tinh xem do la ngay thu bao nhieu trong nam
	printf("\nNgay %d - %d - %d la ngay thu %d trong nam",ngay,thang,nam,NgayTrongNam(ngay,thang,nam));

// cau c: tim ngay truoc do
	NgayTruocDo(ngay,thang,nam);

// cau d: tim ngay ke tiep 
	NgayKeTiep(ngay,thang,nam);
}
