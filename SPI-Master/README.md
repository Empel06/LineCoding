# SPI-Master

## About this folder

This folder contains the code for an **SPI Master** that can send data to a **PSoC6**. The code is written for a **Raspberry Pi Pico** and is located in the file:

```
RP_TC.cpp
```

## Functionality

* The Pico acts as the **SPI Master**.
* The program reads characters you type in the serial monitor and sends them via SPI to a connected PSoC6.
* Chip Select (CS) is automatically controlled to start and stop communication.

## Hardware setup

* **Raspberry Pi Pico SPI pins**:

  * MOSI → GP19
  * SCK  → GP18
  * CS   → GP17 (connected to PSoC6 P10_0)
* **PSoC6**:

  * Ensure it is set to **SPI Slave mode**.
  * Connect MOSI, SCK, CS correctly to the Pico.
  * GND must be connected between both boards.

## Software usage

1. Open `RP_TC.cpp` in the Arduino IDE or a compatible editor for the Raspberry Pi Pico.
2. Upload the code to the Pico.
3. Open the serial monitor at **115200 baud**.
4. Type a character in the serial monitor.
5. The Pico will send the character via SPI to the PSoC6 and also print it back in the serial monitor.

## Example output

```
Pico SPI Master started.
Type text to send via SPI:
Sent via SPI: 1
Sent via SPI: 0
```