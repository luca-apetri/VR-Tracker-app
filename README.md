# VR-Tracker-app

An out-of-tree Zephyr RTOS application designed for a custom VR Tracker targeting the **nRF52840 DK**.

## Structure
* `app/`: Main firmware workspace (C code, configurations).
* `.github/workflows/`: Automated cloud compilation workflows.

## How to Build
Using the nRF Connect Toolchain and extension, select `nrf52840dk/nrf52840` as your board target and run a Pristine Build.