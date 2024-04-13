# Smoke-detection-using-Esp01

I have desgined a smoke sensor using 555 timmer IC and ESP01 as a wifi model.
Thought there are better alternaties of smoke sensors
I took a different approach to build something from what I have learned from my accadmeics and personal experinces.

I used a 555 timer IC to as a trigger and delay to last the exhaust fan for a long period using the combination of resistor and capasitor substuted in the formula T = 1.1 * R * C (i.e T = 1.1 * (27000ohm) * (0.000270F) ¬8 seconds.

With the help of esp01 wifi module and arduino ide I designed a code sucha that whent the smoke sensor triggers the 555 Ic a active high is sent to GPIO pin of Esp01 which then sends a email alerting the user.
