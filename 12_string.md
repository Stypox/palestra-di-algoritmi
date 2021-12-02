# string

Nei precedenti tutorial è già stato usato il tipo `string` per contenere una sequenza di caratteri.
- Sul tipo `string` sono disponibili tutti gli operatori che ci sono anche sul vettore, quindi ad esempio `stringa[x]` per accedere all'`x`-esimo carattere, `stringa.size()` per ottenere la lunghezza di una stringa, ... 
- Si può inizializzare una variabile di tipo `string` anche a partire da uno *string literal*, ovvero da una stringa di C: `string nomeVariabile = "Hello world";`
- `stringa1 + stringa2` concatena due stringhe. Funziona anche l'operatore `+=`. (ad es. `string("Ciao") + string(" ") + string("mondo")` fa `string("Ciao mondo")`)
- Si può usare `stringa1 == stringa2` per vedere se due stringhe sono uguali. Anche `<`, `<=`, `>`, `>=` funzionano, e confrontano *lessicograficamente* due stringhe (ovvero nello stesso modo in cui farebbe un dizionario di una qualche lingua)
- Attenzione che una stringa di C **non equivale** ad una di C++, quindi `string("a") + string("b")` fa `string("ab")`, mentre `"a" + "b"` non ha significato in quanto è la somma tra due puntatori a `char`. Nel dubbio potete sempre mettere `string()` attorno ad ogni stringa di C per essere sicuri che non succedano cose strane.
- Anche per `string` può essere costoso creare una copia ogni volta che ne viene passata una ad una funzione. Come per `vector`, basta mettere una `&` dopo `string` nei parametri della funzione per prevenire la copia. Ad esempio `void modifica(string& stringa)`.

```cpp
string a = "albero";
string b = "casa";

// scrive 6 4 - 1 1 0 0 0
cout << a.size() << " " << b.size() << " - "
	<< (a < b) << " " << (a <= b) << " " << (a == b)
	<< " " << (a >= b) << " " << (a > b) << endl;

a = string(5, 'a'); // carattere 'a' ripetuto 5 volte
b.clear();
b.resize(5, 'a');

// scrive 5 5 - 0 1 1 1 0
cout << a.size() << " " << b.size() << " - "
	<< (a < b) << " " << (a <= b) << " " << (a == b)
	<< " " << (a >= b) << " " << (a > b) << endl;
```

#### Esercizi
- Scrivi un programma che legge due stringhe dall'utente e scrive le seguenti frasi in base alla posizione reciproca tra di esse: maggiore, maggiore o uguale, minore, minore o uguale, uguale.
- Scrivi un programma che, letta una stringa dall'utente, verifichi che la prima lettera sia maiuscola.
- Scrivi un programma che, letta una stringa dall'utente, ne converta tutte le lettere minuscole in maiuscole e poi la riscriva in output.

## Sottostringhe

Se si vuole estrarre un pezzo di stringa dall'interno di una stringa si può usare `stringa.substr(INIZIO, LUNGHEZZA)`, dove `INIZIO` è il primo carattere da mettere nella nuova stringa e `LUNGHEZZA` è il numero totale di caratteri da prendere. Se si omette la lunghezza vendono presi tutti i caratteri fino alla fine della stringa. Ad esempio `string("Hello world").substr(1, 5)` fa `string("ello ")`, mentre `string("Hello world").substr(6)` fa `string("world")`.

```cpp
string s = "Test abcd";
cout << s.substr(0, 4) << endl; // scrive test
cout << s.substr(5, 3) << endl; // scrive abc
cout << s.substr(5) << endl; // scrive abcd
cout << s.substr(6, 0) << endl; // scrive una linea vuota

string s2 = s.substr(2, 5);
cout << s << " -> " << s2 << endl; // scrive Test abcd -> st ab
```

#### Esercizi
- Scrivi un programma che presa in input una stringa `S` e un numero `K`, scriva in output tutte le sottostringe possibili di `S` che hanno lunghezza `K`.
- Scrivi un programma che presa in input una stringa di lunghezza pari, la divida a metà e scriva in output le due metà separatamente.

## Ricerca

`stringa.find(STRINGA)` restituisce il primo indice in `stringa` in cui è presente la sottostringa `STRINGA`. Nel caso `STRINGA` non sia mai presente in `stringa` verrà ritornato il numero speciale `string::npos`. Ad esempio `string("mondo ciao ciao").find("ciao")` restituisce `6`, ovvero la posizione del primo "ciao". Invece `string("test").find("ciao")` restituisce `string::npos`.

```cpp
string a = "una bella bella stringa";
cout << a.find("una") << endl; // scrive 0
cout << a.find("str") << endl; // scrive 16
cout << a.find(" ") << endl; // scrive 3
cout << a.find("bella") << endl; // scrive 4
cout << a.substr(5).find("bella") << endl; // scrive 5

cout << a.find("ciao") << endl; // scrive un numero molto grande, ovvero string::npos
cout << (a.find("ciao") == string::npos) << endl; // scrive 1
cout << (a.find("stringa") == string::npos) << endl; // scrive 0
```

#### Esercizi
- Scrivi un programma che chiede all'utente una stringa che contiene al più una virgola, e se tale stringa contiene una virgola la taglia in quel punto e scrive in output separatamente la parte di sinistra e la parte di destra.
- (difficile) Scrivi una funzione che prende come parametro due stringhe (attento a passarle *per reference*, così non vengono copiate) restituisce un `vector<string>` contenendo i pezzi della prima stringa che si ottengono spezzandola nei punti in cui è uguale alla seconda. Ad esempio `funzione("ah ciao albero ciao", "ia")` dovrebbe restituire gli elementi `string("ah c")`, `string("o albero c")`, `string("o")`.


## Problemi

- Kattis: [autori](https://open.kattis.com/contests/wg4y5t/problems/autori), [filip](https://open.kattis.com/problems/filip)