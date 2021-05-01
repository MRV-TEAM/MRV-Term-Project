#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
using namespace std;

void SPL(){
    int n,m,pilih,masuk=0;
    ifstream splgauss("spl.txt");

    cout<<"==================================================="<<endl;
    cout<<"=             Anda memilih menu SPL               ="<<endl;
    cout<<"==================================================="<<endl;
    cout<<"1. Input Matriks Augmented dengan cara Manual"<<endl;
    cout<<"2. Input Matriks Augmented dengan cara fstream"<<endl;
    cout<<"Kedua menu menerima nxm berbentuk augmented"<<endl;
    cout<<"==================================================="<<endl;
    cin>>masuk;

    if(masuk==1){
        cout<<"==================================================="<<endl;
        cout<<"=      Menu Memasukkan Matriks Secara Manual      ="<<endl;
        cout<<"Banyaknya SPL : ";cin>>n;
        cout<<"Banyak variabel SPL : ";cin>>m;
        cout<<"==================================================="<<endl;
    }else if(masuk==2){
        cout<<"==================================================="<<endl;
        cout<<"=      Menu Memasukkan Matriks Secara fstream      ="<<endl;
        cout<<"Banyaknya SPL : ";cin>>n;
        cout<<"Banyak variabel SPL : ";cin>>m;
        cout<<"Silahkan memasukkkan file dengan format spl.txt"<<endl;
        cout<<"==================================================="<<endl;
    }
    float a[n][m];
    m=m-1;

    //INPUT MATRIKS
    cout<<"Input SPL : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(masuk==1){
                cin>>a[i][j];
            }else if(masuk==2){
                splgauss>>a[i][j];
            }
        }
    }
    cout<<"================= INPUT MATRIKS ==================="<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            cout<<a[i][j]<<"    ";
        }cout<<endl;
    }
    cout<<"==================================================="<<endl;

    cout<<"================ MENU PILIHAN CARA ================"<<endl;
    cout<<"1. Metode Eliminasi Gauss"<<endl;
    cout<<"2. Metode Eliminasi Gauss-Jordan"<<endl;
    cout<<"3. Metode Matriks Balikan"<<endl;
    cout<<"4. Kaidah Cramer"<<endl;
    cout<<"==================================================="<<endl;
    cout<<"Pilihan = ";cin>>pilih;
    cout<<"==================================================="<<endl;

                                                                                        //SPL GAUSS
    if(pilih==1&&(masuk==1||masuk==2)){
        float hasil[m]={0};
        //menu gauss
        int o=0;
        int p=1;
        cout<<"================== PROSES EKESEKUSI ==============="<<endl;
        do{
            //pembagian agar menjadi 1 untuk semua kolom
            cout<<"==================================================="<<endl;
            for(int i=o;i<n;i++){
                float temp= a[i][o];
                for(int j=0;j<=m;j++){
                    a[i][j]= float(a[i][j]/temp);
                    cout<<a[i][j]<<"    ";
                }cout<<endl;
            }
            //pengurangan agar menjadi 0 untuk setiap kolom
            cout<<"==================================================="<<endl;
            for(int i=p;i<n;i++){
                for(int j=o;j<=m;j++){
                    a[i][j]=float(a[i][j]-a[o][j]);
                    cout<<a[i][j]<<"    ";
                }cout<<endl;
            }
            o++;p++;
        }while(o<n);

        //hasil tampil gauss
        cout<<"=================== HASIL OBE ====================="<<endl;
        cout<<"==================================================="<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                cout<<a[i][j]<<"    ";
            }cout<<endl;
        }cout<<endl;
        cout<<"==================================================="<<endl;
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=m;j++){
                if(n==j){
                    hasil[i]=a[i][j]-hasil[i];
                }else{
                    hasil[i]=hasil[i]+(a[i][j]*hasil[j]);
                }
            }
        }
        //hasil variabel spl
        for(int i=0;i<m;i++){
            cout<<"X"<<i+1<<" : "<<hasil[i]<<endl;
        }
        cout<<"==================================================="<<endl;
    }

                                                                                     //SPL GAUSS-JORDAN
    else if(pilih==2&&(masuk==1||masuk==2)){
        //menu gaussjordan
        float hasil[m];
        //menu gauss

        int o=0;
        int p=1;
        cout<<"================== PROSES EKESEKUSI ==============="<<endl;
        do{
            cout<<"==================================================="<<endl;
            //pembagian agar menjadi 1 untuk semua kolom
            for(int i=o;i<n;i++){
                float temp= a[i][o];
                for(int j=o;j<=m;j++){
                    a[i][j]= float(a[i][j]/temp);
                    cout<<a[i][j]<<"    ";
                }cout<<endl;
            }
            cout<<"==================================================="<<endl;
            //pengurangan agar menjadi 0 untuk setiap kolom
            for(int i=p;i<n;i++){
                for(int j=o;j<=m;j++){
                    a[i][j]=float(a[i][j]-a[o][j]);
                    cout<<a[i][j]<<"    ";
                }cout<<endl;
            }
            
            o++;p++;
        }while(o<n);

        o=0;
        do{
            for(int i=0;i<n;i++){
                if(i<o){
                    float temp = a[i][o];
                    for(int j=0;j<=m;j++){
                        a[i][j]=a[i][j]-(temp*a[o][j]);
                    }
                }
            }o++;
        }while(o!=n);

        //hasil obe
        cout<<"=============== HASIL OBE-TEREDUKSI ==============="<<endl;
        cout<<"==================================================="<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                cout<<a[i][j]<<"    ";
            }cout<<endl;
        }cout<<endl;
        cout<<"==================================================="<<endl;

        for(int i=0;i<n;i++){
            for(int j=m;j<=m;j++){
                cout<<"X"<<i+1<<" : "<<a[i][j]<<"    ";
            }cout<<endl;
        }
    }

                                                                                     //SPL INVERS
    else if(pilih==3&&(masuk==1||masuk==2)){
        //menu invers
        float matrix[n][n+n];
        float simpan[n];

        cout<<"=================== MATRIKS B ===================="<<endl;
        //MENYIMPAN HASIL SPL PADA ARRAY SIMPAN
        for(int i=0;i<n;i++){
            for(int j=m;j<=m;j++){
                simpan[i]=a[i][j];
                cout<<"x"<<i+1<<" : "<<simpan[i];
            }cout<<endl;
        }
        cout<<"==================================================="<<endl;
        
        //MEMBUAT MATRIKS IDENTITAS BERADA DISEBELAH KANAN MATRIKS nxn
        int o=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n+n;j++){
                if(j<n){
                    matrix[i][j]=a[i][j];
                }else{
                    if(j-i==n){
                        matrix[i][j]=1;
                    }else{
                        matrix[i][j]=0;
                    }
                }
            }
        }

        //OUTPUT MATRIKS YANG SUDAH DIGABUNGKAN DENGAN MATRIKS IDENTITAS
        for(int i=0;i<n;i++){
            for(int j=0;j<n+n;j++){
                cout<<matrix[i][j]<<"    ";
            }cout<<endl;
        }

        //OPERASI MATRIKS MENGGUNAKAN METODE GAUSS
        o=0;
        int p=1;
        cout<<"================== PROSES EKESEKUSI ==============="<<endl;
        do{
            cout<<"==================================================="<<endl;
            //pembagian agar menjadi 1 untuk semua kolom
            for(int i=o;i<n;i++){
                float temp= matrix[i][o];
                for(int j=o;j<n+n;j++){
                    matrix[i][j]= float(matrix[i][j]/temp);
                    cout<<matrix[i][j]<<"    ";
                }cout<<endl;
            }
            cout<<"==================================================="<<endl;
            //pengurangan agar menjadi 0 untuk setiap kolom
            for(int i=p;i<n;i++){
                for(int j=o;j<n+n;j++){
                    matrix[i][j]=float(matrix[i][j]-matrix[o][j]);
                    cout<<matrix[i][j]<<"    ";
                }cout<<endl;
            }
            
            o++;p++;
        }while(o<n);

        //DILANJUTKAN DENGAN OPERASI MATRIKS MENGGUNAKAN GAUSS-JORDAN
        o=0;
        do{
            for(int i=0;i<n;i++){
                if(i<o){
                    float temp = matrix[i][o];
                    for(int j=0;j<n+n;j++){
                        matrix[i][j]=matrix[i][j]-(temp*matrix[o][j]);
                    }
                }
            }o++;
        }while(o!=n);

        //MATRIKS IDENTITAS AKAN BERADA DI SEBELAH KIRI MATRIKS SETELAH MENGGUNAKAN OPERASI GAUSS-JORDAN
        cout<<"===================== HASIL ======================="<<endl;
        cout<<"==================================================="<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n+n;j++){
                cout<<matrix[i][j]<<"    ";
            }cout<<endl;
        }cout<<endl;
        cout<<"==================================================="<<endl;
        float pindah[n][n]={0};

        //MENGHILANGKAN MATRIKS IDENTITAS DISEBELAH KIRI
        for(int i=0;i<n;i++){
            o=0;
            for(int j=n;j<n+n;j++){
                pindah[i][o]=matrix[i][j];
                o++;
            }
        }

        //OUTPUT MATRIKS YANG SUDAH DIHILANGKAN MATRIKS IDENTITASNYA
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<pindah[i][j]<<"    ";
            }cout<<endl;
        }

        float hasil[n];
        //PERKALIAN MATRIKS DENGAN HASIL
        for(int i=0;i<n;i++){
            for(int j=0;j<1;j++){
                for(int k=0;k<n;k++){
                    float temp=pindah[i][k]*simpan[i];
                    hasil[i]=pindah[i][j]+temp;
                }
            }
        }
        cout<<"==================================================="<<endl;
        //OUTPUT HASIL PERKALIAN MATRIKS DAN SOLUSI SPL NYA
        for(int i=0;i<n;i++){
            cout<<"X"<<i+1<<" : "<<hasil[i]<<endl;
        }
        
    }

                                                                                //SPL CRAMER
    else if(pilih==4&&(masuk==1||masuk==2)){
        //menu crammer
        n=3;m=3;
        float hasil[m];

        //MENYIMPAN HASIL
        for(int i=0;i<n;i++){
            for(int j=m;j<=m;j++){
                hasil[i]=a[i][j];
            }
        }

        cout<<"==================================================="<<endl;
        for(int i=0;i<n;i++){
		    for(int j=m;j<=m;j++){
			    hasil[i]=a[i][j];
			    cout<<a[i][j]<<"	";
		    }cout<<endl;
	    }
        cout<<"==================================================="<<endl;

        float matrixbaru[n][n+2];
	    for(int i=0;i<n;i++){
		    for(int j=0;j<=m;j++){
			    if(j<m){
				    matrixbaru[i][j]=a[i][j];
			    }
		    }
	    }
	
	    int o=0;
	    for(int i=0;i<n;i++){
		    int p=0;
		    for(int j=m;j<m+m-1;j++){
			    matrixbaru[i][j]=a[o][p];
			    p++;
		    }
		    o++;
	    }
	
	    for(int i=0;i<n;i++){
		    for(int j=0;j<m+m-1;j++){
			    cout<<matrixbaru[i][j]<<"		";
		    }cout<<endl;
	    }
	    float kedepan[3]={1};
	    float kebelakang[3]={1};

        float sementara,sementara2;
        kedepan[0]=((a[0][0]*a[1][1]*a[2][2]));
        kedepan[1]=((a[0][1]*a[1][2]*a[2][3]));
        kedepan[2]=((a[0][2]*a[1][3]*a[2][4]));
        sementara=kedepan[0]+kedepan[1]+kedepan[2];

        kebelakang[0]=((a[0][0]*a[1][1]*a[2][2]));
        kebelakang[1]=((a[0][1]*a[1][2]*a[2][3]));
        kebelakang[2]=((a[0][2]*a[1][3]*a[2][4]));
        sementara2=kebelakang[0]+kebelakang[1]+kebelakang[2];
        sementara=sementara-sementara2;
        cout<<"Determinannya adalah : "<<sementara<<endl;
        cout<<"====================================="<<endl;
        
        o=0;

    }else{
        cout<<"==================================================="<<endl;
        cout<<"Pilihan tidak tersedia!"<<endl;
        cout<<"==================================================="<<endl;
    }
   //========================================================================================================================================
}

void DET(){
    int n,masuk;

    ifstream deter("determinan.txt");
    cout<<"==================================================="<<endl;
    cout<<"=       Anda memilih menu MATRIKS BALIKAN         ="<<endl;
    cout<<"==================================================="<<endl;
    cout<<"1. Input Matriks Augmented dengan cara Manual      "<<endl;
    cout<<"2. Input Matriks Augmented dengan cara fstream     "<<endl;
    cout<<"==================================================="<<endl;
    cin>>masuk;
    cout<<"==================================================="<<endl;

    if(masuk==1){
        cout<<"==================================================="<<endl;
        cout<<"=      Menu Memasukkan Matriks Secara Manual      ="<<endl;
        cout<<"Input Matriks berapa n : ";cin>>n;
        cout<<"==================================================="<<endl;
    }else if(masuk==2){
        cout<<"==================================================="<<endl;
        cout<<"=      Menu Memasukkan Matriks Secara Manual      ="<<endl;
        cout<<"Input Matriks berapa n : ";cin>>n;
        cout<<"Silahkan masukkan format file determinan.txt"<<endl;
        cout<<"==================================================="<<endl;
    }
    float a[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(masuk==1){
                cin>>a[i][j];
            }else if(masuk==2){
                deter>>a[i][j];
            }
        }
    }

    int o=0;
    int p=1;
    float temp2;

    do{
        //pembagian agar menjadi 1 untuk semua kolom
        for(int i=o;i<n;i++){
            float temp=a[i][o];
            cout<<"i = "<<i<<"|| o = "<<o<<" ==== ";
            cout<<a[i][o]<<"    "<<endl;
            for(int j=o;j<n;j++){
                a[i][j]= float(a[i][j]/temp);
                cout<<"temp : "<<temp<<endl;
                temp2=temp2*temp;
            }
        }
        //pengurangan agar menjadi 0 untuk setiap kolom
        for(int i=p;i<n;i++){
            for(int j=o;j<n;j++){
                a[i][j]=float(a[i][j]-a[o][j]);
            }
        }
        o++;p++;
    }while(o<=n);

    cout<<"temp2 : "<<temp2<<endl;
    float determinan = float(1/temp2);
    cout<<"Determinan : "<<determinan;
}

void MatriksBalikan(){
    int masuk;
    int n;

    ifstream matriksinvers("matriksinvers.txt");
    cout<<"==================================================="<<endl;
    cout<<"=       Anda memilih menu MATRIKS BALIKAN         ="<<endl;
    cout<<"==================================================="<<endl;
    cout<<"1. Input Matriks Augmented dengan cara Manual      "<<endl;
    cout<<"2. Input Matriks Augmented dengan cara fstream     "<<endl;
    cout<<"==================================================="<<endl;
    cin>>masuk;
    
    if(masuk==1){
        cout<<"==================================================="<<endl;
        cout<<"=      Menu Memasukkan Matriks Secara Manual      ="<<endl;
        cout<<"Input Matriks berapa n : ";cin>>n;
        cout<<"==================================================="<<endl;
    }else if(masuk==2){
        cout<<"==================================================="<<endl;
        cout<<"=      Menu Memasukkan Matriks Secara fstream      ="<<endl;
        cout<<"Input Matriks berapa n : ";cin>>n;
        cout<<"Silahkan masukkan format file matriksinvers.txt"<<endl;
        cout<<"==================================================="<<endl;
    }
    
    float a[n][n];
    float matrix[n][n+n];
    
    cout<<"Input Matriks : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(masuk==1){
                cin>>a[i][j];
            }else if(masuk==2){
                matriksinvers>>a[i][j];
            }
        }
    }

    int o=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+n;j++){
            if(j<n){
                matrix[i][j]=a[i][j];
            }else{
                if(j-i==n){
                    matrix[i][j]=1;
                }else{
                    matrix[i][j]=0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n+n;j++){
            cout<<matrix[i][j]<<"    ";
        }cout<<endl;
    }
    
    o=0;
    int p=1;
    
    cout<<"================== PROSES EKESEKUSI ==============="<<endl;
    do{
        cout<<"==================================================="<<endl;
        //pembagian agar menjadi 1 untuk semua kolom
        for(int i=o;i<n;i++){
            float temp= matrix[i][o];
            for(int j=o;j<n+n;j++){
                matrix[i][j]= float(matrix[i][j]/temp);
                cout<<matrix[i][j]<<"    ";
            }cout<<endl;
        }
        cout<<"==================================================="<<endl;
        //pengurangan agar menjadi 0 untuk setiap kolom
        for(int i=p;i<n;i++){
            for(int j=o;j<n+n;j++){
                matrix[i][j]=float(matrix[i][j]-matrix[o][j]);
                cout<<matrix[i][j]<<"    ";
            }cout<<endl;
        }
        o++;p++;
    }while(o<n);

    o=0;
    do{
        for(int i=0;i<n;i++){
            if(i<o){
                float temp = matrix[i][o];
                for(int j=0;j<n+n;j++){
                    matrix[i][j]=matrix[i][j]-(temp*matrix[o][j]);
                }
            }
        }o++;
    }while(o!=n);

    //hasil obe
    cout<<"=================== HASIL OBE ====================="<<endl;
    cout<<"==================================================="<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+n;j++){
            cout<<matrix[i][j]<<"    ";
        }cout<<endl;
    }cout<<endl;
    cout<<"==================================================="<<endl;


    float pindah[n][n];
    //MENGHILANGKAN MATRIKS IDENTITAS DISEBELAH KIRI
    for(int i=0;i<n;i++){
        o=0;
        for(int j=n;j<n+n;j++){
            pindah[i][o]=matrix[i][j];
            o++;
        }cout<<endl;
    }

    //OUTPUT MATRIKS YANG SUDAH DIHILANGKAN MATRIKS IDENTITASNYA
    cout<<"===================== OUTPUT ======================"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<pindah[i][j]<<"    ";
        }cout<<endl;
    }
}

int main(){
    int n;
    int pilih;

    cout<<"==================================================="<<endl;
    cout<<"||                TUBES MRV 2020 (RB)            ||"<<endl;
    cout<<"||           INSTITUT TEKNOLOGI SUMATERA         ||"<<endl;
    cout<<"||===============================================||"<<endl;
    cout<<"||ANGGOTA KELOMPOK :                             ||"<<endl;
    cout<<"||1. Aulia Rahman Zulfi        (119140110)       ||"<<endl;
    cout<<"||2. Akmal Fauzan Suranta      (119140203)       ||"<<endl;
    cout<<"||3. Agusto Hawlai Rajagukguk  (119140119)       ||"<<endl;
    cout<<"==================================================="<<endl<<endl;

    cout<<"======================= MENU ======================"<<endl;
    cout<<"1. Sistem Persamaan Linier"<<endl;
    cout<<"2. Determinan"<<endl;
    cout<<"3. Matriks Balikan"<<endl;
    cout<<"4. Keluar"<<endl;
    cout<<"==================================================="<<endl;
    cout<<"Pilih : ";cin>>pilih;
    
    switch(pilih){
        case 1 : SPL();break;
        case 2 : DET();break;
        case 3 : MatriksBalikan();break;
        case 4 : return 0;
        default : cout<<"Menu yang anda masukkan tidak tersedia!"<<endl;break;
    }
    return 0;
}