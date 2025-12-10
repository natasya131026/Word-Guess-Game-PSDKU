void gambarHukuman(int kesempatan) {
    cout << "\n--- HUKUMAN ---\n";
    switch (kesempatan) {
        case 8: 
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "      |\n"; cout << "      |\n"; cout << "      |\n"; cout << "      |\n"; break;
        case 7: 
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "      |\n"; cout << "      |\n"; cout << "      |\n"; cout << "      |\n"; break;
        case 6:
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "      |\n"; cout << "      |\n"; cout << "      |\n"; cout << "      |\n"; break;
        case 5:
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "  O   |\n"; cout << "      |\n"; cout << "      |\n"; cout << "      |\n"; break;
        case 4:
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "  O   |\n"; cout << "  |   |\n"; cout << "      |\n"; cout << "      |\n"; break;
        case 3:
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "  O   |\n"; cout << " /|   |\n"; cout << "      |\n"; cout << "      |\n"; break;
        case 2:
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "  O   |\n"; cout << " /|\\  |\n"; cout << "      |\n"; cout << "      |\n"; break;
        case 1:
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "  O   |\n"; cout << " /|\\  |\n"; cout << " /    |\n"; cout << "      |\n"; break;
        case 0:
            cout << "  +---+\n"; cout << "  |   |\n"; cout << "  O   |\n"; cout << " /|\\  |\n"; cout << " / \\  |\n"; cout << "      |\n"; break;
    }
    cout << "-------------\n";
}

void tampilkanBantuan() {
    cout << "\n== BANTUAN BERMAIN ==\n";
    cout << "1. Pilih 'Mulai Permainan Baru'.\n";
    cout << "2. Pilih kategori dan level kesulitan (kesempatan 4 hingga 8).\n";
    cout << "3. Anda akan diberikan kata dengan huruf yang disamarkan dan Petunjuk.\n";
    cout << "4. Anda dapat memilih [1] Tebak Huruf atau [2] Tebak Seluruh Kata.\n";
    cout << "5. Jika Tebak Huruf salah, Anda kehilangan 1 kesempatan.\n";
    cout << "6. Jika Tebak Seluruh Kata salah, Anda kehilangan 3 kesempatan.\n";
    cout << "7. Menang jika semua huruf terbuka, kalah jika nyawa habis.\n";
    cout << "8. Skor dihitung berdasarkan waktu dan sisa kesempatan.\n";
}


void tampilkanTentang() {
    cout << "\n==  TENTANG GAME INI ==\n";
    cout << "Project word guess game\n";
    cout << "Dibuat oleh:Kelompok 2\n";
    cout << "Tujuan: untuk memenuhi ujian akhir pratikum pemrograman\n";
}
