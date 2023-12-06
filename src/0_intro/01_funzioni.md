# Le funzioni

Immaginate se un architetto, nel momento in cui gli viene chiesto di costruire una casa, dovesse fare tutto da solo: progettare, comprare i materiali, costruire la struttura, fare l'impianto elettrico, ... Probabilmente impazzirebbe dopo poco, perchè è difficile saper fare bene tutti quei lavori tenendo tutto sotto controllo. Le aziende edili hanno infatti una gerarchia: l'architetto progetta, sulla base del progetto gli operai costruiscono l'edificio, poi arriva l'elettricista, ...

Anche quando si scrive un programma conviene separare le varie funzionalità in diversi "sottoprogrammi" chiamati dal "programma" principale quando serve. Questo rende il codice più leggibile, chiaro e testabile (un esame che verifica che una persona sappia fare il costruttore di case a tuttotondo sarebbe molto più difficile da scrivere di tanti esami più piccoli per le varie mansioni, come operaio o elettricista). Vediamo quindi come ottenere questo risultato con le funzioni di C++.

## Sintassi

Quando un architetto viene *chiamato* dall'azienda edile gli vengono fornite varie informazioni su ciò che deve progettare, e lui dopo aver svolto il suo lavoro *restituisce* all'azienda il progetto che ha prodotto. Una funzione di un programma funziona nello stesso modo: viene chiamata con una lista di parametri e (di solito) restituisce un risultato. Nell'esempio qui sotto la funzione `somma` riceve due parametri interi, `x` e `y`, e ne restituisce la somma, un'altro intero, grazie all'istruzione `return`. La funzione viene scritta all'esterno del `main`, e viene poi chiamata nel `main` utilizzando le parentesi tonde e mettendo al loro interno i due valori da assegnare ai parametri `x` e `y`, in questo caso `7` e `10`.

```cpp
int somma(int x, int y) {
	int risultato = x + y;
	return risultato;
}

int main() {
	// scrive "La somma e' 17"
	cout << "La somma e': " << somma(7, 10) << endl;
}
```

In generale, quindi, la sintassi è la seguente. Ci possono essere più `return` (ad esempio all'interno di un if) e, nel momento in cui viene incontrato un `return` l'esecuzione della funzione termina immediatamente e ritorna il valore specificato al chiamante.

```cpp
tipo_di_ritorno nome_funzione(tipo_parametro_1 nome_parametro_1, tipo_parametro_2 nome_parametro_2, ...) {
	// calcola tutto ciò che serve basandosi sui parametri
	return /* ... */;
}
```

#### Esercizi
- Scrivi una funzione che moltiplica due numeri decimali (`float`) e restituisce il risultato.
- Scrivi una funzione che, dati due interi, ritorna il massimo tra i due.
- Scrivi una funzione `f` che prende in input un numero decimale `x` e ritorna `x²+1`.


## Procedure

Quando una funzione non "restituisce" nulla, essa è detta essere una procedura. La sintassi è uguale a quella vista qui sopra, eccetto per il tipo di ritorno, che in questo caso sarà `void`, ovvero "nulla". 

```cpp
void saluta(int numeroDiVolte) {
	for(int i = 0; i < numeroDiVolte; ++i) {
		cout << "Ciao!" << endl;
	}
}
```

Ovviamente una funzione può ricevere 0 parametri, ad esempio:

```cpp
void errore() {
	cout << "C'e' stato un errore" << endl;
}
```

Se si vuole uscire da una procedura prima della fine (ad esempio all'interno di un `if`) si può usare `return;` senza nessun valore di ritorno.

#### Esercizi
- Scrivi una procedura che, presa la lunghezza del lato come parametro, disegni sul terminale un quadrato di quella dimensione.
- Scrivi una funzione che chiede all'utente un numero decimale e lo resituisce al *chiamante*.
- Scrivi una funzione che prende in input l'età di una persona e scrive `"Contenuto riservato"` quando l'età è `<18`. In particolare, metti un `if` in cima alla funzione che `return;`a preventivamente nel caso l'età sia `>=18`.


## Ricorsione

Una funzione può essere chiamata anche dentro sè stessa. Ad esempio, proviamo a scrivere una funzione che calcola l'`n`-esimo numero di Fibonacci. Matematicamente, la sequenza di Fibonacci è definita *ricorsivamente* nel seguente modo:
- `f`<sub><code>0</code></sub>` = 0`
- `f`<sub><code>1</code></sub>` = 1`
- `f`<sub><code>n</code></sub>` = f`<sub><code>n-1</code></sub>` + f`<sub><code>n-2</code></sub>

Queste tre semplici regole generano la nota sequenza 0, 1, 1, 2, 3, 5, 8, 13, ..., dove ogni termine è la somma dei due precedenti. La funzione da scrivere è quindi:

```cpp
int fibonacci(int n) {
	if (n == 0) {
		// questo corrisponde a `f_0 = 0`
		return 0;
	}
	
	if (n == 1) {
		// questo corrisponde a `f_1 = 1`
		return 1;
	}

	// questo corrisponde a `f_n = f_n-1 + f_n-2`
	return fibonacci(n-1) + fibonacci(n-2);
}
```

Le funzioni che chiamano sè stesse dentro il loro codice sono dette *ricorsive*. Nello scrivere queste funzioni bisogna stare attenti a non dimenticare i *casi base*. In questo caso i casi base sono quelli in cui `n == 0` o `n == 1`. Se ci fossimo dimenticati di controllarli la funzione avrebbe continuato a chiamare sè stessa all'infinito.

#### Esercizi
- Scrivi una funzione che, preso come parametro `n`, calcola la somma dei primi `n` numeri naturali usando la ricorsione (e senza usare cicli).
- Scrivi una funzione `gcd` che, presi in input due interi `a` e `b` (puoi assumere `a >= b`), calcola il loro massimo comune divisore (Greatest Common Divisor). La formula ricorsiva per calcolare il `gcd` tra due numeri è:
	- `gcd(a, 0) = a`, ovvero, se il secondo parametro passato alla funzione è 0, allora la funzione deve ritornare il primo
	- `gcd(a, b) = gcd(b, a mod b)`, ovvero, se la condizione sopra non è soddisfatta, il massimo comune divisore tra `a` e `b` è uguale al massimo comune divisore tra `b` e il resto della divisione di `a` per `b`


## Problemi

- Kattis: [temperatureconfusion](https://open.kattis.com/problems/temperatureconfusion) (usa il GCD)
