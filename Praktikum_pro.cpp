#include <iostream>
#include <time.h>
#include <iomanip>
#include <conio.h>
using namespace std;
struct pelanggan{
    int harga, pili, bayar, harnas, harmie, harso;
    char nama[100];
    int hargaNasi[3] = {0, 0, 0}; 
   int hargaBakso[3] = {0, 0, 0};
   int hargaMie[3] = {0, 0, 0};
    struct pelanggan *next;
}*head=NULL, *tail, *baru, *cek, *temp;
time_t local;

void nasi(){
   system("cls");
int nas,jml;
baru = (struct pelanggan*)malloc(sizeof(struct pelanggan));
   cout << "\n================== Menu Nasi Goreng ==================";
   cout << "\n1. Nasi goreng sosis       Rp.18.000";
   cout << "\n2. Nasi goreng ayam        Rp.20.000";
   cout << "\n3. Nasi goreng seafood     Rp.25.000";
   cout << "\nSilahkan memilih menu nasi goreng yang anda inginkan :";
   cin >> nas;
   switch (nas) {
      case 1:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jml;
         baru->hargaNasi[0] = 18000 *jml;
         break;

      case 2:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jml;
         baru->hargaNasi[1] =  20000 * jml;
         break;

      case 3:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >>jml;
         baru->hargaNasi[2] =25000  *jml;
         break;
   }
   baru->harnas = baru->hargaNasi[0] + baru->hargaNasi[1] +baru-> hargaNasi[2];

}

void bakso(){
   system("cls");
    int bakso,jml;
    baru = (struct pelanggan*)malloc(sizeof(struct pelanggan));
   cout << "\n================== Menu Bakso ==================";
   cout << "\n1. Bakso urat          Rp.17.000";
   cout << "\n2. Bakso jumbo         Rp.20.000";
   cout << "\n3. Bakso biasa         Rp.14.000";
   cout << "\nSilahkan Memilih Menu Bakso Yang Anda Inginkan :";
   cin >> bakso;
   switch (bakso) {
      case 1:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jml;
         baru->hargaBakso[0] = 17000 * jml;
         break;

      case 2:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >>jml;
         baru->hargaBakso[1] = 20000 * jml;
         break;

      case 3:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jml;
         baru->hargaBakso[2] = 14000 * jml;
         break;
   }

   baru->harso = baru->hargaBakso[0] + baru->hargaBakso[1] + baru->hargaBakso[2];

}

void mie(){
   system("cls");
    int mie,jml;
   baru = (struct pelanggan*)malloc(sizeof(struct pelanggan));
   cout << "\n================== Menu Mie Ayam ==================";
   cout << "\n1. Mie ayam ceker         Rp.17.000";
   cout << "\n2. mie ayam bakso         Rp.17.000";
   cout << "\n3. Mie ayam biasa         Rp.14.000";
   cout << "\nSilahkan Memilih Menu Bakso Yang Anda Inginkan :";
   cin >> mie;
   switch (mie) {
      case 1:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jml;
         baru->hargaMie[0] =  17000 * jml;
         break;

      case 2:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >>jml;
         baru->hargaMie[1] =  17000 * jml;
         break;

      case 3:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jml;
         baru->hargaMie[2] = 14000 * jml;
         break;
   }
   baru->harmie =  baru->hargaMie[0] +  baru->hargaMie[1]  +  baru->hargaMie[2];

}

void total(){
    baru = (struct pelanggan*)malloc(sizeof(struct pelanggan));
    system("cls");
    baru -> harga = baru->harnas + baru->harmie + baru->harso;
 
    cout<<"\nHarga yang Harus dibayar :Rp."<<baru->harga;
    

   
}
void tambah_data(){
   system("cls");
   baru = (struct pelanggan*)malloc(sizeof(struct pelanggan));
   char choice;
   cout<<"\t------------------------- Menu Utama ------------------------- "<<endl;
   cout<<"\nNama pelanggan :";
   fflush(stdin);
   cin>>baru->nama;
   menu:
   cout<<"\nDaftar Menu   :"<<endl;
   cout<<"1.Nasi Goreng";
   cout<<"\n2.Bakso";
   cout<<"\n3.Mie ayam";
   cout<<"\nMenu apa yang anda inginkan :";cin>>baru->pili;

    switch(baru->pili){
        case 1:
        nasi();
        break;

        case 2:
        bakso();
        break;

        case 3:
        mie();
        break;
    }

    cout<<"Ingin menambah pesanan lagi ?(Y/N) :";cin>>choice;

    if(choice == 'Y' || choice == 'y'){
        goto menu;
    }
        else if(choice == 'N' || choice =='n'){
            fflush(stdin);
            total();
        }


}

void Lihat_data(){

}

void  hapus(){

}

void menu(){
    time(&local);
    int pil;
    menu:
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\tRUMAH MAKAN BERKAH"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Waktu :"<<ctime(&local)<<endl;
    cout<<"Pilihan :"<<endl;
    cout<<"1. Tambah Data Pelanggan"<<endl;
    cout<<"2. Lihat Data Pelanggan"<<endl;
    cout<<"3. Hapus Semua Data"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Pilihan :";cin>>pil;

    switch(pil){
        case 1:
        tambah_data();
        break;

        case 2 :
        Lihat_data();
        break;

        case 3:
        hapus();
        break;

        case 4:
        system("cls");
        cout<<"Terima Kasih Telah Membeli Makanan di Rumah Makan Kami";

    }
}   

int main(){
    menu();
}
