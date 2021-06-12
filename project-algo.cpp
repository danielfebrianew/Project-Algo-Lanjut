#include <iostream>
#include <array>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

void input();
void tampilkan();
void searching();
void sorting();
void transaksi();

struct dvd{
	int no_KTP;
	string nama;
	string judul;
	string id_dvd;
};
dvd d[100];

int main(){
	char opsi;
	int pilihan;

	do{
		cout << "=======================" << endl;
		cout << "TUGAS PROJECT ALGO 2021" << endl;
		cout << "=======================" << endl;
		cout << "\t1. INPUT DATA" << endl;
		cout << "\t2. TAMPILKAN DATA" << endl;
		cout << "\t3. SEARCHING DATA" << endl;
		cout << "\t4. SORTING DATA" << endl;
		cout << "\t5. TRANSAKSI" << endl;
		cout << "\t6. KELUAR" << endl;
		cout << "=======================" << endl;
		cout << "=======================" << endl << endl;

		cout << "Masukkan Pilihan\t: "; cin >> pilihan;

		switch(pilihan){
			case 1 : 
				system("cls");
				input();
				cout << "y = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 2 :
				system("cls");
				tampilkan();
				cout << "y = Kembali ke Menu Awal \nn = Keluar dari Aplikasi" << endl << endl;
				cout << "Masukkan Pilihan : "; cin >> opsi;
				system("cls");
				break;
			case 3 :
				system("cls");
				searching();
				break;
			case 4 :
				system("cls");
				sorting();
				break;
			case 5 :
				system("cls");
				transaksi();
				break;
			case 6 :
				exit(1);
		}
	}while(opsi == 'y' || opsi == 'Y');

	system("pause");
	return 0;
}

void input(){
	int banyak_data;
	string nama_file;
	ofstream file;
	
	cout << "=======================" << endl;
	cout << "INPUT DATA KEPENDUDUKAN" << endl;
	cout << "=======================" << endl << endl;
	cout << "Masukkan Nama File\t: "; cin >> nama_file;

	cout << "\nBanyaknya Data = "; cin >> banyak_data;

	cout << "\nSilakan masukkan data peminjaman : " << endl;

	if(banyak_data == 1){
		cout << "\tNama Peminjam\t: "; cin.ignore(); getline(cin, d[0].nama);
		cout << "\tNomor KTP\t: "; cin >> d[0].no_KTP;
		cout << "\tJudul DVD\t: "; cin.ignore(); getline(cin, d[0].judul);
		cout << "\tId DVD\t\t: "; getline(cin, d[0].id_dvd);
		cout << endl;
	}else{
		cout << "\tNama Peminjam\t: "; cin.ignore(); getline(cin, d[0].nama);
		cout << "\tNomor KTP\t: "; cin >> d[0].no_KTP;
		cout << "\tJudul DVD\t: "; cin.ignore(); getline(cin, d[0].judul);
		cout << "\tId DVD\t\t: "; getline(cin, d[0].id_dvd);
		cout << endl;

		for(int i = 1; i < banyak_data; i++){
			cout << "\tNama Peminjam\t: "; getline(cin, d[i].nama);
			cout << "\tNomor KTP\t: "; cin >> d[i].no_KTP;
			cout << "\tJudul DVD\t: "; cin.ignore(); getline(cin, d[i].judul);
			cout << "\tId DVD\t\t: "; getline(cin, d[i].id_dvd);
			cout << endl;
		}
	}

	file.open(nama_file, ios::trunc);
	for(int i = 0; i < banyak_data; i++){
		file << d[i].nama << endl;
		file << d[i].no_KTP << endl;
		file << d[i].judul << endl;
		file << d[i].id_dvd << endl;
	}
	file.close();

	cout << "Data telah berhasil terinput!!" << endl << endl;
}

void tampilkan(){
	ifstream file;
	string nama_file, nama, judul, id;
	int no;

	cout << "==================="<< endl;
	cout << "DATA PEMINJAMAN DVD"<< endl;
	cout << "==================="<< endl << endl;
	cout << "Nama File\t: "; cin >> nama_file;
	cout << endl;

	cout << "========================================================================================"<< endl;
	cout << "Nama" << setw(15) << "Nomor KTP" << setw(15) << "Judul DVD" << setw(12) << "Id DVD" << endl;
	cout << "========================================================================================"<< endl;
	
	file.open(nama_file);
	while(!file.eof()){
		file.clear();
		getline(file,nama);
		cout << nama << setw(19);
		file >> no;
		cout << no << setw(15);
		file.ignore(numeric_limits<streamsize>::max(),'\n'); 
		getline(file,judul);
		cout << judul << setw(12);
		file >> id;
		cout << id << endl;
	}
	cout << "========================================================================================"<< endl;
}

void searching(){
	cout << "belum gayn hehe" << endl;
}

void sorting(){
	cout << "belum gayn hehe" << endl;
}

void transaksi(){
	cout << "belum gayn hehe" << endl;
}