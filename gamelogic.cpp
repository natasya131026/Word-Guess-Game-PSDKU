#include "main.cpp" // Asumsi semua definisi struct dan daftarKataClue ada di main.cpp/header

// --- FUNGSI UTAMA GAME (Modul 3, integrasi dengan Modul 2, 4, 5) ---
void mulaiGame() {
    cout << "╔═══════════════════════════════════════╗\n";
    cout << "║         M E M U L A I   G A M E         ║\n";
    cout << "╠═══════════════════════════════════════╣\n";
    
    GameSettings pengaturan = pilihKategoriDanLevel(); // Modul 2
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    if (!pengaturan.valid) {
        cout << "\nPengaturan game dibatalkan. Kembali ke menu utama.\n";
        return;
    }
    
    // Pemilihan Kata Acak (Modul 2)
    vector<WordData> kataKategori;
    for (const auto& wd : daftarKataClue) {
        if (wd.category == pengaturan.kategoriDipilih) {
            kataKategori.push_back(wd);
        }
    }
    
    if (kataKategori.empty()) {
        cout << "Error: Tidak ada kata untuk kategori ini.\n";
        return;
    }

    WordData kataDipilih = kataKategori[rand() % kataKategori.size()];
    
    string kata = kataDipilih.word;
    string clue = kataDipilih.clue;

    string tebakan(kata.length(), '_');
    int kesempatan = pengaturan.kesempatanAwal; 
    char huruf;
    string hurufSudahDicoba = "";
    string inputPilihan;

    cout << "\nKategori: " << pengaturan.kategoriDipilih << " | Level: " << (pengaturan.kesempatanAwal == 8 ? "Mudah" : (pengaturan.kesempatanAwal == 6 ? "Sedang" : "Sulit")) << endl;
    cout << "PETUNJUK: " << clue << endl;
    
    auto waktuMulai = high_resolution_clock::now(); // Modul 4
    
    // --- GAME LOOP INTI (Modul 3) ---
    while (kesempatan > 0 && tebakan != kata) {
        
        gambarHukuman(kesempatan); // Modul 5
        
        cout << "\nKata: ";
        for (char c : tebakan) {
            cout << c << " ";
        }
        cout << "\nKesempatan tersisa: " << kesempatan << endl;
        cout << "Huruf yang sudah dicoba: [" << hurufSudahDicoba << "]" << endl;
        
        cout <<"\n===============================================\n";
        cout << "[1] Tebak Huruf | [2] Tebak Seluruh Kata (Risiko: -3 Kesempatan)\n";
        cout << ">>> Pilihan Anda (1 atau 2): ";
        
        if (!(cin >> inputPilihan)) {
            cout << "Input tidak valid.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (inputPilihan == "1") {
            cout << "Masukkan SATU huruf: ";
            
            cin >> huruf;
            
            if (!isalpha(huruf)) {
                cout << "Input tidak valid. Harap masukkan SATU huruf.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            huruf = tolower(huruf); 

            if (hurufSudahDicoba.find(huruf) != string::npos) {
                cout << "huruf '" << huruf << "' sudah pernah Anda coba! Silakan masukkan huruf lain.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            hurufSudahDicoba += huruf;
            
            bool benar = false;
            
            for (int i = 0; i < kata.length(); i++) {
                if (kata[i] == huruf) {
                    tebakan[i] = huruf;
                    benar = true;
                }
            }

            if (!benar) {
                kesempatan--;
                cout << "Huruf salah! Coba lagi.\n";
            } else {
                cout << "Ada huruf yang benar! Lanjutkan!\n";
            }
        }
        else if (inputPilihan == "2") {
            string tebakanPenuh;
            cout << "Masukkan tebakan kata penuh: ";
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, tebakanPenuh);
            
            for (char &c : tebakanPenuh) {
                c = tolower(c);
            }
            if (tebakanPenuh == kata) {
                tebakan = kata;
                cout << "TEPAT SEKALI! Anda berhasil menebak kata penuh! : *" << kata <<"*\n";
            } else {
                kesempatan -= 3;
                cout << "TEBAKAN SALAH! Anda kehilangan 3 kesempatan.\n";
            }
            
        } else {
            cout << "Pilihan tidak valid. Harap Masukkan '1' atau '2'.\n";
        }
        
        if (inputPilihan == "1" && !cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        cout << "\n==============================================\n";
    }
    
    // --- AKHIR GAME & HITUNG SKOR (Modul 4) ---
    auto waktuSelesai = high_resolution_clock::now();
    auto durasi = duration_cast<seconds>(waktuSelesai - waktuMulai);
    long long durasiDetik = durasi.count();
    
    gambarHukuman(kesempatan); // Modul 5
    int skorAkhir = 0;
    
    if (tebakan == kata) {
        cout << " SELAMAT! Kamu berhasil menebak kata: *" << kata << "*\n";
        
        skorAkhir = 1000 + (kesempatan * 50);
        skorAkhir += max(0, 500 - (int)durasiDetik * 5); 

        cout << "\n-----------------------------------------------";
        cout << "\n SKOR ANDA \n";
        cout << "Skor Dasar: 1000\n";
        cout << "Bonus Kesempatan (" << kesempatan << "x): +" << kesempatan * 50 << endl;
        cout << "Durasi Waktu: " << durasiDetik << " detik\n";
        cout << "Bonus Waktu: +" << max(0, 500 - (int)durasiDetik * 5) << endl;
        cout << "TOTAL SKOR: " << skorAkhir << " poin\n";
        cout << "-----------------------------------------------\n";

        string namaPemain;
        cout << "Masukkan nama Anda (tanpa spasi): ";
        
        cin >> namaPemain; 
        simpanSkor(namaPemain, skorAkhir); // Modul 4
        
    } else {
        cout << "KAMU KALAH! Kata yang benar adalah: *" << kata << "*\n";
        cout << "TOTAL SKOR: 0 poin\n";
    }
    cout << "===============================================\n";
}
