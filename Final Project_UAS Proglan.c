/* Proyek Akhir Pemrograman Lanjut
Kelas           : Pemrograman Lanjut -02
Kelompok        : 8
Nama Anggota    :
        - Amanda Fairuz Syifa     (2006535653)
        - Firzy Allen             (2006577555)
        - Steven Yosua Saputra    (2006577290)
        - Zana Niswah Awahita     (2006577593)
Judul Proyek    : Program Perampungan dan Pembuatan SKL (Surat Keterangan Lulus)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <omp.h>

#define MAX_LENGTH 256
#define SIZE 100

int main(){
	int sentinel_1 = 0;
	
    struct siswa *data = NULL;
    struct siswa *data1 = NULL;
    
    //Penjelasan program secara singkat
    printf ("\n\n\t===============================================================================================");
	printf ("\n\t\t\t\t\tPROGRAM PERAMPUNGAN DAN PEMBUATAN SKL");
	printf ("\n\t===============================================================================================");
	printf ("\n\n         Program ini dapat membantu pendataan siswa dan proses pencetakan surat keterangan lulus (SKL).");
	printf ("\n\t\t\tSilahkan baca panduan untuk mengetahui cara menggunakan program!\n");
	printf ("\n\n\t\t\t\tSilahkan tekan tombol apapun untuk melanjutkan...");
	getch ();
	system("cls");
	
    menu:
    //Program menampilkan menu yang tersedia
	display_menu();
	int pilihan;
	char input[SIZE];
    char nama_pelajaran[SIZE][SIZE];
    display_database_nilai(nama_pelajaran);
    
    //User memasukkan menu yang diinginkan
    printf("\n\t\tMasukkan Pilihan: ");
    scanf("%d", &pilihan);
            
    switch(pilihan){
        case 1 :
            //Input data siswa 
            system("cls");
            input_data(nama_pelajaran);
            system("cls");
            sentinel_1 = 1;
            goto menu;
            break;
                    
        case 2 :
            //Lihat data siswa
            if(sentinel_1 == 1){
		        system("cls");
		        lihat_data_siswa(data,nama_pelajaran);
		        printf("\n\t\tSilahkan tekan tombol apapun untuk melanjutkan...");
		        getch();
		        system("cls");
		        goto menu;	
			}
			
			else{
				system ("cls");
				printf ("\n\n\t\tMasukkan input data siswa terlebih dahulu.");
				printf ("\n\n\t\tSilahkan tekan tombol apapun untuk melanjutkan...");
				getch ();
				system ("cls");
				goto menu;
			}
            break;
                    
        case 3 :
        	//Lihat daftar sekolah
            system("cls");
            int temp_display;
            temp_display=display_database_sekolah();
            if (temp_display==1){
                system("cls");
                printf("\t\t===========================================\n");
			    printf("\t\t\t    MENCARI NAMA SEKOLAH\n");
			    printf("\t\t===========================================\n\n");
			    printf("\t\tContoh: SMA Negeri 109 Jakarta\n\n");
                printf("\t\tMasukkan nama sekolah Anda: ");
                scanf(" %[^\n]", input);
                search_database_sekolah (input);
                printf("\n\t\tSilahkan tekan tombol apapun untuk melanjutkan...");
                getch();
                system("cls");
                goto menu;
            }
            if (temp_display==0){
                system("cls");
                goto menu;
            }
            break;
                    
        case 4 :    
            //cetak SKL
            
             if(sentinel_1 == 1){
		        system("cls");
		        cetak_SKL(data1);
		        printf("\n\n\n\t\tSilahkan tekan tombol apapun untuk melanjutkan...\n");
		        getch();
		        system("cls");
		        goto menu;	
			}
			
			else{
				system ("cls");
				printf ("\n\n\t\tMasukkan input data siswa terlebih dahulu.");
				printf ("\n\n\t\tSilahkan tekan tombol apapun untuk melanjutkan...");
				getch();
				system("cls");
				goto menu;
			}
            break;
                        
        case 5 :
            //Display panduan
            system("cls");
            display_panduan();
            system ("cls");
            goto menu;
            break;
        
		case 6 :
            //Keluar program
            system("cls");
            keluar();
            system ("cls");
            goto menu;
            break;
        	
		//Terdapat default untuk Error Handling apabila User memasukkan pilihan yang salah
        default :
            system ("cls");
            printf("Pilihan anda tidak sesuai.\nSilahkan ulangi pilihan\n");
            sleep (1);
            system("cls");
            goto menu;
    }
}

int display_menu (){
	printf("\t\t========================================\n");
    printf("\t\t\t       MENU LAYANAN\n");
    printf("\t\t========================================\n\n");
	printf ("\t\t\t1. Input Data Siswa\n");
	printf ("\t\t\t2. Lihat Data Siswa\n");
	printf ("\t\t\t3. Melihat Sekolah\n");
	printf ("\t\t\t4. Cetak SKL\n");
	printf ("\t\t\t5. Panduan\n");
	printf ("\t\t\t6. Keluar\n");
}

int display_database_nilai(char nama_pelajaran[][SIZE]){
	//Program membuka file database dari .txt
    char *file_database = "database_nilai.txt";
    FILE *fd = fopen(file_database,"r");
    int i=0, j=0;

    if(fd==NULL){
        printf("Error, cannot open the file");
        return 0;
    }

    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, fd)){
    	for (i=0;i<strlen(buffer);i++){
            if (buffer[i]==';'){
            	break;
            }
            nama_pelajaran[j][i]=buffer[i];
        }
        j++;
    }
    fclose(fd);
}

