# Accelerating Matrix Multiplication on FPGA using Intel OneAPI

This project aims to analyse how **Pipelining** affects the performance of matrix-multiplier architectures—similar to those found in TPUs—within the **Intel OneAPI** ecosystem.

## Research Objectives

The primary objective of this research is to conduct an analysis of the hardware implementation and operational mechanics of TPU-inspired matrix-multiplier architectures within the Intel OneAPI environment. 

The project focuses on:
* **Pipelining Analysis:** Demonstrating how the progressive application of pipelining techniques to standard matrix multiplication logic resolves data processing bottlenecks.
* **Comparative Experiments:** Evaluating how varying the depth of pipelining stages within the matrix-multiplier impacts FPGA performance, specifically measuring the trade-offs between increased throughput and the utilisation of hardware resources such as DSPs and BRAM.
* **Resource & Performance Trade-offs:** Evaluating how changes in pipelining depth influence FPGA **resource** utilisation (DSPs and BRAM) and overall execution **latency**.
* **Accelerator Architecture Analysis:** Developing understanding of TPU architectures, specifically examining how hardware-level dataflows, such as Systolic Multicast, can be effectively mapped onto FPGA to minimise memory bottlenecks.

## Key Research Questions
1. How does the implementation of pipelining in OneAPI translate into physical FPGA hardware structures?
2. What is the optimal balance between increased throughput (via pipelining) and the consumption of on-chip resources like DSPs and BRAM?
3. To what extent can high-level code(C++) abstractions in OneAPI effectively eliminate computational bottlenecks in matrix-heavy workloads?

## Technology Stack
* **Framework:** Intel OneAPI Toolkit
* **Language:** Data-Parallel C++ (DPC++)
* **Target Hardware:** Intel/Altera FPGA
