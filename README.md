# ROBOT SEGUIDOR DE LINEA USANDO QTR-8a

En este repositorio encontramos un carrito seguidor de linea usando la plataorma de arduino. El robot usa sensores qtr-8a controlados por el algoridmo Proportional-Integral-Derivative (PID) que nos ayuda a el control de los motores por medio de el error obtenido por el movimiento anterior y ayudando en el suavisado de el movimiento.


![Carrito seguidor de linea](https://github.com/user-attachments/assets/bd976919-36d6-4c02-91b1-92f356779255)
Link del funcionamiento: https://www.youtube.com/watch?v=fKZDk9xEpEQ

COMPONENTES USADOS:


*Modulo Qtr-8a Sensores Reflectivos Seguidor De Linea Arduino

*Modulo Puente H L298 Motor Driver Arduino Pic Raspberry

*Arduino uno

*2 Motores 2WD

* Pila lipo 7.4V 300mAh 2S 30C LiPo

PARAMETROS:

*Constantes PID (Kp, Kd): Parámetros ajustables para ajustar la respuesta del controlador PID

*MAX_SPEED,SET_SPEED,MIN_SPEED,SETPOINT: Parametros ajustables dependiendo de el peso, dimenciones, numero de sensores etc


ESAQUEMATICO :

![image](https://github.com/user-attachments/assets/2b115897-6714-401f-acd8-ccc7f034ada7)
( La pila de 9V en el esquema es solo ilustrativa. En el montaje real usamos una LiPo 7.4V 300mAh 2S 30C)

FORMA DE USO:

1. Conectamos la pila con el codigo anteriormente subido.
   
3. Empieza la calibracion marcada con el led (LED_BUILTIN) por 20 segundos
   
5. El robot empezara a seguir linea.

PID Line Follower Tuning

A continuacion se encuentra la guia con la que configure el PID http://robotresearchlab.com/2019/02/16/pid-line-follower-tuning/


How to Program a Line Following Robot

En esta guia encontraras como crear el codigo y las bases de un carro seguidor de linea https://robotresearchlab.com/2019/02/12/how-to-program-a-line-following-robot/


Agradezco especialmente al siguiente repositorio por algunas referencias y ejemplos que fueron de gran ayuda para completar este código: https://github.com/muquitarif/Autonomous-Line-Following-Robot

