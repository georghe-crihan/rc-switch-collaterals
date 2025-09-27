# rc-switch-collaterals

Getting the rc-switch library and peripherals working under RPI-zero.

## Devices

SuperSwitch KSI-194 / KSI-393

The sockets contain *SC5272-M4* to be paired with *SC5262-M4* encoder.
Although that should be signal-compatible with *SC2262* encoder, allowing the KSI-393
remotes to control them.

It has an 8-bit address, with 4 bits of data, capable to drive 16 sockets in theory.

Typically, the sockets contain a label (on the other side of the board, facing the
inner plug prong connections) that lists the address as encoded:

|76543210|outer label|
---------|-----------|
|10F0F1F1|D2451|

where the letter F denotes a *floating* (not connected, NC) bit.

In theory that gives 3^8 = 6561 address combinations.

The remote board has "KS-40" designation.

The encoding is as follows:

|state   | bits |
|--------|------|
| 0 | 00 |
| 1 | 11 |
| F | 01 |

