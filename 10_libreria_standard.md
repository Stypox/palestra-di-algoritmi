# La libreria standard

C++ è fornito di una libreria standard che permette di fare molte cose senza dover scrivere grandi quantità di codice. Come già visto, in cima ai programmi di programmazione competitiva si trovano spesso queste due linee di codice:
- `#include <bits/stdc++.h>` serve per rendere utilizzabili da quel punto in poi tutte le funzionalità della libreria standard di C++ (mettendo però `std::` ogni volta che si vuole usare qualcosa, ad esempio `std::cout<<"Hello world"<<std::endl;`)
- `using namespace std;` fa in modo che si possa accedere alle funzionalità della libreria standard senza mettere `std::` davanti ad ogni cosa (permette quindi di scrivere semplicemente `cout<<"Hello world"<<endl;`)

Quando vi serve qualcosa dalla libreria standard ma non vi ricordate come si chiama o come si usa vi consiglio di consultare [CppReference](https://en.cppreference.com/w/), una *wiki* di C++ che avrete a disposizione anche in gara.

## Funzioni comuni

- `min`, `max`: prendono come parametri due numeri e ne ritornano, rispettivamente, il minimo o il massimo. **Attenzione**: i due numeri devono avere lo stesso *tipo* (si possono quindi passare due `int` o due `float`, ma non un `int` e un `long long`)! (es. `min(6, -7)` fa `-7`)
- `abs`: calcola il valore assoluto di un numero (es. `abs(-5)` fa `5`)
- `sqrt`: calcola la radice quadrata di un numero (es. `sqrt(2)` fa `1.414...`)
- `pow`: calcola la potenza di un numero, dando in risultato un numero *decimale* (es. `sqrt(5, 3)` fa `125.0`)
- `log`, `log10`, `log2`: calcolano il logaritmo di un numeri, rispettivamente in base `e`, `10` e `2` (es. `log10(1000)` fa `3`)
- `sin`, `cos`, `tan`, `asin`, `acos`, `atan`: fanno quello che ci si aspetterebbe. Gli angoli sono da considerarsi in radianti. (es. `cos(0)` fa `1`)
- `hypot` calcola la radice quadrata della somma dei quadrati di due numeri. Può essere utile per trovare la distanza tra due punti. (es. `hypot(3, 4)` fa `5.0` (terna pitagorica 3,4,5))

#### Esercizi
- Scrivi un programma che, date le lunghezze di due cateti di un triangolo rettangolo, ne calcola l'ipotenusa e i tre angoli.
- Scrivi un programma che, chiesti all'utente due numeri, ne calcola il minimo, il massimo e la media geometrica.

## Tipi comuni

Se si vogliono usare degli interi di una specifica dimensione (ad esempio perchè si ha bisogno di rappresentare numeri grandi, oppure perchè si hanno limitazioni di memoria e quindi si vuole ridurre al massimo la dimensione occupata da numeri piccoli) ci sono `int8_t`, `int16_t`, `int32_t`, `int64_t`: la loro dimensione è, rispettivamente, di 8, 16, 32 oppure 64 bit. Nel caso si volessero usare degli interi senza segno esistono anche `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`.

## Costanti comuni

`numeric_limits<TIPO>::min()` e `numeric_limits<TIPO>::max()` dicono, rispettivamente, il minimo e il massimo valore rappresentabile in una variabile con il tipo numerico `TIPO` (es. `numeric_limits<int>::max()` di solito fa `2147483647`, ovvero `2^31-1`, dato che `int` di solito ha 32 bit). Può essere utile usarli quando si vuole calcolare il minimo/massimo degli elementi di un array di tipo `TIPO`: si scorre l'array e ci si tiene salvato in una variabile il minimo/massimo trovato finora. Il valore iniziale da assegnare a tale variabile per assicurarsi che questo algoritmo funzioni sempre è `numeric_limits<TIPO>::max()`/`numeric_limits<TIPO>::min()` (notare lo scambio tra `min` e `max`). Ad esempio:

```cpp
// sul mio computer scrive -2147483648 3.40282e+38
cout << numeric_limits<int>::min() << " " << numeric_limits<float>::max() << "\n";

int64_t minimoFinora = numeric_limits<int64_t>::max();
for (int i = 0; i < 10; ++i) {
	// scrive Inserisci un numero (al minimo -9223372036854775808 e al massimo 9223372036854775807):
	cout << "Inserisci un numero (al minimo " << numeric_limits<int64_t>::min()
		<< " e al massimo " << numeric_limits<int64_t>::max() << "): ";
	int64_t numero;
	cin >> numero;
	minimoFinora = min(minimoFinora, numero);
}
cout << "Il minimo tra i 10 numeri che hai inserito e' " << minimoFinora << "\n";
```

#### Esercizi
- Scrivi un programma che scrive il minimo e il massimo valore contenibile in tutti i tipi di cui si è parlato finora, sia segnati che non, ma anche decimali, booleani, char, ... Noterai che `numeric_limits` non si può applicare a `string`, perchè è un tipo non numerico. Noterai anche che il massimo e il minimo dei tipi segnati sono sempre, rispettivamente, `2^(BIT-1)-1` e `-2^(BIT-1)`, dove `BIT` è il numero di bit di tale tipo. Questo perchè in totale ci sono `BIT` bit, quindi `2^BIT` numeri possibili, ma metà (`2^(BIT-1)`) vanno sotto lo zero, poi c'è lo zero (`1` valore occupato), e i restanti (`2^(BIT-1)-1`) vanno sopra lo zero.
- Scrivi un programma che chiede all'utente tanti numeri con segno, di al massimo 16 bit, e che calcola il massimo e la media tra tutti loro (attenzione: per calcolare la media ti serve tenere da parte la somma di tutti i numeri inseriti finora: ti conviene quindi usare un intero con più di 16 bit per evitare *overflow*).

## pair

`pair` può essere usato per creare una variabile che tiene al suo interno due oggetti. Ad esempio `pair<int, int>` è una coppia di interi, mentre `pair<string, float>` rappresenta una stringa e un numero decimale.
- Per creare una variabile di tipo `pair<A, B>` si tratta `pair<A, B>` come se fosse un *tipo* normale (ad es. `int`): si scriverà quindi `pair<A, B> nomeVariabile;`. Se si volessero inizializzare i due valori contenuti nel paio al momento della dichiarazione si può anche fare `pair<A, B> nomeVariabile(valoreDiTipoA, valoreDiTipoB)`.
- Per accedere ai due elementi contenuti in un paio si scrive `nomeVariabile.first` e `nomeVariabile.second`.

```cpp
pair<string, int> coppia("Ciao", 6);
coppia.second = 7;
// scrive Ciao 7
cout << coppia.first << " " << coppia.second << "\n";
```

#### Esercizi
- Leggi dall'utente quattro numeri decimali (`x1`, `y1`, `x2`, `y2`), e salvali in due variabili di tipo `pair<float, float>` che rappresentano i punti `(x1,y1)` e `(x2,y2)`. Crea una funzione che dati in input due punti `pair<float, float>`, ne calcoli la distanza.

## Problemi

- Kattis: [artichoke](https://open.kattis.com/problems/artichoke), [different](https://open.kattis.com/problems/different)