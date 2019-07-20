#include <iostream>
using namespace std;
int count(int, int);
void make(int, int, int);

int main() {
    int y, m, ds;
    cout << "輸入年份";
    cin >> y;
    for(int i = 1; i <= 12; i++) {
        m = i;
        
        ds = count(y, m);
        make(y, m, ds);
        cout << "\n\n";
    }
}

// 計算天數
// 1901.1.1 星期二
int count(int y, int m) {
    int feb, ds = 0;

    // 算天數(年)
    for(int i = 1901; i <= y; i++) {
        if(i % 4 == 0) {
            if(i % 100 != 0 || i % 400 == 0) {
                ds += 366;
            }else {
                ds += 365;
            }
        }else {
            ds += 365;
        }
    }

    // 算二月
    if(m > 2) {
        if(y % 4 == 0) {
            if(y % 100 != 0 || y % 400 == 0) {
                feb = 29;
            }else {
                feb = 28;
            }
        }else {
            feb = 28;
        }
    }


    // 算天數(月)
    for(int i = 1; i < m; i++) {
        if(i < 8 && i % 2 != 0) {
            ds += 31;
        }else if(i == 2) {
            ds += feb;
        }else if(i > 7 && i % 2 == 0) {
            ds += 31;
        }else {
            ds += 30;
        }
    }

    return ds;
}


void make(int y, int m, int ds){
    int feb, d, t, ts;
    cout << "\n      " << y << "年 " << m << "月\n";
    cout << "一 二 三 四 五 六 日\n";

    if(m >= 2) {
        if(y % 4 == 0) {
            if(y % 100 != 0 || y % 400 == 0) {
                feb = 29;
            }else {
                feb = 28;
            }
        }else {
            feb = 28;
        }
    }
    
    if(m < 8 && m % 2 != 0) {
        d = 31;
    }else if(m == 2) {
        d = feb;
    }else if(m > 7 && m % 2 == 0) {
        d = 31;
    }else {
        d = 30;
    }

    t = ds % 7;
    ts = t;
    for(int i = 0; i < ts; i++) {
        cout << "   ";
    }
    cout << " " << 1;
    ts++;

    for(int i = 2; i < d + 1; i++) {
        if(ts % 7 == 0) {
            cout << "\n";
        }else {
            cout << " ";
        }
        if(i < 10) {
            cout << " ";
        }
        cout << i;
        ts++;
    }
}
