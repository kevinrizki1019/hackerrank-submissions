#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    int flipFront = 0;
    int flipBack = 0;
    int i;

     
    i = 1;
    while (i < p) {
        i += 2;
        flipFront++;
    }

    if (n % 2 == 0) {  // Genap, maka page terakhir hanya ada satu angka saja yaitu n    
        i = n;
        while (i > p) {
            i -= 2;
            flipBack++;
        }
    } else {
        i = n-1;
        while (i > p) {
            i -= 2;
            flipBack++;
        }
    }

    if (flipFront < flipBack) {
        return (flipFront);
    } else {
        return (flipBack);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
