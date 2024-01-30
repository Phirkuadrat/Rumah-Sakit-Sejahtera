#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cari_tanggal_pasien(int cariTanggal){
    int baris, n=0, ditemukan=0, menu, mode,pilihan;
    FILE* fpasien = fopen("pasien.txt", "r");
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF) {
        if (baris == 7) {
            sort_tanggal[n]=pasien.lahir;
            n++;
        }
    }
    bubblesort(n);
    
    int awal = 0, akhir = n - 1, tengah;
    while (awal <= akhir) {                             //Binarry Search//
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

    if (ditemukan == 0) {
        system("cls");
        printf(ANSI_COLOR_RED "Pasien dengan tanggal lahir tersebut tidak tersedia\n\n" ANSI_COLOR_RESET);
    } else {
        rewind(fpasien);
        while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF) {
            if (baris == 7) {
                if (sort_tanggal[tengah]==pasien.lahir){
                    system("cls");
                    pilihan = pasien.kode;
                    printf("===============================\n");
                    printf("          Data Pasien\n");
                    printf("===============================\n");
                    printf("Nama: %s\n", pasien.nama);
                    printf("No HP: %s\n", pasien.NoHP);
                    printf("Alamat: %s\n", pasien.alamat);
                    printf("Jenis Kelamin: %s\n", pasien.kelamin);
                    printf("Pekerjaan: %s\n", pasien.pekerjaan);
                    printf("Tanggal Lahir: %d\n", pasien.lahir);
                    printf("===============================\n");
                    printf("[1] Edit data pasien\n[2] Hapus data pasien\n[3] Kembali\n");
                    printf("----------------------\n");
                    printf("Pilihan: ");
                    scanf("%d",&menu);
                    switch (menu){
                        case 1:
                            fclose(fpasien);
                            mode=2;
                            input_edit_pasien();
                            ubah_data_pasien(pilihan, mode);
                            break;
                        
                        case 2:
                            fclose(fpasien);
                            tampil_data_pasien(pilihan);
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
    }
    fclose(fpasien);
}

void cari_nama_pasien(char inputNama[]){
    int baris, ditemukan, menu, mode, pilihan;
    FILE* fpasien = fopen("pasien.txt", "r+");
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF) {
        if (baris == 7) {
            if (strcmp(inputNama, pasien.nama)==0) {
                pilihan = pasien.kode;
                printf("===============================\n");
                printf("          Data Pasien\n");
                printf("===============================\n");
                printf("Nama: %s\n", pasien.nama);
                printf("No HP: %s\n", pasien.NoHP);
                printf("Alamat: %s\n", pasien.alamat);
                printf("Jenis Kelamin: %s\n", pasien.kelamin);
                printf("Pekerjaan: %s\n", pasien.pekerjaan);
                printf("Tanggal Lahir: %d\n", pasien.lahir);
                printf("===============================\n");
                printf("[1] Edit data pasien\n[2] Hapus data pasien\n[3] Kembali\n");
                printf("----------------------\n");
                printf("Pilihan: ");
                scanf("%d",&menu);
                switch (menu){
                case 1:
                    fclose(fpasien);
                    mode=2;
                    input_edit_pasien();
                    ubah_data_pasien(pilihan, mode);
                    break;
                
                case 2:
                    fclose(fpasien);
                    tampil_data_pasien(pilihan);
                    break;

                case 3:
                    system("cls");
                    break;

                default:
                    system("cls");
                    printf(ANSI_COLOR_RED "Menu tidak tersedia\n\n" ANSI_COLOR_RESET);
                    break;
                }
                ditemukan = 1;
            }
        }
    }
    
    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "No Pasien Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fpasien);
}

void menu_cari_pasien(){
    int menu, inputTanggal;
    char inputNama[30];
    printf("===============================\n");
    printf("          Cari Pasien\n");      
    printf("===============================\n");
    printf("[1] Berdasarkan Nama\n[2] Berdasarkan Tanggal Lahir\n");
    printf("----------------------\n");
    printf("Pilihan: ");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        printf("\nMasukan nama pasien: ");
        scanf(" %[^\n]s", inputNama);
        system("cls");
        cari_nama_pasien(inputNama);
        break;

    case 2:
        printf("\nMasukan tanggal lahir pasien: ");
        scanf("%d",&inputTanggal);
        system("cls");
        cari_tanggal_pasien(inputTanggal);
        break;
    
    default:
        printf(ANSI_COLOR_RED "Menu tidak tersedia" ANSI_COLOR_RESET);
        break;
    }

}

void ubah_data_pasien(int pilihan, int mode){
    int baris;
    FILE* fpasien = fopen("pasien.txt","r");
    FILE* temp = fopen("temp.txt","w+");

    int kode=0;
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF){
        if (baris==7) {
            if (pasien.kode != pilihan){
                kode++;
                fprintf(temp, "Kode: %d\nNama: %s\nNo HP: %s\nAlamat: %s\nJenis Kelamin: %s\nPekerjaan: %s\nTanggal Lahir: %d\n\n", kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, pasien.lahir);
            } else if (mode==2){
                kode++;
                fprintf(temp, "Kode: %d\nNama: %s\nNo HP: %s\nAlamat: %s\nJenis Kelamin: %s\nPekerjaan: %s\nTanggal Lahir: %d\n\n", kode, ubah_pasien.nama, ubah_pasien.NoHP, ubah_pasien.alamat, ubah_pasien.kelamin, ubah_pasien.pekerjaan, ubah_pasien.lahir);
            }
        }
    } 

    fclose(fpasien);
    fclose(temp);
    remove("pasien.txt");
    rename("temp.txt","pasien.txt");
    system("cls");
    if (mode==2){
        printf(ANSI_COLOR_GREEN "Data berhasil diedit\n\n" ANSI_COLOR_RESET);   
    } else {
        printf(ANSI_COLOR_GREEN "Data berhasil dihapus\n\n" ANSI_COLOR_RESET);   
    } 
}

void tampil_data_pasien(int pilihan){
    int baris, menu, mode = 1;
    system("cls");
    printf("===============================\n");
    printf("          Data Pasien\n");
    printf("===============================\n");
    FILE* fpasien = fopen("pasien.txt", "r");
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF) {
        if (baris == 7) {
            if (pilihan == pasien.kode) {
                printf("Nama: %s\n", pasien.nama);
                printf("No HP: %s\n", pasien.NoHP);
                printf("Alamat: %s\n", pasien.alamat);
                printf("Jenis Kelamin: %s\n", pasien.kelamin);
                printf("Pekerjaan: %s\n", pasien.pekerjaan);
                printf("Tanggal Lahir: %d\n", pasien.lahir);
            }
        }
    }
    printf("===============================\n");
    printf("Apakah anda yakin ingin menghapus data pasien \n[1] Ya \n[2] Tidak\n");
    printf("----------------------\n");
    printf("Pilihan: ");
    scanf("%d", &menu);
    if (menu == 1) {
        fclose(fpasien);
        ubah_data_pasien(pilihan, mode);
    } else {
        system("cls");
    }
    fclose(fpasien);
}

void hapus_pasien(){
    list_pasien();
    int pilihan, baris, ditemukan = 0;
    printf("No data pasien yang ingin dihapus: ");
    scanf("%d", &pilihan);

    FILE* fpasien = fopen("pasien.txt", "r");
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF) {
        if (baris == 7) {
            if (pilihan == pasien.kode) {
                fclose(fpasien);
                tampil_data_pasien(pilihan);
                ditemukan = 1;
            }
        }
    }

    if (ditemukan == 0) {
        system("cls");
        printf(ANSI_COLOR_RED "No Pasien Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fpasien);
}

void input_edit_pasien(){
    system("cls");
    printf("===============================\n");
    printf("          Edit Pasien\n");      
    printf("===============================\n");
    printf("Nama: ");
    scanf(" %[^\n]s", ubah_pasien.nama);
    printf("No HP: ");
    scanf("%s", ubah_pasien.NoHP);
    printf("Alamat: ");
    scanf(" %[^\n]s", ubah_pasien.alamat);
    printf("Jenis Kelamin: ");
    scanf(" %[^\n]s", ubah_pasien.kelamin);
    printf("Pekerjaan: ");
    scanf(" %[^\n]s", ubah_pasien.pekerjaan);
    printf("Tanggal Lahir (DDMMYYYY): ");
    scanf("%d",&ubah_pasien.lahir);
}

void edit_pasien(){
    list_pasien();
    int pilihan, baris, ditemukan=0, mode=2;
    printf("No data pasien yang ingin di edit: ");
    scanf("%d",&pilihan);

    FILE* fpasien= fopen("pasien.txt","r");
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF){
        if (baris==7) {
            if (pilihan==pasien.kode){
                fclose(fpasien);
                input_edit_pasien();
                ubah_data_pasien(pilihan, mode);
                ditemukan=1;
            }
        }
    } 

    if (ditemukan==0){
        system("cls");
        printf(ANSI_COLOR_RED "No Pasien Tidak Tersedia\n\n" ANSI_COLOR_RESET);
    }
    fclose(fpasien);
}

void list_pasien(){
    int baris;
    FILE* fpasien = fopen("pasien.txt", "r");
    if (fpasien==NULL || (fgetc(fpasien) == EOF)){
        printf(ANSI_COLOR_RED "Tidak ada data pasien\n\n" ANSI_COLOR_RESET);
    } else {
        rewind(fpasien);
        printf("====================================================================================================================================================\n");
        printf("|                                                                Daftar Pasien                                                                     |\n");
        printf("====================================================================================================================================================\n");
        printf("| %-3s | %-30s | %-15s | %-30s | %-15s | %-20s | %-10s |\n", "No" ,"Nama", "No HP", "Alamat", "Jenis Kelamin", "Pekerjaan", "Tanggal Lahir");
        printf("====================================================================================================================================================\n");
        while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF) {
            if (baris == 7) {
                printf("| %-3d | %-30s | %-15s | %-30s | %-15s | %-20s | %-13d |\n", pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, pasien.lahir);
            }
        }
        printf("====================================================================================================================================================\n\n");
    }
    fclose(fpasien);
}

void input_pasien(){
    int baris, kode=1;
    FILE* fpasien= fopen("pasien.txt","a+");
    while ((baris = fscanf(fpasien, "Kode: %d\nNama: %[^\n]\nNo HP: %s\nAlamat: %[^\n]\nJenis Kelamin: %[^\n]\nPekerjaan: %[^\n]\nTanggal Lahir: %d\n\n", &pasien.kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, &pasien.lahir)) != EOF){
        if (baris==7) {
            kode = pasien.kode+1;
        }
    }
    printf("===============================\n");
    printf("         Input Pasien\n");      
    printf("===============================\n");
    printf("Nama: ");
    scanf(" %[^\n]s", pasien.nama);
    printf("No HP: ");
    scanf("%s", pasien.NoHP);
    printf("Alamat: ");
    scanf(" %[^\n]s", pasien.alamat);
    printf("Jenis Kelamin: ");
    scanf(" %[^\n]", pasien.kelamin);
    printf("Pekerjaan: ");
    scanf(" %[^\n]s", pasien.pekerjaan);
    printf("Tanggal Lahir (DDMMYYYY): ");
    scanf("%d",&pasien.lahir);
    
    fprintf(fpasien, "Kode: %d\nNama: %s\nNo HP: %s\nAlamat: %s\nJenis Kelamin: %s\nPekerjaan: %s\nTanggal Lahir: %d\n\n", kode, pasien.nama, pasien.NoHP, pasien.alamat, pasien.kelamin, pasien.pekerjaan, pasien.lahir);
    
    fclose(fpasien);
    system("cls");
    printf(ANSI_COLOR_GREEN "Pasien Berhasil Ditambahkan\n\n" ANSI_COLOR_RESET);
}

void menu_pasien(){
    int menu;
    while (menu!=6){
        printf("===============================\n");
        printf("         Menu Pasien\n");      
        printf("===============================\n");
        printf("[1] Input Pasien\n[2] List Pasien\n[3] Edit Pasien\n[4] Hapus Pasien\n[5] Cari Pasien\n[6] Kembali\n");
        printf("----------------------\n");
        printf("Pilihan: ");
        scanf("%d",&menu);
        switch (menu){
        case 1:
            system("cls");
            input_pasien();
            break;

        case 2:
            system("cls");
            list_pasien();
            break;

        case 3:
            system("cls");
            edit_pasien();
            break;

        case 4:
            system("cls");
            hapus_pasien();
            break;
        
        case 5:
            system("cls");
            menu_cari_pasien();
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