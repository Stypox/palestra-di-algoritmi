# Trucchetti

## freopen

TODO

## vector

- Se ti piace la sintassi di Python per accedere ai vettori partendo dal fondo, ovvero ad esempio `v[-2]` per leggere il penultimo elemento, in C++ puoi fare `v.end()[-1]` per ottenere lo stesso risultato.
- Se vuoi che durante l'esecuzione il programma crashi sicuramente se accedi ad un elemento di un vettore in una posizione non valida puoi usare `v.at(5)`. Se il vettore ha almeno dimensione `6` allora fa la stessa identica cosa di `v[5]`, mentre se non è così viene lanciata un'eccezione.
