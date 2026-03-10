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
  addi a3, zero, zero #q
  addi t4, zero, zero #i

  FINAL
  lw t1, 0(t0)
  add a0, a3, t1 #r=q+M[i]
  addi t4, t4, 1 #i++
  add t0, t0, 4 #recorrido para apunte a la siguiente memoria
  blt t4, t5, FINAL

  
