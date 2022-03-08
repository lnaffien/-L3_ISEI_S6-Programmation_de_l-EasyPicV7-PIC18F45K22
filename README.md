# L3_ISEI_S6-Programmation_de_l_EasyPicV7-PIC18F45K22

## Enoncé
Réalisez un projet à partir du capteur de température ou à ultrasons, au choix.<br>
Créez une application Android récupérant les données mesurées via Bluetooth.

## Description du projet
Pour ce projet, il a été décidé que le capteur à ultrasons sera utilisé afin de mesurer la quantité remplie d'un contenant.


L'application Android permettra de lancer une ou plusieurs mesures manuellement, à un intervalle choisi, ainsi que de représenter le résultat de plusieurs manières : en chiffres et en imagé, avec un contenant se remplissant à l'image du contenant réel mesuré.

### One Wire
1. Vérifier le commutateur sur la carte.
2. Attention au sens de branchement du capteur de température DS1820
3. Donner les caractéristiques principales du protocole One-Wire
4. En consultant la documentation de la librairie "One Wire library" : 
    - Combien de fonctions contient cette librairie ?
    - Donner les étapes à suivre pour afficher la mesure de la température

3. Le protocole One-Wire : 
    - bus de données
    - 2 fils : 1 masse et 1 données
    - similaire à l'I2C, mais vitesse et cout inférieurs
    - Protocole :
        - Initialisation :
            1. Maitre met le bus à l'état bas
            2. Etat haut en attente de réponse de(s) esclave(s)
            3. Esclave(s) met(tent) le bus à l'état bas
            4. Maître envoie commande ROM
        - Envoie des données par le maître :
            5. Maître envoie données en fonction de la clock définie
        - Envoie des données par l'esclave :
            6. Maître force bus à l'état bas
            7. Esclave transmet les données et maître les lit 