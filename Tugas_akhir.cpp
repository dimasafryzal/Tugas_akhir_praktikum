#include <iostream>
#include <conio.h>
using namespace std;

void Nasi_goreng(), bakso(), Mie_Ayam(), total(), identitas(), makanan_utama();

struct pelanggan {
   string nama;
   char gen;
   int totalbeli;
   void inputPelanggan(string nama, char gen) {
      this->nama = nama;
      this->gen = gen;
   }
   pelanggan *next;
}*head=NULL, *tail, *curr, *newNode;

int hargaNasi[3] = {0, 0, 0}, jumlahNasi[3] = {0, 0, 0};
int hargaBakso[3] = {0, 0, 0}, jumlahBakso[3] = {0, 0, 0};
int hargaMie[3] = {0, 0, 0}, jumlahMie[3] = {0, 0, 0};
void tambahdata(){
   if(head!=NULL){
      newNode = new pelanggan();
      newNode->next=NULL;
      tail->next=newNode;
      tail=newNode;
   }else{
      head=new pelanggan();
      head->next=NULL;
      tail=head;
   }
}
void identitas() {
   string inputNama;
   char inputGen;
   tambahdata();
   cout << "Masukkan nama anda :";
   getline(cin>>ws,inputNama);
   cout << "\nGender anda (L/P)? :";
   cin >> inputGen;
   tail->inputPelanggan(inputNama, inputGen);
   system("cls");
   makanan_utama();
}
void daftarpelanggan(){
   curr=head;
   while(curr!=NULL){
      cout<<"Nama            : "<<curr->nama<<endl;
      cout<<"Jenis Kelamin   : "<<curr->gen<<endl;
      cout<<"Total Transaksi : Rp."<<curr->totalbeli<<endl;
      curr=curr->next;
      cout<<endl;
   }
}
void menu_utama(){
   system("cls");
   int input;
   cout<<"=================== SELAMAT DATANG DI RUMAH MAKAN BERKAH ===================\n";
   cout<<"1. Tambah Pelanggan"<<endl;
   cout<<"2. Lihat Data Pelanggan"<<endl;
   cout<<"3. Exit"<<endl;
   cout<<"Pilih : ";
   cin>>input;
   system("cls");
   switch (input)
   {
   case 1:
      identitas();
      break;
   case 2:
      daftarpelanggan();
      getch();
      menu_utama();
      break;
   case 3:
      return;
   default:
      break;
   }
}

void makanan_utama() {
   system("cls");
   int pil;
   char input;
   cout << "\t\t================== SELAMAT DATANG DI RUMAH MAKAN BERKAH ==================\n";
   if (tail->gen == 'L' || tail->gen == 'l') {
      cout << "\nSilahkan memilih menu yang anda inginkan mas :" << tail->nama << "\n";
   }

   else if (tail->gen == 'P' || tail->gen == 'p') {
      cout << "\nSilahkan memilih menu yang anda inginkan mba :" << tail->nama << "\n";
   }
pil:
   cout << "\n================== Menu Makanan ==================";
   cout << "\n1. Nasi Goreng";
   cout << "\n2. Bakso";
   cout << "\n3. Mie Ayam\n";
   cout << "Masukkan pilihan yang anda inginkan :";
   cin >> pil;
   switch (pil) {
      case 1:
         system("cls");
         Nasi_goreng();
         break;

      case 2:
         system("cls");
         bakso();
         break;

      case 3:
         system("cls");
         Mie_Ayam();
         break;
   }

   cout << "Tambah menu lagi ?(Y/N) :";
   cin >> input;
   if (input == 'Y' || input == 'y') {
      system("pause");
      system("cls");
      goto pil;
   }

   else if (input == 'N' || input == 'n') {
      total();
   }
}

void Nasi_goreng() {
   int nas;
   cout << "\n================== Menu Nasi Goreng ==================";
   cout << "\n1. Nasi goreng sosis       Rp.18.000";
   cout << "\n2. Nasi goreng ayam        Rp.20.000";
   cout << "\n3. Nasi goreng seafood     Rp.25.000";
   cout << "\nSilahkan memilih menu nasi goreng yang anda inginkan :";
   cin >> nas;
   switch (nas) {
      case 1:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahNasi[0];
         hargaNasi[0] = 18000 * jumlahNasi[0];
         jumlahNasi[0]++;
         tail->totalbeli+=hargaNasi[0];
         break;

      case 2:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahNasi[1];
         hargaNasi[1] = 20000 * jumlahNasi[1];
         jumlahNasi[1]++;
         tail->totalbeli+=hargaNasi[1];
         break;

      case 3:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahNasi[2];
         hargaNasi[2] = 25000 * jumlahNasi[2];
         jumlahNasi[2]++;
         tail->totalbeli+=hargaNasi[2];
         break;
   }
}

void Mie_Ayam() {
   int mie;
   cout << "\n================== Menu Mie Ayam ==================";
   cout << "\n1. Mie ayam ceker         Rp.17.000";
   cout << "\n2. mie ayam bakso         Rp.17.000";
   cout << "\n3. Mie ayam biasa         Rp.14.000";
   cout << "\nSilahkan Memilih Menu Bakso Yang Anda Inginkan :";
   cin >> mie;
   switch (mie) {
      case 1:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahMie[0];
         hargaMie[0] = 17000 * jumlahMie[0];
         jumlahMie[0]++;
         tail->totalbeli+=hargaMie[0];
         break;

      case 2:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahMie[1];
         hargaMie[1] = 17000 * jumlahMie[1];
         jumlahMie[1]++;
         tail->totalbeli+=hargaMie[1];
         break;

      case 3:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahMie[2];
         hargaMie[2] = 14000 * jumlahMie[2];
         jumlahMie[2]++;
         tail->totalbeli+=hargaMie[2];
         break;
   }
}

void bakso() {
   int bakso;
   cout << "\n================== Menu Bakso ==================";
   cout << "\n1. Bakso urat          Rp.17.000";
   cout << "\n2. Bakso jumbo         Rp.20.000";
   cout << "\n3. Bakso biasa         Rp.14.000";
   cout << "\nSilahkan Memilih Menu Bakso Yang Anda Inginkan :";
   cin >> bakso;
   switch (bakso) {
      case 1:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahBakso[0];
         hargaBakso[0] = 17000 * jumlahBakso[0];
         jumlahBakso[0]++;
         tail->totalbeli+=hargaBakso[0];
         break;

      case 2:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahBakso[1];
         hargaBakso[1] = 17000 * jumlahBakso[1];
         jumlahBakso[1]++;
         tail->totalbeli+=hargaBakso[1];
         break;

      case 3:
         cout << "Berapa jumlah yang anda inginkan :";
         cin >> jumlahBakso[2];
         hargaBakso[2] = 14000 * jumlahBakso[2];
         jumlahBakso[2]++;
         tail->totalbeli+=hargaBakso[2];
         break;
   }
}
void reset_harga(){
   for (int i = 0; i < 3; i++)
   {
      hargaBakso[i]=0;
      hargaMie[i]=0;
      hargaNasi[i]=0;
   }
   
}
void total() {
here:
   system("cls");
   int harga;
   cout << "-------------------------------------------------------" << endl;
   cout << "|  	             WARUNG BERKAH                   |" << endl;
   cout << "-------------------------------------------------------" << endl;
   cout << "\tNama Pemesan          : " << tail->nama << endl;
   cout << "\tTotal Pembayaran      : Rp " << hargaNasi[0] + hargaNasi[1] + hargaNasi[2] + hargaBakso[0] + hargaBakso[1] + hargaBakso[2] + hargaMie[0] + hargaMie[1] + hargaMie[2] << endl;
   
   cout << "--------------------------------------------" << endl;
   cout << "Silahkan bayar disini 		 : Rp.";
   cin >> harga;
   cout << endl;
   
   int kurang,uang;
   // Perulangan
   if (harga < hargaNasi[0] + hargaNasi[1] + hargaNasi[2] + hargaBakso[0] + hargaBakso[1] + hargaBakso[2] + hargaMie[0] + hargaMie[1] + hargaMie[2]) {
      kurang =  hargaNasi[0] + hargaNasi[1] + hargaNasi[2] + hargaBakso[0] + hargaBakso[1] + hargaBakso[2] + hargaMie[0] + hargaMie[1] + hargaMie[2] - harga;
      cout << "\nSaldo anda kurang, Silahkan bayar lagi : Rp."<<kurang;
      cout<<"\n\nMasukan nominal uang tambahan :Rp.";cin>>uang;
      uang -= kurang;

         if(uang == 0){
            cout<<"\n================== Terima Kasih Telah Belanja di Rumah Makan Kami ==================";
         }
   };
            if (harga >= hargaNasi[0] + hargaNasi[1] + hargaNasi[2] + hargaBakso[0] + hargaBakso[1] + hargaBakso[2] + hargaMie[0] + hargaMie[1] + hargaMie[2]){
           
            cout << "Uang yang anda bayar \t\t\t Rp. " << harga << endl;
            cout << "Uang kembalian \t\t\t\t Rp. " << harga -  (hargaNasi[0] + hargaNasi[1] + hargaNasi[2] + hargaBakso[0] + hargaBakso[1] + hargaBakso[2] + hargaMie[0] + hargaMie[1] + hargaMie[2]) << endl;
            cout << "##################################################" << endl;
            
            };
   getch();
   reset_harga();
   menu_utama();

}

int main() {
   menu_utama();
}