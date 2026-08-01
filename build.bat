@echo off

cd /d E:\Ender-3V3-SE-main

if not exist .pio\tmp mkdir .pio\tmp

set TMP=.pio\tmp

set TEMP=.pio\tmp

set TMPDIR=.pio\tmp

set PYTHONLEGACYWINDOWSFSENCODING=1

python -m platformio run -e STM32F401RC_creality
