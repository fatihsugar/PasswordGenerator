# Şifre Oluşturma Programı

Bu proje, kullanıcıların güçlü ve güvenli parolalar oluşturmasına yardımcı olan bir C++ programıdır. ESET parola oluşturucudan örnek alınarak yapılmıştır ve onun gibi çalışarak, kullanıcının seçtiği karakter setlerine ve parola uzunluğuna göre rastgele parolalar üretir.

## Özellikler
- Büyük Harfler: Parolada büyük harf kullanma seçeneği.
- Küçük Harfler: Parolada küçük harf kullanma seçeneği.
- Rakamlar: Parolada rakam kullanma seçeneği.
- Semboller: Parolada özel semboller kullanma seçeneği.
- Güçlü Rastgelelik: std::random_device ve std::mt19937 kullanarak güvenli rastgele sayı üretimi.
- Kullanıcı Dostu Arayüz: Basit ve anlaşılır komut satırı arayüzü ile kullanıcı girdileri kolayca alınabilir.


## Kurulum

1. Bu projeyi yerel makinenize klonlayın:

    ```sh
    git clone https://github.com/fatihsugar/PasswordGenerator.git
    ```

2. Proje dizinine gidin:

    ```sh
    cd PasswordGenerator
    ```

## Visual Studio ile Derleme ve Çalıştırma

1. **Visual Studio'da Projeyi Açın:**
   - Visual Studio'yu başlatın.
   - `File > Open > Project/Solution` menüsünden projenizin `.sln` dosyasını açın.

2. **Projeyi Derleyin:**
   - `Build > Build Solution` menüsüne tıklayarak projeyi derleyin veya `Ctrl + Shift + B` kısayolunu kullanın.

3. **Projeyi Çalıştırın:**
   - `Debug > Start without Debugging` menüsüne tıklayarak projeyi çalıştırın veya `Ctrl + F5` kısayolunu kullanın.

## Kullanım

Program çalıştığında, sırasıyla şu sorularla karşılaşacaksınız:

1. Parola Uzunluğu: Oluşturmak istediğiniz parolanın uzunluğunu girin.
2. Büyük Harf Kullanımı: Parolada büyük harf kullanmak isteyip istemediğinizi belirtin.
3. Küçük Harf Kullanımı: Parolada küçük harf kullanmak isteyip istemediğinizi belirtin.
4. Rakam Kullanımı: Parolada rakam kullanmak isteyip istemediğinizi belirtin.
5. Sembol Kullanımı: Parolada sembol kullanmak isteyip istemediğinizi belirtin.

Program bu bilgilere dayanarak rastgele bir parola oluşturur ve ekranda gösterir.

## Örnek Kullanım

```sh
Parola olusturucuya hosgeldiniz!
Oluşturmak istediğiniz parolanın uzunlugunu girin (minimum 4): 12
Buyuk harf kullanilsin mi (Y/N): Y
Kuçuk harf kullanilsin mi (Y/N): Y
Rakam kullanilsin mi (Y/N): Y
Sembol kullanilsin mi (Y/N): Y
Oluşturulan parola: A3d@fG7!kLpQ
```

## Gereksinimler
- Visual Studio 2019 veya daha yeni bir sürümü
- C++ destekleyen her hangi bir derleyici program,

## Katkıda Bulunma
Bu projeye katkıda bulunmak isterseniz, lütfen bir pull request açın veya bir issue oluşturun. Her türlü katkı ve geri bildirim değerlidir!

## Lisans
Bu proje MIT lisansı altında lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasını inceleyebilirsiniz.

