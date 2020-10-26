#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Alamat{
    char nama_jalan[100], kota[100], provinsi[100];
    int nomor_rumah;
};

struct Tanggal{
    int tanggal, tahun, bulan;
};

struct Dosen{
    int no, nidn;
    char nama[100], tempat[100];
    struct Alamat alamat;
    struct Tanggal tanggal_lahir;
};

struct Alamat input_alamat(void);
struct Tanggal input_tanggal(void);
struct Dosen input_dosen(void);
void print_data_dosen(struct Dosen data_dosen[], int maxSize);

int main(){
    
    int array_size = 4;
    int current_index = 0;
    struct Dosen list_dosen[array_size];
    
    printf("PROGRAM UNTUK INPUT DATA DOSEN SEBANYAK 5X \n\n");
    
    while (current_index <= 4) {
        list_dosen[current_index] = input_dosen();
        current_index++;
        
        puts("\n==============================================");
        printf("SUCCES: Dosen berhasil diinput\n");
        puts("==============================================\n");
        
    }
    
    print_data_dosen(list_dosen, array_size);
    
    return 0;
}


struct Dosen input_dosen(void){
    
    struct Dosen data_dosen;
    
    puts("\n==============================================");
    printf("INPUT DATA DOSEN\n");
    puts("==============================================\n");
    
    printf("Nomor dosen : ");
    scanf("%d", &data_dosen.no);
    
    printf("NIDN : ");
    scanf("%d", &data_dosen.nidn);
    
    printf("Nama : ");
    scanf(" %[^\n]s", data_dosen.nama);
    
    printf("Tempat : ");
    scanf(" %[^\n]s", data_dosen.tempat);
    
    data_dosen.tanggal_lahir = input_tanggal();
    data_dosen.alamat = input_alamat();
    
    return data_dosen;
    
}

struct Alamat input_alamat(void){
    
    struct Alamat data_alamat;
    
    puts("\n==============================================");
    printf("INPUT DATA ALAMAT\n");
    puts("==============================================\n");
    
    printf("Nama jalan : ");
    scanf(" %[^\n]s",data_alamat.nama_jalan);
    
    printf("Nomor Rumah : ");
    scanf("%d", &data_alamat.nomor_rumah);
    
    printf("Kota : ");
    scanf(" %[^\n]s",data_alamat.kota);
    
    printf("Provinsi : ");
    scanf(" %[^\n]s",data_alamat.provinsi); 
    
    return data_alamat;
    
}


struct Tanggal input_tanggal(void){
    
    struct Tanggal data_tanggal;
    int is_valid_bulan = 0;
    int is_valid_tanggal = 0;
    int bulan, tanggal, tahun;
    
    puts("\n==============================================");
    printf("INPUT DATA TANGGAL LAHIR\n");
    puts("==============================================\n");
    
    // input bulan dan validasi bulan
    while (is_valid_bulan == 0) {
        printf("Bulan (1-12) : ");
        scanf("%d", &bulan);
        
        if ((bulan >= 1) && (bulan <= 12)){
            is_valid_bulan = 1;
        }else{
            printf("Bulan error, masukan angka 1-12! \n");
            is_valid_bulan = 0;
        }
    }
    
    // input tanggal dan validasi tanggal
    while (is_valid_tanggal == 0) {
        
        printf("Tanggal (1-31) : ");
        scanf("%d", &tanggal);
        
        if (tanggal >= 1 && tanggal <= 31){
            
            //validasi bulan februari
            if (bulan == 2){
                
                if (tanggal > 29) {
                    printf("Tanggal Error, feburari tidak boleh melebihi 29! \n");
                    is_valid_tanggal = 0;
                }else{
                    is_valid_tanggal = 1;
                }
                
            // validasi bulan yang mempunyai tanggal < 31
            }else if ((bulan == 2) || (bulan == 4) || (bulan == 6) || (bulan == 9) || (bulan == 11)){
                
                if (tanggal > 30){
                    printf("Tanggal error, tidak ada tanggal %i di bulan %i \n", tanggal, bulan);
                    is_valid_tanggal = 0;
                }else{
                    is_valid_tanggal = 1;
                }
                
                
            }else{
                
                is_valid_tanggal = 1;
                
            }
            
            
        }else{
            
            printf("Tanggal error, masukan angka 1-31! \n");
            is_valid_tanggal = 0;
            
        }
        
    }
    
    
    
    printf("Tahun (contoh: 1995) : ");
    scanf("%d", &tahun);
    
    data_tanggal.tanggal = tanggal;
    data_tanggal.bulan = bulan;
    data_tanggal.tahun = tahun;
    
    return data_tanggal;
}


void print_data_dosen(struct Dosen data_dosen[], int maxSize){
    
    printf("\n## LIST DOSEN YANG BERHASIL DIINPUT ##\n\n");
    
    int i;
    struct Dosen on_dosen;
    
    for(i=0; i<=maxSize; i++){
        
        on_dosen = data_dosen[i];
      
        printf("Nama   : %s\n", on_dosen.nama);
        printf("NIDN   : %d\n", on_dosen.nidn);
        printf("TTL    : %d / %d / %d\n", on_dosen.tanggal_lahir.tanggal, on_dosen.tanggal_lahir.bulan, on_dosen.tanggal_lahir.tahun);
        printf("Alamat : Jalan %s nomor %d , kota %s , %s", on_dosen.alamat.nama_jalan, on_dosen.alamat.nomor_rumah, on_dosen.alamat.kota, on_dosen.alamat.provinsi);
        puts("\n------------------------------------------------\n");
    }
    
}

