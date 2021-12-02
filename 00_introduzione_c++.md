# Introduzione a C++

Il programma di base, qui di seguito, non fa niente. Scriveremo le istruzioni da far eseguire al computer *all'interno del main*, ovvero sotto `int main() {` e sopra `}`. Per il momento si può ignorare tutto il resto (ovvero `#include ...` e `using ...`) e semplicemente darlo per buono. Si possono inserire commenti nei programmi con `// ...` per i commenti su una singola riga, oppure con `/* ... */` per i commenti su multiple righe.
```cpp
#include <bits/stdc++.h>
using namespace std;

// questo e' un commento su una singola riga

/* questo commento 
occupa tante righe */

int main() {
	// il codice verra' scritto qui
}
```


## Scrivere a schermo

Si può usare l'istruzione `cout` per scrivere a schermo numeri e testo (si dice anche "scrivere o dare in output"). Si scrive `cout << ciò_che_si_vuole_scrivere`. Si possono scrivere più cose alla volta semplicemente aggiungendo `<< qualcos_altro`. Per inserire una nuova linea, usare `<< endl`. In C++ ogni istruzione deve avere `;` alla fine, come si vede qui sotto. Per indicare del testo nel programma (d'ora in poi verrà chiamato *stringa*) si usano le virgolette, ad esempio `"il mio testo"`. I numeri interi o decimali si scrivono normalmente (ad esempio, rispettivamente, `42` e `-17.6`).

```cpp
// scrive "Ciao mondo!" nella console e poi va a capo.
cout << "Ciao mondo!" << endl;

// scrive "Siamo nel 2021 e ci sono 19.5°C" nella console e poi va a capo
cout << "Siamo nel " << 2021 << " e ci sono " << 19.5 << "°C" << endl;
```

#### Esercizi
- Scrivi a schermo "Ciao mondo", a-capo tre volte, "crudele", a-capo
- Scrivi a schermo il tuo numero preferito.


## Le variabili

Le variabili servono per tenere salvati dei dati o dei passi parziali durante l'esecuzione del programma. Lo facciamo anche noi quando ad esempio vogliamo trovare le due soluzioni di un'equazione di secondo grado: prima calcoliamo il delta, lo scriviamo a parte e infine lo utilizziamo nella formula.  

Le variabili esistono solo dal momento in cui le dichiariamo, hanno un **tipo** e hanno un **nome** per identificarle. Il tipo può essere, per il momento
- intero: `int`
- decimale: `float`
- stringa `string`

```cpp
// variabile di tipo intero con nome x e valore 0
int x = 0;

// variabile di tipo intero con nome y e valore non impostato
int y;

// variabile di tipo decimale con nome temperatura e valore 19.5
float temperatura = 19.5;

// variabile di tipo stringa con nome divinaCommedia e come valore il primo verso della divina commedia
string divinaCommedia = "Nel mezzo del cammin di nostra vita...";

// si può usare cout anche con le variabili!
// dato che y non ha un valore impostato potrebbe venir scritto un numero a caso
cout << "x e' uguale a " << x << ", y e' uguale a " << y << " e la temperatura e' di " << temperatura << "°C" << endl;
cout << "La divina commedia inizia con: " << divinaCommedia << endl;
```

Il valore contenuto nelle variabili può essere cambiato durante l'esecuzione usando l'operatore `=`. Attenzione: `x = y` significa "assegna il valore della variabile y alla variabile x". **NON** significa che d'ora in poi la variabile x sarà *sempre* uguale a y!

```cpp
// si possono dichiarare piu' variabili sulla stessa riga
int x = 0, y = 5;

x = y; // <- x ora contiene il valore 5
y = -7; // <- y ora contiene il valore -7

// scrive a schermo "x = 5; y = -7;"
cout << "x = " << x << "; y = " << y << ";" << endl;
```

#### Esercizi
- Crea una variabile di un tipo a scelta, chiamala "variabile" e inizializzala con un valore a scelta. Scrivila in output, poi cambiala e scrivila in output di nuovo.


## Prendere in i**n**put una variabile dall'utente
###### Attenzione allo spelling di i**n**put ;-)

Per ricevere un input dall'utente un valore e salvarlo in una variabile si usa l'istruzione `cin >> nomevariabile`. Anche in questo caso si può scrivere `>>` più volte.

```cpp
cout << "Inserisci un numero intero: ";
int x; // <- qui e' stato omesso il valore iniziale di x, dato che sta per essere comunque sovrascritto
cin >> x; // leggi un intero nella variabile x

cout << "Inserisci una stringa: ";
string s;
cin >> s; // leggi una stringa nella variabile s

cout << "Hai inserito " << x << " e " << s << endl;
```

#### Esercizi
- Crea una variabile di tipo `float` e usala più di una volta per leggere un numero decimale dall'utente.


## Operazioni

Le operazioni matematiche di base sono disponibili:
- `x + y` somma
- `-x` opposto di x
- `x - y` differenza
- `x * y` moltiplicazione
- `x / y` divisione
- `x % y` resto della divisione di x per y

Si possono raggrupare le operazioni con le parentesi tonde `()`.

```cpp
int x = 5;
int y = x * x - x + 7;

cout << "x = " << x << "; x^2 - x + 7 = " << y << "; il resto della divisione di " << y << " per 6 e' " << y % 6;
```

Questo codice un po' più complicato risolve un'equazione di secondo grado:
```cpp
float a, b, c;
cout << "Inserisci tre numeri (possibilmente decimali) separati da spazi: ";
cin >> a >> b >> c; 

float delta = b * b - 4 * a * c;

// sqrt(valore) serve per calcolare la radice quadrata
float x1 = (-b + sqrt(delta)) / (2 * a);
float x2 = (-b - sqrt(delta)) / (2 * a);

cout << "L'equazione " << a << "x^2 + " << b << "x + " << c << " = 0 ha come soluzioni x1 = " << x1 << " e x2 = " << x2 << endl;
```

Alcune scorciatoie sono elencate qui di seguito:
- `x += y` equivale a `x = x + y`
- `x -= y` equivale a `x = x - y`
- `x *= y` equivale a `x = x * y`
- `x /= y` equivale a `x = x / y`
- `x %= y` equivale a `x = x % y`
- `++x` e `x++` equivalgono a `x = x + 1` ma:
  - `int y = ++x` -> y assume il valore di x dopo l'incremento
  - `int y = x++` -> y assume il valore di x prima dell'incremento 
- `--x` e `x--` equivalgono a `x = x - 1` e si comportano come `++x` e `x++


```cpp
int x = 6;
x += 7; // x ora vale 13
--x; // x ora vale 12
x %= 5; // x ora vale 2

float f = -5.2;
f /= -6.7; // f ora vale 0.776...

cout << "x = " << x << "; f = " << f << endl;
```

#### Esercizi
- Sperimenta con la divisione: cosa succede se i valori che dividi sono di tipo `int` e non sono divisibili fra loro? E se invece usi il tipo `float`?
- L'elevamento a potenza funziona come ti aspetteresti? Prova ad usare l'operatore `^`: vedrai che fa cose strane, ma sicuramente non eleva a potenza! Infatti `^` fa il *bitwise xor*; per elevare a potenza puoi scrivere `pow(base, esponente)` invece.
- Scrivi un programma che prende in input due numeri e scrive in output la loro somma, la loro differenza e il loro prodotto.


## Condizioni

Talvolta si vuole compiere una scelta e cambiare le operazioni da eseguire in base ad una condizione: ad esempio, se il delta risulta minore di zero in un'equazione di secondo grado si scrive che è impossibile invece di continuare la risoluzione. In C++ questo concetto si esprime con le istruzioni `if` ed `else`. La sintassi è:

```cpp
if (condizione) {
	// se la condizione e' vera viene eseguito questo codice
} else {
	// se la condizione e' falsa viene eseguito quest'altro codice
}
```

Le parentesi grafe possono essere omesse se si scrive una sola istruzione. Il blocco dell'`else` può essere omesso nel caso non si sia interessati ad eseguire del codice quando la condizione è falsa. Nel caso si vogliano controllare più condizioni si può mettere un altro `if` direttamente dopo l'`else`, in questo modo:

```cpp 
if (condizione1) {
	// ...
} else if (condizione2) {
	// ...
} else {
	// ...
}
```

Per scrivere le condizioni esistono le seguenti operazioni:
- `x <= y`, `x < y`, `x >= y`, `x > y` fanno ciò che ci si aspetterebbe
- `x == y` restituisce vero se `x` è uguale a `y`
- `x != y` restituisce vero se `x` è diverso da `y`
- `!a` restituisce l'opposto di `a`, quindi se `a` è vero `!a` è falso
- `a && b` restituisce vero solo quando sia `a` che `b` sono vere, altrimenti restituisce falso
- `a || b` restituisce vero quando almeno una tra `a` e `b` è vera, mentre se sia `a` che `b` sono false restituisce falso
- le parentesi `()` funzionano come con le altre operazioni

Esiste inoltre un tipo `bool` per le variabili, che può assumere solo i valori `true` e `false` e serve per tenere salvato il valore di una condizione, ovvero un valore di verità. I valori `bool` possono essere usati direttamente all'interno degli `if` al posto della condizione.

```cpp
cout << "Inserisci x e y separati da uno spazio: ";
float x, y;
cin >> x >> y;

// variabile di tipo bool per salvare il risultato di una condizione
bool xySonoUguali = x == y;
if (x < y) { // condizione tra le parentesi tonde
	cout << "x e' minore di y" << endl;
} else if (xySonoUguali) { // la condizione e' salvata nella variabile xySonoUguali
	cout << "x e' uguale a y" << endl;
} else {
	cout << "x e' maggiore di y" << endl;
}
```

#### Esercizi
- Secondo le *leggi di De Morgan* `!(a && b)` è la stessa cosa di `(!a) || (!b)`, e `!(a || b)` è la stessa cosa di `(!a) && (!b)`. Scrivi un programma che lo verifica.
- Il programma sopra che calcola gli zeri di un'equazione di secondo grado non è in grado di capire quando non ci sono soluzioni! Miglioralo affinchè si accorga quando il delta è minore di zero e dica all'utente che l'equazione è senza soluzione.
- Quando vuoi controllare se due variabili sono uguali all'interno di un `if`, stai attento ad usare l'operatore `==`! Prova a vedere cosa succede se usi `=` al suo posto (spoiler: se va bene errori di compilazione, se va male il programma fa cose diverse da quelle che ci si aspetta).


## Problemi

Ecco un elenco di problemi semplici presi da varie piattaforme per familiarizzare con C++:
- Olinfo: [easy1](https://training.olinfo.it/#/task/easy1/statement), [easy2](https://training.olinfo.it/#/task/easy2/statement), [easy3](https://training.olinfo.it/#/task/easy3/statement)
- Kattis: [cold](https://open.kattis.com/problems/cold), [qaly](https://open.kattis.com/problems/qaly)
