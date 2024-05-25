package main

import (
	"fmt"
)

const Jmax int = 9
const kmax int = 4
const Nmax int = 1000

type Job struct {
	posisi      string
	Description string
	lokasi      string
	akreditasi  string
	gaji        int
	perus       string
	waktu       string
	persyaratan string
	Rating      rate
}

type rate struct {
	user    [kmax]string
	rating  [kmax]int
	message [kmax]string
}

type tabJob [Jmax]Job

type Login struct {
	NP, KS, TBT, U string
}

type tabLogin [Nmax]Login

var totSer int
var arrL tabLogin
var quit bool
var y string

var arrJ tabJob
var NP,KS,TBT,U string


func main(){
    login()
} 

func pelamar(){
	/* IS. -
	   FS. program berakhir oleh pengguna dengan memilih mau cari kerja atau tidak */ 
quit = false
for !quit{
	menu()
	fmt.Print("Ingin mencari posisi pekerjaan yang cocok untuk kamu? (Ketik 'Y' atau 'N')", " ")
	fmt.Scan(&y)
	if y == "N"{
       quit = true
	}else if y == "Y"{
		infoLoker()
	}
}
}

func menu(){
	/* IS. -
	   FS. Menampilkan menu layar */
	fmt.Println("------------------------------")
	fmt.Println("Selamat Datang di Aplikasi Ganja")
	fmt.Println("------------------------------")
	fmt.Println("Sudah sore waktunya matahari redup")
	fmt.Println("Bersiap malam besok hari rabu")
	fmt.Println("Aku percaya kamu pasti sanggup")
	fmt.Println("Menyerah bukanlah moto hidupmu")
}

func login(){
	/* IS. -
	   FS. Telah mendaftar dan berhasil login untuk mengakses fungsi pelamar(), serta keluar dari login */ 
	var keluar,benar bool
	var n int
	keluar = false
	for !keluar {
		fmt.Println("Selamat datang, kami senang bersama anda")
		fmt.Println("For Your Information, setiap ada spasi, diharapkan untuk tidak mengetik spasi, melainkan menggunakan tanda '_' ")
		fmt.Println("======= Akun Login =======")
		fmt.Println("1. Daftar")
		fmt.Println("2. Masuk")
		fmt.Println("3. Keluar")
		fmt.Print("Pilih Menu : ", " ")
		fmt.Scan(&n)
		if n == 1 {
			fmt.Print("Nama Pengguna: ")
			fmt.Scan(&NP)
			fmt.Print("Username : ")
			fmt.Scan(&U)
			fmt.Print("Kata Sandi: ")
			fmt.Scan(&KS)
			fmt.Print("Tanggal - Bulan - Tahun Lahir : ")
			fmt.Scan(&TBT)
				arrL[totSer].NP = NP
				arrL[totSer].U = U
				arrL[totSer].KS = KS
				arrL[totSer].TBT = TBT
				totSer++
			fmt.Println("Sudah terdaftar")
		}else if n == 2 {
			fmt.Print("Username : ")
			fmt.Scan(&U)
			fmt.Print("Kata Sandi: ")
			fmt.Scan(&KS)
			if U == "I_luv_Ganja" && KS == "Admin123"{
				fmt.Println("Berhasil Login")
				pelamar()
			}
			benar = MasukanPengguna(U, KS)
			if benar{
               fmt.Println("Berhasil Login")
               pelamar()
			}else if !benar && !(U == "I_luv_Ganja" && KS == "Admin123"){
				fmt.Println("Belum Login")
			}
		} else if n == 3 {
			keluar = true
		} else {
			fmt.Println("Salah")
			login()
		}
	}
}

func MasukanPengguna(U,KS string)bool{
	/* mengembalikan nilai true apabila array Login dari NP dan KS sama dengan inputan login NP dan KS, dan juga menghasilkan nilai false jika sebaliknya */
	var i int
	for i = 0;i<totSer;i++{
		if arrL[i].U == U && arrL[i].KS == KS{
			return true
		}
	}
	return false
}

func infoLoker(){
	/* IS. -
	   FS. Menampilkan menu pilihan lowongan pekerjaan dan menerima inputan choice sesuai kebutuhan pengguna */
	var choice int
	fmt.Println("Pilih mau cari berdasarkan apa")
	fmt.Println("1. Berdasarkan posisi")
	fmt.Println("2. Berdasarkan akreditasi")
	fmt.Println("3. Berdasarkan gaji")
	fmt.Println("4. Berdasarkan lokasi")
	fmt.Println("5. Berdasarkan waktu")
	fmt.Println("6. Berdasarkan Rating")
	fmt.Println("7. Keluar")
	fmt.Println("Mau pilih mana? (Ketik angkanya saja)")
	fmt.Scan(&choice)

	if choice == 1{
		posisiV(&arrJ)
	}else if choice == 2{
		Akreditasi(&arrJ)
	}else if choice == 3{
		sortGaji(&arrJ)
		Gaji(&arrJ)
	}else if choice == 4{
		Lokasi(&arrJ)
	}else if choice == 5{
		Waktu(&arrJ)
	}else if choice == 6{
		Rating(&arrJ)
	}else if choice == 7{
        return
	}else {
		fmt.Println("Invalid!")
		infoLoker()
	}

}

func posisiV(arrJ *tabJob) {
	/* IS. terdefinisi array arrJn yang berisi data-data sejumlah Jmax pekerjaan
	   FS. menampilkan daftar posisi pekerjaan yang ada dan memilih posisi */
	var i, posisi int
	var kata, x, p string
	fmt.Println( "Pilihlah posisi yang tertera pada opsi dibawah ini! (Ketik dengan angka saja sesuai dengan posisi yang diinginkan)")
	hasilPT(arrJ)
	for i = 0; i < len(*arrJ); i++ {
		fmt.Printf("%d. %s\n", i+1, arrJ[i].posisi)
	}
	fmt.Scan(&posisi)
	if posisi < 0 && posisi > 9{
		fmt.Println("Invalid")
		posisiV(arrJ)
	}
	fmt.Print("Apakah Anda tertarik dengan pekerjaan ini? (Ketik 'Yes' atau 'No')", " ")
	fmt.Scan(&x)
	if x == "No" {
		posisiV(arrJ)
	} else if x == "Yes" {
		posisi = posisi - 1
		p = arrJ[posisi].posisi
		kata = arrJ[posisi].perus
		Pilihposisi(arrJ, &p, &kata, &posisi)
	}else {
		fmt.Println("Invalid")
		posisiV(arrJ)
	}
}

func cekPTpos(arrJ *tabJob, p, q *string) bool {
	/* Diterima array arrJ yang berisi Jmax bilangan bulat beserta dua string p dan q, mengembalikan TRUE apabila p dan q ditemukan didalam array arrJ menggunakan sequential search */
	var i, j, k int
	var ketemu bool
	ketemu = false
	i = 0
	hasilPT(arrJ)
	for i < len(*arrJ) && !ketemu {
		if arrJ[i].posisi == *p && arrJ[i].perus == *q {
			ketemu = true
			output(arrJ, &i, &j, &k)
		}
		i++
	}
	return ketemu
}

func output(arrJ *tabJob, i, j, k *int) {
	/* IS. Terdefinisi data-data arrJ yang berisi Jmax bilangan bulat dan tiga bilangan bulat i,j, dan k
       FS. Mengembalikan data-data array arrJ */
	fmt.Println("Nama Pekerjaan :", arrJ[*i].posisi, "\nDeskripsi :", arrJ[*i].Description, "\nPerusahaan: ", arrJ[*i].perus, "\nLokasi: ", arrJ[*i].lokasi, "\nGaji: ", arrJ[*i].gaji, "\nAkreditasi: ", arrJ[*i].akreditasi, "\nWaktu:", arrJ[*i].waktu, "\nPersyaratan :", arrJ[*i].persyaratan)
	fmt.Println()
	fmt.Println("Ulasan : ")
	fmt.Println()
	for *k = 0; *k < len((*arrJ)[*i].Rating.user); *k++ {
		fmt.Println("Rating : ", arrJ[*i].Rating.rating[*k], "\nUser : ", arrJ[*i].Rating.user[*k], "\nPesan :", arrJ[*i].Rating.message[*k])
	}
	}

func hasilPT(arrJ *tabJob) {
	/* IS. Terdefinisi data-data arrJ yang berisi Jmax bilangan bulat
	   FS. - */
	var i, k int
	for i = 0; i < len(*arrJ); i++ {
		if i == 0 {
			arrJ[i].posisi = "Data_Scientist"
			arrJ[i].Description = "Data scientist bertugas menganalisis berbagai jenis data besar (big data) yang terakumulasi oleh perusahaan. Profesi ini menggunakan kemampuan analisis data seperti menggabungkan data dari berbagai sumber, memastikan konsistensi dataset (data preparation), memilih faktor atau algoritma yang mempengaruhi hasil prediksi (data exploration), dan membuat infografis yang memudahkan para pengambil keputusan memahami data (data visualisasi)."
			arrJ[i].perus = "PT_RGE_Indonesia"
			arrJ[i].lokasi = "Jakarta"
			arrJ[i].gaji = 15000000
			arrJ[i].akreditasi = "C"
			arrJ[i].waktu = "Paruh_Waktu"
			arrJ[i].persyaratan = "\n1) Pendidikan Minimal S1 Sederajat (Teknik Informatika, Sistem Informasi, Teknik Komputer, Statistika)\n2)Kemampuan untuk menganalisis data secara mendalam menggunakan statistik, pengujian hipotesis, pemodelan prediktif, dan teknik analisis data lainnya\n3)Pengalaman dalam menggunakan alat analisis data seperti pandas, NumPy, dan scikit-learn.\n4)Menguasai bahasa Inggris dengan baik\n5)Komunikasi yang efektif dan keterampilan interpersonal\n6)Kemampuan untuk mengatur waktu dengan baik dan bekerja efisien dalam jangka waktu yang ditentukan."
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 2
					arrJ[i].Rating.user[k] = "Anonymous287"
					arrJ[i].Rating.message[k] = "Meskipun PT RGE Indonesia menawarkan proyek menarik dan lingkungan kerja yang nyaman, tantangan utamanya adalah manajemen yang kaku dan kurangnya koordinasi antar divisi, yang menghambat efisiensi, inovasi, dan menyebabkan ketidakpastian di antara karyawan. Perusahaan perlu meningkatkan responsivitas dan fleksibilitas manajemen serta komunikasi antar divisi untuk menciptakan lingkungan kerja yang lebih produktif."
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 3
					arrJ[i].Rating.user[k] = "Frzasyabdi2375 "
					arrJ[i].Rating.message[k] = "Pengalaman di sini cukup bermanfaat. Lingkungan kerja bagi beberapa divisi terasa nyaman, namun tantangan muncul karena manajemen terlihat kaku dalam menerima perubahan. Koordinasi antar divisi juga sering kali bermasalah dan tidak selaras."
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 4
					arrJ[i].Rating.user[k] = "Wifakhridwi73"
					arrJ[i].Rating.message[k] = "Pekerjaan sebagai Data Scientist memberikan kesempatan untuk bekerja dalam lingkungan yang menyenangkan. Namun, tantangannya adalah membutuhkan kerja keras yang konsisten untuk mengatasi tugas-tugas yang kompleks dan terkadang memerlukan pemecahan masalah yang mendalam."
				}
			}
		} else if i == 1 {
			arrJ[i].posisi = "Content_Creator"
			arrJ[i].Description = "Content creator adalah seorang profesional yang bertanggung jawab untuk membuat konten yang menarik dan relevan untuk ditampilkan di berbagai platform media, seperti situs web, media sosial, blog, atau saluran YouTube. Tugas utama mereka adalah menciptakan konten yang dapat menarik perhatian dan berinteraksi dengan audiens, meningkatkan kesadaran merek, dan mempromosikan produk atau layanan Perusahaan."
			arrJ[i].perus = "PT_Rejeki_Kencana_Mandiri"
			arrJ[i].lokasi = "Bandung"
			arrJ[i].gaji = 10000000
			arrJ[i].akreditasi = "C"
			arrJ[i].waktu = "Full_Time"
			arrJ[i].persyaratan = "\n1)Berinteraksi secara aktif dengan audiens melalui chat dan komentar.\n2)Menyampaikan konten dengan jelas dan memikat menggunakan kemampuan berbicara yang baik.\n3)Memahami tren dan topik yang sedang populer untuk menarik minat audiens\n4)Mempromosikan dan memperkenalkan produk atau layanan perusahaan kepada audiens\n5)Kesadaran tentang isu-isu etika dalam konten, termasuk hak cipta, kejujuran, dan privasi."
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 3
					arrJ[i].Rating.user[k] = "Berlin83"
					arrJ[i].Rating.message[k] = "Teman kerja yang supportif dan tidak saling menjatuhkan, tetapi tidak ada jenjang karir yang jelas dan kondisi perusahaan yang kurang baik."
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 5
					arrJ[i].Rating.user[k] = "Arsy7493"
					arrJ[i].Rating.message[k] = "Suasana kerja yang nyaman serta kedekatan dengan jajaran manajemen membuat kita menjadi betah untuk bekerja, selain itu banyak reward yang diberikan untuk karyawan."
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 4
					arrJ[i].Rating.user[k] = "EloiseBella059"
					arrJ[i].Rating.message[k] = "Suasana kerja yang nyaman serta kedekatan dengan jajaran manajemen membuat kita menjadi betah untuk bekerja, selain itu banyak reward yang diberikan untuk karyawan."
				}
			}

		} else if i == 2 {
			arrJ[i].posisi = "Accounting"
			arrJ[i].Description = "Seorang akuntan adalah seorang profesional yang bertanggung jawab untuk memantau dan mengelola keuangan suatu Perusahaan. Tugas utamanya termasuk menyusun dan menganalisis laporan keuangan, memeriksa catatan keuangan, mengelola pajak, dan memberikan saran keuangan kepada manajemen atau klien."
			arrJ[i].perus = "PT_Schenck_Process_Indonesia"
			arrJ[i].lokasi = "Palembang"
			arrJ[i].gaji = 7000000
			arrJ[i].akreditasi = "D"
			arrJ[i].waktu = "Kasual"
			arrJ[i].persyaratan = "\n1) Memiliki gelar sarjana di bidang akuntansi\n2) Memiliki keterampilan dan pengetahuan akuntansi yang baik\n3) Min. Pengalaman min. 1 tahun\n4) Mampu berbicara dan menulis dalam bahasa Inggris\n5) Berorientasi pada detail dan pembelajar yang cepat\n6) Mampu mengoperasikan Microsoft Office"
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 1
					arrJ[i].Rating.user[k] = "Amelll999"
					arrJ[i].Rating.message[k] = "“Layanan yang mereka tawarkan terasa kurang profesional dan kurang kompeten dalam mengelola keuangan klien. Pelaporan keuangan seringkali tidak akurat dan terlambat, menyebabkan ketidakpercayaan dan ketidakpuasan dari pihak klien. Kurangnya komunikasi yang efektif dan respons yang lambat juga merupakan masalah yang signifikan."
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 3
					arrJ[i].Rating.user[k] = "Marselino3320"
					arrJ[i].Rating.message[k] = "Kerja santai, tidak ada tekanan, SOP Jelas, kekeluargaan, minusnya kadang harus berhadapan dengan atasan dimana atasan melanggar SOP , gaji rendah."
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 4
					arrJ[i].Rating.user[k] = "Velisia823"
					arrJ[i].Rating.message[k] = "Semua saya suka dri perusahaan ini.menjadi seorang yg dibutuhkan lebih baik dripada tidak di butuhkan,dengan cara bekerja dengan baik dan cerdas bisa mengambil keputusan besar dan meningkatkan kualitas sumber daya yg ada .dan meningkatkan keuntungan perusahaan."
				}
			}
		} else if i == 3 {
			arrJ[i].posisi = "Business_Development"
			arrJ[i].Description = "Pekerjaan dalam pengembangan bisnis (Business Development) melibatkan identifikasi, penilaian, dan pengejaran peluang pertumbuhan baru untuk suatu perusahaan atau organisasi. Seorang profesional Business Development bertanggung jawab untuk menciptakan strategi dan menjalankan inisiatif yang bertujuan untuk meningkatkan pendapatan, memperluas pangsa pasar, dan memperkuat posisi kompetitif perusahaan."
			arrJ[i].perus = "PT_Wisdra_International"
			arrJ[i].lokasi = "Semarang"
			arrJ[i].gaji = 14000000
			arrJ[i].akreditasi = "B"
			arrJ[i].waktu = "Paruh_Waktu"
			arrJ[i].persyaratan = "\n1) Keterampilan komunikasi yang sangat baik untuk berinteraksi dengan klien dan anggota tim.\n2) Terbuka untuk semua jurusan (Magang dipersilakan melamar).\n3) Bergairah tentang Keuangan Pribadi dan Pengembangan Manusia.\n4) Memiliki kemampuan kepemimpinan dan komunikasi yang baik.\n5) Lebih disukai lulusan penuh (S1) dari Universitas terkemuka"
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 1
					arrJ[i].Rating.user[k] = "DisappointedAlien42"
					arrJ[i].Rating.message[k] = "Perusahaan ini memang adalah perusahaan yang menghancurkan nama baik Indonesia. Fix jangan masuk kesini"
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 2
					arrJ[i].Rating.user[k] = "MysticalExplorer567"
					arrJ[i].Rating.message[k] = "Masih baik aku kasih 2, kalau tidak memang ini perusahaan mending tutup aja"
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 4
					arrJ[i].Rating.user[k] = "EnchantedCustomer101"
					arrJ[i].Rating.message[k] = "Gw sebagai alumni cukup senang untuk bekerja di perusahaan ini"
				}
			}

		} else if i == 4 {
			arrJ[i].posisi = "Auditor"
			arrJ[i].Description = "Auditor adalah profesional yang bertanggung jawab untuk mengevaluasi dan memeriksa keuangan, proses bisnis, dan sistem internal suatu perusahaan untuk memastikan kepatuhan terhadap standar akuntansi, peraturan, dan kebijakan yang berlaku."
			arrJ[i].perus = "PT_Sukanda_Djaya"
			arrJ[i].lokasi = "Pontianak"
			arrJ[i].gaji = 9000000
			arrJ[i].akreditasi = "D"
			arrJ[i].waktu = "Kasual"
			arrJ[i].persyaratan = "\n1) Gelar sarjana di bidang akuntansi\n2) Pengalaman sebagai auditor internal.\n3) Memiliki pengetahuan mendalam tentang SAP\n4) Pemikir analitis dengan keterampilan konseptual dan pemecahan masalah yang kuat.\n5) Perhatian yang cermat terhadap detail dengan kemampuan melakukan banyak tugas.\n6) Kemampuan untuk bekerja secara mandiri dan sebagai bagian dari tim."
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 5
					arrJ[i].Rating.user[k] = "MysticMingle17"
					arrJ[i].Rating.message[k] = "Saya menyukai pekerjaan ini Karana ingin mencari pengalaman kerja di bidang industri. Dan jika saya sudah bekerja di perusahaan ini saya akan melakukan berbagai macam kegiatan atau bekerja di bawah tekanan. Dalam bekerja pasti ada kesulitan dalam menjalankan tugas jadi saya pikir itu hal yang biasa"
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 4
					arrJ[i].Rating.user[k] = "LunaLabyrinth88"
					arrJ[i].Rating.message[k] = "Kesempatan belajar banyak hal dan karir yang terbuka bagi siapa saja yang punya kompetensi dan kapasitas dalam menggali potensi diri untuk kemajuan perusahaan dan karir kita.Kesulitan di perusahaan ini adalah akses jalan yang sangat padat di jam jam kerja."
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 3
					arrJ[i].Rating.user[k] = "GalaxyGazer47"
					arrJ[i].Rating.message[k] = "Lingkungan baik, banyak hal yang harus diperbaiki tetapi sulit berinovasi di lingkup perusahaan, namun Leadership dari atasan kurang"
				}
			}
		} else if i == 5 {
			arrJ[i].posisi = "Admin"
			arrJ[i].Description = "Seorang admin mengelola tugas administratif, komunikasi, dan dukungan untuk operasi harian. Ini termasuk pemeliharaan catatan, penjadwalan, manajemen inventaris, dan pengelolaan anggaran. Kemampuan organisasi yang baik, multitasking, dan penggunaan perangkat lunak kantor penting dalam peran ini."
			arrJ[i].perus = "PT_Perdana_Bangun_Pusaka_Tbk"
			arrJ[i].lokasi = "Yogyakarta"
			arrJ[i].gaji = 16000000
			arrJ[i].akreditasi = "B"
			arrJ[i].waktu = "Full_Time"
			arrJ[i].persyaratan = "\n1) Pengalaman min 1 Tahun dalam administrasi Kantor\n2) Kemampuan mengerjakan tugas administrasi yang andal dan jika dibutuhkan juga memahami tentang pengelolaan finansial\n3) Dapat bekerja secara terstruktur\n4) Memiliki analytical thinking\n5) Memiliki manajemen waktu yang baik\n6) Mampu mengoperasikan komputer dan berbagai fungsi dokumen serta excel dengan baik"
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 1
					arrJ[i].Rating.user[k] = "Tiara19"
					arrJ[i].Rating.message[k] = "Sayangnya, pengalaman saya dengan perusahaan ini tidak memuaskan. Layanan administratif yang mereka tawarkan terasa kurang profesional dan kurang responsif terhadap kebutuhan klien. Saya sering mengalami keterlambatan dalam penanganan dokumen dan komunikasi yang kurang jelas. Sangat disayangkan melihat standar pelayanan yang rendah dari sebuah perusahaan administrasi."
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 3
					arrJ[i].Rating.user[k] = "SergiRoberto20"
					arrJ[i].Rating.message[k] = "Layanan administratif yang mereka berikan cukup standar, meskipun terkadang ada beberapa kekurangan dalam hal responsivitas dan kecepatan dalam menangani permintaan. Perlu adanya peningkatan dalam hal efisiensi dan komunikasi agar dapat memberikan pengalaman yang lebih baik kepada klien."
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 4
					arrJ[i].Rating.user[k] = "LewisHamilton44"
					arrJ[i].Rating.message[k] = "Perusahaan ini memberikan pengalaman administratif yang luar biasa. Layanan mereka sangat profesional, responsif, dan efisien. Mereka mampu mengelola dokumen dan proses administratif dengan sangat baik, serta memberikan solusi yang tepat waktu untuk setiap kebutuhan klien."
				}
			}
		} else if i == 6 {
			arrJ[i].posisi = "Legal_Officer"
			arrJ[i].Description = "Legal officer bertanggung jawab untuk memberikan pengarahan kepada direksi terkait masalah hukum, potensi risiko, dan tindakan apa yang perlu diambil ketika terjadi masalah. Mereka juga perlu memberikan pertimbangan atas semua kemungkinan risiko sebelum membuat rekomendasi apapun."
			arrJ[i].perus = "PT_Richeese_Kuliner_Indonesia"
			arrJ[i].lokasi = "Denpasar"
			arrJ[i].gaji = 20000000
			arrJ[i].akreditasi = "A"
			arrJ[i].waktu = "Full_Time"
			arrJ[i].persyaratan = "\n1) Usia Maksimal 30 tahun\n2) Pendidikan magister hukum lebih diutamakan\n3) Memiliki pengalaman minimal 2 tahun sebagai SPV Legal (diutamakan berpengalaman di perusahaan F&B dan Retail)\n4) Memiliki pengalaman terkait litigasi & non-litigasi\n5) Memiliki sertifikasi profesi yang sah dari PERADI\n6) Memiliki sertifikasi Toefl (Minimal Toefl 500 / TOEIC 750 / IELTS 6)\n7) Lancar berbahasa Inggris baik lisan & tulisan"
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Description = "Data scientist bertugas menganalisis berbagai jenis data besar (big data) yang terakumulasi oleh perusahaan. \n  Profesi ini menggunakan kemampuan analisis data seperti menggabungkan data dari berbagai sumber, memastikan konsistensi dataset (data preparation),\n memilih faktor atau algoritma yang mempengaruhi hasil prediksi (data exploration), dan membuat infografis yang memudahkan para pengambil keputusan memahami data (data visualisasi)."
					arrJ[i].Rating.rating[k] = 5
					arrJ[i].Rating.user[k] = "EnigmaticEcho23"
					arrJ[i].Rating.message[k] = "Saya sanggat suka bekerja di perusahan ini itu adalah Susana yang menyenangkan dan hidup dengan bersosialisasi. Tapi ya,mungkin saya akan kesulitan ketika sedang melayani pelanggan tetepi saya sanggup untuk menyenangkan hati dan perasaan mereka menjadi senang"
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 4
					arrJ[i].Rating.user[k] = "QuantumQuirks76"
					arrJ[i].Rating.message[k] = "Banyak ilmu dan potensi yang terbentuk saat bekerja, mulai dari gaya kepemimpinan, memotivasi, dan memahami individu satu dengan yang lainnya, selain itu mental pun cukup teruji karena kita selalu di pertemukan dengan sebuah masalah baru, baik dari internal maupun eksternal dan kita harus cermat dalam menghadapi masalah tersebut, terlebih saya dulu penempatan jauh di luar pulau sehingga pengalaman bekerja sangat berkesan dan membuat saya mengerti artinya rasa pulang. Namun, pas Corona, membuat sulit ritel cukup terpukul sehingga banyak pertimbangan perusahan untuk memangkas hak dari karyawan sehingga saya pekerja luar pulau tidak sanggup karena terlalu banyak hak yang di potong,"
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 3
					arrJ[i].Rating.user[k] = "SerendipitySailor55"
					arrJ[i].Rating.message[k] = "Mudah Naik Jabatan dan Customer adalah Raja. Tantangannya, Apabila menjelang Ramadhan Crew di kurangin - Insentive Berubah-ubah - Sering Melakukan pengurangan Karyawan secara sepihak - Selalu mendapat Ancaman PHK."
				}
			}
		} else if i == 7 {
			arrJ[i].posisi = "UI/UX_Designer"
			arrJ[i].Description = "Seorang UI/UX designer adalah seorang profesional yang bertanggung jawab untuk merancang pengalaman pengguna yang optimal dalam aplikasi, situs web, atau produk digital lainnya. Mereka fokus pada penyempurnaan antarmuka pengguna (UI) dan pengalaman pengguna (UX) produk atau aplikasi tersebut. Peran mereka sangat penting dalam memastikan bahwa pengguna dapat berinteraksi dengan produk secara mudah, intuitif, dan menyenangkan."
			arrJ[i].perus = "Kerthi_Suroboyo_Santhi"
			arrJ[i].lokasi = "Surabaya"
			arrJ[i].gaji = 7500000
			arrJ[i].akreditasi = "C"
			arrJ[i].waktu = "Kontrak"
			arrJ[i].persyaratan = "\n1) Gelar Sarjana Desain Grafis, Desain UI/UX, atau bidang terkait.\n2) Pengalaman kerja minimal 7 tahun sebagai Desainer UI/UX atau posisi desain terkait.\n3) Memahami prinsip desain dan tren terkini di UI/UX.\n4) Mampu menggunakan software desain seperti Adobe XD, Sketch, atau Figma.\n5) Pengetahuan tentang teknologi web dan seluler terkini, termasuk kerangka HTML, CSS, JavaScript, dan UI seperti Bootstrap atau Desain Material.\n6) Kemampuan berpikir kreatif dan menciptakan solusi desain "
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 5
					arrJ[i].Rating.user[k] = "ImpressedPartner123"
					arrJ[i].Rating.message[k] = "Kerthi Suroboyo Santhi adalah mitra yang andal dan berdedikasi dalam mengelola keuangan bisnis kami. Mereka tidak hanya memberikan layanan yang luar biasa, tetapi juga berkolaborasi dengan kami untuk mencapai tujuan bersama. Saya sangat menghargai kerja sama kami dengan mereka."
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 2
					arrJ[i].Rating.user[k] = "SkepticalInvestor567"
					arrJ[i].Rating.message[k] = "Saya merasa agak ragu dengan Kerthi Suroboyo Santhi. Meskipun mereka memiliki sejarah yang cukup lama, saya tidak yakin dengan kualitas layanan dan keandalan mereka. Saya merasa seperti ada kekurangan transparansi dalam bisnis mereka."
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 3
					arrJ[i].Rating.user[k] = "NeutralObserver789"
					arrJ[i].Rating.message[k] = "Kerthi Suroboyo Santhi adalah perusahaan yang cukup standar dalam industri mereka. Layanan mereka memadai, tetapi tidak ada yang benar-benar menonjol. Saya berharap mereka bisa memberikan lebih banyak inovasi dan nilai tambah kepada klien mereka."
				}
			}
		} else if i == 8 {
			arrJ[i].posisi = "Civil_Engineering"
			arrJ[i].Description = "Civil Engineering bertanggung jawab atas perencanaan, desain, konstruksi, dan pemeliharaan infrastruktur fisik seperti jembatan, jalan raya, gedung, dan sistem drainase. Pekerjaan mereka mencakup berbagai aspek, mulai dari analisis struktural hingga pengelolaan proyek konstruksi."
			arrJ[i].perus = "PT_Lippo_Karacawi_Tbk"
			arrJ[i].lokasi = "Medan"
			arrJ[i].gaji = 6000000
			arrJ[i].akreditasi = "E"
			arrJ[i].waktu = "Full_Time"
			arrJ[i].persyaratan = "\n1) Kandidat harus memiliki setidaknya gelar Sarjana Teknik Sipil\n2) Minimal 5 tahun pengalaman kerja di bidang terkait diperlukan untuk posisi ini.\n3) Berpengalaman dalam proyek perumahan\n4) Siap ditempatkan di Medan"
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				if k == 0 {
					arrJ[i].Rating.rating[k] = 5
					arrJ[i].Rating.user[k] = "GerhanaMagis78"
					arrJ[i].Rating.message[k] = "Banyak bertemu dengan berbagai customer dan pihak lainnya, memiliki lingkungan yang baik antara level jabatan/posisi, saling mendukung antar karyawan.Challengesnya tu Medan lapangan yang cukup panas sehingga perlu menjaga baik kesehatan, dan cepat tanggap terkait kejadian-kejadian tak terduga di kawasan."
				} else if k == 1 {
					arrJ[i].Rating.rating[k] = 1
					arrJ[i].Rating.user[k] = "PurnamaPermai55"
					arrJ[i].Rating.message[k] = "Working across a mall in Medan mall, so if you felt a bit bored, a coffee shop it's only within a walking distance. They got working attendance sheet in place, but the good news is they don't really care if you're late or not."
				} else if k == 2 {
					arrJ[i].Rating.rating[k] = 2
					arrJ[i].Rating.user[k] = "JelajahJiwaku36"
					arrJ[i].Rating.message[k] = "need strength and logic, it's almost consume full of your day.But, the challenges are Logic, think everything and solving problem as soon as possible, need very well condition of your health"
				}
			}
		}
	}
}

func Gaji(arrJ *tabJob) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat
	   FS. Mengembalikan data-data gaji dan memilih gaji */
	var g, gaji, o, no,d int
	var y, x, p, k, pos, per,e string
	var i int
	var h, found bool

	for i = 0; i < len(*arrJ); i++ {
		fmt.Printf("%d. %s\n", i+1, arrJ[i].posisi)
		fmt.Println()
		fmt.Printf("Gaji: %d\n", arrJ[i].gaji)
		fmt.Println()
	}
	fmt.Println("Pilih range gaji yang dinginkan :")
	fmt.Println("1) 1jt - 4jt")
	fmt.Println("2) 5jt - 8jt")
	fmt.Println("3) 9jt - 12jt")
	fmt.Println("4) 13jt - 16jt")
	fmt.Println("5) 17jt - 20jt")
	fmt.Print("Pilihan: ")
	fmt.Scan(&g)
	if g < 1 && g > 5{
		fmt.Println("Invalid")
		Gaji(arrJ)
	}
	found = false
	if g >= 1 && g <= 5 {
		fmt.Println("Info Gaji yang cocok untuk kamu")
		for i = 0; i < len(*arrJ); i++ {
			gaji = arrJ[i].gaji
			if (g == 1 && gaji >= 1000000 && gaji <= 4000000) || (g == 2 && gaji >= 5000000 && gaji <= 8000000) || (g == 3 && gaji >= 9000000 && gaji <= 12000000) || (g == 4 && gaji >= 13000000 && gaji <= 16000000) || (g == 5 && gaji >= 17000000 && gaji <= 20000000) {
				fmt.Printf("%d. %s\n", i+1, arrJ[i].posisi)
				fmt.Println()
				fmt.Printf("Gaji: %d\n", gaji)
				fmt.Println()
				found = true
			}
		}
		if !found {
			fmt.Println("Maaf, kami tidak menemukan gaji yang tapat untuk kamu")
			fmt.Println("Mau balik ke menu utama? (Ketik Y or N)")
			fmt.Scan(&x)
			if x == "Y" {
				infoLoker()
			} else if x == "N" {
				Gaji(arrJ)
			}

		}
	}
	fmt.Print("Apakah tertarik dengan gaji tersebut? (Ketik Y or N)", " ")
	fmt.Scan(&y)
	if y == "Y" {
		fmt.Println("Pilih nomor yang sesuai dengan porsi kamu :")
		fmt.Scan(&no)
		no = no - 1
		p = arrJ[no].posisi
		o = arrJ[no].gaji
		h = cekPTgaji(arrJ, &p, &o)
		if h {
			fmt.Println("Mau tambah Komen? (Ketik Y or N)")
			fmt.Scan(&k)
			if k == "Y" {
				pos = arrJ[no-1].posisi
				per = arrJ[no-1].perus
				tambahUlasan(arrJ, &pos, &per)
				fmt.Println("Apakah mau diedit (Ketik '1'), dihapus (Ketik '2'), atau balik ke menu utama (Ketik '3')?")
				fmt.Scan(&d)
				if d == 1{
                   editUlasan(arrJ,&pos,&per)
				   fmt.Println("Balik ke menu utama (Ketik 'Y') ?")
				   fmt.Scan(&e)
				   if e == "Y"{
					infoLoker()
				   }
				}else if d == 2{
					hapusUlasan(arrJ,&pos,&per)
					fmt.Println("Balik ke menu utama (Ketik 'Y') ?")
					fmt.Scan(&e)
					if e == "Y"{
					 infoLoker()
					}
				}else if d == 3{
					infoLoker()
				}else {
						fmt.Println("Invalid")
						Gaji(arrJ)
				}
			}
		}
	} else if k == "N" {
		fmt.Println("Baiklah, Apakah mau cari gaji lainnya (Ketik Y or N)")
		fmt.Scan(&x)
		if x == "Y" {
			Gaji(arrJ)
		} else if x == "N" {
			fmt.Println("Baiklah, kembali ke menu utama")
			infoLoker()
		}else{
			fmt.Println("Invalid")
		    Gaji(arrJ)
		}
	}else {
		fmt.Println("Invalid")
		Gaji(arrJ)
	}
}

func Rating(arrJ *tabJob) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat
	   FS. Mengembalikan data-data rating dan memilih rating */
	hasilPT(arrJ)
	var i, j, k, g, rat, no int
	var y, us, mes, x, pos, per string
	var found bool
	for i = 0; i < len(*arrJ); i++ {
		fmt.Printf("%d. %s\n", i+1, arrJ[i].posisi)
		fmt.Println()
		fmt.Printf("Perusahaan %d: %s\n", j+1, arrJ[i].perus)
		fmt.Println()
		for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
			fmt.Printf("Rating %d: %d\n", k+1, arrJ[i].Rating.rating[k])
			fmt.Println()
			fmt.Printf("User     : %s\n", arrJ[i].Rating.user[k])
			fmt.Println()
			fmt.Printf("Pesan    : %s\n", arrJ[i].Rating.message[k])
			fmt.Println()
		}
	}
	fmt.Println("Pilih rating yang dinginkan :")
	fmt.Println("1) Rating 5/5")
	fmt.Println("2) Rating 4/5")
	fmt.Println("3) Rating 3/5")
	fmt.Println("4) Rating 2/5")
	fmt.Println("5) Rating 1/5")
	fmt.Print("Pilihan: ")
	fmt.Scan(&g)
	if g < 1 && g > 5{
			fmt.Println("Invalid")
			Rating(arrJ)
	}
	fmt.Println("Hasil yang kami temukan")
	found = false
	if g >= 1 && g <= 5 {
		for i = 0; i < len(*arrJ); i++ {
			for k = 0; k < len((*arrJ)[i].Rating.user); k++ {
				rat = arrJ[i].Rating.rating[k]
				us = arrJ[i].Rating.user[k]
				mes = arrJ[i].Rating.message[k]
				if (g == 1 && rat == 5) || (g == 2 && rat == 4) || (g == 3 && rat == 3) || (g == 4 && rat == 2) || (g == 5 && rat == 1) {
					fmt.Printf("%d. %s\n", i+1, arrJ[i].posisi)
					fmt.Println()
					fmt.Printf("Perusahaan :%s\n", arrJ[i].perus)
					fmt.Println()
					fmt.Printf("User: %s\n", us)
					fmt.Println()
					fmt.Printf("Pesan: %s\n", mes)
					fmt.Println()
					found = true
				}
			}

		}
		if !found {
			fmt.Println("Maaf, kami tidak menemukan rating yang tepat")
			fmt.Println("Mau balik ke menu utama? (Ketik Y or N)")
			fmt.Scan(&x)
			if x == "Y" {
				infoLoker()
			} else if x == "N" {
				Rating(arrJ)
			}
		}
	}
	fmt.Println("Apakah tertarik dengan rating tersebut? (Ketik Y or N)")
	fmt.Scan(&y)
	if y == "Y" {
		fmt.Println("Pilih nomor berapa")
		fmt.Scan(&no)
		no = no - 1
		pos = arrJ[no].posisi
		per = arrJ[no].perus
		Pilihposisi(arrJ, &pos, &per, &no)
	} else if y == "N" {
		fmt.Println("Baiklah, Apakah mau cari gaji lainnya (Ketik Y or N)")
		fmt.Scan(&x)
		if x == "Y" {
			Rating(arrJ)
		} else if x == "N" {
			fmt.Println("Baiklah, kembali ke menu utama")
			infoLoker()
		}else {
			fmt.Println("Invalid")
			Rating(arrJ)
		}
	}else {
		fmt.Println("Invalid")
			Rating(arrJ)
	}
}

func Akreditasi(arrJ *tabJob) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat
	   FS. Mengembalikan data-data akreditasi dan memilih akreditasi */
	var i, pilih, no int
	var akred, y, pos, per string
	fmt.Print("1) Akreditasi A\n2) Akreditasi B\n3) Akreditasi C\n4) Akreditasi D\n5) Akreditasi E\n")
	fmt.Println("Mau akreditasi yang mana nih? (Pilih nomor saja)")
	fmt.Scan(&pilih)
	if pilih < 1 && pilih > 5{
		fmt.Println("Invalid")
			Akreditasi(arrJ)
	}
	hasilPT(arrJ)
	for i = 0; i < len(*arrJ); i++ {
		akred = arrJ[i].akreditasi
		if (pilih == 1 && akred == "A") || (pilih == 2 && akred == "B") || (pilih == 3 && akred == "C") || (pilih == 4 && akred == "D") || (pilih == 5 && akred == "E") {
			fmt.Printf("%d. %s\n", i+1, arrJ[i].posisi)
			fmt.Println()
			fmt.Printf("Perusahaan : %s\n", arrJ[i].perus)
			fmt.Println()
			fmt.Printf("Akreditasi :%s\n", arrJ[i].akreditasi)
			fmt.Println()
		}
	}

	fmt.Println("Apakah ada menemukan akreditasi yang tepat untuk kamu? (Ketik Y or N)")
	fmt.Scan(&y)
	if y == "Y" {
		fmt.Println("Pilih nomor :")
		fmt.Scan(&no)
		no = no - 1
		pos = arrJ[no].posisi
		per = arrJ[no].perus
		Pilihposisi(arrJ, &pos, &per, &no)
	} else if y == "N" {
		fmt.Println("Belum cocok ya, baik kami kembalikan ke halaman utama ya")
		infoLoker()
	}else {
		fmt.Println("Invalid")
			Akreditasi(arrJ)
	}
}

func Lokasi(arrJ *tabJob) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat
	   FS. Mengembalikan data-data lokasi dan memilih lokasi */
	var i, pilih, no int
	var locad, y, pos, per,x string
	fmt.Println("Pilih lokasi yang cocok untuk kamu")
	fmt.Print("1) Jakarta\n2) Bandung\n3) Medan\n4) Surabaya\n5) Palembang\n6) Denpasar\n7) Yogyakarta\n 8) Pontianak\n 9) Semarang")
	fmt.Scan(&pilih)
	if pilih < 1 && pilih > 9{
		fmt.Println("Invalid")
			Lokasi(arrJ)
	}
	hasilPT(arrJ)
	for i = 0; i < len(*arrJ); i++ {
		locad = arrJ[i].lokasi
		if (pilih == 1 && locad == "Jakarta") || (pilih == 2 && locad == "Bandung") || (pilih == 3 && locad == "Medan") || (pilih == 4 && locad == "Suarabaya") || (pilih == 5 && locad == "Palembang") || (pilih == 6 && locad == "Denpasar") || (pilih == 7 && locad == "Yogyakarta") || (pilih == 8 && locad == "Pontianak") ||  (pilih == 9 && locad == "Semarang"){
			fmt.Printf("%d. %s\n", i+1, arrJ[i].posisi)
			fmt.Println()
			fmt.Printf("Perusahaan : %s\n", arrJ[i].perus)
			fmt.Println()
			fmt.Printf("Lokasi :%s\n", arrJ[i].lokasi)
			fmt.Println()
		}
	}
	fmt.Println("Apakah ada menemukan lokasi yang tepat untuk kamu? (Ketik Y or N)")
	fmt.Scan(&y)
	if y == "Y" {
		fmt.Println("Pilih Nomor :")
		fmt.Scan(&no)
		no = no - 1
		pos = arrJ[no].posisi
		per = arrJ[no].perus
		Pilihposisi(arrJ, &pos, &per, &no)
	} else if y == "N" {
		fmt.Println("Baiklah, Apakah mau cari lokasi lainnya (Ketik Y or N)")
		fmt.Scan(&x)
		if x == "Y" {
			Lokasi(arrJ)
		} else if x == "N" {
			fmt.Println("Baiklah, kembali ke menu utama")
			infoLoker()
		}else {
			fmt.Println("Invalid")
			Lokasi(arrJ)
		}
	}else{
		fmt.Println("Invalid")
			Lokasi(arrJ)
	}
}

func Pilihposisi(arrJ *tabJob, p, q *string, no *int) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat, dua string p dan q dan satu bilangan bulat no
	   FS. Memeriksa apakah fungsi cekPTpos valid. Jika valid, maka bisa menambahkan ulasan atau balik ke menu */
	var k, pos, per,e string
	var h bool
	var d int
	h = cekPTpos(arrJ, p, q)
	if h {
		fmt.Println("Mau tambah Komen? (Ketik Y or N)")
		fmt.Scan(&k)
		if k == "Y" {
			pos = arrJ[*no].posisi
			per = arrJ[*no].perus
			tambahUlasan(arrJ, &pos, &per)
			fmt.Println("Apakah mau diedit (Ketik '1'), dihapus (Ketik '2'), atau balik ke menu utama (Ketik '3')?")
				fmt.Scan(&d)
				if d == 1{
                   editUlasan(arrJ,&pos,&per)
				   fmt.Println("Balik ke menu utama (Ketik 'Y') ?")
				   fmt.Scan(&e)
				   if e == "Y"{
					infoLoker()
				   }
				}else if d == 2{
					hapusUlasan(arrJ,&pos,&per)
					fmt.Println("Balik ke menu utama (Ketik 'Y') ?")
					fmt.Scan(&e)
					if e == "Y"{
					 infoLoker()
					}
				}else if d == 3{
					infoLoker()
				}else {
					fmt.Println("Invalid")
			        Pilihposisi(arrJ,p,q,no)
				}
		}else if k == "N"{
			fmt.Println("Baiklah, kembali ke menu utama")
			infoLoker()
		}else {
			fmt.Println("Invalid")
			Pilihposisi(arrJ,p,q,no)
		}
	}
}

func cekPTgaji(arrJ *tabJob, p *string, q *int) bool {
		/* Diterima array arrJ yang sudah terurut berdasarkan gaji dan berisi Jmax bilangan bulat beserta dua string p dan q,
		   mengembalikan TRUE apabila p dan q ditemukan di dalam array arrJ menggunakan binary search */
		var awal, akhir, tengah,i int
		awal = 0
		akhir = len(*arrJ) - 1
		searchSortGajiAscending(arrJ)
	
		for i = 0; i < len(arrJ); i++{
			if arrJ[i].posisi == *p{
		for awal <= akhir {
			tengah = (awal + akhir) / 2
			if arrJ[tengah].gaji == *q {
				output(arrJ, &tengah, &awal, &akhir)
				return true
			} else if  arrJ[tengah].gaji < *q {
				awal = tengah + 1
			} else {
				akhir = tengah - 1
			}
		}
		}
	}
		return false
	}

func sortGaji(arrJ *tabJob) {
	/* IS. terdefinisi array arrJ yang berisi Jmax bilangan bulat 
	   FS. array arrJ bagian gaji terurut secara DESCENDING dan ASCENDING dengan menggunakan algoritma selection sort */
	var pass, idx,no, i int
	var temp string
	hasilPT(arrJ)
	fmt.Println("Mau terurut gimana?\n 1) Besar ke kecil\n2) Kecil ke besar")
	fmt.Scan(&no)
	if no == 1{
		pass = 1
		for pass <= len(*arrJ)-1 {
			idx = pass - 1
			i = pass
			for i < len(*arrJ) {
				if arrJ[idx].gaji <= arrJ[i].gaji {
					idx = i
				}
				i++
			}
			swap(&arrJ[pass-1].gaji, &arrJ[idx].gaji)
			temp = arrJ[pass-1].posisi
			arrJ[pass-1].posisi = arrJ[idx].posisi
			arrJ[idx].posisi = temp
			pass++

		}

	} else if no == 2 {
		pass = 1
		for pass <= len(*arrJ)-1 {
			idx = pass - 1
			i = pass
			for i < len(*arrJ) {
				if arrJ[idx].gaji > arrJ[i].gaji {
					idx = i
				}
				i++
			}
			swap(&arrJ[pass-1].gaji, &arrJ[idx].gaji)
			temp = arrJ[pass-1].posisi
			arrJ[pass-1].posisi = arrJ[idx].posisi
			arrJ[idx].posisi = temp
			pass++
		}
	}else {
		fmt.Println("Invalid")
		sortGaji(arrJ)
	}
}

func searchSortGajiAscending(arrJ *tabJob){
	var pass, idx, i int
	var temp string
	hasilPT(arrJ)
	pass = 1
		for pass <= len(*arrJ)-1 {
			idx = pass - 1
			i = pass
			for i < len(*arrJ) {
				if arrJ[idx].gaji > arrJ[i].gaji {
					idx = i
				}
				i++
			}
			swap(&arrJ[pass-1].gaji, &arrJ[idx].gaji)
			temp = arrJ[pass-1].posisi
			arrJ[pass-1].posisi = arrJ[idx].posisi
			arrJ[idx].posisi = temp
			pass++
		}
	}

func swap(a, b *int) {
	/* IS. Terdefinisi 2 buah bilangan bulat a dan b
	   FS. Mengembalikan nilai a dan b yang sudah ditukar */
	var temp int
	temp = *a
	*a = *b
	*b = temp
}

func sortRating(arrJ *tabJob) {
	/* IS. terdefinisi array arrJ yang berisi Jmax bilangan bulat 
	   FS. array arrJ bagian rating terurut secara DESCENDING dan ASCENDING dengan menggunakan algoritma insertion sort */
	var j, i, idx, key,no int
	hasilPT(arrJ)
	fmt.Println("Mau terurut gimana?\n 1) Besar ke kecil\n2) Kecil ke besar")
	fmt.Scan(&no)
	if no == 1 {
		for j = 0; j < len(*arrJ); j++ {
			for i = 1; i < len((*arrJ)[i].Rating.user); i++ {
				key = arrJ[j].Rating.rating[i]
				idx = i - 1
				for idx >= 0 && arrJ[j].Rating.rating[idx] < key {
					arrJ[j].Rating.rating[idx+1] = arrJ[j].Rating.rating[idx]
					idx--
				}
				arrJ[j].Rating.rating[idx+1] = key
			}

		}
	} else if no == 2 {
		for j = 0; j < len(*arrJ); j++ {
			for i = 1; i < len((*arrJ)[i].Rating.user); i++ {
				key = arrJ[j].Rating.rating[i]
				idx = i - 1
				for idx >= 0 && arrJ[j].Rating.rating[idx] >= key {
					arrJ[j].Rating.rating[idx+1] = arrJ[j].Rating.rating[idx]
					idx--
				}
				arrJ[j].Rating.rating[idx+1] = key
			}

		}
	}else {
		fmt.Println("Invalid")
		sortRating(arrJ)
	}
}

func Waktu(arrJ *tabJob) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat
	   FS. Mengembalikan data-data waktu dan memilih waktu */
	var g int
	var y, p, waktu, o, k, pos, per,x,e string
	var i, j, no,d int
	var h, found bool
	hasilPT(arrJ)
	for i = 0; i < len(*arrJ); i++ {
		fmt.Printf("Posisi: %d. %s\n", i+1, arrJ[i].posisi)
		fmt.Println()
		fmt.Printf("Waktu %d: %d\n", j+1, arrJ[i].waktu)
		fmt.Println()

	}
	fmt.Println("Pilih waktu yang dinginkan :")
	fmt.Print("1) Full Time \n2) Kontrak\n3) Paruh Waktu\n4) Kasual\n")
	fmt.Scan(&g)
	if g < 1 && g > 4{
		fmt.Println("Invalid")
		Waktu(arrJ)
	}
	found = false
	if g >= 1 && g <= 4 {
		fmt.Println("Info Waktu yang cocok untuk kamu")
		for i = 0; i < len(*arrJ); i++ {
			waktu = arrJ[i].waktu
			if (g == 1 && waktu == "Full_Time") || (g == 2 && waktu == "Kontrak") || (g == 3 && waktu == "Paruh_Waktu") || (g == 4 && waktu == "Kasual") {
				fmt.Printf("%d. %s\n",i+1, arrJ[i].posisi)
				fmt.Println()
				fmt.Printf("   Waktu: %s\n", waktu)
				fmt.Println()
				found = true
			}
		}
		if !found {
			fmt.Println("Maaf, kami tidak menemukan waktu yang tapat untuk kamu")
			fmt.Println("Mau balik ke menu utama? (Ketik Y or N)")
			fmt.Scan(&x)
			if x == "Y" {
				infoLoker()
			} else if x == "N" {
				Waktu(arrJ)
			}

		}
	}
	fmt.Println("Apakah tertarik dengan waktu tersebut? (Ketik Y or N)")
	fmt.Scan(&y)
	if y == "Y" {
		fmt.Print("Pilih nomor :"," ")
		fmt.Scan(&no)
		no = no - 1
		p = arrJ[no].posisi
		o = arrJ[no].waktu
		h = cekPTwaktu(arrJ, &p, &o)
		if h {
			fmt.Println("Mau tambah Komen? (Ketik Y or N)")
			fmt.Scan(&k)
			if k == "Y" {
				pos = arrJ[no].posisi
				per = arrJ[no].perus
				tambahUlasan(arrJ, &pos, &per)
				fmt.Println("Apakah mau diedit (Ketik '1'), dihapus (Ketik '2'), atau balik ke menu utama (Ketik '3')?")
				fmt.Scan(&d)
				if d == 1{
                   editUlasan(arrJ,&pos,&per)
				   fmt.Println("Balik ke menu utama (Ketik 'Y' or 'N') ?")
				   fmt.Scan(&e)
				   if e == "Y"{
					infoLoker()
				   }
				}else if d == 2{
					hapusUlasan(arrJ,&pos,&per)
					fmt.Println("Balik ke menu utama (Ketik 'Y' or 'N') ?")
					fmt.Scan(&e)
					if e == "Y"{
					 infoLoker()
					}
				}else if d == 3{
					infoLoker()
				}else {
					fmt.Println("Invalid")
		            Waktu(arrJ)
				}
			}
		} else if y == "N" {
			fmt.Println("Baiklah, Apakah mau cari waktu lainnya (Ketik Y or N)")
			fmt.Scan(&x)
			if x == "Y" {
				Waktu(arrJ)
			} else if x == "N" {
				fmt.Println("Baiklah, kembali ke menu utama")
				infoLoker()
			}else {
				fmt.Println("Invalid")
		        Waktu(arrJ)
			}
		}else {
			fmt.Println("Invalid")
		    Waktu(arrJ)
		}
	}
}

func cekPTwaktu(arrJ *tabJob, p, q *string) bool {
	/* Diterima array arrJ yang berisi Jmax bilangan bulat beserta dua string p dan q, mengembalikan TRUE apabila p dan q ditemukan didalam array arrJ menggunakan sequential search */
	var i, j, k int
	var ketemu bool
	ketemu = false
	i = 0
	hasilPT(arrJ)
	for i < len(*arrJ) && !ketemu {
		if arrJ[i].posisi == *p && arrJ[i].waktu == *q {
			ketemu = true
			output(arrJ, &i, &j, &k)
		}
		i++
	}
	return ketemu
}

func tambahUlasan(arrJ *tabJob, pos, per *string) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat dan dua string pos dan per
	   FS. Menambahkan komentar pada suatu pekerjaan dan perusahaan*/
	var i,j int
	var  m string
	var r int

	fmt.Println("Berapa rating (1-5)?")
	fmt.Scan(&r)
	fmt.Println("Pesan :")
	fmt.Scan(&m)

	for i = 0; i < len(*arrJ); i++ {
		if (*arrJ)[i].posisi == *pos && (*arrJ)[i].perus == *per {
			for j = 0; j < kmax; j++ {
				if (*arrJ)[i].Rating.user[j] == "" {
					(*arrJ)[i].Rating.user[j] = U
					(*arrJ)[i].Rating.rating[j] = r
					(*arrJ)[i].Rating.message[j] = m
					fmt.Println("Ulasan berhasil ditambahkan!")
				}
			}
		}
	}
}

func editUlasan(arrJ *tabJob, pos, per *string) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat dan dua string pos dan per
	   FS. Mengedit komentar pada suatu pekerjaan dan perusahaan*/
	var i, j, newRating int
	var newMessage string
	
	for i = 0; i < len(*arrJ); i++ {
		if arrJ[i].posisi == *pos {
			for j = 0; j < len((*arrJ)[i].Rating.user); j++ {
				if arrJ[i].Rating.user[j] == U {
					fmt.Println("Ratingnya jadi apa?")
					fmt.Scan(&newRating)
					fmt.Println("Pesannya apa?")
					fmt.Scan(&newMessage)
					arrJ[i].Rating.rating[j] = newRating
					arrJ[i].Rating.message[j] = newMessage
					fmt.Println("Ulasan berhasil diubah!")
				}
			}
		}
	}
}
func hapusUlasan(arrJ *tabJob, pos, per *string) {
	/* IS. Terdefinisi array arrJ yang berisi Jmax bilangan bulat dan dua string pos dan per
	   FS. Menghapus komentar pada suatu pekerjaan dan perusahaan*/
	var i, j int

	for i = 0; i < len(*arrJ); i++ {
		if (*arrJ)[i].posisi == *pos && (*arrJ)[i].perus == *per{
			for j = 0; j < len((*arrJ)[i].Rating.user); j++ {
				if (*arrJ)[i].Rating.user[j] == U {
					(*arrJ)[i].Rating.user[j] = (*arrJ)[i].Rating.user[len((*arrJ)[i].Rating.user)-1]
					(*arrJ)[i].Rating.rating[j] = (*arrJ)[i].Rating.rating[len((*arrJ)[i].Rating.rating)-1]
					(*arrJ)[i].Rating.message[j] = (*arrJ)[i].Rating.message[len((*arrJ)[i].Rating.message)-1]

					fmt.Println("Ulasan pengguna berhasil dihapus!")
				}
			}

		}
	}
}
