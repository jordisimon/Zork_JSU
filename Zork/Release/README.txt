---------------------------------------------------------------------------------------------------------------------------
------------------------------------------- JORK --------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------
Autor: Jordi Simon Urbano

Jork es la meva versió del Zork.
Es tracta d'una aventura ambientada a la vigília de Halloween.
Ets un nen que vol anar a buscar caramels amb els seus amics, però no pots sortir de casa fins que vagis correctament disfressat.
L'aventura consisteix en recorrer la casa, buscant i combinant objectes per aconseguir parts de la disfressa, fins que ta mare
estigui satisfeta amb el resultat i et permeti sortir.
 
La meva versió te algun extra com ara la capacitat de utilitzar un objecte sobre un altre per tal de transformar-lo en quelcom nou i diferent.
També hi ha portes que nomes es poden desbloquejar amb certs objectes.
A més també permet parlar amb els altres personatges que ens anem trobant. Aquests podran donar-nos nous objectes (en algun cas només si complim
certes condicions) i fins i tot poden respondre frases aleatories cada vegada.
També ho he salpebrat amb una mica d'humor i algun easter egg amagat.

El projecte esta desenvolupat amb el Visual Studio 2015.
Si es vol compilar amb Visual Studio 2013 s'han d'editar les opcions del projecte:
Zork -> Properties -> Configuration Properties -> General -> Platform Toolset --> Seleccionar "Visual Studio 2013 (v120)"

A l'hora d'executar-lo s'ha de tenir instalat el redistribuïble de Visual C++ for Visual Studio 2015 (x86):
https://www.microsoft.com/en-us/download/details.aspx?id=48145

Repositori Git:
https://github.com/jordisimon/Zork_JSU/


Commandes disponibles en el joc:
"n" o "north" 					--> desplaçar-se al nort
"s" o "south" 					--> desplaçar-se al sud
"e" o "east"  					--> desplaçar-se al est
"w" o "west"  					--> desplaçar-se al oest
"u" o "up"						--> desplaçar-se amunt
"d" o "down"					--> desplaçar-se avall
"l" o "look"					--> mirar al voltant (look me --> mirar-se a un mateix)
"ex" o "examine" X				--> examinar l'objecte X
"in" o "inspect" X				--> igual que examine
"p" o "pick" X					--> agafar l'objecte X
"p" o "pick" X from Y			--> agafar l'objecte X contingut a Y
"t" o "take" X					--> igual que pick
"t" o "take" X from Y			--> igual que pick
"dr" o "drop" X					--> deixar l'objecte X
"un" o "unlock" (dir) with X	--> desbloquejar (dir) amb l'objecte X. (dir) es una de les possibles direccions de moviment
"use" X on Y					--> utilitzar l'objecte X a l'objecte Y
"i" o "inventory"				--> imprimeix la llista d'objectes que portes al damunt
"ta" o "talk" to X				--> parla amb el personatge X
"sp" o "speak" to X				--> igual que talk
"q" o "quit" o "exit" o "leave"	--> sortir del joc

Walkthrough per acabar el joc ràpidament:

south
west
take curtain
east
east
take key from closet
west
up
take paint
use paint with curtain
east
take lid from can
west
take pumpkin from cupboard
unlock down with key
down
take tape
take hammer
use hammer with lid
up
north
talk to dad
use knife with pumpkin
west
take umbrella
use tape with umbrella
south
take boots
north
talk to mom
unlock west with key
west
