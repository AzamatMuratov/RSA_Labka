#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;

long int p, q, n, t, temp[100], j;

long int decryptedText[100], encryptedText[100], i, len;

bool flag;

string msg;

void encrypt(long int);
void decrypt(long int);
long int gcalculated(long int a, long int b);
bool isPrime(long int);
long int calculatE();
long calculateD(long int);


void encrypt(long int e)
{
    long int pt, ct, key = e, k;
    i = 0;
    len = msg.length();
    while (i != len){
        pt = decryptedText[i];
        pt = pt - 97;
        k = 1;
        for (j = 0; j < key; ++j) {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 97;
        encryptedText[i] = ct;
        i++;
    }
    encryptedText[i] = -1;
    cout << "\n encryp message\n";
    for (i = 0; i < len; ++i) {
        printf("%c", encryptedText[i]);
    }
}
void decrypt(long int d)
{
    long int pt, ct, key = d, k;
    i = 0;
    while (encryptedText[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; ++j) {
            k = k * ct;
            k = k % n;
        }
        pt = k +97;
        decryptedText[i] = pt;
        i++;
    }
    decryptedText[i] = -1;
    cout << "\ndecryp message\n";
    for (i = 0; i < len; ++i) {
        printf("%c", decryptedText[i]);
    }
    printf("\n");
}
long int gcalculated(long int a, long int b)
{
    if (b == 0)
    {
        return a;
    }
    else
        return gcalculated(b, a % b);
}
bool isPrime(long int pr){
    int i;
    j = (long int)sqrt((long double)pr);
    for (i = 2; i <= j; ++i)
    {
        if(pr % i == 0)
            return false;
    }
    return true;
}
long int calculateD(long int x)
{
    long int k =1;
    while(1){
        k = k +t;
        if(k % x ==0)
            return (k / x);
    }
}
long int calculatE()
{
    for (i = 2; i < t; ++i) {
        if (gcalculated(i,t) == 1)
            return i;
    }
    return -1;
}


int main() {

    do {
        cout << "enter p:" << endl;
        cin >> p;
        flag = isPrime(p);

        if (!flag) {
            cout << "\nnepravil vvod\n";
        }
    } while (flag == 0);
    do {
        cout << "enter q:" << endl;
        cin >> q;
        flag = isPrime(q);

        if(!flag)
        {
            cout << "\nnepr vvod\n";
        }
    }
    while(flag == 0);
    cout << "enter message to be encrypted:\n";
    fflush(stdin);

    getline(cin, msg);
    for (i = 0; msg[i] != NULL; i++)
        decryptedText[i] = msg[i];
    cout << i;

    n = p*q;
    t = (p-1) * (q-1);
    long int e = calculatE();
    long int d = calculateD(e);

    encrypt(e);
    decrypt(d);

    system("PAUSE");

    return 0;
}


