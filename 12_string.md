# string

Nei precedenti tutorial è già stato usato il tipo `string` per contenere una sequenza di caratteri.
- Sul tipo `string` sono disponibili tutti gli operatori che ci sono anche sul vettore, quindi ad esempio `stringa[x]` per accedere all'`x`-esimo carattere, `stringa.size()` per ottenere la lunghezza di una stringa, ... 
- Si può inizializzare una variabile di tipo `string` anche a partire da uno *string literal*, ovvero da una stringa di C: `string nomeVariabile = "Hello world";`
- `stringa1 + stringa2` concatena due stringhe. Funziona anche l'operatore `+=`. (ad es. `string("Ciao") + string(" ") + string("mondo")` fa `string("Ciao mondo")`)
- Si può usare `stringa1 == stringa2` per vedere se due stringhe sono uguali. Anche `<`, `<=`, `>`, `>=` funzionano, e confrontano *lessicograficamente* due stringhe (ovvero nello stesso modo in cui farebbe un dizionario di una qualche lingua)

## Sottostringhe

Se si vuole estrarre un pezzo di stringa dall'interno di una stringa si può usare `stringa.substr(INIZIO, LUNGHEZZA)`, dove `INIZIO` è il primo carattere da mettere nella nuova stringa e `LUNGHEZZA` è il numero totale di caratteri da prendere. Ad esempio `string("Hello world").substr(0, 5)` fa `string("Hello")`, mentre `string("Hello world").substr(6, 3)` fa `string("wor")`.

## Ricerca

Per trovare 