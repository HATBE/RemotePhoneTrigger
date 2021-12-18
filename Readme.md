# Remote Phone Trigger

Kleines Fun Projekt. In dem via Anruf, eine kleine Show Sequenz abgearbeitet wird, danach wird ein Relais ausgelöst.

## Signale

| Bauteilname | Device Out | Arduino In |
|-|-|-|
|Buzzer|5V <br> GND|D9 <br> GND|
|LED|5V (200 Ohm) <br> GND|D13 <br> GND|
|Relay|5V <br> Digital <br> GND|5V <br> D12 <br> GND|
|Sim5320E|5V <br> VMCU <br> TX <br> RX <br> GND|5V <br> 5V <br> D11 <br> D10 <br> GND|

## Flussdiagramm

![Flussdiagramm](img/flussdiagramm.png)