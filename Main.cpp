#include <iostream>
using namespace std;
\\TOLOL
int MENU(){
    int pilih;
    cout<<"============== MENU =============="<<endl;
    cout<<"1. Metode Eliminasi Gauss"<<endl;
    cout<<"2. Metode Eliminasi Gauss-Jordan"<<endl;
    cout<<"3. Metode Matriks Balikan"<<endl;
    cout<<"4. Kaidah Cramer"<<endl;
    cout<<"=================================="<<endl;
    cout<<"Pilihan = ";cin>>pilih;
    return pilih;
}

void Gauss(float *x){

}

void GaussJordan(float *x){

}

void Invers(float *x){

}

void Crammer(float *x){

}

void SPL(){
    int n,i,j;
    cin>>n;
    float a[n][n];

    for(i=0;i<=n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];

        }
    }

    int pilih = MENU();
    switch(pilih){
        case 1 : Gauss(&a[i][j]);break;
        case 2 : GaussJordan(&a[i][j]);break;
        case 3 : Invers(&a[i][j]);break;
        case 4 : Crammer(&a[i][j]);break;
        default :break;
    }
}

void DET(){

}

void MatriksBalikan(){
    
}


int main(){
    int n;
    int pilih;
    
    cout<<"============== MENU =============="<<endl;
    cout<<"1. Sistem Persamaan Linier"<<endl;
    cout<<"2. Determinan"<<endl;
    cout<<"3. Matriks Balikan"<<endl;
    cout<<"4. Keluar"<<endl;
    cin>>pilih;
    

    switch(pilih){
        case 1 : SPL();break;
        case 2 : DET();break;
        case 3 : MatriksBalikan();break;
        case 4 : return 0;
        default : cout<<"Menu yang anda masukkan tidak tersedia!"<<endl;break;
    }

}
