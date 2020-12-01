#include "Field.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void play() {
    Field a(19, 5);
    pair<int, int> p, pc;
    p.first = 0;
    p.second = 0;
    pc.first = 0;
    pc.second = 0;
    while (a.predict2(p.first, p.second) == draw) {
        pc = a.nextMove2();
        a.put(pc.first, pc.second);
        a.print();
        if (a.predict2(pc.first, pc.second) != draw) {
            cout << "WINX";
            break;
        }
        cin >> p.first >> p.second;
        p = a.nextMove2();
        a.put(p.first, p.second);
        a.print();
    }
}

// Записывает в файлы кооринаты просчитанной точки
void nextMove() {
    ofstream out("//home/kirill/PycharmProjects/flaskProject/Cwrite");
    ifstream in("//home/kirill/PycharmProjects/flaskProject/Pwrite");
    string a;
    getline(in, a);
    getline(in, a);
    vector<vector<int>> field(19);
    for (int ii = 0; ii < 19; ++ii) {
        field[ii].reserve(19);
        for (int jj = 0; jj < 10; ++jj) {
            field[ii][jj] = 0;
        }
    }
    int kk = 0;
    for (int k = 0; k < 361; ++k) {
        if (a[k] == '0') {
            field[k / 19][k % 19] = 0;
            ++kk;
        }
        if (a[k] == 'X') {
            field[k / 19][k % 19] = 1;
            ++kk;
        }
        if (a[k] == ' ') {
            field[k / 19][k % 19] = -1;
        }
    }
    Field f(field, kk);
    auto p = f.nextMove2();
    out << p.first << "\n" << p.second << endl;
    in.close();
    out.close();
}

// Записывает в файл всю строку как игровое поле и статус игры
void put() {
    ofstream out("//home/kirill/PycharmProjects/flaskProject/Cwrite");
    ifstream in("//home/kirill/PycharmProjects/flaskProject/Pwrite");
    string a, i, j;
    getline(in, a);
    getline(in, i);
    getline(in, j);
    vector<vector<int>> field;
    int kk = 0;
    for (int k = 0; k < 361; ++k) {
        if (a[k] == '0') {
            field[k / 19][k % 19] = 0;
            ++kk;
        }
        if (a[k] == 'X') {
            field[k / 19][k % 19] = 1;
            ++kk;
        }
        if (a[k] == ' ') {
            field[k / 19][k % 19] = -1;
        }
    }
    Field f(field, kk);
    field = f.getField();
    status p = f.put(stoi(i), stoi(j));
    for (int ii = 0; ii < 19; ++ii) {
        for (int jj = 0; jj < 19; ++jj) {
            if (field[ii][jj] == 0) {
                out << "0";
            }
            if (field[ii][jj] == 1) {
                out << "X";
            }
            if (field[ii][jj] == -1) {
                out << " ";
            }
        }
    }
    out << "\n";
    out << p << endl;
    in.close();
    out.close();
}

int main() {
    ifstream in("//home/kirill/PycharmProjects/flaskProject/Pwrite");
    string a;
    getline(in, a);
    in.close();
    if (a == "put") {
        put();
    }
    else {
        nextMove();
    }
    return 0;
}
