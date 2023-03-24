//Stack Ban (id Ban dan Merk Ban)
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

            bool penuh()
            {
                return (count == BMAXX);
            }

            bool kosong()
            {
                return (count == -1);
            }

            void push(Ban val)
            {
                if (!penuh())
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
                if (!kosong())
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
                if (!kosong())
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
                if (!kosong())
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
};



int main(int argc, char const *argv[])
{
    Stack* stackBan = new Stack();

    Ban* ban1 = new Ban();

    ban1->idBan = 1;
    ban1->merkBan = "Dunlop";

    stackBan->push(*ban1);

    Ban* ban2 = new Ban();
    
    ban2->idBan = 2;
    ban2->merkBan = "Michelin";

    stackBan->push(*ban2);

    Ban* ban3 = new Ban();

    ban3->idBan = 3;
    ban3->merkBan = "Pirelli";

    stackBan->push(*ban3);

    Ban* ban4 = new Ban();

    ban4->idBan = 4;
    ban4->merkBan = "Bridgestone";

    stackBan->push(*ban4);

    stackBan->pop();

    stackBan->print();

    return 0;
}
