# futabavfd
The Futaba NA202SD08FA vfd has a 8bit interface and 1 write strobe to command the display.
You can control the display with a set of predefined characters and cursor commands.
For example hex 0x14 resets the display hex 0x14 shows an ! 
After every byte the write strobe is set to high for 250 micro sec

Code is free to use for any purpose.
