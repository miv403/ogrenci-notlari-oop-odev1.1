---
author: miv403, zia
date: 2024-10-26
---

# COM2009 OOP birinci ödev

2024-2025 güz nesne yönelimli programlama ödevi.

## ödev açıklaması

1. girdi.csv dosyasından veriler okunarak bir nesne sınıfı
oluşturulacaktır.

    1. Ad → `string[]`
    2. Öğr. No → `string[]`
    3. Ara Sınav → `float[]`
    4. 2\. sınav → `float[]`
    5. Ödev → `float[]`
    6. Final → `float[]`
    7. Devam Sayısı → `int[]`

    Dosyada bu alanlar yer almaktadır. Bu alanlar birbirinden virgül
    ile ayrılmaktadır ve türleri yukarıda verildiği gibidir. `girdi.csv`
    için [şu adresi](https://raw.githubusercontent.com/zyavuz610/data/refs/heads/master/ogrenci-not/öğrenci%20notları%20-%20isimli.csv) kullanabilirsiniz.

2. Oluşturulacak Sınıf ismi `Student` olmalıdır ve dosyadan değerleri
   okudukça ilgili alanların değerleri ilgili değişkenlere
   yazılmalıdır.
3. Tasarlanacak sınıf içerisinde `constructor`, `destructor`,
   `readFromCSV()`, `average()`, `print()` metodları olmaldır.

    1. *constructor* → değişkenlere ilk değer verme ve dinamik dizi
    oluşturmak için
    2. *destructor* → dinamik dizileri silmek için
    3. `readFromCSV()` → değerleri dosyadan okuyup değişkenlere
    yüklemek için
    4. `average()` → arasınav (%20), 2.sınav (%20), ödev(%20), final
    (%40) olacak şekilde ortalama bulmalıdır.
    5. `print()` → öğrenci listesini ekrana formatlı olarak çıktı
    verilmelidir. Bu metod parametresiz olduğunda tüm listeyi, 0
    değerini argüman olarak gönderdiğimizde kalan öğrenci listesini, 1
    değerini argüman olarak gönderdiğimizde ise geçenleri
    listelemelidir. 50 değeri geçmek için eşik değeri alınmalıdır.
    6. `print()` methoduna string bir değer arguman olarak
    geçildiğinde bu  değeri dosya ismi olarak kabul edip sonuçlar
    dosyaya yazılmalıdır.

4. Bunların dışında yardımcı metodlar da tanımlayabilirsiniz.
