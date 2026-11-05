# Marlin Firmware for Creality Ender-3 V3 SE
[![CodeFactor](https://www.codefactor.io/repository/github/byrbyrka/ender-3-v3-se-custom/badge)](https://www.codefactor.io/repository/github/byrbyrka/ender-3-v3-se-custom)

Custom Marlin firmware build for the Creality Ender-3 V3 SE 3D printer.
## Acknowledgments
This project is based on the work by [navaismo/Ender-3V3-SE](https://github.com/navaismo/Ender-3V3-SE). 
Special thanks to the original author for providing the foundation for this firmware.
## Features
- Multi-language support (9 languages)
- Auto bed leveling with CR-Touch probe
- Filament runout detection
- Power loss recovery
- Thermal runaway protection
- Customizable PID settings
- Mesh bed leveling with 6x6 grid
- Babystepping support
- Linear advance compatible
## Supported Languages
- English
- Russian
- Spanish
- French
- German
- Italian
- Polish
- Portuguese
- Chinese
## Building
### Prerequisites
- PlatformIO (recommended)
- Python 3.x
- Git
### Build Instructions
```bash
# Clone the repository
git clone <repository-url>
cd <repository-directory>
# Install PlatformIO
pip install platformio
# Build firmware
pio run -e STM32F103RET6_creality
# Upload firmware
pio run -e STM32F103RET6_creality --target upload
```
### Alternative Build Methods
#### Using Make
```bash
make
```
#### Using Docker
```bash
docker-compose run --rm marlin pio run -e STM32F103RET6_creality
```
## Installation
1. Download the compiled firmware from the Releases section or build it yourself
2. Copy the `.bin` file to your SD card
3. Insert the SD card into your printer
4. Power on the printer - firmware will flash automatically
5. Wait for the process to complete (printer may restart)
## Configuration
Main configuration files are located in:
- `Marlin/Configuration.h` - Main settings
- `Marlin/Configuration_adv.h` - Advanced settings
### Key Settings
- Board: BOARD_CREALITY_V4
- Motherboard: Creality V4.2.7 / V4.3.1
- Extruders: 1
- Bed size: 235x235x250 mm
- Thermistors: Standard Creality configuration
## Troubleshooting
### Common Issues
1. **Printer not booting after flash**
   - Verify you have the correct board version
   - Try flashing the stock firmware first
   - Check SD card format (FAT32)
2. **Bed leveling issues**
   - Ensure probe is properly connected
   - Check Z-offset settings
   - Clean the build surface
3. **Temperature reading errors**
   - Verify thermistor connections
   - Check thermistor type settings
## Contributing
Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.
## License
This project is licensed under the GNU General Public License v3.0 - see the LICENSE file for details.
Original Marlin firmware is licensed under GPL-3.0.
## Resources
- [Marlin Documentation](https://marlinfw.org/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Ender-3 V3 SE Community](https://www.reddit.com/r/ender3v3se/)
## Version
Current firmware version: 1.1.0
---
**Disclaimer**: Flashing custom firmware may void your warranty. Use at your own risk.
