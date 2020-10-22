#include <iostream>
using namespace std;

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

void SPL(){
    int n,m;
    
    cout<<"Banyaknya SPL : ";cin>>n;
    cout<<"Banyak variabel SPL : ";cin>>m;
    float a[n][m+1];

    //input
    cout<<"Input SPL : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            cin>>a[i][j];
        }
    }

    int pilih = MENU();

    if(pilih==1){
        float hasil[m];
        //menu gauss
        int o=0;
        int p=1;
        
        do{
            //pembagian agar menjadi 1 untuk semua kolom
            for(int i=0+o;i<n;i++){
                float temp= a[i][o];
                for(int j=0+o;j<=m;j++){
                    a[i][j]= float(a[i][j]/temp);
                }
            }
            //pengurangan agar menjadi 0 untuk setiap kolom
            for(int i=0+p;i<n;i++){
                for(int j=0+o;j<=m;j++){
                    a[i][j]=float(a[i][j]-a[o][j]);
                }
            }
            o++;p++;
        }while(o<=m);

        //hasil tampil gauss
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
        
        //penjumlahan
        o=m;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=m;j++){
            }cout<<endl;
        }
        //hasil variabel spl
        for(int i=1;i<=m;i++){
            cout<<"X"<<i<<" : "<<hasil[i]<<endl;
        }
    }

    else if(pilih==2){
        //menu gaussjordan
        float hasil[m];
        //menu gauss
        int o=0;
        int p=1;

        do{
            //pembagian agar menjadi 1 untuk semua kolom
            for(int i=0+o;i<n;i++){
                float temp= a[i][o];
                for(int j=0+o;j<=m;j++){
                    a[i][j]= float(a[i][j]/temp);
                }
            }
            //pengurangan agar menjadi 0 untuk setiap kolom
            for(int i=0+p;i<n;i++){
                for(int j=0+o;j<=m;j++){
                    a[i][j]=float(a[i][j]-a[o][j]);
                }
            }
            o++;p++;
        }while(o<=m);
        
        //hasil gaussjordan
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
    }
    else if(pilih==3){
        //menu invers
    }else if(pilih==4){
        //menu crammer
    }else{
        cout<<"Pilihan tidak tersedia!"<<endl;
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
    cout<<"=================================="<<endl;
    cout<<"Pilih : ";cin>>pilih;
    
    switch(pilih){
        case 1 : SPL();break;
        case 2 : DET();break;
        case 3 : MatriksBalikan();break;
        case 4 : return 0;
        default : cout<<"Menu yang anda masukkan tidak tersedia!"<<endl;break;
    }

}
//penjumlahan
        /*for(int i=n-1;i>=0;i--){
            for(int j=m;j>=0;j--){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;*/
