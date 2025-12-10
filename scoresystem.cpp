bool bandingkanSkor(const ScoreEntry& a, const ScoreEntry& b) {
    return a.skor > b.skor;
}

void tampilkanPeringkat() {
    ifstream fileSkor("highscores.txt");
    vector<ScoreEntry> peringkat;
    string nama;
    int skor;

    if (fileSkor.is_open()) {
        cout << "\n============================================\n";
        cout << "         🏆 P A P A N   P E R I N G K A T 🏆\n";
        cout << "============================================\n";
        
        while (fileSkor >> nama >> skor) {
            peringkat.push_back({nama, skor});
        }
        fileSkor.close();

        sort(peringkat.begin(), peringkat.end(), bandingkanSkor);
        
        int count = 0;
        for (const auto& entry : peringkat) {
            if (count < 10) {
                cout << "[" << count + 1 << "]. " << entry.nama << " - " << entry.skor << " Poin\n";
                count++;
            } else {
                break;
            }
        }
        if (peringkat.empty()) {
            cout << "Belum ada skor yang tercatat.\n";
        }
        cout << "============================================\n";
    } else {
        cout << "Belum ada skor yang tercatat. Mainkan game sekarang!\n";
    }
}
