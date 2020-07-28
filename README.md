# Gravity Powered Garden Watering System

This is my garden watering setup. It is a fairly simple design but like all projects you underestimate how much goes into something so simple. Hopefully this tutorial can help someone else create something similar. 

## Setup

On the solar side there is a 20w solar panel connected to a simple charge controller, the battery is also connected to this and the load is sent to the circuit board.

The Arduino is simply a MOSFET TIP120 connected to pin D6 which opens the valve when a signal is sent.

I used the following design from the web by 
[Matyn Currey](http://www.martyncurrey.com/controlling-a-solenoid-valve-from-an-arduino/) for the circuit layout. Simply use the leads from the "Load" output on the solar controller to connect where the power plug is on this circuit.

#### Modifying for your setup
You need to edit lines 4-8 with your WiFi and MQTT Settings. 

## Home Assistant

To control the valve the Arduino communicates to HA via MQTT. Included are the config files once MQTT is setup. There is a switch that controls the opening and closing of the valve, as well as a sensor that receives a signal from the Arduino when the valve is open or closed. 

[How to setup MQTT in HA](https://www.home-assistant.io/integrations/mqtt/)

I have an MQTT server setup locally, however if you are just getting started, I recommend [CloudMQTT](https://www.cloudmqtt.com/). <br>-- [How to setup an MQTT server quickly](https://www.cloudmqtt.com/docs/index.html)
<br>-- [How to setup an MQTT locally](https://appcodelabs.com/introduction-to-iot-build-an-mqtt-server-using-raspberry-pi)

## Water Lines

On the other end of the valve is a simple hose, this is connected to a PVC loop in the garden that has small holes drilled into it. I recommend drilling only a few holes in the line while the tank is about 1/4 full. Test pressure and add holes as needed to adjust. 

## Components

[Solar Panel](https://www.amazon.com/dp/B0833N3FGH/ref=cm_sw_em_r_mt_dp_U_GGciFbWQ0X8XP)<br>
[Charge Controller](https://www.amazon.com/dp/B072MMDY4F/ref=cm_sw_em_r_mt_dp_U_vGciFbX19YY85)<br>
[Battery](https://www.menards.com/main/tools/automotive/automotive-batteries/fvp-reg-voltedge-reg-u1l-215v-lawn-and-garden-battery/2609714/p-4364363665501704-c-1516819218414.htm)<br>
[Outdoor Box](https://www.amazon.com/gp/product/B07PWD6QPX/ref=ppx_yo_dt_b_asin_title_o08_s01?ie=UTF8&psc=1)<br>
[Solenoid Valve](https://www.amazon.com/gp/product/B07G982TXM/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1)<br>
[IBC Adaptor](https://www.amazon.com/gp/product/B075B5R5FX/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)<br>
[Waterproof Plugs](https://www.amazon.com/gp/product/B01F54PFLE/ref=ppx_yo_dt_b_asin_title_o07_s00?ie=UTF8&psc=1)<br>
[NodeMCU](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010N1SPRK/ref=sr_1_2_sspa?dchild=1&keywords=nodeMCU&qid=1595943339&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyQVBSOTdaVUFZMkYyJmVuY3J5cHRlZElkPUEwOTA5NTQ0SUFFQUNRT1M4U0Q1JmVuY3J5cHRlZEFkSWQ9QTA1MzgxMzBXT0pVQk1BNTRNQ1Amd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl)<br>
[MOSFET & Diode](https://www.amazon.com/TIP120-Darlington-Transistor-Arduino-Diodes/dp/B00FVLGYEY) *(you can find these cheaper elsewhere, they also come in most starter kits)* <br>
[Resistor Kit](https://www.amazon.com/Elegoo-Values-Resistor-Assortment-Compliant/dp/B072BL2VX1/ref=sr_1_3?dchild=1&keywords=resistor+kit&qid=1595967748&sr=8-3) *(requires a 2.2k resistor)* <br>
[Solderable Breadboard](https://www.amazon.com/ELEGOO-Prototype-Soldering-Compatible-Arduino/dp/B072Z7Y19F/ref=sr_1_4?dchild=1&keywords=breadboard+solderable&qid=1595967819&sr=8-4)


## Future Upgrades

The setup is currently a 1/2 inch valve, which is fine but it restricts flow and so the pressure isn’t where I want it. I would recommend using a 1”. Alternately switching from a solenoid to a ball valve will likely help flow, it will also help with power consumption because the solenoid pulls power the entire time it is open. 

Up next for the code I will add a timeout that prevents it from being open longer than a set amount of time in case it loses connection to HomeAssistant.

I may add a couple float switches to the tank to notify me when the tank is low and to track usage.

##### I will update this repo as I add more to the project.
