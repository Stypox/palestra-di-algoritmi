# vector

I vettori in C++ sono dei contenitori (*container*) che si comportano in modo simile agli array, ma che hanno dimensione dinamica e possono essere ridimensionati. Per creare un vettore contenente elementi di tipo `TIPO` si scrive `vector<TIPO>`.

## Inizializzazione

L'inizializzazione di una variabile di tipo `vector` si può fare nei seguenti modi (attenzione alle parentesi usate!):
- `vector<TIPO> nomeVariabile;` crea un vettore vuoto di elementi di tipo `TIPO` (ad es. `vector<float> valori`)
- `vector<TIPO> nomeVariabile(DIMENSIONE, VALORE);` crea un vettore con al suo interno il numero `DIMENSIONE` di elementi di tipo `TIPO` inizializzati al valore `VALORE` (ad es. `vector<int> classifica(158, 1)`)
- `vector<TIPO> nomeVariabile{ELEMENTO_1, ELEMENTO_2, ...};` crea un vettore di tipo `TIPO` contenente gli elementi `ELEMENTO_1`, `ELEMENTO_2`, ... (ad es. `vector<string> nomi{"Alessio", "Fabio", "Teodora"}`)

## Accesso

Per accedere agli elementi di un `vector` ci sono i seguenti modi:
- `v[posizione]` si usa per accedere all'elemento in posizione `posizione-1`, poichè gli indici partono da `0` (funziona come per gli array normali, ad es. `v[0]` restituisce il primo elemento)
- `v.front()` si usa per accedere al primo elemento
- `v.back()` si usa per accedere all'ultimo elemento

## Aggiunta di elementi e ridimensionamento

- `v.push_back(ELEMENTO)` aggiunge `ELEMENTO` in fondo al vettore (ad es. `v.push_back(42.0)`)
- `v.resize(NUOVA_DIMENSIONE, VALORE)` ridimensiona il vettore così che abbia `NUOVA_DIMENSIONE` elementi. Se `NUOVA_DIMENSIONE` è maggiore della dimensione che aveva precedentemente, i nuovi elementi vengono inizializzati col valore `VALORE`. (ad es. `v.resize(1000, 0)`)
- `v.pop_back()` rimuove l'ultimo elemento del vettore
- `v.size()` restituisce la dimensione dell'array 
