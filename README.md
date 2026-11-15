# Job Buddy - Job Application Tracker

<!-- Badges & Shields -->
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://en.cppreference.com/w/cpp/20)
[![Qt 6.8+](https://img.shields.io/badge/Qt-6.8%2B-007ACC.svg?logo=qt)](https://www.qt.io/)
[![CMake](https://img.shields.io/badge/CMake-3.20%2B-064F8C.svg?logo=cmake)](https://cmake.org/)
[![Build Status](https://github.com/riciadavinci/REPO/actions/workflows/ci.yaml/badge.svg)](https://github.com/riciadavinci/REPO/actions)
[![codecov](https://codecov.io/gh/riciadavinci//graph/badge.svg?token=NONE)](https://codecov.io/gh/riciadavinci/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)


## 1. Overview

<br>

<p align="right"><sub>[&nbsp;<a href="#job-buddy---job-application-tracker">Back to Top</a> &nbsp;•&nbsp; <a href="#table-of-contents">Table of Contents</a>&nbsp;]</sub></p>

## 2. Gallery

<table>
  <tr>
    <td align="center">
      <img src="docs/img/LiveTelemetryView.PNG" alt="" width="400"/>
      <br/>
      <sub><b>Figure 1:</b> </sub>
    </td>
    <td align="center">
      <img src="docs/img/SensorNodesList.PNG" alt="" width="400"/>
      <br/>
      <sub><b>Figure 2:</b> </sub>
    </td>
  </tr>
</table>

<br>

<p align="right"><sub>[&nbsp;<a href="#job-buddy---job-application-tracker">Back to Top</a> &nbsp;•&nbsp; <a href="#table-of-contents">Table of Contents</a>&nbsp;]</sub></p>

## Table of Contents
| # | Section |
|---|---|
| **1.** | [Overview](#1-overview) |
| **2.** | [Gallery](#gallery) |
| **3.** | [Project Directory Structure](#3-project-directory-structure) |
| **4.** | [Tech-Stack](#4-tech-stack) |
| **5.** | [System Architecture & Design Patterns](#5-system-architecture--design-patterns) |
|  | **5.1** &emsp;[Overview](#51-overview) |
|  | **5.2** &emsp;[Component: Dashboard - _EnvDash_](#52-component-dashboard---envdash) |
|  | **5.3** &emsp;[Component: Firmware - _EnvFirm_](#53-component-firmware---envfirm) |
|  | **5.4** &emsp;[Component: Mock Hardware - _EnvMock_](#54-component-mock-hardware---envmock) |
| **6.** | [Project Scope](#6-project-scope) |
|  | **6.1** &emsp;[Component: Dashboard - _EnvDash_](#61-component-dashboard---envdash) |
|  | **6.2** &emsp;[Component: Firmware - _EnvFirm_](#62-component-firmware---envfirm) |
|  | **6.3** &emsp;[Component: Mock Hardware - _EnvMock_](#63-component-mock-hardware---envmock) |

<br>

<p align="right"><sub>[&nbsp;<a href="#job-buddy---job-application-tracker">Back to Top</a> &nbsp;•&nbsp; <a href="#table-of-contents">Table of Contents</a>&nbsp;]</sub></p>

## 3. Project Directory Structure
```text
project-name/
├── .github/
│   └── workflows/                  # GitHub Actions workflow
│       └── ci.yaml
├── src/                            # Source Files
│   ├── main.cpp
│   ├── CMakeLists.txt
│   ├── core/
│   ├── job_application/
│   └── ui/
├── tests/                          # Tests
│   ├── main_tests.cpp
│   └── CMakeLists.txt
└── codecov.yml                     # Codecov.io settings
```

<br>

<p align="right"><sub>[&nbsp;<a href="#job-buddy---job-application-tracker">Back to Top</a> &nbsp;•&nbsp; <a href="#table-of-contents">Table of Contents</a>&nbsp;]</sub></p>


## 4. Tech-Stack

### Overview/Shared
- Programming Language: C++ (C++20 standard), C++ Standard Library
- Testing & Code Coverage: Google Test, Google Mock, GCov, Codecov
- Linting & Sanitizers: Clang-Tidy, ASan, UBSan, TSan
- Build Tools: CMake 3.30.5, Ninja 1.31.1
- My custom deps/libs: 
    - sequelite-cpp &emsp;([GitHub🔗](https://github.com/riciadavinci/sequelite-cpp))

### Development Setup
- OS Tested on: Windows 10 & Ubuntu 26.04
- Compilers Tested on: 
    - Windows: MSVC 2022 (v19.41.34123 x64)

### Build Setup
- OS Tested on: GitHub Actions windows-latest & ubuntu-24.04
- Compilers Tested on:
    - Windows: MSVC 2022
    - Linux: GCC & Clang


<br>

<p align="right"><sub>[&nbsp;<a href="#job-buddy---job-application-tracker">Back to Top</a> &nbsp;•&nbsp; <a href="#table-of-contents">Table of Contents</a>&nbsp;]</sub></p>

## 5. System Architecture & Design Patterns

### 5.1 Overview

<!-- #### Architecture -->

<div align="center">
<img src="docs/img/top-level-system-architecture.svg" alt="Qt6 Dashboard GUI" height="350"/>
      <br/>
<sub><b>Figure:</b> Top-level System Architecture</sub>
</div>

### 5.2 Component: Dashboard - _EnvDash_

<div align="center">
<img src="docs/img/component-a-dashboard-system-architecture.svg" alt="Qt6 Dashboard GUI" height="450"/>
      <br/>
<sub><b>Figure:</b> Component A - Dashboard (<i>EnvDash</i>) System Architecture</sub>
</div>

### 5.3 Component: Firmware - _EnvFirm_

<div align="center">
<img src="docs/img/component-b-firmware-system-architecture.svg" alt="Qt6 Dashboard GUI" height="350"/>
      <br/>
<sub><b>Figure:</b> Component B - Firmware (<i>EnvFirm</i>) System Architecture</sub>
</div>

### 5.4 Component: Mock Hardware - _EnvMock_

<div align="center">
<img src="docs/img/component-c-mock-hardware-system-architecture.svg" alt="Qt6 Dashboard GUI" height="350"/>
      <br/>
<sub><b>Figure:</b> Component C - Mock Hardware (<i>EnvMock</i>) System Architecture</sub>
</div>

<br>

<p align="right"><sub>[&nbsp;<a href="#job-buddy---job-application-tracker">Back to Top</a> &nbsp;•&nbsp; <a href="#table-of-contents">Table of Contents</a>&nbsp;]</sub></p>


## 6. Project Scope

The primary objective of **_EnvDash_** is to provide a real-time desktop interface for visualizing environmental sensor telemetry originating from hardware nodes (Pico 2 firmware) or simulated environments/mock hardware (Python).

#### In-Scope (v1.0 Deliverables)
- **Real-Time Telemetry Visualization:** Live rendering of temperature, humidity, and atmospheric metrics using Qt Quick / QML widgets and dynamic charts.
- **Multi-Transport Support:** Data ingestion over Serial (UART/USB) for physical hardware connections and IPC/Local Sockets for communication with the Python mock hardware simulator.
- **Hardware Status Monitoring:** UI indicators for connection state, packet loss, transmission frequency, and system threshold alerts.
- **Cross-Platform Target:** Build targets verified on both Windows (MSVC) and Linux (GCC & Clang) environments.
- **Multi-Threading & Async Programming:** Using QThreads for dedicated services (Telemetry Ingestion through QUdpSocket), local SQLite Telemetry logging, and Hardware Node Device Management. Using QtConcurrent for Asynchronous Database calls and I/O tasks to prevent freezing Main UI thread.
<!-- - **Configurable Dashboard Settings:** Controls enabling users to adjust sample rates, threshold triggers, and chart timeframes dynamically. -->

#### Out-of-Scope (v1.0 Non-Goals)
- **Cloud Storage & Remote Sync:** No direct backend cloud integration (AWS/Azure/GCP) or remote database persistence for v1.0; logging is handled locally.
- **Mobile / Web Platforms:** Exclusive focus on desktop environments (no iOS, Android, or WebAssembly targets).
- **User Authentication:** Single-user local desktop application without user login or permission roles.
- **Direct Firmware Flashing:** The application consumes telemetry streams only and does not perform OTA or direct firmware flashing to the microcontroller.

<br>

<p align="right"><sub>[&nbsp;<a href="#job-buddy---job-application-tracker">Back to Top</a> &nbsp;•&nbsp; <a href="#table-of-contents">Table of Contents</a>&nbsp;]</sub></p>
