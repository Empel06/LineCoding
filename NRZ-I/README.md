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
