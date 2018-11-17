# ProjetRS

1er commit: 

Main: reconnait les différents arguments, pour l'instant j'ai utilisé printf() pour voir comment ça fonctionnait mais à modifier éviemment 
listing: fait la liste des éléments présents dans le dossier courant, ils sont triés par ordre alphabétique mais les fichiers avec des
majuscules sont affichés avant (c'est l'inverse avec ls) donc fonction compare à modifier 

commit du 17/11:

J'ai supprimé listing.h et rajouté listing.c (en gros le même code, je m'était juste trompée pour l'utilisation d'un fichier .h) et ne pas oublier IL FAUT TOUJOURS UNE FONCTION main(). 
Maintenant travailler davantage sur le code pour que ./listing DOSSIER = find DOSSIER dans le cas d'un dossier vide, dans le cas d'un dossier se trouvant antérieurement ou dans les descendants. 
