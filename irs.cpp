#include <iostream>
#include<list>
using namespace std;

class Board{
    public: 
        Board(int size = 100){
            for (int i = 1; i < 101; i++) {
                board.push_back(i);
            }
            cout << "Board constructed" << endl;
            p1_score = 0;
            p2_score = 0;
            irs_score = 0;
        }

        void print(){
            for (auto i:board){
                cout << i << " ";
            }
            cout << endl;
        }

        void move(){
            print();
            int temp;
            cout << "player 1 pick number" << endl;
            cin >> temp;
            p1_score += temp;
            board.remove(temp);
            irs_move(temp);

            cout << "player 2 pick number" << endl;
            cin >> temp;
            p2_score += temp;
            board.remove(temp);
            irs_move(temp);

            cout << endl;
            cout << "Player 1: " << p1_score << endl;
            cout << "Player 2: " << p2_score << endl;
            cout << "IRS: " << irs_score << endl;
        }
        void irs_move(int input){
            for (int p = 2; p <= input/2; p++) {
                if ((input % p) == 0) {
                    for (auto i:board) {
                        if (i == p) {
                            irs_score += p;
                        }
                    }
                    board.remove(p);
                }
            }

        }

        int get_size(){
            return int(board.size());
        }

    private:
        list<int> board;
        int p1_score;
        int p2_score;
        int irs_score;
};

int main(void){
    Board irs;
    while (irs.get_size() > 0) {
        irs.move();
    }
    return 0;
}
