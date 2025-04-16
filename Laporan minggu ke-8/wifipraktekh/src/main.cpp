#include <WiFi.h>

// Ganti dengan SSID dan password jaringan Wi-Fi yang ingin digunakan
const char* ssid = "Kontrakan Gay";        // Ganti dengan SSID jaringan yang ingin Anda hubungkan
const char* password = "11223344"; // Ganti dengan password jaringan Wi-Fi

// Sinyal yang dianggap cukup kuat
const int minSignalStrength = -60;  

void setup() {
  Serial.begin(115200);  // Mulai komunikasi serial

  WiFi.mode(WIFI_STA);    // Set mode WiFi ESP32 sebagai Station
  WiFi.disconnect();      // Putuskan koneksi Wi-Fi sebelumnya
  delay(100);

  Serial.println("Pemindaian Jaringan Wi-Fi Dimulai...");
}

void loop() {
  int n = WiFi.scanNetworks(); // Pemindaian jaringan Wi-Fi di sekitar
  Serial.println("Pemindaian Selesai");

  if (n == 0) {
    Serial.println("Tidak ada jaringan Wi-Fi yang ditemukan.");
  } else {
    Serial.print(n);
    Serial.println(" jaringan Wi-Fi ditemukan:");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));  // Menampilkan SSID
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));  // Menampilkan kekuatan sinyal (RSSI)
      Serial.print("dBm)");

      // Menampilkan status kualitas sinyal
      if (WiFi.RSSI(i) > minSignalStrength) {
        Serial.print(" - Koneksi Sinyal Cukup Baik");
      } else {
        Serial.print(" - Sinyal Lemah");
      }
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");

      // Menyambung ke jaringan jika SSID dan sinyal cukup baik
      if (WiFi.SSID(i) == ssid && WiFi.RSSI(i) > minSignalStrength) {
        Serial.println("Menyambung ke Wi-Fi...");
        WiFi.begin(ssid, password);  // Mencoba menyambungkan ke Wi-Fi

        // Tunggu sampai terhubung
        while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
        }
        Serial.println("Terhubung ke Wi-Fi!");
        break; // Keluar dari loop setelah terhubung
      }
    }
  }
  
  Serial.println("");
  delay(5000); // Lakukan pemindaian setiap 5 detik
}
