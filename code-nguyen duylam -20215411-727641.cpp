#include<stdio.h>
#include<string.h>
struct mathang{
    char ten[50];
    char donvitinh[50];
    int dongia,soluong;
    
};
float thanhtien(mathang a){
    return a.dongia*a.soluong;
}
float tienvanchuyen(mathang a){
    float tien=0;
    if(strcmp(a.donvitinh, "Thung") == 0){
        if(a.soluong<20){
        tien = 70;
        }else if(a.soluong<35){
        tien = 105;
        }else if(a.soluong<50){
        tien = 125;
        }else if(a.soluong>=50){
        tien = 170;
        }
    }else{
        tien = 125;
    }
    return tien;
}
struct XuatKho{
    char ten[50],maphieu[50];
    int ngay,thang,nam;
    int somathang;
    float sotiendathanhtoan;
    mathang x[50];

};
float tongthanhtien(XuatKho a){
    float tong=0;
    for(int i=0;i<a.somathang;i++){
        tong =tong+thanhtien(a.x[i]);
    }
    return tong;
}
float tongthanhtiencacphieuxuat(XuatKho a[],int soluong){
    float tong =0;
    for(int i=0;i<soluong;i++){
        tong =tong +tongthanhtien(a[i]);
    }
    return tong;
}
float tongvanchuyen(XuatKho a){
    float tong=0;
    for(int i=0;i<a.somathang;i++){
        tong =tong+tienvanchuyen(a.x[i]);
    }
    return tong;
}
float tongtienvanchuyen(XuatKho a[],int soluong){
    float tong =0;
    for(int i=0;i<soluong;i++){
        tong =tong +tongvanchuyen(a[i]);
    }
    return tong;
}
float tongtienphaithanhtoan(XuatKho a){
    return tongvanchuyen(a)+tongthanhtien(a);
}
float tongtienphaithanhtoancaphieu(XuatKho a[],int soluong){
    float tong =0;
    for(int i=0;i<soluong;i++){
        tong =tong +tongtienphaithanhtoan(a[i]);
    }
    return tong;
}
float tongtiendathanhtoancaphieu(XuatKho a[],int soluong){
    float tong =0;
    for(int i=0;i<soluong;i++){
        tong =tong +a[i].sotiendathanhtoan;
    }
    return tong;
}



float tinhtrang(XuatKho a){
    return tongtienphaithanhtoan(a)-a.sotiendathanhtoan;
}
void nhap(XuatKho kho[],int &soluong){
    printf("\nBAN DA CHON PHIEU XUAT MAT HANG\n");
    printf("Nhap so luong phieu xuat: "); 
    scanf("%d",&soluong);
    for(int i=0;i<soluong;i++){
        printf("Nhap thong tin phieu xuat %d\n",i+1);
        printf("Ten kho hang: "); 
        getchar();
        fgets(kho[i].ten,sizeof(kho[i].ten),stdin);
        
        printf("Ma phieu xuat: "); fgets(kho[i].maphieu,sizeof(kho[i].maphieu),stdin);
        
        printf("Ngay lap phieu xuat: \n");
        printf("Ngay: ");scanf("%d",&kho[i].ngay);
        
        printf("Thang: ");scanf("%d",&kho[i].thang);
        printf("Nam: ");scanf("%d",&kho[i].nam);
        printf("so mat hang: ");scanf("%d",&kho[i].somathang);
        for(int j=0;j<kho[i].somathang;j++){
            printf("\nMat Hang thu %d\n",j+1);
            printf("Ten mat Hang: ");
            getchar();
            fgets(kho[i].x[j].ten,sizeof(kho[i].x[j].ten),stdin);
            
            printf("Don vi Tinh: ");
            fgets(kho[i].x[j].donvitinh,sizeof(kho[i].x[j].donvitinh),stdin);
            printf("So luong: ");scanf("%d",&kho[i].x[j].soluong);
            printf("Don Gia: ");scanf("%d",&kho[i].x[j].dongia);
        }
        printf("so tien da thanh toan: "); scanf("%f",&kho[i].sotiendathanhtoan);
    }
}
float cong(mathang a){
    return thanhtien(a)+tienvanchuyen(a);
}
void inkq(XuatKho kho[],int soluong){
    printf("\nBAN DA CHON IN RA PHIEU XUAT\n");
    for(int i=0;i<soluong;i++){
        printf("Ten Kho Hang %s\n",kho[i].ten);
        printf("Ngay %d than %d nam %d\n",kho[i].ngay,kho[i].thang,kho[i].nam);
        printf("So mat hang: %d\n",kho[i].somathang);
        printf("Da Thanh Toan: %0.2f\n",kho[i].sotiendathanhtoan);
        printf("tong Thanh tien: %0.2f\n",tongthanhtien(kho[i]));
        printf("tong van chuyen: %0.2f\n",tongvanchuyen(kho[i]));
        printf("tong phai thanh toan: %0.2f\n",tongtienphaithanhtoan(kho[i]));
        printf("tinh trang thanh toan:      %0.2f\n",tinhtrang(kho[i]));
        printf("chi tiet cac mat hang: \n");
        printf("%20s \t %10s \t %10s \t %10s \t %20s \t %20s \t %10s\n","TenMatHang","DonVT","SoL","DonGia","ThanhTien","Vanchuyen","cong");
        for(int j=0;j<kho[i].somathang;j++){
            printf("%20s \t %10s \t %5d \t %5d \t %5.2f \t %5.2f \t %5.2f\n",kho[i].x[j].ten,kho[i].x[j].donvitinh,kho[i].x[j].soluong,kho[i].x[j].dongia,thanhtien(kho[i].x[j]),tienvanchuyen(kho[i].x[j]),cong(kho[i].x[j]));
        }
        printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    }
    printf("\ntong thanh tien cac phieu xuat %0.2f",tongthanhtiencacphieuxuat(kho,soluong));
    printf("\ntong tien van chuyen %0.2f",tongtienvanchuyen(kho,soluong));
    printf("\ntong tien phai thanh toan %0.2f",tongtienphaithanhtoancaphieu(kho,soluong));
    printf("\ntong tien da thanh toan %0.2f",tongtiendathanhtoancaphieu(kho,soluong));
    printf("\ntrinh trang thanh toan: %0.2f",tongtienphaithanhtoancaphieu(kho,soluong)-tongtiendathanhtoancaphieu(kho,soluong));
    
}


int main(){
    XuatKho kho[50];
    int soluong;
    int luachon;
    printf("Nguyen Duy Lam - 20215411-727641-IT3040-2022.2\n");
    do{
        printf("\n**CHUONG TRINH QUAN LY PHIEU XUAT**\n");
        printf("**1. Nhap cac phieu xuat, mat hang**\n");
        printf("**2. In ket qua phieu xuat va mat hang**\n");
        printf("**0. Thoat\n");
        printf("*****************************************\n");
        printf("**          Nhap lua chon              **\n");
        scanf("%d",&luachon);
        
        switch (luachon){
        case 1:
            nhap(kho,soluong);
            break;
        case 2: 
            inkq(kho,soluong);
            break;
        }
    }while(luachon!=0);
    return 0;
}