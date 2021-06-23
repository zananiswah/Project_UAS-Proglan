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

int main() {
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
	return 0;
}
