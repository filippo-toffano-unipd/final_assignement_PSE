FINAL ASSIGNEMENT PSE CORSE

=====================================================================================================================================================

##  Introduzione:


Lo scopo dell'assegnamento è simulare un sistema di 2 linee di trasporto pezzi costitutite ognuna da:
    - 1 sistema di visione che rileva la presenza di un pezzo nel conveyor, la sua tipologia, la sua posizione e l'istante di rilevazione;
    - 1 cobot che preleva il pezzo alla fine del conveyor e porlo in una scatola di capacità 10pz;

Una volta che la scatola sarà piena verrà risvegliato un sistema AGV che avrà il compito di prelevare la scatola e porla in magazzino.

## Setup

Per prima cosa è necessario scaricare la repository.
Per fare ciò basta copiare il link di questa repo (contenuto in alto a destra nella casella 'Code') e clonarla 
in un ambiente LINUX usando il comando:

```bash
git clone (link copiato)
```

## Compilazione del programma:

Per compilare ed eseguire poi il programma è necessario:
    - creare una cartella `build` nel percorso principale (si può utilizzare il comando `mkdir build`);
    - entrare nella cartella 'build' 
    - eseguire il seguente comando 

```bash
cmake .. && make && ./app/application lunghezza_lineaA velocità_lineaA lunghezza_lineaB velocità_lineaB
```

Al posto dei parametri di lunghezza e velocità delle 2 linee, inserire dei valori INTERI. 


*NOTA: nella `lib global_variables` è impostabile uno Scale Factor (SF) per poter accelerrare o rallentare l'esecuzione della simulazione*  
=====================================================================================================================================================
