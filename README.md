# rc-switch-collaterals

Getting the rc-switch library and peripherals working under RPI-zero.

* https://github.com/sui77/rc-switch.git
* https://github.com/WiringPi/WiringPi.git 

If you want to visualize a telegram copy the raw data and 
paste it into http://test.sui.li/oszi/

## RC-Switch hardware

---

### FS1000A 433MHz RF transmitter and receiver Brief Note

*October 23, 2023 / Team Communication*

*Last Updated on May 9, 2024*

FS1000A 433MHz RF transmitter and receiver Brief Note For wireless application design.
This 433MHz Tx and Rx module uses ASK (Amplitude Shift Keying) Modulation. These
modules are used in multiple applications like, For Short distance communication,
Home Automation, Remote controls and Car security etc.., Many manufacturers producing
these TX/RX modules with frequency range from 315MHz to 334MHz. Especially *Wenshing*
from Taiwan Makes (303.875MHz / 310MHz / 315MHz / 318MHz / 418MHz / 433.92MHz)
Wireless ASK RF Transmitter and Receiver. Due to its simple operation and shape,
these modules are widely used in many wireless applications. By understanding its
operation and internal schematic you can also explore the ability of ASK RF
Transmitter and Receiver.

Before jumping into the Hardware and Schematic operations, let us recall What is ASK?
and How it works? We know *Amplitude Shift Keying* is the part of Digital Modulation
Techniques. Here input is Digital data either logic HIGH (1) or logic LOW (0) and
the Carrier is sinusoidal wave with 433MHz (frequency varies with respect to Tx/Rx
Module). Depending on the Digital unipolar binary sequence transistor switch Allows
or Stops the Carrier sinusoidal wave. At the output it appears as Amplitude shift
keyed wave. Due to its frequency range and antenna circuitry it becomes RF wave and
propagates.

#### ASK Waveform

![ASK Waveform](pics/ask-waveform.png)

As you can see how the ASK wave S(t) is modulated by using the Digital Data m(t),
Carrier Frequency C(t). Depending on the ASK modulator Switch, data modulation
(bit rate) varies.

#### FS1000A 433MHz Transmitter Circuit Diagram

![FS1000A 433MHz ASK Transmitter Module](schematic/FS1000A-433MHz-ASK-Transmitter-module.png)

#### FS1000A 433MHz Receiver Circuit Diagram

![FS1000A 433MHz ASK Receiver Module](schematic/FS1000A-433MHz-ASK-Receiver-Module.png)

#### Construction & Working

The Transmitter uses 433MHz Crystal oscillator to produce Carrier signal and
Transistor Q1 S8050 acts as modulator switch and modulates Digital input data
with Carrier signal and converts it into ASK Wave.(SWG18) 8 Turns and 3 Turns
coils produce electromagnetic wave that can be propagated using Antenna. The
schematic above is given for reference and does not exactly replicate the actual
Module. Here the module picture uses 433.92MHz SAW (Surface Acoustic Wave)
Resonator in TO-39 package.

The 433MHz Receiver Module contains the following circuits:

1. Rectifier,
1. Envelope Detector,
1. Comparator and
1. Output Buffer.

After Receiving the ASK RF signal, it is amplified by the transistor T1 and
Rectified by using two 1N4148 Diodes. Then the Comparator LM358 Compares and
separates Enveloped signal then it is converted into Square wave (binary sequence)
as Data output.

Even though there is no specific pin number, the silkscreen text denotes each pin
name. If there is no such text keep the component on the module toward you face and
follow the table for pin details.

#### 433MHz RF TX

|Pin Number	|Pin Name	|Pin Description
|-------|-------|---------------------------------------------
|1	|DATA	|Data Input pin (Data to be Transmitted)
|2	|VCC	|+Ve Power supply to the Transmitter circuit
|3	|GND	|Gnd Supply to the Transmitter circuit
|4 (PCB Via) |ANT 	|Antenna pin to be connected with Wire antenna


#### 433MHZ RF RX

|Pin Number	|Pin Name	|Pin Description
|---------------|---------------|------------------------
|1	|VCC	|+Ve Power supply to the Receiver circuit
|2	|DATA	|Data Output Pin (Data Receiving Pin)
|3	|DATA	|Data Output Pin (Data Receiving Pin)
|4	|GND	|Gnd Supply to the Receiver Circuit
|5 (PCB Via)	|ANT	|Antenna pin to be connected with Wire antenna

#### Specifications

##### For Receiver Module

* It can operate with 3V to 9V input DC Voltage.
* Operating Frequency is 433.92MHz (433MHz)
* Transmitter consumes 4mA to 40mA current during its operation.
* It can Transmit up to 100 Meter distance.
* It has 10Kbps Data Transmission rate.

##### For Receiver Module

* It can operate with 3.5V to 12V input DC voltage.
* Operating Frequency can be minor tuned 433.92MHz (433MHz)
* Current consumption for operation 20mA – 30mA.
* Data Transfer rate 10Kbps.
* Sensitivity of this receiver is 105db.

#### Interfacing

These modules can be used as Wireless Switch, Discrete logic data Transmitter and
Receiver or by using HT12E Encoder and HT12D Decoder IC we can interface these
modules with Arduino, Raspberry PI or any other micro controllers.

---
### Antenna considerations

Basic physics gives Thomson LC equation (formula for resonant frequency):

![Thomson equation](pics/ThomsonEq.png)

When using an external antenna a 1/4 wavelength is recommended. Ideally 
use 50 impedance ohm single-core wire, the length of the antenna 433M is 
about 17cm (1/4 wavelength). When locating the receiver antenna keep it 
as far away as possible from shielded areas, high voltages, and any 
possible interfering frequencies.

I tried 17cm wires straight and coiled (see image) when receiving / transmitting

![Straight antenna](pics/straight-antenna.jpg) 

I got much better results using a 19.5 cm connector wire (when receiving)

![Better straight antenna](pics/better-straight-antenna.jpg) 

Need a better antenna.

A balanced dipole antenna works extremely well with those modules, shown in the
photo below. The connection labelled GND is actually the other antenna connection!

The antenna wires are each 17 cm long for 433 MHz. I get over 300 meters range,
line of sight with the setup shown.

433 MHz is roughly 70cm wave length... so a half wave dipole is about 33cm .... cut
in half one side to the antenna connector the other side to ground.

![Dipole](pics/Dipole.gif)

![Second Dipole](pics/BetterAntenna.jpg)

### Issues
They can't work without a vital component in place. That inductor
provides power to the high-frequency oscillator.

Luckily somebody else has gone to the effort of analyzing the issue.

Review this website.

[FS1000A 433 MHZ TRANSMITTER – L2 MISSING](https://vk4ghz.com/fs1000a-433-mhz-transmitter-l2-missing/)

Here is the schematic from that site.

![Transmitter schematic](schematic/naCDy.png)

*answered Apr 5, 2022 at 1:57*

* The linked page shows how to solve the problem, but using enamel insulated copper wire to wind the coil. I don't have any of that, but I do have some plastic insulated wire that should work. Assuming I make it the same size: 4mm diameter by 3 turns, and just strip the insulation off the ends to solder it, should that work OK? –  *Commented Apr 5, 2022 at 2:45*
* The inductor is non-critical so should be ok. –  *Commented Apr 5, 2022 at 4:00*
* @dgnuf - You may be interested in the software I use for making inductors. Not affiliated, I just use and enjoy it. It's called Coil64 and you can find it here: coil32.net/download-coil64-for-windows.html – *Commented Apr 5, 2022 at 4:04*

### RPI power considerations

#### The FS0001A transmitter

The transmitter would require higher power for better range and throughput, and should
be OK if connected to +5V. That is, the Data pin could be driven by RPI's 3.3v 
without any additional level shifters, as it drives the base of the transistor.

#### The MX-RM-5V reciever

The reciever should not require more than 3.3v of power, otherwise a simple voltage
divider should solve the problem.

![Simple voltage divider](Voltage-divider-1.png)

Basic calculation suggests a 2:1 ratio, that is a 4.7K/10K or a 10K/20K resistor
pair.

However it should, in theory, be possible to power it off the 5v rail, as the
device does already contain a voltage divider (in the form of a 2.2M resistor,
acting as R1 on the schematic above).

#### Reciever noise

If powered from the RPI header, there seems to be much noise. This could be fixed
by powering it off an external PSU.

## Devices Driven

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

# Software issues

## Python -- RuntimeError: Failed to add edge detection - On RaspberryPI

I am using Bullseye version. I was able to fix this by rolling back the firmware update [rpi-update] to the stable version.

```shell
sudo apt-get update; sudo apt-get install --reinstall raspberrypi-bootloader raspberrypi-kernel
```

After that update the software and reboot.

```shell
sudo apt-get update
sudo apt-get upgrade
```
