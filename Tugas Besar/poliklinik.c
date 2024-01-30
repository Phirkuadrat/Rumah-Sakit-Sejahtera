#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_cari_poliklinik(){
    char inputPoliklinik[30];
    int baris, ditemukan=0, menu, mode, pilihan;
    printf("\nMasukan nama poliklinik: ");
    scanf(" %[^\n]s", inputPoliklinik);
    
    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (strcmp(inputPoliklinik, poliklinik.nama)==0){
                system("cls");
                pilihan=poliklinik.kode;
                ditemukan=1;
                printf("===============================\n");
                printf("        Data Poliklinik\n");
                printf("===============================\n");
                printf("Nama Poliklinik: %s\n",poliklinik.nama);
                printf("Biaya: Rp.%d\n",poliklinik.biaya);
                printf("===============================\n");
                printf("[1] Edit data poliklinik\n[2] Hapus data poliklinik\n[3] Kembali\n");
                printf("----------------------\n");
                printf("Pilihan: ");
                scanf("%d",&menu);
                switch (menu){
                case 1:
                    fclose(fpoliklinik);
                    mode=2;
                    input_edit_poliklinik();
                    ubah_data_poliklinik(pilihan, mode);
                    break;
                
                case 2:
                    fclose(fpoliklinik);
                    tampil_data_poliklinik(pilihan);
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
        printf(ANSI_COLOR_RED "Nama Poliklinik Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fpoliklinik);
    
}

void ubah_data_poliklinik(int pilihan, int mode){
    FILE *fpoliklinik = fopen("poliklinik.txt","r");
    FILE *temp = fopen("temp.txt","w+");

    int baris, kode=0;
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (poliklinik.kode!=pilihan){
                kode++;
                fprintf(temp, "Kode: %d\nNama: %s\nBiaya: %d\n\n", kode, poliklinik.nama, poliklinik.biaya);
            } else if (mode==2){
                kode++;
                fprintf(temp, "Kode: %d\nNama: %s\nBiaya: %d\n\n", kode, ubah_poliklinik.nama, ubah_poliklinik.biaya);
            }
        }
    }

    fclose(fpoliklinik);
    fclose(temp);
    remove("poliklinik.txt");
    rename("temp.txt","poliklinik.txt");
    system("cls");
    if (mode==2){
        printf(ANSI_COLOR_GREEN "Data berhasil diedit\n\n" ANSI_COLOR_RESET);   
    } else {
        printf(ANSI_COLOR_GREEN "Data berhasil dihapus\n\n" ANSI_COLOR_RESET);   
    } 
}

void tampil_data_poliklinik(int pilihan){
    int baris, menu, mode = 1;
    system("cls");
    printf("===============================\n");
    printf("        Data Poliklinik\n");
    printf("===============================\n");
    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (pilihan==poliklinik.kode){
                printf("Nama Poliklinik: %s\n",poliklinik.nama);
                printf("Biaya: Rp.%d\n",poliklinik.biaya);
            }
        }
    }
    printf("===============================\n");
    printf("Apakah anda yakin ingin menghapus data poliklinik \n[1] Ya \n[2] Tidak\n");
    printf("----------------------\n");
    printf("Pilihan: ");
    scanf("%d", &menu);
    if (menu == 1) {
        fclose(fpoliklinik);
        ubah_data_poliklinik(pilihan, mode);
    } else {
        system("cls");
    }
    fclose(fpoliklinik);
}

void hapus_poliklinik(){
    list_poliklinik();
    int pilihan, baris, ditemukan=0;
    printf("No poliklinik yang ingin di edit: ");
    scanf("%d",&pilihan);

    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (pilihan==poliklinik.kode){
                fclose(fpoliklinik);
                tampil_data_poliklinik(pilihan);
                ditemukan=1;
            }
        }
    }

    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "No Poliklinik Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fpoliklinik);

}

void input_edit_poliklinik(){
    system("cls");
    printf("===============================\n");
    printf("       Input Poliklinik\n");      
    printf("===============================\n");
    printf("Nama: ");
    scanf(" %[^\n]s", ubah_poliklinik.nama);
    printf("Biaya: Rp.");
    scanf("%d",&ubah_poliklinik.biaya);
}

void edit_poliklinik(){
    list_poliklinik();
    int pilihan, baris, ditemukan=0, mode=2;
    printf("No poliklinik yang ingin di edit: ");
    scanf("%d",&pilihan);

    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            if (pilihan==poliklinik.kode){
                fclose(fpoliklinik);
                input_edit_poliklinik();
                ubah_data_poliklinik(pilihan, mode);
                ditemukan=1;
            }
        }
    }

    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "No Poliklinik Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fpoliklinik);
}

void list_poliklinik(){
    int baris;
    FILE* fpoliklinik= fopen("poliklinik.txt","r");
    printf("===========================================\n");
    printf("|             Daftar Poliklinik           |\n");
    printf("===========================================\n");
    printf("| %-3s | %-20s | %-9s |\n", "Kode", "Nama Poliklinik", "Biaya");
    printf("===========================================\n");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            printf("| %-4d | %-20s | Rp.%-6d |\n", poliklinik.kode, poliklinik.nama, poliklinik.biaya);
        }
    }
    printf("===========================================\n");
    fclose(fpoliklinik);
}

void input_poliklinik(){
    int baris, kode=1;
    FILE* fpoliklinik= fopen("poliklinik.txt","a+");
    while ((baris = fscanf(fpoliklinik, "Kode: %d\nNama: %[^\n]\nBiaya: %d\n\n", &poliklinik.kode, poliklinik.nama, &poliklinik.biaya)) != EOF){
        if (baris==3) {
            kode = poliklinik.kode+1;
        }
    }
    printf("===============================\n");
    printf("       Input Poliklinik\n");      
    printf("===============================\n");
    printf("Nama Poliklinik: ");
    scanf(" %[^\n]s", poliklinik.nama);
    printf("Biaya: Rp.");
    scanf("%d",&poliklinik.biaya);
    
    fprintf(fpoliklinik, "Kode: %d\nNama: %s\nBiaya: %d\n\n", kode, poliklinik.nama, poliklinik.biaya);
    
    fclose(fpoliklinik);
    system("cls");
    printf(ANSI_COLOR_GREEN "Poliklinik Berhasil Ditambahkan\n\n" ANSI_COLOR_RESET);
}

void menu_poliklinik(){
    int menu;
    while (menu!=6){
        printf("===============================\n");
        printf("       Menu Poliklinik\n");      
        printf("===============================\n");
        printf("[1] Input Poliklinik\n[2] List Poliklinik\n[3] Edit Poliklinik\n[4] Hapus Poliklinik\n[5] Cari Poliklinik\n[6] Kembali\n");
        printf("----------------------\n");
        printf("Pilihan: ");
        scanf("%d",&menu);
        switch (menu){
        case 1:
            system("cls");
            input_poliklinik();
            break;

        case 2:
            system("cls");
            list_poliklinik();
            break;

        case 3:
            system("cls");
            edit_poliklinik();
            break;

        case 4:
            system("cls");
            hapus_poliklinik();
            break;
        
        case 5:
            menu_cari_poliklinik();
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