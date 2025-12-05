# Devices

## RC7000D Carlon/Lamson remote control for lighting.

NA2-HW2190T, NA2 HW2190T, NA2HW2190T, NA2HW219OT, NA2HW2I90T

Thomas & Betts Corporation WIRELESS OUTDOOR LIGHT CONTROL TRANSMITTER HW2190T

2AESZHW2170R, 2AESZ HW2170R, 2AESZ-HW2170R, 2AESZ-HW217OR, 2AESZ-HW2I70R, 2AE5Z-HW2170R

Xodus Innovations LLC

- Wireless Plugin Switch HW2170R
- Wireless Light Socket Switch
- Wireless Switched Outlet HW2175
- Wireless Pull Chain Socket Switch HW2165

- NA2RRXV213X -> 2AESZ‐HW2170R
- DE4‐HW2181T -> 2AESZ‐HW2181T


Has a range of switches / remotely controlled fixtures / wall plugs that can be
used to remotely control various lighting.

FCC IDs have been changed (apparently after the Carlon business division has been
sold to Xodus).

Notably, the devices do not have any group IDs whatsoever. That is, only four
device IDs (encoded by the jumpers on both, reciever and transmitter as A, B, C and
D).

Contrary to other remote controlled sockets, these devices do not contain any
standard encoder/decoder chips, but Microchip's MCUs in both, reciever and
transmitter. The transmitter often contains just Chip-On-Board (COB, package-less IC,
covered by a plastic or epoxy blob).

## Westinghouse TK206

FCC ID: 2AHNS-TK206

(Also dubbed as Stanley in the manual, provided to FCC).

Has an [unknown] tansmitter/encoder DIP IC marked as 

```
PR3T21116N
B7035-1
```

Other batch contains the ```TE90TP16N``` DIP package, that seems to be analogous to the
above transmitter/encoder IC.

The sockets contain a SYNOXO 480R (8-pin version) reciever along with some defaced
decoder IC (also 8-pin).

The sockets have the ability to be paired with the transmitter - long-pressing the power button for
three seconds puts the socket into the learning mode, whereas pressing the on button (for two seconds)
on the transmitter and then off in turn completes the sequence. I suspect one could thus inverse the
function of the transmitter buttons though. :)

Sniffing the data:
```
22591314 unit 14 on, period: 258us.
```
It's the ```KlikAanKlikUit``` protocol used by several different companies.