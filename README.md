# Garden Watering System

This is my garden watering setup. It is a fairly simple design but like all projects you underestimate how much goes into something so simple. Hopefully this tutorial can help someone else create something similar. 

## Setup

On the solar side there is a 20w solar panel connected to a simple charge controller, the battery is also connected to this and the load is sent to the circuit board.

The Arduino is simply a Mosfet connected to pin D6 which opens the valve when a signal is sent.

I used the following design from the web by 
[Matyn Currey](http://www.martyncurrey.com/controlling-a-solenoid-valve-from-an-arduino/) for the circuit layout. Simply use the leads from the "Load" output on the solar controller to connect where the power plug is on this circuit.

## Home Assistant

To control the valve the Arduino communicates to HA via MQTT. Included are the config files once MQTT is setup. There is a switch that controls the opening and closing of the valve, as well as a sensor that receives a signal from the Arduino when the valve is open or closed. 

## Components

[Solar Panel](https://www.amazon.com/dp/B0833N3FGH/ref=cm_sw_em_r_mt_dp_U_GGciFbWQ0X8XP)<br>
[Charge Controller](https://www.amazon.com/dp/B072MMDY4F/ref=cm_sw_em_r_mt_dp_U_vGciFbX19YY85)<br>
[Battery](https://www.menards.com/main/tools/automotive/automotive-batteries/fvp-reg-voltedge-reg-u1l-215v-lawn-and-garden-battery/2609714/p-4364363665501704-c-1516819218414.htm)<br>
[Outdoor Box](https://www.amazon.com/gp/product/B07PWD6QPX/ref=ppx_yo_dt_b_asin_title_o08_s01?ie=UTF8&psc=1)<br>
[Solenoid Valve](https://www.amazon.com/gp/product/B07G982TXM/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1)<br>
[IBC Adaptor](https://www.amazon.com/gp/product/B075B5R5FX/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)<br>
[Waterproof Plugs](https://www.amazon.com/gp/product/B01F54PFLE/ref=ppx_yo_dt_b_asin_title_o07_s00?ie=UTF8&psc=1)<br>
[NodeMCU](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010N1SPRK/ref=sr_1_2_sspa?dchild=1&keywords=nodeMCU&qid=1595943339&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyQVBSOTdaVUFZMkYyJmVuY3J5cHRlZElkPUEwOTA5NTQ0SUFFQUNRT1M4U0Q1JmVuY3J5cHRlZEFkSWQ9QTA1MzgxMzBXT0pVQk1BNTRNQ1Amd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl)<br>

