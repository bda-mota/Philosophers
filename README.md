# Philosophers 

Este projeto recria o clássico "Problema dos Filósofos Comilões" utilizando threads e mutexes. O objetivo é simular a sincronização e concorrência entre múltiplos filósofos que precisam compartilhar recursos limitados (garfos) para comer, pensar e dormir.

"X filósofos estão sentados em uma mesa redonda com tigelas de comida. Há um garfo colocado na frente de cada filósofo, e o número de garfos é igual ao número de filósofos. Durante todo o dia, os filósofos se revezam entre comer, dormir e pensar. Para comer, um filósofo precisa de dois garfos, e cada garfo pode ser usado por apenas um filósofo de cada vez. A qualquer momento, um filósofo pode pegar ou colocar um garfo, mas não pode começar a comer até ter ambos os garfos. Os filósofos alternam entre comer, dormir ou pensar. Enquanto estão comendo, não estão pensando nem dormindo; enquanto estão pensando, não estão comendo nem dormindo; e, claro, enquanto estão dormindo, não estão comendo nem pensando."

Vale ressaltar que o tempo para morrer (se não comer) deve ser maior do que o tempo para comer e dormir. Caso contrário, um filósofo morrerá(ex: 4 380 200 200 2). Se todas as condições forem atendidas(ex: 4 410 200 200) e não se tenha atribuído a quantidade de refeições, para finalizar o programa a execução deverá ser interrompida, pois nenhum filósofo morrerá.

## Como Clonar o Repositório

Para clonar este repositório, utilize o seguinte comando:

```bash
git clone https://github.com/bda-mota/Philosophers.git
```

## Como Compilar o Projeto
Navegue até o diretório do projeto:

```bash
cd philo
make
```
Isso irá gerar o executável ./philo.

Nota: Certifique-se de que você tenha o make e um compilador C (como gcc) instalados em seu sistema. O Makefile está configurado para compilar o código-fonte do projeto e criar o executável necessário.
Como Executar o Programa
Após a compilação, você pode executar o programa com os seguintes argumentos:

```bash
./philo nbr_philo time_to_die time_to_eat time_to_sleep nbr_of_meals
```
### Argumentos

nbr_philo: Número de filósofos.

time_to_die: Tempo em que um filósofo pode sobreviver sem comer antes de morrer.

time_to_eat: Tempo em que um filósofo leva para comer.

time_to_sleep: Tempo em milissegundos que um filósofo leva para dormir.

nbr_of_meals (opcional): Número de refeições que cada filósofo deve fazer. Se não for fornecido, o programa continuará até que todos os filósofos morram ou o tempo de execução termine.
