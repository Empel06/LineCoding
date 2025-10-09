# Bipolar Pseudoternary Line Coding  
## Explanation, Operation, and Visualization  

**Author:** Emiel Mangelschots & Quinten Crets  
**Course:** Digital Communication / Embedded Systems  
**Academic Year:** 2025–2026  

---

## Overview  

**Bipolar Pseudoternary** is a line coding scheme where logical `0` bits alternate between positive and negative voltage levels, while logical `1` bits are transmitted as zero voltage.  
It is a mirror image of the AMI (Alternate Mark Inversion) code, where `1`s are alternating and `0`s are zeros.  

This approach helps eliminate DC components and improves synchronization.

---

## Principle of Operation  

| Bit Value | Signal Level | Description |
|------------|---------------|--------------|
| `1` | 0 V | No pulse transmitted |
| `0` | Alternating +V / -V | Each consecutive `0` changes polarity |

The alternating polarity of zeros ensures that the signal has **no DC bias** and allows easy detection of transmission errors (since two same-polarity zeros in a row indicate an error).

---

## Example Bit Sequence  

```
Data bits:  1 0 0 1 1 0 0 0
```

| Bit | Action | Output Signal |
|-----|---------|----------------|
| 1 | No pulse | 0 V |
| 0 | Positive pulse | +V |
| 0 | Negative pulse | -V |
| 1 | No pulse | 0 V |
| 1 | No pulse | 0 V |
| 0 | Positive pulse | +V |
| 0 | Negative pulse | -V |
| 0 | Positive pulse | +V |

---

## Conceptual Waveform

```
Data:       1   0   0   1   1   0   0   0
Signal:  --- +V --- -V --- 0 --- +V --- -V --- +V ---
```

---

## Advantages and Disadvantages

| Advantages | Disadvantages |
|-------------|----------------|
| No DC component | More complex encoding logic |
| Simple error detection | Requires alternating tracking logic |
| Good synchronization | Slightly reduced bandwidth efficiency |

---

## Comparison with AMI

| Feature | AMI (Alternate Mark Inversion) | Bipolar Pseudoternary |
|----------|--------------------------------|------------------------|
| Active Bit | 1 | 0 |
| Zero Level | 0 V | 0 V for logical 1 |
| DC Component | None | None |
| Error Detection | Yes (double polarity error) | Yes (same principle) |

---

## Python Visualization Example

```python
import matplotlib.pyplot as plt
import numpy as np

data = [1, 0, 0, 1, 1, 0, 0, 0]
signal = []
last_polarity = 1

for bit in data:
    if bit == 0:
        last_polarity *= -1
        signal.append(last_polarity)
    else:
        signal.append(0)

t = np.arange(0, len(signal))
plt.step(t, signal, where='post')
plt.ylim(-1.5, 1.5)
plt.title("Bipolar Pseudoternary Line Coding")
plt.xlabel("Bit Period")
plt.ylabel("Signal Level (V)")
plt.grid(True)
plt.show()
```

---

## Applications  

- Digital telephony systems (T-carrier)  
- Baseband transmission links  
- Communication systems requiring DC balance  

---

## Conclusion  

Bipolar Pseudoternary provides excellent DC balance, simple error detection, and reliable synchronization.  
Although slightly more complex to implement, it’s highly efficient for channels where maintaining zero DC offset and minimizing interference are critical.
