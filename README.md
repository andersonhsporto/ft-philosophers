# ft-philosophers

Um pequeno projeto para aprender os conceitos básicos de threads e mutex. <br>
Com base no "problema [Jantar dos filósofos](https://blog.pantuza.com/artigos/o-jantar-dos-filosofos-problema-de-sincronizacao-em-sistemas-operacionais)",
originalmente formulado por Edsger Dijkstra.

### Funções permitidas
memset, printf, malloc, free, write, usleep, gettimeofday, 
pthread_create, pthread_detach, pthread_join, pthread_mutex_init, 
pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

### Descriçao

> Cinco filósofos estão sentados em uma mesa redonda para jantar. <br>
> Cada filósofo tem um prato com espaguete à sua frente. <br>
> Cada prato possui um garfo para pegar o espaguete. <br>
> O espaguete está muito escorregadio e, para que um filósofo consiga comer, será necessário utilizar dois garfos. <br>
> Nesse sentido, cada filósofo alterna entre duas tarefas: comer ou pensar. <br>
> Quando um filósofo fica com fome, ele tenta pegar os garfos à sua esquerda e à sua direita; <br>
> um de cada vez, independente da ordem. <br>
> Caso ele consiga pegar dois garfos, ele come durante um determinado tempo e depois recoloca os garfos na mesa. <br>
> Em seguida ele volta a pensar.<br>

#### Argumentos 
O programa recebe os seguintes argumentos
```
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
* _number_of_philosophers_: O número de filosofos e de garfos.
* _time_to_die_: O tempo (em milissegundos) desde o início da última refeição ou o início da simulação, após o qual um filósofo morrerá de fome. 
* _time_to_eat_: O tempo (em milissegundos) em que filósofo leva para comer. Durante esse tempo, eles precisam segurar dois garfos.
* _time_to_sleep_: O tempo que um filósofo passará dormindo.
* _number_of_times_each_philosopher_must_eat_: Este argumento é opcional. Se todos os filósofos comerem pelo menos "number_of_times_each_philosopher_must_eat" vezes, a simulação para. Se não for especificado, a simulação para quando um filósofo morre.

## How to launch
Compile o programa através do Makefile usando o comando ```$ make``` na raiz do repósitorio

Execute assim:
```
$ ./philo 4 410 200 200
```
