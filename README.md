
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
*** github_username, repo_name, twitter_handle, email, project_title, project_description
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]





  <h3 align="center">Program Perampungan dan Pembuatan SKL</h3>

  <p align="center">
    Program yang bertujuan untuk memudahkan sekolah dalam menyimpan data peserta didik serta mencetak SKL dalam bahasa C.
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Daftar Konten</h2></summary>
  <ol>
    <li>
      <a href="#tentang-proyek">Tentang Proyek</a>
      <ul>
        <li><a href="#dibuat-dengan">Dibuat dengan</a></li>
      </ul>
    </li>
    <li>
      <a href="#penjelasan">Penjelasan</a>
      <ul>
      </ul>
    </li>
    <li><a href="#lisensi">Lisensi</a></li>
    <li><a href="#kontak">Kontak</a></li>
    <li><a href="#penutup">Penutup</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## Tentang Proyek

![tampilan_awal](https://user-images.githubusercontent.com/72308202/123299060-56293b80-d543-11eb-9727-992aaf81c52e.png)

Program perampungan dan pembuatan SKL (Surat Keterangan Lulus) ini merupakan program yang bertujuan untuk memudahkan sekolah dalam menyimpan data peserta didik serta mencetak SKL. User dapat memilih menu yang ingin dijalankan sesuai dengan kebutuhannya.

Tersedia 6 (enam) buah pilihan menu, yang terdiri dari Input Data Siswa, Lihat Data Siswa, Lihat Sekolah, Cetak SKL, Panduan, juga Keluar. 

[Video Penjelasan: Google Drive](https://drive.google.com/file/d/1SURTfFcEwOY-1Nhtd8k3kvtYPXk3FIcT/view?usp=drivesdk)

### Dibuat dengan
Menggunakan library tambahan yaitu OpenMP (Open Multi-Processing) sebuah antarmuka pemrograman aplikasi (API) yang mendukung multi processing shared memory pemrograman khususnya dalam bahasa C yang dipakai pada *project* ini.
* [OpenMP](https://www.openmp.org/)

## Penjelasan

Pada menu **Input Data**, user diminta untuk memasukkan seluruh data yang dibutuhkan oleh program untuk diolah. Data tersebut terdiri dari 6 (enam) jenis data, yaitu: nama siswa, TTL, NIS, NISN, Kelas, dan nilai yang terdiri dari 14 mata pelajaran.

Menu ke-2, yaitu **Lihat Data Siswa** dapat menampilak seluruh hasil input yang telah dimasukkan oleh user dari menu pertama. 

Sementara menu ketiga, adalah menu yang berfungsi untuk menampilkan **List Sekolah** beserta nomor indeks dan NPSN-nya. Menu ini diharapkan diakses oleh user sebelum menginput data dengan tujuan untuk mengetahui nomor indeks sekolah yang dibutuhkan pada menu Input Data Siswa. Selain menampilkan list sekolah yang telah terdaftar, apabila sekolah yang diinginkan belum tercantum dalam list, user juga dapat menambahkan sekolah tersebut dengan cara mendaftarkannya.

Sementara menu ke-4, **Cetak SKL**, adalah menu yang digunakan untuk mencetak SKL dengan data-data sesuai input user, dilengkapi pula dengan keterangan LULUS/TIDAK LULUS, serta rata-rata yang diperoleh dari perhitungan 14 nilai mata pelajaran.
![cetak_skl](https://user-images.githubusercontent.com/72308202/123299206-79ec8180-d543-11eb-9c77-3f55ab4ed62e.png)

Menu ke-5, **Panduan**, adalah menu yang berfungsi untuk menampilkan penjelasan prosedur penggunaan program. Dan menu terakhir adalah menu yang akan digunakan ketika user akan keluar dari program. Menu ini akan meminta konfirmasi apakah user benar-benar ingin keluar atau kembali menggunakan program.


<!-- LICENSE -->
## Lisensi

Distributed under the Creative Common.



<!-- CONTACT -->
## Kontak

 - Amanda Fairuz Syifa [Github](https://github.com/amandafairuz14) - amanda.fairuz@ui.ac.id
 - Firzy Allen [Github](https://github.com/firzyallen) - firzy.allenn@ui.ac.id
 - Steven Yosua Saputra [Github](https://github.com/stevenys10) - steven.yosua@ui.ac.id
 - Zana Niswah Awahita [Github](https://github.com/zananiswah) - zana.niswah@ui.ac.id

Project Link: [Project_UAS-Proglan: Proyek Akhir Pemrograman Lanjut Semester 2](https://github.com/zananiswah/Project_UAS-Proglan)



<!-- ACKNOWLEDGEMENTS -->
## Penutup
This source code is made by Amanda Fairuz Syifa (2006535653), Firzy Allen (2006577555), Steven Yosua Saputra (2006577290), Zana Niswah Awahita (2006577593) as final programming assignment in Even Semester 2020/2021 for course Advance Programming + Lab. (ENCE602003) in Undergraduate of Computer Engineering study program, Department of Electrical Engineering, Faculty of Engineering, Universitas Indonesia.

Thank You **Dr. Ruki Harwahyu, ST. MT. MSc.** as our lecture.





<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/zananiswah/Project_UAS-Proglan.svg?style=for-the-badge
[contributors-url]: https://github.com/zananiswah/Project_UAS-Proglan/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/github_username
