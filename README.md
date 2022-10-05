# ft-philosophers
![norminette](https://github.com/andersonhsporto/ft-philosophers/workflows/norminette/badge.svg)

&emsp;Implementação de conceitos básicos de threads e mutex. <br>
ft-philosophers utiliza como base o "problema [Jantar dos filósofos](https://blog.pantuza.com/artigos/o-jantar-dos-filosofos-problema-de-sincronizacao-em-sistemas-operacionais)", originalmente formulado por Edsger Dijkstra.

### Funções permitidas:

```
memset, printf, malloc, free, write, usleep, gettimeofday, 
pthread_create, pthread_detach, pthread_join, pthread_mutex_init, 
pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
```


### Descriçao do problema:

> Cinco filósofos estão sentados em uma mesa redonda para jantar. <br>
> Cada filósofo tem um prato com espaguete à sua frente. <br>
> Cada prato possui um garfo para pegar o espaguete. <br>
> O espaguete está muito escorregadio e, para que um filósofo consiga comer, será necessário utilizar dois garfos. <br>
> Nesse sentido, cada filósofo alterna entre duas tarefas: comer ou pensar. <br>
> Quando um filósofo fica com fome, ele tenta pegar os garfos à sua esquerda e à sua direita; <br>
> um de cada vez, independente da ordem. <br>
> Caso ele consiga pegar dois garfos, ele come durante um determinado tempo e depois recoloca os garfos na mesa. <br>
> Em seguida ele volta a pensar.<br>

#### Argumentos:
O programa recebe os seguintes argumentos:

| Argumento          | Descrição                              |
| :-----------------:| :----------------------------------:   |
| number_of_philosophers                         | Número de filósofos e de garfos. |
| time_to_die                                    | O tempo (em milissegundos) desde o início da última refeição ou o início da simulação, após o qual um filósofo morrerá de fome. |
| time_to_eat                                    | O tempo (em milissegundos) em que filósofo leva para comer. Durante esse tempo, eles precisam segurar dois garfos. |
| time_to_sleep                                  | O tempo que um filósofo passará dormindo. |
| number_of_times_each_philosopher_must_eat      | Este argumento é opcional. Se todos os filósofos comerem pelo menos "number_of_times_each_philosopher_must_eat" vezes, a simulação para. Se não for especificado, a simulação para quando um filósofo morre. |


## Como executar:
Compile o programa através do Makefile usando o comando ```$ make``` na raiz do repósitorio

Exemplo:
```
$ ./philo 4 410 200 200
```
<img src="https://github.com/andersonhsporto/ft-philosophers/blob/main/img/1.png" 
     width="600" 
     height="500" />
     
## REFERÊNCIAS
[Jantar dos filosofos -](https://blog.pantuza.com/artigos/o-jantar-dos-filosofos-problema-de-sincronizacao-em-sistemas-operacionais) Problema de sincronização em Sistemas Operacionais

[Code Vault: Playlist: Unix Threads in C -](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) Video 1 (Short introduction to threads) - Video 7 (How to pass arguments to threads in C)

[Jacob Sorber: Playlist: Programming with Threads -](https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM) Video 1 (How to create and join threads in C) - Video 3 (Safety and Speed Issues with Threads)
