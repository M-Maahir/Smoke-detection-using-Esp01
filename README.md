# Smoke-detection-using-Esp01

I have desgined a smoke sensor using 555 timmer IC and ESP01 as a wifi model.
Thought there are better alternaties of smoke sensors
I took a different approach to build something from what I have learned from my accadmeics and personal experinces.

I used a 555 timer IC to as a trigger and delay to last the exhaust fan for a long period using the combination of resistor and capasitor substuted in the formula T = 1.1 * R * C (i.e T = 1.1 * (27000ohm) * (0.000270F) ¬8 seconds.

With the help of esp01 wifi module and arduino ide I designed a code sucha that whent the smoke sensor triggers the 555 Ic a active high is sent to GPIO pin of Esp01 which then sends a email alerting the user.
![Screenshot_20240413_173745](https://github.com/M-Maahir/Smoke-detection-using-Esp01/assets/124713802/56b57ba0-121b-4c57-bec4-01b83f616ee6)
![Screenshot_20240413_173706](https://github.com/M-Maahir/Smoke-detection-using-Esp01/assets/124713802/ae130e01-a5eb-4863-beb8-bd90a45ef7d2)
![Screenshot_20240413_173648](https://github.com/M-Maahir/Smoke-detection-using-Esp01/assets/124713802/1661226a-c617-41ac-b33a-bd6c220abaf7)
![Screenshot_20240413_173619](https://github.com/M-Maahir/Smoke-detection-using-Esp01/assets/124713802/6c3a48ed-fcd9-4bbb-8e67-be7e5d747a85)
![20221203_225904](https://github.com/M-Maahir/Smoke-detection-using-Esp01/assets/124713802/ea842f0f-18cd-4a53-8006-d47e16d8f8f7)
