

.data
    a: .word 0
    x: .word 0
    c: .word 0
    d: .word 0
    e: .word 0
    text1 : .asciiz "a="
    temp0: .word 0
    text2 : .asciiz "c="
    temp1: .word 0
    temp2: .word 0
    temp3: .word 0
    text3 : .asciiz "e="
enter : .asciiz " \n" 
.text
main:
	li $t0, 30
	sw $t0, a
	li $v0, 4
	la $a0, text1
	syscall

	li $v0, 4
	la $a0, enter
	syscall
	li $v0, 1
	lw $a0, a
	syscall

	li $v0, 4
	la $a0, enter
	syscall
	li $t0, 10
	sw $t0, x
	lw $s0, a
	li $s1, 300
	div $s1, $s0
	mflo $t2
	sw $t2, temp0
	lw $t0, temp0
	sw $t0, c
	li $v0, 4
	la $a0, text2
	syscall

	li $v0, 4
	la $a0, enter
	syscall
	li $v0, 1
	lw $a0, c
	syscall

	li $v0, 4
	la $a0, enter
	syscall
	lw $t0, a
	li $t1, 2
	mult $t0, $t1
	mflo $t2
	sw $t2, temp1
	lw $t0, temp1
	addi $t2, $t0, 2
	sw $t2, temp2
	lw $t0, temp2
	sw $t0, d
	lw $t0, a
	lw $t1, x
	mult $t0, $t1
	mflo $t2 
	sw $t2, temp3
	lw $t0, temp3
	sw $t0, e
	li $v0, 4
	la $a0, text3
	syscall

	li $v0, 4
	la $a0, enter
	syscall
	li $v0, 1
	lw $a0, e
	syscall

	li $v0, 4
	la $a0, enter
	syscall

	li $v0, 4
	la $a0, enter
	syscall
	li $v0, 10
	syscall