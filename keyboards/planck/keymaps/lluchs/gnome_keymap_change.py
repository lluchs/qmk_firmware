#!/usr/bin/env python3

# Adapted from https://askubuntu.com/a/881403

from gi.repository import Gio, GLib

# Create a udev rule like the following:
# ACTION=="add", SUBSYSTEM=="tty", ATTRS{idVendor}=="feed", ATTRS{idProduct}=="6060", MODE="0666", SYMLINK+="ttyPlanck", ENV{ID_MM_DEVICE_IGNORE}="1"

TTY_PATH = '/dev/ttyPlanck'

# Send a character to the keyboard TTY device.
def tty_send(ch):
    try:
        with open(TTY_PATH, 'a') as f:
            f.write(ch)
    except:
        print("Planck not found")

def on_changed(settings, key):
    # This will run if specific key of a schema changed
    val = settings.get_value(key)
    print("Language changed", key, val)
    ch = 'Q'
    if 'neo' in str(val[0]):
        ch = 'N'
    print(' -> ', ch)
    tty_send(ch)

def main():
  # We're focusing on this specific schema
  settings = Gio.Settings.new("org.gnome.desktop.input-sources")
  # Once the key changes, on_changed function will run
  settings.connect("changed::mru-sources", on_changed)
  loop = GLib.MainLoop()
  loop.run()

if __name__ == "__main__":
  main()
