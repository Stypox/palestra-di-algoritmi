# stack

Le pile sono dei *container* che funzionano in modo simile alle pile di piatti al ristorante: quando dei piatti vengono lavati vengono messi in cima alla pila; quando invece serve un piatto questo viene preso sempre da in cima alla pila e usato. Le operazioni supportate sono quindi quelle per aggiungere in cima e per togliere dalla cima. In C++ si può creare una pila di tipo `TIPO` usando `stack<TIPO>`, ad esempio `stack<string>`. Gli `stack` supportano le seguenti operazioni:
- `s.push(ELEMENTO)` per aggiungere `ELEMENTO` (di tipo `TIPO`) in cima alla pila
- `s.top()` per leggere l'elemento in cima alla pila
- `s.pop()` per rimuovere l'elemento in cima alla pila
- `s.size()` restituisce il numero di elementi nella pila

```cpp
stack<int> s;
s.push(5);
s.push(6);
s.push(7);

// scrive 3 7
cout << s.size() << " " << s.top() << endl;

s.pop();
// scrive 2 6
cout << s.size() << " " << s.top() << endl;
```

## Problemi

- Kattis: [pairingsocks](https://open.kattis.com/contests/wg4y5t/problems/pairingsocks), [backspace](https://open.kattis.com/contests/wg4y5t/problems/backspace)
