Changelog del juego:


_20/04/2016_
→ Implementada clase “personaje” que incluye todos los elementos controlables (IA o humano) del escenario. La clase tiene los siguientes atributos:
	→ Tipo. Define la clase o especialización del personaje (tipo enum).
	→ Ataque físico. Cantidad de daño capaz de causar en un ataque directo (sin consumo).
	→ Ataque de habilidad. Cantidad de daño capaz de causar en un ataque especial. *
	→ Salud. Cantidad de puntos de aguante (daño que puede soportar).
	→ Defensa. Cantidad de puntos de daño capaz de disipar al recibir un ataque (porcentual).
	→ Defensa de habilidad. Idem a la anterior pero con ataques de habilidad.
	→ Daño. Daño base de habilidad usada (multiplicar por el ataque de habilidad).
	→ Bonificación. Parámetro para saber la modificación que tiene un personaje.
	→ Velocidad. Capacidad máxima para desplazarse por el campo en cada turno.
	→ Bando. Parámetro que define si es aliado, neutral o enemigo.
	→ Nivel. Caracteriza los atributos del personaje en función de su experiencia adquirida.
	→ Experiencia. Puntos que sirven para subir de nivel.
	→ Posición. Caracteriza su posición actual en el mapa.
	→ Aguante. Capacidad para realizar ataques de habilidad, se consume con su uso.
	→ Disponibilidad. Parámetro para conocer el estado del personaje.
* Esto incluye curaciones.

La clase cuenta con los siguientes métodos:
	→ Atacar. Devuelve el valor calculado del daño que administra en el ataque.
	En función del parámetro que se le pase devuelve daño físico o de habilidad. Resta Aguante.
	→ Defender. Devuelve el valor de la reducción de daño total en función del recibido.
	→ Actualizar. Actualiza las características del personaje después de la modificación. 	Comprueba también la posibilidad o no de ataque.
	→ Moverse. Calcula la velocidad y mueve al personaje sobre el mapa.

→ Implementada clase “Posición” Para definir dos coordenadas en el mapa.


_21/04/2016_
Creación de la clase Objeto
Decisión de limitar a 1 ítem por personaje jugable.
Creación de la clase Bonus. //No me entero de nada