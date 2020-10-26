#include <stdio.h>
#include <string.h>
  
int main(){
    
    int bulan, tanggal;
    char nama[50];
    char zodiak[50];
    int is_valid_bulan = 0;
    int is_valid_tanggal = 0;
    
    
    printf("Masukan Nama : ");
    scanf(" %[^\n]s", nama);
    
    printf("Masukan Tanggal Lahir : \n");
    
    
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
    
    

    
    // cari zodiak
  
    if( (bulan == 12 && tanggal >= 22) || (bulan == 1 && tanggal <= 19) ){
        strcpy(zodiak, "Capricorn");
    }
    else if( (bulan == 1 && tanggal >= 20) || (bulan == 2 && tanggal <= 17) ){
        strcpy(zodiak, "Aquarius");
    }
    else if( (bulan == 2 && tanggal >= 18) || (bulan == 3 && tanggal <= 19) ){
        strcpy(zodiak, "Pisces");
    }
    else if( (bulan == 3 && tanggal >= 20) || (bulan == 4 && tanggal <= 19) ){
        strcpy(zodiak, "Aries");
    }
    else if( (bulan == 4 && tanggal >= 20) || (bulan == 5 && tanggal <= 20) ){
        strcpy(zodiak, "Taurus");
    }
    else if( (bulan == 5 && tanggal >= 21) || (bulan == 6 && tanggal <= 20) ){
        strcpy(zodiak, "Gemini");
    }
    else if( (bulan == 6 && tanggal >= 21) || (bulan == 7 && tanggal <= 22) ){
        strcpy(zodiak, "Cancer");
    }
    else if( (bulan == 7 && tanggal >= 23) || (bulan == 8 && tanggal <= 22) ){
        strcpy(zodiak, "Leo");
    }
    else if( (bulan == 8 && tanggal >= 23) || (bulan == 9 && tanggal <= 22) ){
        strcpy(zodiak, "Virgo");
    }
    else if( (bulan == 9 && tanggal >= 23) || (bulan == 10 && tanggal <= 22) ){
        strcpy(zodiak, "Libra");
    }
    else if( (bulan == 10 && tanggal >= 23) || (bulan == 11 && tanggal <= 21) ){
        strcpy(zodiak, "Scorpio");
    }
    else if( (bulan == 11 && tanggal >= 22) || (bulan == 12 && tanggal <= 21) ){
        strcpy(zodiak, "Sagittarius");
    }
    else{
        printf("Input tanggal lahir error!\n");
    }
    
    printf("\n -------------------------------- \n");
    
    //Output
    printf("Nama : %s \n", nama);
    printf("Bintang : %s \n", zodiak);
    printf("Tanggal Lahir : Tanggal %d Bulan %d \n", tanggal, bulan);
    
    
    
    
    return 0;
}

