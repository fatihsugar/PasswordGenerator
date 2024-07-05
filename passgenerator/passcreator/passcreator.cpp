#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

string GeneratePassword(int length, char customSpecialChar, bool addRandomNumber, char customNumber) {
    const string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string specialChars = "!@#$%^&*()_+";
    const string digitChars = "0123456789";

    string password;

    if (length < 1) {
        return "Gecersiz uzunluk!";
    }

    // Zorunlu bir buyuk harf ekleyelim
    password += uppercaseChars[rand() % uppercaseChars.length()];

    // Ozetle karakteri kendiniz girmek ister misiniz?
    cout << "Ozel karakteri kendiniz girmek ister misiniz? (Yes/No veya Y/N olarak cevap verin): ";
    string customSpecialCharChoice;
    cin >> customSpecialCharChoice;

    if (customSpecialCharChoice == "Yes" || customSpecialCharChoice == "Y" || customSpecialCharChoice == "yes" || customSpecialCharChoice == "y") {
        cout << "Ozel karakteri girin: ";
        cin >> customSpecialChar;
    }
    else {
        const string allSpecialChars = specialChars;
        cout << "Ozel karakter rastgele olusturulsun mu? (Yes/No veya Y/N olarak cevap verin): ";
        string randomSpecialCharChoice;
        cin >> randomSpecialCharChoice;

        if (randomSpecialCharChoice == "Yes" || randomSpecialCharChoice == "Y" || randomSpecialCharChoice == "yes" || randomSpecialCharChoice == "y") {
            customSpecialChar = allSpecialChars[rand() % allSpecialChars.length()];
        }
        else {
            customSpecialChar = '\0'; // Ozel karakter eklenmeyecek
        }
    }

    // Ozetle sayi girmek ister misiniz?
    cout << "Ozel sayi girmek ister misiniz? (Yes/No veya Y/N olarak cevap verin): ";
    string customNumberChoice;
    cin >> customNumberChoice;

    if (customNumberChoice == "Yes" || customNumberChoice == "Y" || customNumberChoice == "yes" || customNumberChoice == "y") {
        cout << "Ozel sayiyi girin: ";
        cin >> customNumber;
    }
    else {
        const string allDigitChars = digitChars;
        cout << "Ozel sayi rastgele olusturulsun mu? (Yes/No veya Y/N olarak cevap verin): ";
        string randomNumberChoice;
        cin >> randomNumberChoice;

        if (randomNumberChoice == "Yes" || randomNumberChoice == "Y" || randomNumberChoice == "yes" || randomNumberChoice == "y") {
            customNumber = allDigitChars[rand() % allDigitChars.length()];
        }
        else {
            customNumber = '\0'; // Ozel sayi eklenmeyecek
        }
    }

    // Rastgele sayi eklemek ister misiniz?
    cout << "Rastgele sayi eklemek ister misiniz? (Yes/No veya Y/N olarak cevap verin): ";
    string addRandomNumberChoice;
    cin >> addRandomNumberChoice;

    if (addRandomNumberChoice == "Yes" || addRandomNumberChoice == "Y" || addRandomNumberChoice == "yes" || addRandomNumberChoice == "y") {
        password += digitChars[rand() % digitChars.length()];
    }

    // Ozetle karakteri ekleyelim
    if (customSpecialChar != '\0') {
        password += customSpecialChar;
    }

    // Ozel sayiyi ekleyelim
    if (customNumber != '\0') {
        password += customNumber;
    }

    // Geri kalan karakterleri rastgele secelim
    const string allChars = lowercaseChars + uppercaseChars;
    for (int i = password.length(); i < length; ++i) {
        password += allChars[rand() % allChars.length()];
    }

    // Sifreyi karistiralim
    for (int i = 0; i < length; ++i) {
        int swapIndex = rand() % length;
        swap(password[i], password[swapIndex]);
    }

    return password;
}

int main() {
    srand(time(0));

    int length;
    char customSpecialChar = '\0';
    char customNumber = '\0';

    cout << "Kac haneli bir parola olusturmak istersiniz: ";
    cin >> length;

    if (length < 1) {
        cout << "Gecersiz uzunluk!" << endl;
        return 1;
    }

    string password = GeneratePassword(length, customSpecialChar, true, customNumber); // Rastgele sayi eklemek icin true
    cout << "Olusturulan parola: " << password << endl;

    return 0;
}
