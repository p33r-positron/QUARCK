# QUARCK - QUARtet Code

...Et le K c'est pour Koin Koin :)  
  
QUARCK est une norme de codage de caractères, comme l'ASCII ou l'UNICODE :D  
Sauf que l'UNICODE utilise 16 Bits, l'ASCII 8 Bits, et le QUARCK... 4 Bits...
Il porte bien son nom hein ! QUARCK, car c'est tout petit ! QUARCK... Quark, vous l'avez ? :)  
(D'ailleurs le projet devait s'appeler QUACK de base, le bruit du canard, coin coin !)  
  
# Mais comment faire rentrer 26 lettres dans 16 combinaisons ?

Et oui, un quartet c'est 4 Bits, 2^4 vaut 16, comment ai-je fait ?  
Vous allez comprendre, regardez la 14ème combinaison :)  

# La table QUARCK

Coin coin ! On passe sur un quartet !  
  
0 - NULL  
1 - a  
2 - b  
3 - c  
4 - d  
5 - e  
6 - f  
7 - g  
8 - h  
9 - i  
10 - j  
11 - k  
12 - l  
13 - m  
14 - La prochaine lettre est +13 (Ex: a -> n, m -> z)  
15 - La prochaine lettre est majuscule  
  
Et le meilleur c'est qu'on peut faire rentrer tout ça dans un chiffre héxadécimal :D (De 0 à F)  
  
# Combinaisons spéciales

Si on oublie les lettres de m à z, les lettres majuscules, et les deux en même temps, on a:  
  
14 0 - NULL +13 -> Barre d'espace  
15 0 - NULL Majuscule -> Retour à la ligne  
15 15 - Double Majuscule -> EOF, fin de fichier ("Rétro"compatible avec l'ASCII)  
  
# Outils développés

-Bibliothèque QUARCK en C: Possède quelques fonctions de stdio.h en version QUARCK, telles que (f)putqckar, (f)put2qckar et (f)putsqck  
-ASCII2QUARCK et QUARCK2ASCII: Permet de traduire des documents d'une table à l'autre !   
-QUARCKLIRE: Équivalent de CAT/TYPE pour lire un fichier QUARCK, littéralement `quarck2ascii <fichier> /dev/stdout`  
