#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
