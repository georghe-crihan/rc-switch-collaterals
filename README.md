# rc-switch-collaterals

Getting the rc-switch library and peripherals working under RPI-zero.

* https://github.com/sui77/rc-switch.git
* https://github.com/WiringPi/WiringPi.git 

If you want to visualize a telegram copy the raw data and 
paste it into http://test.sui.li/oszi/

## RC-Switch hardware

### Issues
They can't work without a vital component in place. That inductor
provides power to the high-frequency oscillator.

Luckily somebody else has gone to the effort of analyzing the issue.

Review this website.

[FS1000A 433 MHZ TRANSMITTER – L2 MISSING](https://vk4ghz.com/fs1000a-433-mhz-transmitter-l2-missing/)

Here is the schematic from that site.

answered Apr 5, 2022 at 1:57

* The linked page shows how to solve the problem, but using enamel insulated copper wire to wind the coil. I don't have any of that, but I do have some plastic insulated wire that should work. Assuming I make it the same size: 4mm diameter by 3 turns, and just strip the insulation off the ends to solder it, should that work OK? –  Commented Apr 5, 2022 at 2:45
* The inductor is non-critical so should be ok. –  Commented Apr 5, 2022 at 4:00
* @dgnuf - You may be interested in the software I use for making inductors. Not affiliated, I just use and enjoy it. It's called Coil64 and you can find it here: coil32.net/download-coil64-for-windows.html – Commented Apr 5, 2022 at 4:04

## Devices

### SuperSwitch KSI-194 / KSI-393

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

