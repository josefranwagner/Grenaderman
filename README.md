# Grenaderman


Trabajo realizado durante la cursada de la materia Algoritmos I - Facultad de Ingeniería de la Universidad de Buenos Aires.


__Objetivo:__ Escribir tests unitarios que validen el correcto funcionamiento lógico del programa siguiendo las especificaciones técnicas y conceptuales que se detallan a continuación.


### Especificaciones conceptuales

#### Argumento

La Tierra ha sido invadida!! La terrible raza alienígena conocida como Murloc,
unos seres humanoides con características ícticas, ha llegado para quedarse!!

La tecnología murloc llegó a un nivel de desarrollo tal que les permitió crear
enormes máquinas con complejos sistemas de defensa para resistir el embate a la
Tierra lo máximo posible y lograr una conquista incuestionable.

En el otro lado del mundo, un hombre común recibió el impacto de un meteorito
de un compuesto extraño conocido como granadita que, en vez de acabar con su vida,
le otorgó la habilidad de volar, hacerse invisible y lanzar una limitada cantidad de
granadas radioactivas, convirtiéndose en el poco convencional Grenaderman!!

Al escuchar semejante noticia, la Alianza, la fuerza encargada de repeler el
ataque alienígena, decidió llamarlo para acabar de una vez por todas con la invasión y
recuperar nuestro preciado hogar.

#### Sobre la dinámica de una partida

- Preparación del terreno: modificación del tipo de terreno de cada hectárea.

- Asedio de los murloc: posicionamiento de la maquinaria de guerra y activación de
sus distintos mecanismos de defensa.

- Defensa a mano del atacante invisible: nuestro héroe sobrevolando el área
intentando destruir la maquinaria murloc antes de quedarse sin municiones.

#### Sobre el terreno invadido

Al hablar del terreno nos referimos a un área de 10x10 hectáreas (100 hectáreas
en total). Sobre este espacio se ubicarán físicamente las máquinas de guerra murloc y
nuestro Grenaderman dejará caer sus municiones.

El terreno puede ser de 3 tipos posible:

- ___Simple:___ un tipo de terreno sin nada especial, libre de restricciones.
  
- ___Montañoso:___ un tipo de terreno que se eleva tan alto que ninguna máquina puede
posicionarse allí ni sus defensas, así como no puede ser sobrevolada e incluso corta la
propagación de cualquier tipo de explosión.

- ___Abismal:___ un tipo de terreno que llega tan profundo hacia el centro del planeta que
cualquier máquina terrestre o granada que se coloque aquí se debe considerar
totalmente perdida. Sólo las máquinas voladoras pueden posicionarse en este tipo de
terreno.

#### Sobre la maquinaria murloc

La tecnología murloc logró desarrollar 5 tipos de máquinas de guerra:

- ___Cañones de perlas:___ el tipo de arma más simple, ocupan 1 hectárea y no tienen
defensa alguna.

- ___Torres coralinas:___ al posicionarse en un hectárea, inmediatamente despliegan
muros hechos de coral superresistente en la hectáreas ubicadas en sus perímetro.
Cada uno de estos muros es resistente a 1 sóla explosión, es decir cuando recibe un
impacto bloquea la propagación de la explosión pero luego es destruido. Al destruirse
la torre, todos sus muros se desintegran al instante.

- ___Nebulares hirvientes:___ al posicionarse en un hectárea, inmediatamente generan
nubes de agua hirviendo imperecederas en 2 combinaciones de hectáreas linderas
posibles: en los 4 puntos cardinales, o en las 4 diagonales. Estas nubes interrumpen
la propagación de cualquier explosión y no pueden ser despejadas a menos que se
destruya a la nebular desde alguno de sus puntos desprotegidos.

- ___Huracanes de tiburones:___ unidades voladoras que ocupan 1 hectárea, tienen
tiburones robot, simplemente letales. ¿Quién necesita defenderse cuando tiene
tiburones para atacar?

- ___Leviatanques:___ su nombre surgió de un ingenioso juego de palabras (“Leviatán” y
“tanque”), estas armas son fruto de las mentes ingenieriles murloc más brillantes,
armas voladoras totalmente imponentes y destructivas capaces de ocupar 4 hectáreas
dispuestas en un área de 2x2 hectáreas. No se puede considerar destruida hasta que
sus 4 partes no sean destruidas. También hay que tener en cuenta que los
leviatanques no pueden rozarse unos a los otros, por fallas estructurales que podrían
producirse por la vibración de otr leviatanque lindero, es decir, debe haber 1 hectárea
de diferencia entre un leviatanque y otro.

Hay que considerar además que todas estas armas poseen cabezales capaces de
repeler cualquier granada que se libere justo encima de ellas, al igual que sus
defensas poseen mecanismos repelentes de granadas. Al igual que una granada
liberada sobre un terreno abismal, las granadas liberadas directamente sobre una
máquina o defensa serán consideradas un desperdicio de municiones.

Cuando cualquiera de estas maquinarias es destruida, ella y sus defensas
simplemente deben desaparecer del área de invasión.

#### Sobre el Grenaderman

La invisibilidad de nuestro superhéroe lo hace básicamente intocable, por lo cual
nunca lo veremos en el terreno invadido, pero sí veremos el producto de sus ataques.

El Grenaderman contará con 2 tipos de municiones:

- ___Granadas justicieras:___ la rectitud es lo que caracteriza a estas granadas,
expandiendo la explosión por los 4 puntos cardinales hasta un máximo de 2 hectáreas,
esto significa que la explosión afectará a la hectárea donde fue liberada la granada y 2
hectáreas más en dirección a los punto cardinales.

- ___Granadas verdaderas:___ estas granadas son el complemento de las granadas
justicieras, expandiendo la explosión en dirección diagonal hasta un máximo de 2 hectáreas, esto significa que la explosión afectará a la hectárea donde fue liberada la
granada y 2 hectáreas más en las direcciones diagonales.

Nuestro héroe tendrá un arsenal compuesto por 7 de cada una de estas granadas,
por lo cual al alcanzar ambos límites, si quedara alguna máquina murloc en el terreno
la defensa se consideraría un fracaso.

#### Sobre la configuración del área invadida

Se deben tener en cuenta las siguientes pautas:

- No se podrá cambiar el tipo de terreno de una hectárea a montañoso si se
encontrara alguna arma posicionada en dicha hectárea.

- Si se realiza un cambio de terreno a abismal y en esa hectárea hubiera un arma no
voladora, dicha arma y sus defensas serán removidas del área de invasión.

- Ni las distintas armas ni sus defensas pueden superponerse. Caso contrario, se
debe cancelar el posicionamiento del arma que se intenta ingresar.

- Si a la defensa de alguna arma le corresponde un hectárea montañosa o abismal,
dicha defensa no podrá ser instalada pero el resto sí. Por ejemplo al posicionar una
torre coralina al lado de un terreno montañoso, el muro que correspondería a ese
terreno no podrá ser desplegado.

Como las máquinas voladoras pueden ser posicionadas tanto en terreno simple
como en terreno abismal, cuando se destruyen el tipo de esos terrenos debe persistir.

### Especificaciones técnicas

#### Grenaderman.h

Se debe desarrollar la biblioteca grenaderman.h que debe incluir las siguientes
funcionalidades:

// PRE: Las matrices deben estar creadas.

// POST: Si puede realizar el cambio de tipo de terreno de la hectárea
ubicada en la fila y columna indicadas, lo concreta y devuelve true,
sino abortará la operación y devolverá false.

___bool cambiarTipoTerreno(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int fila, int columna,
char tipoTerreno);___


// PRE: Las matrices deben estar creadas.

// POST: Si puede posicionar el cañón de perlas en la hectárea
ubicada en la fila y columna indicadas devuelve true, sino abortará
la operación y devolverá false.

___bool posicionarCanionPerlas(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int fila, int columna);___


// PRE: Las matrices deben estar creadas.

// POST: Si puede posicionar la torre coralina en la hectárea ubicada
en la fila y columna indicadas devuelve true, sino abortará la
operación y devolverá false.

___bool posicionarTorreCoralina(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int fila, int columna);___


// PRE: Las matrices deben estar creadas. Si el parámetro
enDireccionesCardinales es true entonces se colocarán las defensas
en las direcciones cardinales, sino será en las diagonales.

// POST: Si puede posicionar la nebular hirviente en la hectárea
ubicada en la fila y columna indicadas devuelve true, sino abortará
la operación y devolverá false.

___bool posicionarNebularHirviente(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int fila, int columna,
bool enDireccionesCardinales);___


// PRE: Las matrices deben estar creadas.

// POST: Si puede posicionar el huracán de tiburones en la hectárea
ubicada en la fila y columna indicadas devuelve true, sino abortará
la operación y devolverá false.

___bool posicionarHuracanTiburones(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int fila, int columna);___


// PRE: Las matrices deben estar creadas.

// POST: Si puede posicionar el leviatanque en las hectáreas
indicadas (fila y columna desde corresponden a la punta noroeste
de la máquina, y fila y columna hasta a la punta sureste) devuelve
true, sino abortará la operación y devolverá false.

___bool posicionarLeviatanque(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int filaDesde, int columnaDesde,
int filaHasta, int columnaHasta);___


// PRE: Las matrices deben estar creadas.

// POST: Si tiene suficientes municiones, libera una granada
justiciera en la hectárea ubicada en la fila y columna indicadas.
De ser así, actualizará la cantidad restante de municiones e
indicará cuántas hectáreas sufrieron daño por la explosión junto
con sus pares fila-columna, y finalmente devolverá true. Caso
contrario se abortará la operación y devolverá false.

___bool liberarGranadaJusticiera(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int fila, int columna,
int *municiones, int *cantHectareasAfectadas,
int hectareasAfectadas[9][2]));___


// PRE: Las matrices deben estar creadas.

// POST: Si tiene suficientes municiones, libera una granada
verdadera en la hectárea ubicada en la fila y columna indicadas.
De ser así, actualizará la cantidad restante de municiones e
indicará cuántas hectáreas sufrieron daño por la explosión junto
con sus pares fila-columna, y finalmente devolverá true. Caso
contrario se abortará la operación y devolverá false.

___bool liberarGranadaVerdadera(char terrenos[][DIMENSION],
char maquinas[][DIMENSION], int fila, int columna,
int *municiones, int *cantHectareasAfectadas,
int hectareasAfectadas[9][2]);___


- Los tipos de terreno serán ‘ ’ si es simple, ‘M’ si es montañoso y ‘A’ si es abismal.

- Las máquinas de guerra serán ‘C’ si es un cañón de perlas, ‘T’ si es una torre coralina, ‘N’ si es una nebular hirviente con paredes en dirección cardinal, ‘Z’ si es
una nebular hirviente con paredes en dirección diagonal, ‘H’ si es un huracán de
tiburones y ‘L’ si es un leviatanque.

- Las defensas de las máquinas serán ‘t’ si es la defensa de una torre coralina y ‘n’ si
es la defensa de una nebular hirviente.

- Para representar una parte de un leviatanque que sufrió daños se considerará el
valor ‘l’.

- La ausencia de máquinas se representará con el caracter ‘ ’ (espacio en blanco).

- Se debe considerar a las filas y columnas como números entre 1 y 10 inclusive;
los tipos de terreno se considerarán como los caracteres previamente especificados; la
matriz de terrenos se inicializará con terrenos simples y la de máquinas con ausencia
de máquinas.

- En el archivo *grenaderman.h* SÓLO deben figurar las funciones acá mencionadas
para poder utilizarlas en los tests. En el archivo *grenaderman.c* se podrá utilizar
cualquier función/procedimiento auxiliar que crean conveniente.

#### GrenadermanTest.c

- La estructura de este programa se caracterizará por tener una función o
procedimiento por cada caso de prueba que se les ocurriese. Por ejemplo habría un
procedimiento que vería el caso de liberar una granada directamente sobre un arma,
comprobando que no hubo ninguna hectárea afectada y las municiones de la granada
liberada se verían decrementadas.

### Referencias

<https://es.wikipedia.org/wiki/Bomberman>

<http://es.worldofwarcraft.wikia.com/wiki/Murloc>

<http://wow-es.gamepedia.com/Alianza>

<https://es.wikipedia.org/wiki/Sharknado>
