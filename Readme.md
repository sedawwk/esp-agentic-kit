# ESP Agentic Kit

ESP-IDF component wrapping the Tuya **agentic-kit** SDK for ESP32 devices.

## Overview

This component bundles the Tuya AI 2.1 (TAI 2.1) protocol stack as an ESP-IDF component, enabling ESP32-based devices to communicate with Tuya's AI services. It includes:

- **RTC TCP Client** — Tuya AI 2.1 real-time communication protocol
- **IoT Client** — Device onboarding, MQTT messaging, and HTTP client
- **Tuya BLE** — Bluetooth provisioning support
- **PAL** — FreeRTOS + lwIP platform abstraction layer

## Dependencies

- ESP-IDF (uses `mbedtls`, `freertos`, `lwip`, `esp_netif`, etc.)
- Git submodules — run `git submodule update --init` after cloning

## Submodule

| Path | URL |
|---|---|
| `agentic-kit` | `git@github.com:tuya/agentic-kit.git` |

## Example

See `examples/rtc-tcp-client/` for a working example.

## License

See the upstream [agentic-kit](https://github.com/tuya/agentic-kit) repository for license details.