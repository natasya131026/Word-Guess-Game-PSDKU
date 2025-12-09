#include "main.cpp" // Asumsi semua definisi struct dan daftarKataClue ada di main.cpp/header

// --- FUNGSI PILIH KATEGORI & LEVEL (Modul 2) ---
GameSettings pilihKategoriDanLevel() {
    GameSettings settings;
    int pilihanKategori;
    int pilihanLevel;

    cout << "\n## PILIH KATEGORI KATA 📚\n";
    cout << "-------------------------\n";
    cout << "[1] Teknologi\n";
    cout << "[2] Akademik\n";
    cout << "[3] Umum\n";
    cout << ">>> Pilihan Anda (1-3): ";
    cin >> pilihanKategori;

    if (cin.fail() || pilihanKategori < 1 || pilihanKategori > 3) {
        cout << "Pilihan kategori tidak valid.\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return settings;
    }

    switch (pilihanKategori) {
        case 1: settings.kategoriDipilih = "Teknologi"; break;
        case 2: settings.kategoriDipilih = "Akademik"; break;
        case 3: settings.kategoriDipilih = "Umum"; break;
    }
    
    cout << "\n## PILIH LEVEL KESULITAN 💪\n";
    cout << "---------------------------\n";
    cout << "[1] Mudah (8 Kesempatan)\n";
    cout << "[2] Sedang (6 Kesempatan)\n";
    cout << "[3] Sulit (4 Kesempatan)\n";
    cout << ">>> Pilihan Anda (1-3): ";
    cin >> pilihanLevel;
    
    if (cin.fail() || pilihanLevel < 1 || pilihanLevel > 3) {
        cout << "Pilihan level tidak valid. Default ke Sedang (6 kesempatan).\n";
        settings.kesempatanAwal = 6;
    } else {
        switch (pilihanLevel) {
            case 1: settings.kesempatanAwal = 8; break;
            case 2: settings.kesempatanAwal = 6; break;
            case 3: settings.kesempatanAwal = 4; break;
        }
    }
    
    settings.valid = true;
    return settings;
}
