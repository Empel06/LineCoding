# NRZ-I Line Coding  
## Explanation, Operation, and Visualization  

**Author:** Emiel Mangelschots & Quinten Crets  
**Course:** Digital Communication / Embedded Systems  
**Academic Year:** 2025–2026  

---

## Overview  

**NRZ-I (Non-Return-to-Zero Inverted)** is a line coding method used in digital communication to represent binary data as electrical signals.  
The signal changes (inverts) only when a logical `1` is transmitted, while a logical `0` leaves the signal unchanged.  
This improves synchronization compared to NRZ-L.

---

## Principle of Operation  

| Bit Value | Action on Signal | Explanation |
|------------|------------------|--------------|
| `0` | No change | The signal level stays the same. |
| `1` | Invert (toggle) the signal level | The signal switches polarity. |

---

## Example Bit Sequence  

```
Data bits:  1 0 0 1 1 0 1 0
```

| Bit | Action | Output Signal |
|-----|---------|----------------|
| 1 | Invert | High |
| 0 | No change | High |
| 0 | No change | High |
| 1 | Invert | Low |
| 1 | Invert | High |
| 0 | No change | High |
| 1 | Invert | Low |
| 0 | No change | Low |

---

## Conceptual Waveform

```
Data:       1   0   0   1   1   0   1   0
Signal:  ___     __________________      _______
          |_____|                  |____|
```

---

## Advantages and Disadvantages

| Advantages | Disadvantages |
|-------------|----------------|
| Improved synchronization | Long runs of 0s cause sync loss |
| Reduced DC bias | Requires initial state knowledge |
| Efficient bandwidth usage | No inherent error detection |

---

## Python Visualization Example

```python
import matplotlib.pyplot as plt
import numpy as np

data = [1, 0, 0, 1, 1, 0, 1, 0]
signal = []
level = 1  # initial level

for bit in data:
    if bit == 1:
        level *= -1
    signal.append(level)

t = np.arange(0, len(signal))
plt.step(t, signal, where='post')
plt.ylim(-1.5, 1.5)
plt.title("NRZ-I Line Coding")
plt.xlabel("Bit Period")
plt.ylabel("Signal Level")
plt.grid(True)
plt.show()
```

---

## Applications  

- USB (NRZI variant)  
- Magnetic/optical storage  
- Serial communication (SDLC, HDLC)

---

## Conclusion  

NRZ-I enhances synchronization and reduces DC bias compared to NRZ-L but struggles with long sequences of zeros.  
It serves as a useful baseline when comparing with more self-clocking codes like Manchester or Bipolar schemes.
