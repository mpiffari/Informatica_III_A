Informatica III A - 🏫
======

<p align="center">
  <img width="500" height="460" src="/Documentazione%20progetto/Immagini//UniBg.png">
</p>

Applicazioni scritte durante il corso di [Informatica III A](https://cs.unibg.it/gargantini/didattica/info3/), tenuto dal professor [Angelo Gargantini](https://cs.unibg.it/gargantini/index.html)
presso l'Università degli Studi di Bergamo nell'anno accademico 2019/2020.

## Cyclone 🌀
Il progetto sviluppato è una piccola applicazione da inserire come black-box all'interno di un sistema più grande.
Nello specifico si è pesanto di andare ad inserire una funzionalità di ricerca e visualizzazione di una lista di 
cartoline nell'ambito di un sistema in grado di gestire spedizione e smistamento di esse.

L'applicazione consente di andare a parsare le informazioni relative ad un insieme di cartoline (composte da mittente, destinatario e luogo da cui è
stata inviata) contenute all'interno di un file .txt: questo file è pesanto come un insieme di cartoline relative ad un certo account, con il quale l'utenterisulta essere loggato sull'ipotetica piattaforma.
Una volta completato il parsing l'applicazione permette di scegliere secondo quale parametro andare a completare la ricerca:
- *BY SENDER* (ricerca per nome completo del mittente);
- *BY RECEIVER* (ricerca per nome completo del destinatario);
- *BY PLACE* (ricerca per nome completo del luogo da cui la cartolina è stat spedita);

Nello specifico è stata inizialmente realizzata la versione in C, su cui sono stati realizzati i vari test e bug fix.
Si è poi applicato un export manuale in ambiente Cyclone.
 per la crittografi􏰄a di stringhe utilizzando cifrari a sostituzione con chiavi decise dall'utente.

Oltre a questo sono anche state re-implementate in Cyclone alcune funzioni di supporto per le stringhe come strcpy e strncpy 
in maniera safe a differenza delle loro controparti in C.

## C++ 🔣
Per quanto riguarda invece la parte relativa a cpp è stata invece implementata una libreria utile per andare a gestire il calcolo matriciale:
nello specifico sono state realizzate alcune funzionalità di supporto quali
- *Somma* elemento per elemento;
- *Sottrazione* elemento per elemento;
- *Moltiplicazione* elemento per elemento;
- *Inizializzazione* di matrici come matrici identità (di default con dimensione 1x1, altrimenti con numero di *rows* e *columns* passato come parametro;
- Possibilità di applicare *trasformazioni* (functions) ad ogni elemento della matrice;
- Funzionalità di supporto alla *log* delle matrici;

Il tutto è stato realizzato secondo un pattern generico, con l'utilizzo dei *templates*.

<p align="center">
  <img src="/Documentazione%20progetto/Immagini/ClassDiagram.jpg">
</p>

## Scala
Il progetto realizzato in Scala si inserisce invece (come per quello che riguarda il progetto in ASMETA) nell'ambito della realizzazione
di un'area break presso l'università.
Nello specifico in Scala è stata progettata un insieme di funzionalità per gestire la distribuzione di bevande energetiche.

Nello specifico, sono state inserite queste principali funzionalità:
- Visualizzazione di informazioni relative ad un certo energy drink;
- Scelta di un prodotto che, nel caso di data di scadenza superata, verrà fornito liberamente all'utente;
- Possibilità di settare la lingua del distributore (introdotti solamente *ITA* e *ENG*): questo settaggio si rifletterà sulla ricerca dell'energy drink più adatto
tramite tag (dato che ad ogni tipologia di energy drink è associato un insieme di tag che ne definiscono le caratteristiche salienti).

## ASMETA 🤖
Nell'ambito ASMETA è stata invece realizzata una *coffee vending machine* da affiancare al distributore di energy drink progettato in Scala.

La macchina a stati realizzata e gestita è la seguente:

<p align="center">
  <img src="/Documentazione%20progetto/Immagini/FSM.png">
</p>

## Correzione prova 😎
Sono stati inseriti anche i codici sorgenti relativi allo svolgimento della prova di Febbrario 2020 (non si garantisce sulla correttezza e completezza delle soluzioni).

## License
[MIT](https://choosealicense.com/licenses/mit/)
