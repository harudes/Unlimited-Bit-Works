.text # Aqui empieza el segmento de codigo
.globl __start
__start:
	la $t0,array # $t0 apuntara a los elementos
	lw $t1,count # sale del bucle cuando $t1 es 0
	lw $t2,suma # inicializa min ($t2)
loop:
	lw $t4,($t0) # carga la siguiente palabra del arreglo
	add $t2, $t2, $t4
#end:
	add $t1,$t1,-1 # decrementa el contador
	add $t0,$t0,4
	bnez $t1,loop # y continua si contador>0
	la $a0,ans1 # cuando termina el bucle imprime respuestas
	li $v0,4
	syscall # imprime "La suma es: "
	move $a0,$t2
	li $v0,1
	syscall # Imprime la suma
	la $a0,endl # imprime un salto de linea
		li $v0,4
		syscall
		li $v0,10
		syscall # fin del programa...
#################################################
# data segment #
#################################################
	.data # Aqui empieza el segmento de datos
array: .word 3,4,2,6,12,7,18,26,2,14,19,7,8,12,13
count: .word 4
suma: .word 0
endl: .asciiz "\n"
ans1: .asciiz "La suma es: "