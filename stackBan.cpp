//Stack Ban (id Ban dan Merk Ban)
// Pertama, mengambil library yang dibutuhkan
#include <iostream>
#define BMAXX 10
using namespace std;

struct Ban
{
    int idBan;
    string merkBan;
};

struct Stack
{
    private :
        int count;
    public :
        Ban* item;

            Stack()
            {
                count = -1;
                item = new Ban[BMAXX];
            }

            bool full()
            {
                return (count == BMAXX);
            }

            bool empty()
            {
                return (count == -1);
            }

            void push(Ban val)
            {
                if (!full())
                {
                    count++;
                    item[count] = val;
                }
                else
                {
                    cout << "Stack Penuh" << endl;
                }
            }

            void pop()
            {
                if (!empty())
                {
                    count--;
                }
                else
                {
                    cout << "Stack Kosong" << endl;
                }
            }

            void top()
            {
                if (!empty())
                {
                    cout << "ID Ban : " << item[count].idBan << endl;
                    cout << "Merk Ban : " << item[count].merkBan << endl;
                }
                else
                {
                    cout << "Stack Kosong" << endl;
                }
            }

            void print()
            {
                if (!empty())
                {
                    for (int i = count; i >= 0; i--)
                    {
                        cout << "ID Ban : " << item[i].idBan << endl;
                        cout << "Merk Ban : " << item[i].merkBan << endl;
                    }
                }
                else
                {
                    cout << "Stack Kosong" << endl;
                }
            }

            void length()
            {
                cout << "Jumlah Tumpukan Ban : ";
                if (!empty())
                {
                    cout << count + 1 << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }

            ~Stack()
            {
                delete[] item;
            }
};

Stack stackBan;

void menu()
{
    int pilihan;
    Ban ban;
    do
    {
        cout << "\n----------- Menu Stack Ban -----------" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Push    (Menambah data baru)" << endl;
        cout << "2. Pop     (Menghapus data terakhir)" << endl;
        cout << "3. Top     (Menampilkan data terakhir)" << endl;
        cout << "4. Print   (Menampilkan semua data)" << endl;
        cout << "5. Length  (Menampilkan jumlah data)" << endl;
        cout << "6. Exit    (Keluar dari menu)" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        cout << "--------------------------------------" << endl;
        switch (pilihan)
        {
        case 1:
            cout << "ID Ban : ";
            cin >> ban.idBan;
            cout << "Merk Ban : ";
            cin >> ban.merkBan;
            stackBan.push(ban);
            break;
        case 2:
            stackBan.pop();
            break;
        case 3:
            stackBan.top();
            break;
        case 4:
            stackBan.print();
            break;
        case 5:
            stackBan.length();
            break;
        case 6:
            cout << "Terima Kasih :)" << endl;
            break;
        default:
            cout << "Pilihan Tidak Ada :(" << endl;
            break;
        }
    } while (pilihan != 6);
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
