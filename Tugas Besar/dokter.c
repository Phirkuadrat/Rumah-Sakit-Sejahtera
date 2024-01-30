#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cari_dokter(){
    char inputDokter[30];
    int baris, ditemukan=0, menu, pilihan;
    printf("\nMasukan nama dokter: ");
    scanf(" %[^\n]s", inputDokter);
    
    FILE* fdokter= fopen("dokter.txt","r");
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            if (strcmp(inputDokter, dokter.nama)==0){
                system("cls");
                ditemukan=1;
                pilihan = dokter.kode;
                printf("===============================\n");
                printf("         Data Dokter\n");
                printf("===============================\n");
                printf("Nama Dokter: %s\n",dokter.nama);
                printf("Spesialis: %s\n",dokter.spesialis);
                printf("Poliklinik: %s\n",dokter.poliklinik.nama);
                printf("===============================\n");
                printf("[1] Edit data dokter\n[2] Hapus data dokter\n[3] Kembali\n");
                printf("----------------------\n");
                printf("Pilihan: ");
                scanf("%d",&menu);
                switch (menu){
                case 1:
                    fclose(fdokter);
                    system("cls");
                    input_edit_dokter(pilihan);
                    break;
                
                case 2:
                    fclose(fdokter);
                    tampil_data_dokter(pilihan);
                    break;

                case 3:
                    system("cls");
                    break;

                default:
                    system("cls");
                    printf(ANSI_COLOR_RED "Menu tidak tersedia\n\n" ANSI_COLOR_RESET);
                    break;
                }
            }
        }
    }

    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "Nama Dokter Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fdokter);
}

void ubah_data_dokter(int pilihan, int mode){
    FILE *fdokter = fopen("dokter.txt","r");
    FILE *temp = fopen("temp.txt","w+");

    int baris, kode=0;
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            if (dokter.kode!=pilihan){
                kode++;
                fprintf(temp, "Kode: %d\nNama: %s\nSpesialis: %s\nPoliklinik: %s\n\n", kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama);
            } else if (mode==2){
                kode++;
                fprintf(temp, "Kode: %d\nNama: %s\nSpesialis: %s\nPoliklinik: %s\n\n", kode, ubah_dokter.nama, ubah_dokter.spesialis, ubah_dokter.poliklinik.nama);
            }
        }
    }

    fclose(fdokter);
    fclose(temp);
    remove("dokter.txt");
    rename("temp.txt","dokter.txt");
    system("cls");
    if (mode==2){
        printf(ANSI_COLOR_GREEN "Data berhasil diedit\n\n" ANSI_COLOR_RESET);   
    } else {
        printf(ANSI_COLOR_GREEN "Data berhasil dihapus\n\n" ANSI_COLOR_RESET);   
    } 
}

void tampil_data_dokter(int pilihan){
    int baris, menu, mode = 1;
    system("cls");
    printf("===============================\n");
    printf("           Data Dokter\n");
    printf("===============================\n");
    FILE* fdokter= fopen("dokter.txt","r");
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            if (pilihan==dokter.kode){
                printf("Nama Dokter: %s\n", dokter.nama);
                printf("Spesialis: %s\n", dokter.spesialis);
                printf("Poliklinik: %s\n", dokter.poliklinik.nama);
            }
        }
    }
    printf("===============================\n");
    printf("Apakah anda yakin ingin menghapus data dokter \n[1] Ya \n[2] Tidak\n");
    printf("----------------------\n");
    printf("Pilihan: ");
    scanf("%d",&menu);
    if (menu == 1) {
        fclose(fdokter);
        ubah_data_dokter(pilihan, mode);
    } else {
        system("cls");
    }
    fclose(fdokter);
}

void hapus_dokter(){
    list_dokter();
    int pilihan, baris, ditemukan=0, mode=2;
    printf("No dokter yang ingin di edit: ");
    scanf("%d",&pilihan);

    FILE* fdokter= fopen("dokter.txt","r");
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            if (pilihan==dokter.kode){
                ditemukan=1;
                fclose(fdokter);
                tampil_data_dokter(pilihan);
            }
        }
    }

    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "No Dokter Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fdokter);
}

void input_edit_dokter(int pilihan){
    int baris, ditemukan=0,mode=2;
    printf("===============================\n");
    printf("         Edit Dokter\n");      
    printf("===============================\n");
    printf("Nama Dokter: ");
    scanf(" %[^\n]s", ubah_dokter.nama);
    printf("Spesialis : ");
    scanf(" %[^\n]s", ubah_dokter.spesialis);
    printf("\n");

    list_poliklinik();
    printf("Masukan Kode Poliklinik: ");
    scanf("%d",&ubah_dokter.poliklinik.kode);
    
    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (ubah_dokter.poliklinik.kode==poliklinik.kode){
                ubah_dokter.poliklinik = poliklinik;
                ditemukan=1;
            }
        }
    }

    if (ditemukan==1){
        fclose(fpoliklinik);
        ubah_data_dokter(pilihan, mode);
    } else {
        printf(ANSI_COLOR_RED "Kode poliklinik tidak ditemukan, dokter gagal diedit" ANSI_COLOR_RESET);
    }
    fclose(fpoliklinik);
};

void edit_dokter(){
    list_dokter();
    int pilihan, baris, ditemukan=0, mode=2;
    printf("No dokter yang ingin di edit: ");
    scanf("%d",&pilihan);

    FILE* fdokter= fopen("dokter.txt","r");
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            if (pilihan==dokter.kode){
                ditemukan=1;
                fclose(fdokter);
                system("cls");
                input_edit_dokter(pilihan);
            }
        }
    }

    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "No Dokter Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fdokter);
};

void list_dokter(){
    int baris;
    FILE* fdokter= fopen("dokter.txt","r");
    printf("=================================================================================================\n");
    printf("|                                        Daftar Dokter                                          |\n");
    printf("=================================================================================================\n");
    printf("| %-3s | %-30s | %-30s | %-20s |\n", "Kode", "Nama Dokter", "Spesialis", "Poliklinik");
    printf("=================================================================================================\n");
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            printf("| %-4d | %-30s | %-30s | %-20s |\n", dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama);
        }
    }
    printf("=================================================================================================\n");
    fclose(fdokter);
}

void input_dokter(){
    int baris, kode=1, ditemukan=0;
    FILE* fdokter= fopen("dokter.txt","a+");
    while ((baris = fscanf(fdokter, "Kode: %d\nNama: %[^\n]\nSpesialis: %[^\n]\nPoliklinik: %[^\n]\n\n", &dokter.kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama)) != EOF){
        if (baris==4) {
            kode = dokter.kode+1;
        }
    }

    printf("===============================\n");
    printf("         Input Dokter\n");      
    printf("===============================\n");
    printf("Nama Dokter: ");
    scanf(" %[^\n]s", dokter.nama);
    printf("Spesialis : ");
    scanf(" %[^\n]s", dokter.spesialis);
    printf("\n");

    list_poliklinik();
    printf("Masukan Kode Poliklinik: ");
    scanf("%d",&dokter.poliklinik.kode);
    baris=0;
    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (dokter.poliklinik.kode==poliklinik.kode){
                dokter.poliklinik = poliklinik;
                ditemukan=1;
            }
        }
    }
    
    if (ditemukan==1){
        fprintf(fdokter, "Kode: %d\nNama: %s\nSpesialis: %s\nPoliklinik: %s\n\n", kode, dokter.nama, dokter.spesialis, dokter.poliklinik.nama);
        system("cls");
        printf(ANSI_COLOR_GREEN "Dokter Berhasil Ditambahkan\n\n" ANSI_COLOR_RESET);
    } else {
        system("cls");
        printf(ANSI_COLOR_RED "Kode poliklinik tidak ditemukan, dokter gagal ditambahkan\n\n"ANSI_COLOR_RESET);
    }
    fclose(fdokter);
    fclose(fpoliklinik);
}

void menu_dokter(){
    int menu;
    while (menu!=6){
        printf("===============================\n");
        printf("         Menu Dokter\n");      
        printf("===============================\n");
        printf("[1] Input Dokter\n[2] List Dokter\n[3] Edit Dokter\n[4] Hapus Dokter\n[5] Cari Dokter\n[6] Kembali\n");
        printf("----------------------\n");
        printf("Pilihan: ");
        scanf("%d",&menu);
        switch (menu){
        case 1:
            system("cls");
            input_dokter();
            break;

        case 2:
            system("cls");
            list_dokter();
            break;

        case 3:
            system("cls");
            edit_dokter();
            break;

        case 4:
            system("cls");
            hapus_dokter();
            break;
        
        case 5:
            cari_dokter();
            break;

        case 6:
            system("cls");
            break;

        default:
            system("cls");
            printf(ANSI_COLOR_RED "Menu Tidak Tersedia\n\n" ANSI_COLOR_RESET);
            break;
        }
    }
}
