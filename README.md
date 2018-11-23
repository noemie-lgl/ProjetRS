# ProjetRS

1er commit: 

Main: reconnait les différents arguments, pour l'instant j'ai utilisé printf() pour voir comment ça fonctionnait mais à modifier éviemment 
listing: fait la liste des éléments présents dans le dossier courant, ils sont triés par ordre alphabétique mais les fichiers avec des
majuscules sont affichés avant (c'est l'inverse avec ls) donc fonction compare à modifier 

commit du 17/11:

J'ai supprimé listing.h et rajouté listing.c (en gros le même code, je m'était juste trompée pour l'utilisation d'un fichier .h) et ne pas oublier IL FAUT TOUJOURS UNE FONCTION main(). 
Maintenant travailler davantage sur le code pour que ./listing DOSSIER = find DOSSIER dans le cas d'un dossier vide, dans le cas d'un dossier se trouvant antérieurement ou dans les descendants. 

commit du 18/11:

listing n'affiche plus "." et ".."
Quand le dossier est vide, il affiche le nom du dossier (comme find)
Quand le dossier n'existe pas, renvoie "rsfind: DOSSIER: No such file or directory" : à la place de rsfind, faut-il que ce soit find pour renvoyer exactement la même chose que find? S'affiche en anglais sur mon ordinateur mais ne correspond pas sur ubuntu sur les ordis de l'école: find: 'ProjetRS': Aucun fichier ou dossier de ce type

commit du 23/11:

J'ai tout mis dans un même fichier rsfind.c. Je l'ai aussi commité sur gitlab et j'ai fait les modifications directement dessus puisqu'avec gitlab on peut directement voir si la compilation s'est bien déroulé; d'ailleurs je pense qu'on va finalement commiter que sur gitlab. 
