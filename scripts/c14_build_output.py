"""
C14 Build Output Script for Ender-3 V3 SE (STM32F401)

This script runs after PlatformIO build and:
1. Creates build_output/STM32F4_UPDATE/ directory structure
2. Copies the firmware binary with a timestamped filename
3. Prepares the output for SD-card flashing on C14 boards

Bootloader behavior on C14:
- Ignores root directory
- Looks exclusively in STM32F4_UPDATE/ folder on SD card
- Requires unique filename on each flash to bypass bootloader cache
"""

import datetime
import os
import shutil

Import("env")


def post_build_action(source, target, env):
    """Post-build: copy firmware to C14 SD-card update folder."""
    build_dir = env.subst("$BUILD_DIR")
    project_dir = env.subst("$PROJECT_DIR")

    # Source binary from PlatformIO build directory
    firmware_bin = os.path.join(build_dir, "firmware.bin")

    if not os.path.exists(firmware_bin):
        print(f"[C14] Warning: firmware.bin not found at {firmware_bin}")
        return

    # Target directory: build_output/STM32F4_UPDATE/
    output_base = os.path.join(project_dir, "build_output")
    update_dir = os.path.join(output_base, "STM32F4_UPDATE")
    os.makedirs(update_dir, exist_ok=True)

    # Generate timestamped filename to bypass bootloader cache
    now = datetime.datetime.now()
    timestamp = now.strftime("%y%m%d_%H%M%S")
    dest_name = f"firmware_{timestamp}.bin"
    dest_path = os.path.join(update_dir, dest_name)

    shutil.copy2(firmware_bin, dest_path)

    print(f"[C14] Firmware copied to: {dest_path}")
    print(
        f"[C14] Copy the entire 'build_output/STM32F4_UPDATE/' folder to your SD card."
    )
    print(
        f"[C14] Ensure the file has a unique name on each flash to bypass bootloader cache."
    )


# Register post-action hook
env.AddPostAction("$BUILD_DIR/firmware.bin", post_build_action)
