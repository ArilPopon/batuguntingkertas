#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// membuat dasaran class player
class Player
{
protected:
    string nama;
    int pilihan;

public:
    // constructor
    Player(string n)
    {
        nama = n;
        pilihan = 0; // default
    }

    // desctructor
    ~Player()
    {
        cout << "Destructor dipanggil untuk " << nama << endl;
    }

    // setter Pilihan
    void setPilihan(int p)
    {
        pilihan = p;
    }

    // getter Pilihan
    int getPilihan()
    {
        return pilihan;
    }

    // getter nama
    string getNama()
    {
        return nama;
    }
};

// clas turunan human Player sama Computer Player
class HumanPlayer : public Player
{
public:
    // constructor nama pemain
    HumanPlayer(string n) : Player(n) {}

    // method untuk pilihan
    void inputPilihan()
    {
        cout << "\n[1] Batu\n[2] Gunting\n[3] kertas\n";
        cout << nama << ", Pilih Gerakan Apa Kamu: ";
        cin >> pilihan;
    }
};

class ComputerPlayer : public Player
{
public:
    // constructor
    ComputerPlayer(string n = "Komputer") : Player(n) {}

    // method pilihan
    void generatePilihan()
    {
        pilihan = (rand() % 3) + 1; // pilih angka acak 1-3
        cout << nama << "Memilih Secara Acak Otomatis" << endl;
    }
};

// class Game
class Game
{
private:
    HumanPlayer pemainManusia;
    ComputerPlayer pemainKomputer;

    // fungsi konversi pilihan ke string
    string konversiPilihan(int p)
    {
        switch (p)
        {
        case 1:
            return "Batu";
            break;
        case 2:
            return "Gunting";
            break;
        case 3:
            return "Kertas";
            break;
        default:
            return "tidak valid";
            break;
        };
    };

    // Fungsi cek hasil permainan
    void cekHasil()
    {
        int p1 = pemainManusia.getPilihan();
        int p2 = pemainKomputer.getPilihan();

        // Tampilkan PIlihan dari pemain
        cout << pemainManusia.getNama() << "Memilih: " << konversiPilihan(p1) << endl;
        cout << pemainKomputer.getNama() << "Memilih: " << konversiPilihan(p2) << endl;

        // tetntukan pemenang
        if (p1 == p2)
        {
            cout << "Hasil: Seri";
        }
        else if ((p1 == 1 && p2 == 2) || (p1 == 2 && p2 == 3) || (p1 == 3 && p2 == 1))
        {
            cout << "Pemenangnya adalah : " << pemainManusia.getNama() << endl;
        }
        else
        {
            cout << "Pemenangnya adalah : " << pemainKomputer.getNama() << endl;
        }
    }

public:
    // constructor game
    Game(string namaPemain) : pemainManusia(namaPemain), pemainKomputer() {};

    // method jalankan permainan
    void mainkan()
    {
        pemainManusia.inputPilihan();
        pemainKomputer.generatePilihan();
        cekHasil();
    }
};

// main class
int main()
{

    srand(time(0));

    string nama;
    cout << "Masukkan Nama Kamu: ";
    cin >> nama;

    Game g(nama); // buat object game dengan nama player

    char lagi;
    do
    {
        g.mainkan();
        cout << "\nMain Lagi?\n";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    cout << "Terimakasih Telah Bermain, sampai jumpa" << endl;

    return 0;
}