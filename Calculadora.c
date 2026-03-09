.data
selector: .word 0
a: .word 5
b: .word 3
c: .word 0

.text

MAIN:
lui t0, 0x10000
lw s0, 0(t0)
lw s1, 4(t0)
lw s2, 8(t0)
lw s3, 12(t0)
  
SELECTOR:

addi t1, zero, 1
  beq t0, t1, CASE1

addi t1, zero, 2
  beq t0, t1, CASE2

addi t1, zero, 3
  beq t0, t1, CASE3

addi t1, zero, 4
  bge to, t1, DEFAULT
CASE1:
  add s3, s1, s2
  sw s3, 12(t0)
  jal zero, MAIN

CASE2:
  sub s3, s1, s2
  sw s3, 12(t0)
  jal zero, MAIN

CASE3:
  addi t1, zero, zero
  MULT:
  add s3, s1,s1
  addi t1, t1, 1
  bne s3, t1, MULT
  sw s3, 12(t0)
  jal zero, MAIN

DEFAULT:
  and s3 s1, s2
  sw s3, 12(t0)
  jal zero, MAIN
