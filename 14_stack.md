# stack

Le pile sono dei *container* che funzionano in modo simile alle pile di piatti al ristorante: quando dei piatti vengono lavati vengono messi in cima alla pila; quando invece serve un piatto questo viene preso sempre da in cima alla pila e usato. Le operazioni supportate sono quindi quelle per aggiungere in cima e per togliere dalla cima. In C++ si può creare una pila di tipo `TIPO` usando `stack<TIPO>`, ad esempio `stack<string>`. Le `queue` supportano le seguenti operazioni:
- `q.push(ELEMENTO)` per aggiungere `ELEMENTO` (di tipo `TIPO`) in fondo alla coda
- `q.front()` per leggere l'elemento in cima alla coda
- `q.pop()` per rimuovere l'elemento in cima alla coda
- `q.size()` restituisce il numero di elementi in coda

```cpp
queue<int> q;
q.push(5);
q.push(6);
q.push(7);

// scrive 3 5
cout << q.size() << " " << q.front() << endl;

q.pop();
// scrive 2 6
cout << q.size() << " " << q.front() << endl;
```
