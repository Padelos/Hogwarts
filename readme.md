# Σχετικά με την παρούσα εργασία
Αυτό το project εχεί υλοποιηθεί στα πλαίσια της μιας ακαδικαϊκής εργασίας.

![](Hogwarts-demo.gif)

* Παντελεήμων Πρώιος
* 18390023

## test.cpp
Τα .test.cpp είναι για να έλεγχο την λειτουργία του κάθε header.

## Makefile

Μέσα στο make file υπάρχουν:
- build: κατασκευάζει το συνολικό project (compile)
- run: τρέχει το project με τον χάρτη map10-20.txt αφού τρέξει το build (compile & run)
- map,cords,gem,player,game,ai που ήταν για να τρέξουν τα test.cpp

επίσης το compilation έχει γίνει με -std=c++11

## Αλγόριθμος καλύτερου μονοπατιού

Προσπάθησα να χρησιμοποιήσω τον Α* αλλά υπήρξαν κάποια αρκετά προβλήματα, οπότε έβαλα για ευκολία το Manhattan Distance.

# Cords
κλάση με συντεταγμένες x,y. Επίσης, έχει γίνει overload του op=, op< και op==

# GameObject
Υπάρχει σε αυτό το enum gameObj με P,M,G (P=potter M=malfoy G=gem), κληρονομεί την Cords, και έχει επίσης υπερφορτωμένο τον op= και μία virtual method. Είναι pure virtual class.

# Player
Κληρονομεί το GameObject και έχει ως attribute gameObj id

# Gem
Κληρονομεί το GameObject, έχει και αυτή το gameObjId και ακόμα κρατάει σε ένα attribute της τους γύρους που έχει ακόμα έτσι ώστε να αλλάξει θέσει. Κάνει overload τον op-= για να μειώνει τους γύρους.

# PlayerAI
Κληρωνομεί τον player. Έχει ως attribute έναν pointer του χάρτη, της συντεταγμένες του στόχου goal (για της οποίες πάντα ελέγχει αν έχουν αλλάξει) και την κίνηση move που επέλεξε να κάνει από τον πίνακα moves.

- η findClosestCell υπολογίζει και εκχωρεί τιμή στην move
- η returnMove επιστρέφει της συντεταγμένες κίνησης απο την θέση που βρίσκεται, δηλαδή :
    - (-1, 0) -> north
    - ( 1, 0) -> south
    - ( 0, 1) -> east
    - ( 0,-1) -> west
    - ( 0, 0) -> no available moves
- η isValid δίνοντάς της συντεταγμένες, επιστρέφει αν είναι εντός των ορίων του πίνακα ή όχι
- η isUnBlocked επιστρέφει true αν δεν υπάρχει άλλος παίχτεις σε αυτές τις συντεταγμένες, ούτε αν είναι τοίχος.
- calculateMD υπολογίζει τον Manhatta Distance


# Map

- char **map: αποθηκεύει τον χάρτη όπως τον διάβασε από το αρχείο.
- string path: αποθηκεύει το path για να διαβάσει τον χάρτη
- int rows,cols: αποθηκεύει το μέγεθος του πίνακα.
- list<GameObject *> locations: αποθηκεύει όλα τα GameObject (Gem,Player,PlayerAI)
- η μέθοδος setMap είναι protected γιατί θα πρέπει πρώτα να έχει γίνει set των newRows/newCols για το μέγεθος
- η display() εμφανίζει τον χάρτη και τα αντικείμενα στο std::cout (δεν χρησιμεύει κάπου)
- op+= προσθέτει στην list<GameObject *> locations ένα GameObject
- setCordsOf: δέχεται ως όρισμα την διεύθυνση του GameObject και τις συντεταγμένες που θέλει να τοποθετηθεί. Αν υπάρχει εμπόδιο ή άλλο GameObject εκτός του Gem επιστρέφει false.
- loadMap(): φορτώνει τον χάρτη από το αρχείο path, αν δεν υπάρχει επιστρέφει false

# GameEngine / GameManager

- Έχει ως attributes το Gem, τον PlayerAI, τον Player και το Map
- randomPosition(GameObject *): τοποθετεί το GameObject σε τυχαίο position
- initPositions: καλεί την randomPosition για κάθε GameObject και καλεί την setGemRounds για να αρχικοποιήσει την θέση του Gem πόσους γύρους θα κρατήσει
- gemFound(): αν βρεθεί κάποιο GameObject που δεν είναι το Gem να έχει τις ίδιες συντεταγμένες με το Gem τότε επιστρέφει την διεύθυνση του GameObject αλλιώς nullptr
- run: κάνει την εκκίνηση του παιχνιδιού δίνοντας του ένα char* το οποίο είναι το αρχείο που περιέχει τον χάρτη
- initScreen: κάνει τα βασικά πράγματα για το ncurses (π.χ. initsrc, keypad, θέτει colors) και τέλος καλεί την displayScreen
- displayScreen: εμφανίζει τον χάρτη με τους παίκτες και τα σωστά χρώματα
