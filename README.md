# PLOT TWIST
**Plot Twist** est un mini-langage mathématique réalisé par **Fabien Delattre** et **Simon Lecoq** dans le cadre d’un projet ISEN en 2016.
Il n'est pas parfait, mais nous n'allons pas en faire tout un fromage, sinon les bisons seront jaloux des vaches...
![Démonstration](https://github.com/lowlighter/language-theory/raw/master/docs/demo.gif)

# Installer le projet

## Télécharger les dépendances
Ce programme nécessite l'utilisation d'un analyser lexicale et syntaxique, ainsi que diverses autres bibliothèques.
Tapez la commande ci-dessous pour installer **flex**, **bison**, **cmake**, **boost** et **openssl**.

```shell
    sudo apt-get install flex bison cmake libboost-all-dev libssl-dev
```

## Démarrer le projet
Une fois prêt, rendez-vous à la racine du dossier parent puis exécutez la commande suivante, qui vous permettra de compiler les resources et de démarrez le serveur :

```shell
    make && ./start_server
```

Rendez-vous ensuite dans le dossier */client* puis ouvrez le fichier *index.html* dans votre navigateur préféré.

# Premiers pas
Une fois le client lancé, vous pouvez rentrez des formules et des expressions. Appuyez ensuite sur la touche **Entrée** pour évaluer le résultat.
```python
    >>> 1+1
    2
```

Il est possible d’écrire plusieurs commandes sur une seule ligne.
Il suffit pour cela de les séparer par un **;** (*point-virgule*).
*Notez qu’en mode ligne de commande, chaque résultat individuel sera affiché.*

```python
    >>> 1+1; 3
    3
```

# Opérations arithmétiques
## Addition
```python
    >>> 2+40
    42
```
## Soustraction
```python
    >>> 69-27
    42
```
## Multiplication

*Note : la multiplication implicite entre un nombre et une variable est également supportée.*
```python
    >>> 21*2
    42
    >>> a = 21; 2a
    42
```
## Division
```python
    >>> 84/2
    42
```
## Modulo
```python
    >>> 142%100
    42
```
## Factorielle
```python
    >>> 4!
    24
```
## Puissance
```python
    >>> 4^2
    16
    >>> e^2
    7.38906
```

# Variables
Il est possible de déclarer des variables.
Les variables peuvent être composées de caractères alphanumériques (*underscore* inclus) mais ne peuvent pas commencer par un chiffre.
A noter que certains identificateurs sont réservés par le langage et ne peuvent être utilisés en tant que nom de variable.

## Déclarer et utiliser une variable
```python
    >>> a = 13
    >>> a = a * 2
    26
```

Certaines variables sont prédéfinies par le langage.

## Les variables prédéfinies

**Pi**
```python
    >>> pi
    3.14159265358979
```
**e**
```python
    >>> e
    2.71828182845905
```
**true**
```python
    >>> true
    1
```
**false**
```python
    >>> false
    0
```

## La variable ans
Celle-ci est une variable spéciale contenant le résultat de la dernière opération effectuée.
Elle ne possède aucune valeur si la ligne précédente était une déclaration de fonction ou de variable ou lors d’un affichage graphique ou tabulaire.
```python
    >>> 1+1
    2
    >>> 40 + ans
    42
```

# Fonctions
## Déclarer et utiliser une fonction
Il est possible de déclarer des fonctions. Les noms de fonctions peuvent être composées de caractères alphanumériques (underscore inclus) mais ne peuvent commencer par un chiffre.
A noter que certains identificateurs sont réservés par le langage et ne peuvent être utilisés en tant que nom de fonction.

**Nota Bene** : Il est impératif que qu'il n'y ait **pas** d'espace entre la déclaration de la fonction et le signe égal.

```python
    >>> polynome2(x)= x^2 + x + 1
    >>> polynome2(3)
    13
```

Il est aussi possible de passer un tableau en paramètre d’une fonction.
```python
    >>> polynome2(x)= x^2 + x + 1
    >>> polynome2([0, 10, 1])
```

![Tableau de données](https://github.com/lowlighter/language-theory/raw/master/docs/table.png)

Vous pouvez bien évidemment utiliser d’autres noms pour vos variables d’évaluation :
```python
    >>> degree_to_rad(theta)=((2*pi)/360)*theta  
    >>> degree_to_rad(360)
    6.28318530717959
```

Mais aussi utiliser des variables que vous avez (ou allez) définir !
*Note : la variable doit être définie au moment vous exécutez votre fonction, au quel cas une erreur variable indéfinie sera retournée.*

```python
    >>> a = 2  
    >>> f(x)= a*x + b
    >>> b = 3
    >>> f(1)
    5
```

Et aussi faire des compositions de fonctions :
```python
    >>> f(x)= x ; g(x)= x * f(x) ;
    >>> g(f(10))
    100
```

## Fonctions mathématiques
Les fonctions mathématiques prennent en argument soit un nombre, soit une variable, ou même une expression !
Vous pouvez donc faire des calculs entre les parenthèses de celles-ci, incroyable n’est-ce-pas ?
Notez cependant que vous ne pourrez pas déclarer de variables ou de fonction ayant le même nom qu’une des fonctions listées ci-dessous.  

**Racine carré**
Cette fonction retourne la racine carrée de l’expression évaluée.
```python
    >>> sqrt(42^2)
    42
```

**Absolu**
Cette fonction retourne la valeur absolue de l’expression évaluée.
```python
    >>> abs(-42)
    42
```

**Fonctions trigonométriques**
Cette catégorie regroupe les fonctions suivantes : **cos** (*cosinus*), **sin** (*sinus*) et **tan** (*tangente*) ainsi que leurs inverses **acos**, **asin** et **atan**.
```python
    >>> cos(pi)^2 + sin(pi)^2
    1
    >>> tan(pi/4)
    1
```

**Fonctions hyperboliques**
Cette catégorie regroupe les fonctions suivantes : **cosh** (*cosinus hyperbolique*), **sinh** (*sinus hyperbolique*) et **tanh** (*tangente hyperbolique*) ainsi que leurs inverses **acosh**, **asinh** et **atanh**.
```python
    >>> cosh(pi)^2 - sinh(pi)^2
    1
    >>> tanh(0)
    0
```

**Exponentielles et logarithmes**
Cette catégorie regroupe les fonctions suivantes : **exp** (*exponentielle*), **ln** (*logarithme népérien)* et **log** (*logarithme décimal*).
```python
    >>> log(10^42)
    42
    >>> ln(e)
    1
```

## Fonctions utilitaires
Ici sont répertoriées les fonctions plus ou moins utiles !

**Nombre premier**
Cette fonction retourne **1** (*true*) si l’expression évaluée est un nombre premier.
```python
    >>> prime(2)
    1
```

**Minimum et maximum entre deux nombres**
Ces fonctions retournent respectivement le minimum et le maximum entre deux valeurs.
```python
    >>> min(-42, 42)
    -42
    >>> max(-42, 42)
    42
```

**Variable définie**
Cette fonction retourne **1** (*true*) si la variable est définie. *Note : cette fonction ne fonctionne uniquement que pour les variables, et non les fonctions.*
```python
    >>> isset(a)
    0
    >>> a = 1
    >>> isset(a)
    1
```

## Fonctions cools
**Coeur**
```python
    >>> f(x)= sqrt(cos(x))*cos(30*x)-0.1+sqrt(abs(x))
```

## Afficher une fonction
Il est possible d’afficher une fonction en utilisant la fonction **plot** :
```python
    >>> f(x)= x^3
    >>> plot(f)
```
![Affichage simple](https://github.com/lowlighter/language-theory/raw/master/docs/plot_single.png)


Il est également possible d’afficher plusieurs fonctions.
```python
    >>> f(x)= x
    >>> g(x)= x^2
    >>> h(x)= x^3
    >>> plot(f, g, h)
```
![Affichage multiple](https://github.com/lowlighter/language-theory/raw/master/docs/plot_multiple.png)

Il est possible de spécifier les bornes du graphe en passant une **range** en dernier paramètre de la fonction plot.
```python
    [from, to, step(optionnel)]
```

Les expressions au sein des ranges sont également supportés.
```python
    >>> f(x)= cos(x)
    >>> plot(f, [0, 2*pi])
```
![Affichage bornée](https://github.com/lowlighter/language-theory/raw/master/docs/plot_ranged.png)


# Structures conditionnelles
## Expressions booléennes et opérateurs logiques
Plot Twist supporte l’utilisation des opérateurs de comparaison d’égalité **==**, de différentiabilité **!=**, de supériorité **>** et **>=**, ainsi que ceux d’infériorité **<** et **<=**.
Les expressions booléennes retourne la valeur **1** (*true*) si celle-ci est vérifiée, et **0** (*false*) dans le cas contraire.
```python
    >>> 1 == true
    1
    >>> 1+1 <= 2
    1
```

Les opérateurs logiques **&&** (*ET*) et **||** (*OU*) permettent de réaliser des expressions plus complexes.
Cependant, pour être sur de l’exactitude de votre formule, n’oubliez pas d’utiliser des parenthèses !
```python
    >>> true && true
    1
    >>> true || false
    1
    >>> (true && false)||(1 < 42)
    1
```

## Expressions ternaires
Plot Twist permet l’utilisation de structures conditionnelles.
Elles s’utilisent ainsi:
```python
    <SI>?<ALORS>:<SINON>
```

Par exemple :
```python
    >>> b = 1
    >>> b = b < 2 ? 3 : 1
    >>> b
    3
```

Et peuvent être chaînées les unes dans les autres :
```python
    >>> true ? true ? 1 : 0 : 0
    1
    >>> true ? false ? 0 : 1 : 0
    1
    >>> false ? true ? 0 : 0 : 1
    1
```

Notez que ces dernières peuvent être utilisées dans des fonctions et permettre ainsi de faire de la récursivité.
```python
    >>> f(x)= x > 0 ? 1+f(x-1) : 1
    >>> f(1)
    2
```

# Compilation et tests
Il est possible d’utiliser l’interpréteur directement côté serveur en se plaçant à la racine et en tapant la commande suivante :
```shell
    make fast
```

Ce mode est plus restreint et ne peut évidemment pas afficher de graphique.
L’affichage des fonctions par range est également désactivé.

![Ligne de commande](https://github.com/lowlighter/language-theory/raw/master/docs/cli.png)

Vous pouvez faire réaliser les tests unitaires en utilisant la commande:
```shell
    make test
```

![Tests unitaires](https://github.com/lowlighter/language-theory/raw/master/docs/tests.png)

# Interface utilisateur
## Historique
Plot Twist inclut un historique des commandes précédemment tapées. Vous pouvez le parcourir grâce aux flèches ***haut*** et ***bas*** du clavier.

## Barre d'outils
La barre d'outils offre tout un tas de possibilités.
![Barre d'outil](https://github.com/lowlighter/language-theory/raw/master/docs/tools.png)

- Enregistrer localement le plot sous format png
- Enregistrer le plot dans le cloud puis l’éditer
- Zoomer par sélection
- Se déplacer (Cela actualise automatiquement l’affichage)
- Zoomer / Dézoomer
- Afficher / Masquer les données au survol

Il est aussi possible, lorsque plusieurs fonctions sont affichées, de masquer ou non certaines fonctions.
![Afficher ou masquer des courbes](https://github.com/lowlighter/language-theory/raw/master/docs/display.png)
