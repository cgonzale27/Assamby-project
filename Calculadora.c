.data
selector: .word 0 #empezando a escribir desde 0x10000000 que es donde empieza data
a: .word 5 #cada valor tiene espacio de 32 bites o 1 word aunque no se ocupe
b: .word 3
c: .word 0

.text

MAIN:
lui t0, 0x10000 #guardamos la aproximacion del inicio de data com lui porque no podemos cuardar toda la direccion em 32 bits
lw s0, 0(t0) #el valor de t0 recorrido sin moverse ya que es el primer valor en data
lw s1, 4(t0) #segundo valor en data recorrido 32bits porque el valor anterior (selector) abarca 32 bits
lw s2, 8(t0)
lw s3, 12(t0)
  
SELECTOR:

addi t1, zero, 1 #manipulamos t1 para que se comoarte con s0(selector) y dar el salto al case
  beq s0, t1, CASE1

addi t1, zero, 2
  beq s0, t1, CASE2

addi t1, zero, 3
  beq s0, t1, CASE3

  jal zero, DEFAULT #se hicieron todas las comparaciones, entonces si llega a este punto ya es default que es cualquier valor del selector indiferente a 1,2 o 3

CASE1: #suma facil com add
  add s3, s1, s2
  sw s3, 12(t0) #escribir el resultado a partir del espacio de memoria que c tiene asignado
  
  jal zero, MAIN #saltar a main

CASE2:
  sub s3, s1, s2 #resta dab lol
  sw s3, 12(t0) #escribir en el espacio de memoria de c
  jal zero, MAIN

CASE3:
  addi t1, zero, zero #iterador aumenta
  add s3, zero, zero #poner s3 en 0 para la multiplicacion
  MULT:
  add s3, s3,s1 #c=c+a
  addi t1, t1, 1 #i++
  bne s2, t1, MULT #comparando iterador t1!=s2 para seguir el ciclo de multiplicacin
  #multiplicacion se cumplira hasta que se le sume a 0 (s3 forzado a iniciar en 0) el valor de s1, la cantidad de veces que s2 sea
  sw s3, 12(t0) #escribir en RAM
  jal zero, MAIN

DEFAULT:
  and s3, s1, s2 #compuerta AND donde hace la compuerta AND bit por bit de s1 y s2, ex. s1=2=10, s2=1=01, s1ANDs2=s3 ; s3=decima, 0=00 binario
  sw s3, 12(t0) #escribir el 0 o 1 en el espacio de RAM de C
  jal zero, MAIN
