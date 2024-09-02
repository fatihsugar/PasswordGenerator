﻿#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cctype>

// Kullanıcıdan evet/hayır yanıtını alacak fonksiyon
bool getYesOrNo(const std::string& prompt) {
    std::string response;
    while (true) {
        std::cout << prompt << " (Y/N): ";
        std::cin >> response;

        // Küçük harfe çevir
        for (auto& c : response) c = std::tolower(c);

        if (response == "y" || response == "yes") {
            return true;
        }
        else if (response == "n" || response == "no") {
            return false;
        }
        else {
            std::cout << "Lutfen 'Y' veya 'N' olarak cevap verin.\n";
        }
    }
}

// Parola oluşturma fonksiyonu
std::string GeneratePassword(int length, bool includeUppercase, bool includeLowercase, bool includeDigits, bool includeSymbols) {
    // Karakter setlerini tanımla
    const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string digitChars = "0123456789";
    const std::string symbolChars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    std::vector<std::string> selectedSets;
    if (includeUppercase) selectedSets.push_back(uppercaseChars);
    if (includeLowercase) selectedSets.push_back(lowercaseChars);
    if (includeDigits) selectedSets.push_back(digitChars);
    if (includeSymbols) selectedSets.push_back(symbolChars);

    if (selectedSets.empty()) {
        return "Hata: En az bir karakter seti seçmelisiniz!";
    }

    if (length < selectedSets.size()) {
        return "Hata: Parola uzunluğu, seçilen karakter türlerinin sayısından küçük olamaz!";
    }

    // Rastgele sayı üretimi için C++ random kütüphanesini kullan
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<> dist(0, 0); // Başlangıçta geçerli değil

    std::string password;
    // İlk olarak, her karakter setinden en az bir karakter ekleyelim
    for (const auto& set : selectedSets) {
        std::uniform_int_distribution<> distSet(0, set.size() - 1);
        password += set[distSet(generator)];
    }

    // Kalan karakterleri rastgele seçilen tüm karakter setlerinden ekleyelim
    std::string allChars;
    for (const auto& set : selectedSets) {
        allChars += set;
    }

    std::uniform_int_distribution<> distAll(0, allChars.size() - 1);
    for (int i = password.size(); i < length; ++i) {
        password += allChars[distAll(generator)];
    }

    // Şifreyi karıştıralım
    std::shuffle(password.begin(), password.end(), generator);

    return password;
}

int main() {
    // Kullanıcıdan giriş almak için
    int length;
    bool includeUppercase, includeLowercase, includeDigits, includeSymbols;

    std::cout << "Parola olusturucuya hosgeldiniz!\n";

    // Parola uzunluğunu al
    while (true) {
        std::cout << "Olusturmak istediginiz parolanin uzunlugunu girin (minimum 4): ";
        std::cin >> length;

        if (std::cin.fail() || length < 4) {
            std::cin.clear(); // Hatalı giriş temizle
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Girişi temizle
            std::cout << "Gecersiz uzunluk. Lutfen 4 veya daha buyuk bir sayi girin.\n";
        }
        else {
            break;
        }
    }

    // Kullanıcı seçimlerini al
    includeUppercase = getYesOrNo("Buyuk harf kullanilsin mi");
    includeLowercase = getYesOrNo("Kucuk harf kullanilsin mi");
    includeDigits = getYesOrNo("Rakam kullanilsin mi");
    includeSymbols = getYesOrNo("Sembol kullanilsin mi");

    // Parola oluştur
    std::string password = GeneratePassword(length, includeUppercase, includeLowercase, includeDigits, includeSymbols);

    // Hata kontrolü
    if (password.find("Hata") == 0) {
        std::cout << password << std::endl;
    }
    else {
        std::cout << "Olusturulan parola: " << password << std::endl;
    }

    return 0;
}
