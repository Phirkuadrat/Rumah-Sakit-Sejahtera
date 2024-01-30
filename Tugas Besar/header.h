#ifndef header_h
#define header_h

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct{
    int kode;
    char nama[30];
    char username[30];
    char password[30];
} data_user;

typedef struct{
    int kode;
    char nama[30];
    char NoHP[15];
    char alamat[30];
    char kelamin[15];
    char pekerjaan[30];
    long int lahir;
} data_pasien;

typedef struct{
    int kode;
    char nama[30];
    long int biaya;
} data_poliklinik;

typedef struct{
    int kode;
    char nama[30];
    char spesialis[30];
    data_poliklinik poliklinik;
} data_dokter;

typedef struct {
    int kode;
    int tanggal;
    data_pasien pasien;
    data_poliklinik poliklinik;
    data_dokter dokter;
    char asuransi[5];
    long int totalBayar;
    char statusPembayaran[20];
} data_registasiUlang;

data_user akun;
data_pasien pasien, ubah_pasien;
data_poliklinik poliklinik, ubah_poliklinik;
data_dokter dokter, ubah_dokter;
data_registasiUlang registrasiUlang;
char ubah_statusPembayaran[20];
int sort_tanggal[100];

void menu();
void menu_registrasi();
void menu_login();
int cek_login();
int cek_registrasi();
void menu_sesudah_login();

void menu_pasien();
void input_pasien();
void list_pasien();
void edit_pasien();
void input_edit_pasien();
void hapus_pasien();
void tampil_data_pasien(int pilihan);
void ubah_data_pasien(int pilihan, int mode);
void menu_cari_pasien();
void cari_nama_pasien(char inputNama[]);
void cari_tanggal_pasien(int cariTanggal);

void menu_poliklinik();
void input_poliklinik();
void list_poliklinik();
void edit_poliklinik();
void input_edit_poliklinik();
void hapus_poliklinik();
void tampil_data_poliklinik(int pilihan);
void ubah_data_poliklinik(int pilihan, int mode);
void menu_cari_poliklinik();


void cari_dokter();
void ubah_data_dokter(int pilihan, int mode);
void tampil_data_dokter(int pilihan);
void hapus_dokter();
void input_edit_dokter(int pilihan);
void list_dokter();
void input_dokter();
void menu_dokter();

void cari_dokter_registrasi();
void cari_poliklinik_registrasi();
void cari_tanggal_registrasi();
void menu_cari_registrasiUlang();
void cetak_nota();
void konfirmasi_pembayaran(int pilihan);
void pilih_registrasiUlang();
void list_registrasiUlang();
int input_registrasiUlang_asuransi();
int input_registrasiUlang_dokter();
int input_registrasiUlang_poliklinik();
int input_registrasiUlang_pasien();
void input_registrasiUlang();
void menu_registrasiUlang();

#endif