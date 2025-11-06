#include <SPI.h>

#define SPI_MOSI 19  // GP19
#define SPI_SCK  18  // GP18
#define SPI_CS   17  // GP17 (verbonden met P10_0 op PSoC6)

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Pico SPI Master gestart.");

  SPI.begin();   // Start SPI
  pinMode(SPI_CS, OUTPUT);
  digitalWrite(SPI_CS, HIGH);  // CS inactief

  Serial.println("Typ tekst om via SPI te verzenden:");
}

void loop() {
  // Wacht op invoer van de gebruiker via seriële monitor
  if (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\r' || c == '\n') return;

    digitalWrite(SPI_CS, LOW);  // SPI selecteren
    SPI.transfer(c);            // Verstuur 1 byte via SPI
    digitalWrite(SPI_CS, HIGH); // SPI deselecteren

    Serial.print("Verzonden via SPI: ");
    Serial.println(c);
  }
}