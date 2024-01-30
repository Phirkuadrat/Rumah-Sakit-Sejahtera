#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cari_dokter_registrasi(){
    int baris, ditemukan=0;
    char cariDokter[30];
    printf("\nMasukan nama poliklinik: ");
    scanf(" %[^\n]s",&cariDokter);

    system("cls");
    printf("===================================================================================================================================================\n");
    printf("|                                                           Daftar Registrasi Ulang                                                                \n");
    printf("===================================================================================================================================================\n");
    printf("| %-3s | %-30s | %-10s | %-30s | %-30s | %-12s |\n", "No" ,"Nama Pasien", "Tanggal Registrasi", "Poliklinik", "Nama Dokter", "Status Pembayaran");
    printf("===================================================================================================================================================\n");
    FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
    while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
        if (baris==12){
            if(strcmp(cariDokter, registrasiUlang.dokter.nama)==0){
                ditemukan=1;
                printf("| %-3d | %-30s | %-18d | %-30s | %-30s | %-17s |\n", registrasiUlang.kode, registrasiUlang.pasien.nama, registrasiUlang.tanggal, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.statusPembayaran); 
            }
        }
    }
    printf("===================================================================================================================================================\n");

    if (ditemukan == 1){
        fclose(fregistrasi);
        pilih_registrasiUlang();
    } else {
        fclose(fregistrasi);
        system("cls");
        printf(ANSI_COLOR_RED "Registrasi ulang dengan dokter tersebut tidak tersedia\n\n" ANSI_COLOR_RESET);
    }
}

void cari_poliklinik_registrasi(){
    int baris, ditemukan=0;
    char cariPoliklinik[30];
    printf("\nMasukan nama poliklinik: ");
    scanf(" %[^\n]s",&cariPoliklinik);


    system("cls");
    printf("===================================================================================================================================================\n");
    printf("|                                                           Daftar Registrasi Ulang                                                                \n");
    printf("===================================================================================================================================================\n");
    printf("| %-3s | %-30s | %-10s | %-30s | %-30s | %-12s |\n", "No" ,"Nama Pasien", "Tanggal Registrasi", "Poliklinik", "Nama Dokter", "Status Pembayaran");
    printf("===================================================================================================================================================\n");
    FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
    while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
        if (baris==12){
            if(strcmp(cariPoliklinik, registrasiUlang.poliklinik.nama)==0){
                ditemukan=1;
                printf("| %-3d | %-30s | %-18d | %-30s | %-30s | %-17s |\n", registrasiUlang.kode, registrasiUlang.pasien.nama, registrasiUlang.tanggal, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.statusPembayaran); 
            }
        }
    }
    printf("===================================================================================================================================================\n");

    if (ditemukan == 1){
        fclose(fregistrasi);
        pilih_registrasiUlang();
    } else {
        fclose(fregistrasi);
        system("cls");
        printf(ANSI_COLOR_RED "Registrasi ulang dengan poliklinik tersebut tidak tersedia\n\n" ANSI_COLOR_RESET);
    }
    
}

void cari_tanggal_registrasi(){
    int cariTanggal,n=0,baris, ditemukan;
    printf("\nMasukan Tanggal Registrasi Ulang: ");
    scanf("%d",&cariTanggal);
    
    FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
    while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
        if (baris==12){
            sort_tanggal[n] = registrasiUlang.tanggal;
            n++;
        }
    }

    bubblesort(n);

    int awal = 0, akhir = n - 1, tengah;
    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (sort_tanggal[tengah] == cariTanggal) {
            ditemukan = 1;
            break;
        } else if (sort_tanggal[tengah] < cariTanggal) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (ditemukan==1){
        rewind(fregistrasi);
        system("cls");
        printf("===================================================================================================================================================\n");
        printf("|                                                           Daftar Registrasi Ulang                                                                \n");
        printf("===================================================================================================================================================\n");
        printf("| %-3s | %-30s | %-10s | %-30s | %-30s | %-12s |\n", "No" ,"Nama Pasien", "Tanggal Registrasi", "Poliklinik", "Nama Dokter", "Status Pembayaran");
        printf("===================================================================================================================================================\n");
        while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
            if (baris==12){
                if (registrasiUlang.tanggal == sort_tanggal[tengah]){
                printf("| %-3d | %-30s | %-18d | %-30s | %-30s | %-17s |\n", registrasiUlang.kode, registrasiUlang.pasien.nama, registrasiUlang.tanggal, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.statusPembayaran); 
                }            
            }
        }
        printf("===================================================================================================================================================\n");
        fclose(fregistrasi);
        pilih_registrasiUlang();
    } else {
        system("cls");
        printf(ANSI_COLOR_RED "Registrasi ulang dengan tanggal tersebut tidak tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fregistrasi);
}

void menu_cari_registrasiUlang(){
    int menu;
    printf("=====================================\n");
    printf("         Cari Registrasi Ulang\n");      
    printf("=====================================\n");
    printf("[1] Berdasarkan Tanggal Registrasi\n[2] Berdasarkan Poliklinik Tujuan\n[3] Berdasarkan Nama Dokter\n");
    printf("-------------------------------------\nMasukan Pilihan: ");
    scanf("%d",&menu);
    switch (menu){
        case 1:
            cari_tanggal_registrasi();
            break;

        case 2:
            cari_poliklinik_registrasi();
            break;

        case 3:
            cari_dokter_registrasi();
            break;

        default:
            break;
    }
}

void cetak_nota(){
    int menu;
    printf("===================================================\n");
    printf("                Nota Pembayaran\n");      
    printf("===================================================\n");
    printf("Kode Registrasi: %d\n", registrasiUlang.kode);
    printf("Tanggal Registrasi: %d\n", registrasiUlang.tanggal);
    printf("Nama Pasien: %s\n", registrasiUlang.pasien.nama);
    printf("No Hp: %s\n", registrasiUlang.pasien.NoHP);
    printf("Jenis Kelamin: %s\n", registrasiUlang.pasien.kelamin);
    printf("Tanggal Lahir: %d\n", registrasiUlang.pasien.lahir);
    printf("Poliklinik Tujuan: %s\n", registrasiUlang.poliklinik.nama);
    printf("Nama Dokter: %s\n", registrasiUlang.dokter.nama);
    printf("Asuransi: %s\n", registrasiUlang.asuransi);
    printf("---------------------------------------------------\n");
    printf("Registrasi ulang dikenakan biaya\ndikenakan tambahan sebesar\nRp.25.000\n");
    printf("---------------------------------------------------\n");
    printf("Biaya Konsultasi: Rp.%ld\n", registrasiUlang.poliklinik.biaya);
    printf("Total Bayar: Rp.%ld\n", registrasiUlang.totalBayar);
    printf("===================================================\n");
    printf("*Nota sudah dicetak, input berapa saja untuk kembali\n");
    printf("---------------------------------------------------\n");
    scanf("%d",&menu);
}

void konfirmasi_pembayaran(int pilihan){
    int menu,ditemukan=0;
    printf("\n[1] Lunas\n[2] Belum Lunas\n-----------------\nMasukan Pilihan: ");
    scanf("%d",&menu);
    switch (menu){
        case 1:
            strcpy(ubah_statusPembayaran ,"Lunas");
            ditemukan=1;
            break;
        
        case 2:
            strcpy(ubah_statusPembayaran,"Belum Lunas");
            ditemukan=1;
            break;

        default:
            system("cls");
            printf(ANSI_COLOR_RED "Menu Tidak Ditemukan\n\n" ANSI_COLOR_RESET);
            break;
    }

    if (ditemukan==1){
        int baris;
        FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
        FILE* ftemp = fopen("temp.txt","w+");

        while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
            if (baris==12){
                if (pilihan == registrasiUlang.kode){
                    fprintf(ftemp, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %s\nNo Hp: %s\nJenis Kelamin: %s\nTanggal Lahir: %d\nPoliklinik: %s\nDokter: %s\nAsuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %s\n\n", registrasiUlang.kode, registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, registrasiUlang.poliklinik.biaya, registrasiUlang.totalBayar, ubah_statusPembayaran);
                } else {
                    fprintf(ftemp, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %s\nNo Hp: %s\nJenis Kelamin: %s\nTanggal Lahir: %d\nPoliklinik: %s\nDokter: %s\nAsuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %s\n\n", registrasiUlang.kode, registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, registrasiUlang.poliklinik.biaya, registrasiUlang.totalBayar, registrasiUlang.statusPembayaran);
                }
            }
        }
        fclose(fregistrasi);
        fclose(ftemp);
        remove("registrasi_ulang.txt");
        rename ("temp.txt", "registrasi_ulang.txt");
        system("cls");
        printf(ANSI_COLOR_GREEN "Pembayaran Berhasil Dikonfirmasi\n\n" ANSI_COLOR_RESET);
    }
}

void pilih_registrasiUlang(){
    int kodeRegistrasiUlang, baris, ditemukan=0, menu;
    printf("Masukan No Registrasi Ulang: ");
    scanf("%d",&kodeRegistrasiUlang);

    FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
    while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
        if (baris==12){
            if (kodeRegistrasiUlang == registrasiUlang.kode){
                ditemukan=1;
                printf("\n[1] Cetak Nota\n[2] Konfirmasi Pembayaran\n[3] Kembali\n-------------------------------\nMasukan Pilihan: ");
                scanf("%d",&menu);
                switch (menu){
                    case 1:
                        system("cls");
                        cetak_nota();
                        system("cls");
                        break;
                    case 2: 
                        fclose(fregistrasi);
                        konfirmasi_pembayaran(kodeRegistrasiUlang); 
                        break;
                    case 3: 
                        system("cls");
                        break;
                    default:
                        system("cls");
                        printf(ANSI_COLOR_RED "Menu Tidak Ditemukan\n\n" ANSI_COLOR_RESET);
                        break;
                }
            }
        }
    }
    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "Tidak ada data registrasi ulang dengan kode tersebut\n\n" ANSI_COLOR_RESET);
    }
    
    fclose(fregistrasi);
}

void list_registrasiUlang_sudahLunas(){
    int baris;
    FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
    if (fregistrasi == NULL || (fgetc(fregistrasi) == EOF)){
        printf(ANSI_COLOR_RED "Tidak ada data registrasi ulang\n\n" ANSI_COLOR_RESET);
    } else {
        rewind(fregistrasi);
        printf("===================================================================================================================================================\n");
        printf("|                                                           Daftar Registrasi Ulang                                                                \n");
        printf("===================================================================================================================================================\n");
        printf("| %-3s | %-30s | %-10s | %-30s | %-30s | %-12s |\n", "No" ,"Nama Pasien", "Tanggal Registrasi", "Poliklinik", "Nama Dokter", "Status Pembayaran");
        printf("===================================================================================================================================================\n");
        while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
            if (baris==12){
                if (strcmp(registrasiUlang.statusPembayaran, "Lunas")==0){
                    printf("| %-3d | %-30s | %-18d | %-30s | %-30s | %-17s |\n", registrasiUlang.kode, registrasiUlang.pasien.nama, registrasiUlang.tanggal, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.statusPembayaran);
                }
            }
        }
        printf("===================================================================================================================================================\n");
    }
    fclose(fregistrasi);
}

void list_registrasiUlang_belumLunas(){
    int baris;
    FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
    if (fregistrasi == NULL || (fgetc(fregistrasi) == EOF)){
        printf(ANSI_COLOR_RED "Tidak ada data registrasi ulang\n\n" ANSI_COLOR_RESET);
    } else {
        rewind(fregistrasi);
        printf("===================================================================================================================================================\n");
        printf("|                                                           Daftar Registrasi Ulang                                                                \n");
        printf("===================================================================================================================================================\n");
        printf("| %-3s | %-30s | %-10s | %-30s | %-30s | %-12s |\n", "No" ,"Nama Pasien", "Tanggal Registrasi", "Poliklinik", "Nama Dokter", "Status Pembayaran");
        printf("===================================================================================================================================================\n");
        while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
            if (baris==12){
                if (strcmp(registrasiUlang.statusPembayaran, "Belum Lunas")==0){
                    printf("| %-3d | %-30s | %-18d | %-30s | %-30s | %-17s |\n", registrasiUlang.kode, registrasiUlang.pasien.nama, registrasiUlang.tanggal, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.statusPembayaran);
                }
            }
        }
        printf("===================================================================================================================================================\n");
    }
    fclose(fregistrasi);
}

void list_registrasiUlang(){
    int baris;
    FILE* fregistrasi = fopen("registrasi_ulang.txt","r");
    if (fregistrasi == NULL || (fgetc(fregistrasi) == EOF)){
        printf(ANSI_COLOR_RED "Tidak ada data registrasi ulang\n\n" ANSI_COLOR_RESET);
    } else {
        rewind(fregistrasi);

        printf("===================================================================================================================================================\n");
        printf("|                                                           Daftar Registrasi Ulang                                                                \n");
        printf("===================================================================================================================================================\n");
        printf("| %-3s | %-30s | %-10s | %-30s | %-30s | %-12s |\n", "No" ,"Nama Pasien", "Tanggal Registrasi", "Poliklinik", "Nama Dokter", "Status Pembayaran");
        printf("===================================================================================================================================================\n");
        while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
            if (baris==12){
                printf("| %-3d | %-30s | %-18d | %-30s | %-30s | %-17s |\n", registrasiUlang.kode, registrasiUlang.pasien.nama, registrasiUlang.tanggal, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.statusPembayaran);
            }
        }
        printf("===================================================================================================================================================\n");
    }
    fclose(fregistrasi);
}

void menu_list_registrasiUlang(){
    int menu;
    printf("===============================\n");
    printf("      List Registrasi Ulang\n");      
    printf("===============================\n");
    printf("[1] Tampilkan Semua Registrasi Ulang\n[2] Tampilkan Registrasi Ulang Yang Belum Lunas\n[3] Tampilkan Registrasi Ulang Yang Sudah Lunas\n[4] Kembali\n");
    printf("--------------------------------\nMasukan Pilihan: ");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        list_registrasiUlang();
        break;
    
    case 2:
        list_registrasiUlang_belumLunas();
        break;

    case 3:
        list_registrasiUlang_sudahLunas();
        break;

    case 4:
        system("cls");
        break;

    default:
        system("cls");
        printf(ANSI_COLOR_RED "Menu Tidak Ditemukan\n\n" ANSI_COLOR_RESET);
        break;
    }
}

int input_registrasiUlang_asuransi(){
    int menu, ditemukan=1;
    printf("\nApakah Menggunakan Asuransi:\n[1] Ya\n[2] Tidak\n----------------\nMasukan Pilihan: ");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        strcpy(registrasiUlang.asuransi,"Ya");
        registrasiUlang.totalBayar=0;
        strcpy(registrasiUlang.statusPembayaran ,"Lunas");
        break;

    case 2:
        strcpy(registrasiUlang.asuransi,"Tidak");
        registrasiUlang.totalBayar= registrasiUlang.poliklinik.biaya + 25000;
        strcpy(registrasiUlang.statusPembayaran ,"Belum Lunas");
        break;

    default:
        ditemukan=0;
        printf(ANSI_COLOR_RED "Menu Tidak Tersedia\n\n" ANSI_COLOR_RESET);
        break;
    }
    return ditemukan;
}

int input_registrasiUlang_dokter(){
    int baris,kodeDokter, ditemukan=0;
    printf("=================================================================================================\n");
    printf("|                                        Daftar Dokter                                          |\n");
    printf("=================================================================================================\n");
    printf("| %-3s | %-30s | %-30s | %-20s |\n", "Kode", "Nama Dokter", "Spesialis", "Poliklinik");
    printf("=================================================================================================\n");
    FILE* fdokter = fopen("dokter.txt","r");
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            if (strcmp(registrasiUlang.poliklinik.nama, dokter.poliklinik.nama)==0){
                printf("| %-4d | %-30s | %-30s | %-20s |\n", dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama);
                ditemukan=1;
            }
        }
    }
    
    if (ditemukan!=0){
        printf("=================================================================================================\n");
        printf("\nMasukan Kode Dokter: ");
        scanf("%d",&kodeDokter);

        rewind(fdokter);
        while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
            if (baris==4) {
                if (kodeDokter==dokter.kode){
                    registrasiUlang.dokter = dokter;
                }
            }
        }
        fclose(fdokter);
        ditemukan = input_registrasiUlang_asuransi();
        return ditemukan;
    } else {
        system("cls");
        printf(ANSI_COLOR_RED "Dokter Dengan Poliklinik Ini Tidak Ditemukan\n\n" ANSI_COLOR_RESET);
        fclose(fdokter);
        return 0;
    }
}

int input_registrasiUlang_poliklinik(){
    int kodePoliklinik, baris, ditemukan;
    list_poliklinik();
    printf("\nMasukan Kode Poliklinik: ");
    scanf("%d",&kodePoliklinik);

    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (poliklinik.kode == kodePoliklinik){
                ditemukan= 1;
                registrasiUlang.poliklinik = poliklinik;
            }
        }
    }
    fclose(fpoliklinik);
    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "Poliklinik Tidak Ditemukan\n\n" ANSI_COLOR_RESET);
        return 0;
    } else {
        printf("\n");
        ditemukan = input_registrasiUlang_dokter();
        return ditemukan;
    }
}

int input_registrasiUlang_pasien(){
    int kodePasien,baris, ditemukan=0;
    list_pasien();
    printf("Masukan Kode Pasien: ");
    scanf("%d",&kodePasien);

    FILE* fpasien= fopen("pasien.txt","r");
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF){
        if (baris==7) {
            if(kodePasien==pasien.kode){
                registrasiUlang.pasien = pasien;
                ditemukan=1;
            }
        }
    }

    fclose(fpasien);
    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "Pasien Tidak Ditemukan\n\n" ANSI_COLOR_RESET);
        return 0;
    } else {
        printf("\n");
        ditemukan = input_registrasiUlang_poliklinik();
        return ditemukan;
    }
}

void input_registrasiUlang(){
    int baris,ditemukan, kode=1;
    FILE* fregistrasi = fopen("registrasi_ulang.txt","a+");
    while ((baris = fscanf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %[^\n]\nNo Hp: %s\nJenis Kelamin: %[^\n]\nTanggal Lahir: %d\nPoliklinik: %[^\n]\nDokter: %[^\n]\n Asuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %[^\n]\n\n", &registrasiUlang.kode, &registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, &registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, &registrasiUlang.poliklinik.biaya, &registrasiUlang.totalBayar, registrasiUlang.statusPembayaran))!=EOF){
        if (baris==12){
            kode = registrasiUlang.kode + 1;
        }
    }
    printf("===============================\n");
    printf("     Input Registrasi Ulang\n");      
    printf("===============================\n");
    printf("Masukan Tanggal (DDMMYYYY): ");
    scanf("%d",&registrasiUlang.tanggal);
    printf("\n");
    ditemukan = input_registrasiUlang_pasien();
    if (ditemukan==1){
        fprintf(fregistrasi, "Kode: %d\nTanggal Registrasi: %d\nNama Pasien: %s\nNo Hp: %s\nJenis Kelamin: %s\nTanggal Lahir: %d\nPoliklinik: %s\nDokter: %s\nAsuransi: %s\nBiaya Konsultasi: %ld\nTotal Bayar: %ld\nStatus Pembayaran: %s\n\n", kode, registrasiUlang.tanggal, registrasiUlang.pasien.nama, registrasiUlang.pasien.NoHP, registrasiUlang.pasien.kelamin, registrasiUlang.pasien.lahir, registrasiUlang.poliklinik.nama, registrasiUlang.dokter.nama, registrasiUlang.asuransi, registrasiUlang.poliklinik.biaya, registrasiUlang.totalBayar, registrasiUlang.statusPembayaran);
        system("cls");
        registrasiUlang.kode = kode;
        cetak_nota();
        system("cls");
    }
    fclose(fregistrasi);
}

void menu_registrasiUlang(){
    int menu;
    while (menu!=4){
        printf("===============================\n");
        printf("      Menu Registrasi Ulang\n");      
        printf("===============================\n");
        printf("[1] Registrasi Ulang\n[2] List Registrasi Ulang\n[3] Cari Registrasi Ulang\n[4] Kembali\n");
        printf("----------------------\n");
        printf("Pilihan: ");
        scanf("%d",&menu);
        switch (menu){
        case 1:
            system("cls");
            input_registrasiUlang();
            break;

        case 2:
            system("cls");
            menu_list_registrasiUlang();
            pilih_registrasiUlang();
            break;

        case 3:
            system("cls");
            menu_cari_registrasiUlang();
            break;

        case 4:
            system("cls");
            break;
        
        default:
            system("cls");
            printf(ANSI_COLOR_RED "Menu Tidak Tersedia\n\n" ANSI_COLOR_RESET);
            break;
        }
    }
}