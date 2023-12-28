#!/bin/bash

# Specify the path to your DMG file
DMG_FILE="/Users/rugilesamusyte/Documents/v3.0.dmg"

# Specify the first destination directory
DESTINATION_DIR1="/Users/rugilesamusyte/Desktop/VU/Rugile-Samusyte"

# Specify the second destination directory
DESTINATION_DIR2="/Users/rugilesamusyte/Desktop"

# Specify the desired mount point
MOUNT_POINT="/Volumes/v3.0"

# Mount the DMG file
hdiutil attach "$DMG_FILE" -mountpoint "$MOUNT_POINT"

# Copy the contents to the first destination directory
cp -r "$MOUNT_POINT"/* "$DESTINATION_DIR1"

# Copy the contents to the second destination directory
cp -r "$MOUNT_POINT"/* "$DESTINATION_DIR2"

# Unmount the DMG
hdiutil detach "$MOUNT_POINT"


