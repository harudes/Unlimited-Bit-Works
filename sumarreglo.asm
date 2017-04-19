.text # Aqui empieza el segmento de codigo
.globl __start
__start:
	la $t0,array # $t0 apuntara a los elementos
	lw $t1,count # sale del bucle cuando $t1 es 0
	lw $t2,suma # inicializa min ($t2)
	la $a0,ans1
	li $v0,4
	syscall # imprime "Ingrese un numero: "
	li $v0,5
	syscall
	add $t1, $t1,$v0
	la $a0,ans2 # cuando termina el bucle imprime respuestas
	li $v0,4
	syscall # imprime "La suma de los "
	move $a0,$t1
	li $v0,1
	syscall # Imprime la cantidad de numeros sumados
	la $a0,ans3 # cuando termina el bucle imprime respuestas
	li $v0,4
	syscall # imprime " primeros numeros es: "
	la $a0,endl # imprime un salto de linea
		li $v0,4
		syscall
loop:
	lw $t4,($t0) # carga la siguiente palabra del arreglo
	add $t2, $t2,$t4
	add $t1,$t1,-1 # decrementa el contador
	add $t0,$t0,4
	bnez $t1,loop # y continua si contador>0
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
count: .word 0
suma: .word 0
endl: .asciiz "\n"
ans1: .asciiz "Ingrese un numero: "
ans2: .asciiz "La suma de los "
ans3: .asciiz " primeros numeros es: "