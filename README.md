# ESP32-Real-Time-Voice-to-Text-Processor


## Overview

The **ESP32 Real-Time Voice-to-Text Processor** is a sophisticated speech-to-text solution utilizing the ESP32 microcontroller. This project enables real-time audio processing, converting spoken language into text and integrating with the Deepgram API for high-quality transcription. It features audio recording, playback, and live transcription capabilities, making it ideal for voice-driven applications.

## Features

- **Real-Time Speech-to-Text Conversion**: Converts spoken language into text in real time.
- **Audio Recording and Playback**: Records audio through an I2S amplifier and plays it back.
- **Deepgram Integration**: Leverages Deepgram’s Speech-to-Text API for accurate transcription.
- **WiFi Connectivity**: Connects to WiFi for API requests and data transmission.
- **SD Card Support**: Stores recorded audio files on an SD card.

## Hardware Requirements

- **ESP32 Development Board**
- **I2S Amplifier (e.g., MAX98357)**
- **Microphone Module**
- **SD Card Module**
- **Push Button**
- **LED**

## Software Requirements

- **Arduino IDE** with ESP32 support
- **Deepgram API Key** (Sign up for an API key at [Deepgram](https://deepgram.com))

## Installation

1. **Setup Arduino IDE:**
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Add ESP32 board support to the Arduino IDE. Follow the instructions [here](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).

2. **Install Required Libraries:**
   - Go to `Sketch` > `Include Library` > `Manage Libraries`.
   - Search for and install the following libraries:
     - `WiFi`
     - `SD`
     - `Audio`

3. **Clone the Repository:**

   ```bash
   git clone https://github.com/Futuredhruv/ESP32-Real-Time-Voice-to-Text-Processor.git
