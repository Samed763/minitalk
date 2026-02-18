minitalk projen için, tıpkı Libft dökümantasyonunda olduğu gibi profesyonel ve teknik detayları içeren README.md taslağı aşağıdadır:

Minitalk - UNIX Sinyalleri ile Küçük Bir İletişim Programı
📝 Proje Hakkında
Bu proje, iki süreç (process) arasında UNIX sinyallerini kullanarak küçük bir veri değişim mekanizması tasarlamayı amaçlamaktadır. Proje kapsamında bir Server ve bir Client uygulaması geliştirilmiştir. İletişim, yalnızca SIGUSR1 ve SIGUSR2 sinyalleri kullanılarak bit seviyesinde gerçekleştirilir.

🛠️ Teknik Mekanizma
Sinyal Kullanımı: Veriler, her karakterin 8 bitine karşılık gelecek şekilde sinyallere dönüştürülür. SIGUSR1 genellikle '1' bitini, SIGUSR2 ise '0' bitini temsil eder.

Hassas İletişim: Client, gönderdiği her bitin Server tarafından alındığından emin olmak için bir geri bildirim (acknowledgment) bekler.

Süreç Yönetimi: Server başlatıldığında kendi PID (Process ID) numarasını ekrana yazdırır ve Client bu PID'yi kullanarak hedef sürece sinyal gönderir.

🚀 Kullanım
Derleme
Tüm dosyaları derlemek ve çalıştırılabilir dosyaları oluşturmak için şu komutları kullanabilirsiniz:

Bash

# Zorunlu bölümü derlemek için:
make

# Bonus özelliklerle derlemek için:
make bonus
Çalıştırma
Önce Server'ı başlatın:

Bash

./server
Ekranda Server PID: 12345 gibi bir çıktı göreceksiniz.

Başka bir terminal sekmesinde Client'ı kullanarak mesaj gönderin:

Bash

./client <SERVER_PID> "Merhaba Dünya!"
📂 Dosya Yapısı
server.c: Sinyalleri karşılayan, bitleri birleştirip karaktere dönüştüren ve ekrana yazdıran ana sunucu kodu.

client.c: Verilen stringi bitlerine ayırıp hedef PID'ye gönderen istemci kodu.

utils.c: PID yazdırma ve string işlemleri için kullanılan yardımcı fonksiyonlar (ft_putstr, ft_putnbr vb.).

server_bonus.c & client_bonus.c: İletişimin onaylandığına dair geri bildirim mekanizmasını içeren geliştirilmiş versiyonlar.

📌 Özellikler
Tek seferde binlerce karakteri hızla aktarabilir.

sigaction yapısı kullanılarak sinyal çakışmaları ve veri kayıpları önlenmiştir.

Hata yönetimi: Geçersiz PID veya eksik argüman durumunda kullanıcıyı bilgilendirir.