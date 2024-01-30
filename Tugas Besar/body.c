#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubblesort(int n){
    int i,j,temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (sort_tanggal[j] > sort_tanggal[j+1]){
                temp = sort_tanggal[j];
                sort_tanggal[j] = sort_tanggal[j+1];
                sort_tanggal[j+1] = temp;
            }
        }
    }
}

void menu_sesudah_login(){
    int menu;
    while (menu!=5){
        printf("========================================\n");
        printf("         Rumas Sakit Sejahtera\n");
        printf("========================================\n");
        printf("[1] Pasien\n[2] Poliklinik\n[3] Dokter\n[4] Registrasi Ulang\n[5] Kembali\n");
        printf("----------------------\n");
        printf("Pilihan: ");
        scanf("%d",&menu);
        switch (menu){
        case 1:
            system("cls");
            menu_pasien();
            break;

        case 2:
            system("cls");
            menu_poliklinik();
            break;

        case 3:
            system("cls");
            menu_dokter();
            break;

        case 4:
            system("cls");
            menu_registrasiUlang();
            break;
        
        case 5:
            system("cls");
            break;

        default:
            system("cls");
            printf(ANSI_COLOR_RED "Menu Tidak Tersedia\n\n" ANSI_COLOR_RESET);
            break;
        }
    }
}

int cek_login(char inputUsername[], char inputPassword []){
    FILE* file= fopen("akun.txt","r");
    while (fscanf(file, "kode: %d\nusername: %s\npassword: %s\nnama: %[^\n]\n\n", &akun.kode, akun.username, akun.password, akun.nama) != EOF){
        if (strcmp(akun.username, inputUsername) == 0 && strcmp(akun.password, inputPassword) == 0){
            fclose(file);
            return 1;
        }  
    }
    fclose(file);
    return 0;
}

void menu_login(){
    int menu=0;
    char inputUsername[30], inputPassword[30];
    FILE* file= fopen("akun.txt","r");
    if (file == NULL) {
        printf(ANSI_COLOR_RED "Tidak ada akun yang terdaftar, daftar terlebih dahulu!\n\n" ANSI_COLOR_RESET);
    } else {
        while (menu!=1){
            printf("========================================\n");
            printf("              Menu Login\n");
            printf("========================================\n");
            printf("Username (tekan '#' untuk kembali): ");
            scanf("%s", inputUsername);
            if (inputUsername[0] == '#') {
                menu = 0;
                system("cls");
                printf("Kembali\n\n");
                break;
            }
            printf("Password: ");
            scanf("%s", inputPassword);
            menu = cek_login(inputUsername, inputPassword);
            if (menu != 1) {
                system("cls");
                printf(ANSI_COLOR_RED "Username Atau Password Salah, Coba Lagi\n\n" ANSI_COLOR_RESET);
            } else {
                break;
            }
        }
        fclose(file);
        if (menu !=0){
            system("cls");
            printf(ANSI_COLOR_GREEN "Berhasil login\n\n" ANSI_COLOR_RESET);
            menu_sesudah_login();
        }   
    }
    fclose(file);
}

int cek_registrasi(char inputUsername[], char inputPassword[], char inputNama[]){
    if (strchr(inputUsername, '#') != NULL){
        return 1;
    }
    int baris;
    FILE* file = fopen("akun.txt", "a+");
    while ((baris = fscanf(file, "kode: %d\nusername: %s\npassword: %s\nnama: %[^\n]\n\n", &akun.kode, akun.username, akun.password, akun.nama)) != EOF){
        if (baris == 4){
            if (strcmp(akun.username, inputUsername) == 0){
                fclose(file);
                return 2;
            }
        }
    }

    int kode = akun.kode + 1;
    fprintf(file, "kode: %d\nusername: %s\npassword: %s\nnama: %s\n\n", kode, inputUsername, inputPassword, inputNama);
    fclose(file);
    return 0;
}

void menu_registrasi(){
    char inputUsername [30];
    char inputPassword [30];
    char inputNama [30];
    printf("========================================\n");
    printf("           Menu Registrasi\n");
    printf("========================================\n");
    printf("Masukan Username (maksimal 10 karakter): ");
    scanf("%s", inputUsername);
    printf("Masukan Password (maksimal 10 karakter): ");
    scanf("%s", inputPassword);
    printf("Masukan Nama (maksimal 10 karakter) : ");
    scanf(" %[^\n]s", inputNama);
    int hasil = cek_registrasi(inputUsername, inputPassword, inputNama);
    if (hasil == 1){
        system("cls");
        printf(ANSI_COLOR_RED "Terdapat penggunaan karakter khusus pada username. Akun gagal dibuat\n\n" ANSI_COLOR_RESET);
    } else if (hasil == 2){
        system("cls");
        printf(ANSI_COLOR_RED "Username sudah digunakan. Akun gagal dibuat\n\n" ANSI_COLOR_RESET);
    } else {
        system("cls");
        printf(ANSI_COLOR_GREEN "Akun berhasil dibuat\n\n" ANSI_COLOR_RESET);
    }
};

void menu(){
    int menu;
    while (menu!=3){
        printf("======================\n");
        printf("        Menu\n");
        printf("======================\n");
        printf("[1] Login\n[2] Registrasi\n[3] Keluar\n");
        printf("----------------------\n");
        printf("Pilihan: ");
        scanf("%d",&menu);
        switch (menu){
        case 1:
            system("cls");
            menu_login();
            break;

        case 2:
        system("cls");
            menu_registrasi();
            break;

        case 3:
            system("cls");
            printf("Program Selesai");
            break;
        
        default:
            system("cls");
            printf("Menu Tidak Tersedia\n\n");
            break;
        }
    }
}