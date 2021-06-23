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

int input_data(char nama_pelajaran[][SIZE]){
    int sentinel = 1;
    int i;
    char answer;
    
	system("cls");
	printf("\t\t==========================================================\n");
	printf("\t\t\t\t\tInput Data           \n");
	printf("\t\t==========================================================\n");

    while(sentinel != -1){
        temp = malloc(sizeof(struct siswa));
        ptr=head;
        printf("\n\t\tCatatan:\n\t\tNomor indeks sekolah dapat dilihat pada menu nomor 3.\n");
        //User menginput data sesuai kebutuhan program
        printf("\n\t\tNama\t\t\t: ");
        scanf(" %[^\n]", temp->nama);
        input_indeks:
        printf ("\n\t\tIndeks Sekolah\t\t: ");
        scanf (" %d",&temp->sekolah);
        printf("\n\t\tTempat, tanggal lahir\t: ");
        scanf(" %[^\n]", temp->TTL);
        printf("\n\t\tNIS\t\t\t: ");
        scanf(" %d", &temp->NIS);
        printf("\n\t\tNISN\t\t\t: ");
    	scanf(" %d", &temp->NISN);
        printf("\n\t\tKelas\t\t\t: ");
        scanf(" %[^\n]", temp->kelas);
        for (i=0;i<14;i++){
            printf("\n\t\tNilai %s\t: ", nama_pelajaran[i]);
            scanf(" %d", &temp->nilai[i]);
            if( temp->nilai[i] < 0 || temp->nilai[i] > 100){
                while(temp->nilai[i] < 0 || temp->nilai[i] > 100){
                    printf("\n\t\tMasukkan kembali nilai %s\t: ", nama_pelajaran[i]);
                    scanf(" %d", &temp->nilai[i]);
                }
            } 
            else{
                continue;
            }
        }
	    temp->next=NULL;
	    
	    printf("\n\t\t_____________________________________________________________");
	    answer:
	    printf("\n\n\t\tApakah Anda ingin memasukkan data kembali? (Y/N)");
	    printf("\n\t\tKetik Pilihan (Y=Ya)(N=Tidak): ");
	    scanf("%s", &answer);
	            
	    if(answer=='y'||answer=='Y'){
	        if(head==NULL){
	            head = temp;
	            continue;
	        }
	        while(ptr->next!=NULL){
	            ptr=ptr->next;
	        }
		    ptr->next=temp;
		    continue;
	    }
	                
	    else if(answer=='n'||answer=='N'){
	        if(head==NULL){
	            head = temp;
	            break;
	        }
	        while(ptr->next!=NULL){
	            ptr=ptr->next;
	        }
	        ptr->next=temp;
	        sentinel=-1;
	        continue;
	    }
	    else{
	        printf("\n\t\tInputan yang Anda masukkan salah.\n\t\tSilahkan memasukkan kembali input Anda.");
	        printf("\n\t\t_____________________________________________________________");
	        goto answer;
	    }
    }
}

int lihat_data_siswa(struct siswa *data, char nama_pelajaran[][SIZE]){
    int i;
    int counter=7;
    int j=1;
    int sentinel = 1;
    data = head;
    char buffer[MAX_LENGTH];
    
    printf ("\t\t========================================\n");
    printf ("\t\t\t\tDATA SISWA\n");
    printf ("\t\t========================================\n\n");
    
    while(sentinel==1){
    	//Menampilkan hasil input sesuai dengan input user
	    printf("\n\t\t1. Nama \t\t: %s", data->nama);
        printf ("\n\t\t2. Nama Sekolah \t: ");
        char *file_database = "database_sekolah.txt";
    	FILE *fd = fopen(file_database,"r");
    	
	    while (fgets(buffer, MAX_LENGTH, fd)){
	       if (j==data->sekolah){
				for (i=0;i<strlen(buffer);i++){
		            if (buffer[i]==';'){
		                printf(" ");
		                continue;
		            }
		            printf("%c", buffer[i]);
		        }
		        fclose(fd);
		    }
		    j++;
		}
        printf("\t\t3. TTL \t\t\t: %s", data->TTL);
        printf("\n\t\t4. NIS \t\t\t: %d", data->NIS);
        printf("\n\t\t5. NISN \t\t: %d", data->NISN);
        printf("\n\t\t6. Kelas \t\t: %s", data->kelas);
        
        for(i=0;i<14;i++){
            printf("\n\t\t%d. Nilai Siswa %s: %d",counter++,nama_pelajaran[i],data->nilai[i]);  
        }  
        
        data=data->next;
        j=1;
        counter = 7;
        printf("\n\t\t_____________________________________________________________\n");
        
        if(data == NULL){
            sentinel = -1;
    	}
    }
}