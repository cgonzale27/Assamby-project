.data

M: .word 0,1,2,3,4 #arreglo de 0-16 t1
P: .word 10,11,12 # de20-28 t2
R: .word 0,0,0 #de 32-44 t3

r: .word 0; #recorrido 48 a0
i: .word 0; #recorrido 52 a1
j: .word 0; #recorrido 56 a2
q: .word 0; #recorrido 60 a3

.text

lui t0, 10000
  
  addi a0, zero, zero #r
  addi a1, zero, zero #i
  addi a2, zero, zero #j
  addi a3, zero, zero #q
  
MAIN 

  lw s1, 20(t0) #inicio arreglo P
  lw t2, 0(t0) #inicio arreglo M
  lw t4, 32(t0) #inicio arreglo R
BUCLE1
  slti t5, a2, 3 #j<3; t1=1
  beq t5, x0, BUCLE2 #t1=0 va a bucle2 porque i>=3 y se rompe el bucle
  lw t6, 0(s1) #cargar valor del arreglo en la memoria
  add a3, a3, t6 #q=P[j]
  addi a2, a2, 1 #j++
  addi s1, s1, 4 #recorrer siguiente posicion de memoria del arreglo

  BUCLE2
  slti t1, a1, 5 #i<5; t1=1 sigue el bucle
  beq t1, x0, FINAL #si t1=0 se rompio el for
  lw t3, 0(t2) #t3=M[i]
  addi a0, a3, t3 #r=q+M[i]
  addi a1, a1, 1 #i++
  addi t2, t2, 4 #Mover t2 al siguiente espacio de memoria de M[]
  bne t1, x0, BUCLE2

  FINAL
  sw a0, 0(t4) #R[j]=r
  add a0, zero, zero #r=0
  bne t5, x0 BUCLE1 #Si t5=1 i<3 sige bucle
