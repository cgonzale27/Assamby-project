.data

M: .word 0,1,2,3,4 #arreglo de 0-16 t1
P: .word 10,11,12 # de20-28 t2
R: .word 0,0,0 #de 32-44 t3

r: .word 0 #recorrido 48 a0
i: .word 0 #recorrido 52 a1
j: .word 0 #recorrido 56 a2
q: .word 0 #recorrido 60 a3

.text
  #r a0
  #i a1
  #j a2
  #q a3
  
MAIN: 
  lui t0, 0x10000 #inicio .data
  addi s1, t0, 20 #inicio arreglo P
  addi t2, t0, 0 #inicio arreglo M
  addi t4, t0, 32 #inicio arreglo R
  add a2, zero, zero #j=0
BUCLE1:
  slti t5, a2, 3 #j<3; t1=1
  beq t5, x0, MAIN #t1=0 va a MAIN porque i>=3 y se rompe el bucle
  lw t6, 0(s1) #cargar valor del arreglo en la memoria
  add a3, x0, t6 #q=P[j]
  addi a1, zero, zero #i=0 es funcional pero no eficaz lol
  addi s1, s1, 4 #recorrer siguiente posicion de memoria del arreglo

  BUCLE2:
  slti t1, a1, 5 #i<5; t1=1 sigue el bucle
  beq t1, x0, FINAL #si t1=0 se rompio el for
  lw t3, 0(t2) #t3=M[i]
  add a0, a3, t3 #r=q+M[i]
  addi a1, a1, 1 #i++
  addi t2, t2, 4 #Mover t2 al siguiente espacio de memoria de M[]
  bne t1, x0, BUCLE2

  FINAL:
  addi t2, t0, 0 #reinicio a donde inicia la memoria del arreglo M para volver a usar el arreglo desde el primer argumento
  sw a0, 0(t4) #R[j]=r
  add a0, zero, zero #r=0
  addi t4, t4, 4 #recorrer R[j] al siguiente espacio de me oria para ponerle el nuevo valor de r calculado
  addi a2, a2, 1 #j++ apenas termina un ciclo de BUCLE1
  bne t5, x0, BUCLE1 #Si t5=1 i<3 en MAIN
