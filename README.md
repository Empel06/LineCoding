# Line Coding on the PSoC6  
## Comparative Study and Implementation  
**By:** Emiel Mangelschots & Quinten Crets  
**Course/Project:** Digital Communication / Embedded Systems  
**Academic Year:** 2025–2026  

---

## Overview  

In this project, we research and implement two line coding methods on the PSoC6 microcontroller.  
Each group was assigned one fixed coding scheme and chose a second one for comparison.  

We evaluate the performance of both coding methods under different conditions (noise, interference, bitrate) using objective criteria such as noise immunity, bandwidth efficiency, synchronization, error detection, and real-time performance.

Additionally, we design a testbench that allows these properties to be measured in a standardized and reproducible way.

---

## Implementation

### Line Coding Methods
- **Coding 1:** (NRZ-I)  
- **Coding 2:** (Bipolar Pseudoternary)  

Each coding scheme was implemented in firmware on the PSoC6. Data is received in real time via an SPI master and processed by the PSoC6, which applies and decodes the line coding.

### Hardware & Software
- **Platform:** PSoC6 (MCU + FPGA-like functionality via IO-matrix)  
- **Communication:** SPI (Slave configuration)  
- **Analysis Tools:** Oscilloscope / Logic Analyzer  
- **Data Analysis:** Python / MATLAB  
- **Development Environment:** ModusToolbox  

---

## Testbench

Our testbench is designed to evaluate the following parameters:

| Parameter | Description | Measurement Method |
|------------|--------------|--------------------|
| Noise Immunity | How robust is the coding scheme against noise and interference? | Adding simulated noise via the testbench |
| Bandwidth Efficiency | How much data can be transmitted per Hz of bandwidth? | Comparison of effective bitrate |
| Synchronization | How easily can the system synchronize? | Clock recovery and sync-bit analysis |
| Error Detection | Can the coding detect transmission errors? | Bit error analysis with fault injection |
| Real-time Performance | How fast is the data processed? | Latency = Propagation + Transmission + Queueing + Processing |

---

## Real-time Processing

The PSoC6 utilizes:
- DMA for direct data transfer between the SPI interface and the line coding module  
- LUTs (Look-Up Tables) and hardware comparators for fast signal processing  
- Internal OpAmps for analog signal conditioning if required  
- Dual-core architecture (M4 + M0+) to separate processing and logging tasks  

This setup minimizes latency and enhances deterministic real-time performance.

---

## Evaluation Criteria

| Criterion | Description |
|------------|--------------|
| Implementation Correctness | Does the implementation match the theoretical coding scheme? |
| Testbench Completeness | Were all relevant parameters tested? |
| Result Quality | Are the results clearly presented and consistent? |
| Depth of Analysis | Are the differences between the coding methods well explained? |
| Presentation | Is the presentation clear, persuasive, and visually supported? |

---

## Visualization & Analysis

We use:
- An oscilloscope or logic analyzer to visualize the waveforms of both line codes  
- Python (NumPy, Matplotlib, Pandas) or MATLAB for data processing, plotting, and frequency-domain analysis  

Examples of possible visualizations include:
- Time- and frequency-domain comparisons  
- Bit error graphs  
- Latency histograms  

---

## Objectives

We aim to:
1. Experimentally confirm the theoretical properties of both coding schemes  
2. Identify the coding method with the best combination of robustness, efficiency, and real-time behavior  
3. Present our findings clearly and convincingly during the in-class competition  

---

## Submission

Submission is done via Google Classroom.  
The submitted package includes:
- Source code of both implementations  
- Testbench code and documentation  
- Analysis files (MATLAB/Python)  
- Presentation (PDF or PowerPoint)  
- This README file  

---

## Authors

**Emiel Mangelschots**  
**Quinten Crets**
